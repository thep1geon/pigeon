#include "include/stringbuilder.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Allocate a new StringBuilder on the heap and initialize it
StringBuilder* string_builder_new() {
    StringBuilder* sb = malloc(sizeof(StringBuilder));
    assert(sb);

    sb->len = 0;
    sb->cap = 16;
    sb->data = malloc(sb->cap);
    assert(sb->data);

    return sb;
}

// Free the memory related to a StringBuilder object
void string_builder_free(StringBuilder* sb) {
    assert(sb);
    free(sb->data);
    free(sb);
}

// Frees the StringBuilder and returns a non-mutable String object
String string_builder_to_string(StringBuilder* sb) {
    string_builder_append_char(sb, '\0');

    String s = {
        .was_allocated = true,
        .len = sb->len-1,
        // We don't want to include the null byte as part of the length
    };

    s.data = malloc(s.len+1);
    assert(s.data);
    memcpy((char*)s.data, sb->data, s.len+1);

    string_builder_free(sb);

    return s;
}

void string_builder_append_char(StringBuilder* sb, char c) {
    if (sb->len == sb->cap) {
        sb->cap *= 2;
        sb->data = realloc(sb->data, sb->cap);
        assert(sb->data);
    }

    sb->data[sb->len++] = c;
}

void string_builder_append_cstr(StringBuilder* sb, const char* str) {
    usize len = strlen(str);
    for (usize i = 0; i < len; ++i) {
        string_builder_append_char(sb, str[i]);
    }
}

void string_builder_append_string(StringBuilder* sb, const String* str) {
    for (usize i = 0; i < str->len; ++i) {
        string_builder_append_char(sb, str->data[i]);
    }
}

void string_builder_delete(StringBuilder* sb, usize start, usize end) {
    assert(end > start);
    assert(start < sb->len);

    memmove(sb->data+start, sb->data+end, sb->len - end);
    sb->len -= end - start;
    memset(sb->data + sb->len, '\0', sb->cap - sb->len);
}

void string_builder_reverse(StringBuilder* sb) {
    for (usize i = 0; i < sb->len / 2; ++i) {
        char tmp = sb->data[i];
        sb->data[i] = sb->data[sb->len - i - 1];
        sb->data[sb->len - i - 1] = tmp;
    }
}

void string_builder_shrink(StringBuilder* sb) {
    if (sb->len == 0) return;
    sb->cap = sb->len;
    sb->data = realloc(sb->data, sb->cap);
    assert(sb->data);
}
