#ifndef __STRING_H
#define __STRING_H

#include "alias.h"

typedef struct string_t String;
struct string_t {
    const char* data;
    usize len;
    bool was_allocated : 1;
};

// Making and Destroying Strings

// Make a new string with the data and the stdlib strlen function
String string_new(const char* data);

// Zero-allocate a new String with len length
String string_alloc(usize len);

// Make a new string with the data and a given length
String string_from_parts(const char* data, usize len);

// Attempt to free a stirng. If the String's data was not heap-allocated,
// the function will simply return, no invalid free
void string_free(String* str);

// Comparing two Strings and that sort

// Compare the equality of two strings
bool string_eq(const String* str, const String* other);

// Check if str contains needle
bool string_has(const String* str, const String* needle);

// Functions that return Strings
// 
// The returned string must be freed as it's heap-allocated

// return a subtring between start and end index
String string_substr(const String* str, usize start, usize end);

// Return the string in lowercase
String string_to_lower(const String* str);

// Return the string in uppercase
String string_to_upper(const String* str);

// Return a string from an integer
String string_from_i32(i32 num);

// Open a file, read it and return the contents of the file as a string
String string_slurp_file(const char* file_path);

// Reverse a String
String string_rev(const String* str);

// Functions that return a number of sorts

// Take a String and return its hash value using builtin hash function
u64 string_hash(const String* str);

// Returns the index of the given character in the string. -1 if the character 
// is not in the String
isize string_index_of(const String* str, char c);

// Returns the index of the subtring in the string. -1 if the substring does not
// exist in the given String
isize string_index_of_substr(const String* str, const String* needle);

// Returns an integer value of the given String
i32 string_to_i32(const String* str);

#endif  //__STRING_H
