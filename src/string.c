#include "include/string.h"
#include "include/stringbuilder.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

String string_new(const char* data) {
    return (String) {
        .data = data,
        .len = strlen(data),
        .was_allocated = false,
    };
}

String string_from_parts(const char* data, usize len) {
    return (String){
        .data = data,
        .len = len,
        .was_allocated = false,
    };
}

void string_free(String* str) {
    if (str->was_allocated) {
        free((char*)str->data);
    }
}

// Comparing two Strings and that sort

// Compare the equality of two strings
bool string_eq(const String* str, const String* other) {
    if (str->len != other->len) {
        return false;
    }

    for (usize i = 0; i < str->len; ++i) {
        if (str->data[i] != other->data[i]) {
            return false;
        }
    } 

    return true;
}

// Check if str contains needle
bool string_has(const String* str, const String* needle) {
    if (needle->len > str->len) {
        return false;
    }

    if (string_eq(str, needle)) {
        return true;
    }

    for (usize i = 0; i < str->len - needle->len; ++i) {
        if (str->data[i] == needle->data[0]) {
            String a = (String) {
                str->data+i, 
                needle->len, 
                0
            }; 

            if (string_eq(&a, needle)) {
                return true;
            }
        }
    }

    return false;
}

// Functions that return Strings
// 
// The returned string must be freed as it's heap-allocated

// return a subtring between start and end index
String string_substr(const String* str, usize start, usize end) {
    assert(end > start);
    usize len = end - start;
    char* buf = calloc(len+1, sizeof(char));
    for (usize i = start; i < end; ++i) {
        buf[i-start] = str->data[i];
    }
    return (String) {
        buf,
        len,
        true,
    };
}

// Return the string in lowercase
String string_to_lower(const String* str) {
    // A -> 65
    // Z -> 90
    
    StringBuilder* sb = string_builder_new();
    for (usize i = 0; i < str->len; ++i) {
        char c = str->data[i];
        if (c > 'A' && c < 'Z') c += 32;
        string_builder_append_char(sb, c);
    }

    return string_builder_to_string(sb);
}

// Return the string in uppercase
String string_to_upper(const String* str);

// Return a string from an integer
String string_from_i32(i32 num);

// Open a file, read it and return the contents of the file as a string
String string_slurp_file(const char* path) {
    FILE* file = NULL;
    file = fopen(path, "rb");
    assert(file);

    fseek(file, 0, SEEK_END);
    usize file_size = ftell(file);
    rewind(file);

    char* file_data = (char*) calloc(file_size+1, 1);
    assert(file_data);

    fread(file_data, 1, file_size, file);
    fclose(file);

    return (String) {
        .data = file_data,
        .len = file_size, 
        .was_allocated = true
    };
}

// Functions that return a number of sorts

// Take a String and return its hash value using builtin hash function
u64 string_hash(const String* str);

// Returns the index of the given character in the string. -1 if the character 
// is not in the String
ssize string_index_of(const String* str, char c);

// Returns the index of the subtring in the string. -1 if the substring does not
// exist in the given String
ssize string_index_of_substr(const String* str, const String* needle);

// Returns an integer value of the given String
i32 string_to_i32(const String* str);

