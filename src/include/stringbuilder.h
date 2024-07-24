#ifndef __STRINGBUILDER_H
#define __STRINGBUILDER_H

#include "alias.h"
#include "string.h"

typedef struct string_builder_t {
    char* data;
    usize len;
    usize cap;
} StringBuilder;

StringBuilder* string_builder_new();
void string_builder_free(StringBuilder* sb);

String string_builder_to_string(StringBuilder* sb);
void string_builder_append_char(StringBuilder* sb, char c);
void string_builder_append_cstr(StringBuilder* sb, const char* str);
void string_builder_append_string(StringBuilder* sb, const String* str);
void string_builder_delete(StringBuilder* sb, usize start, usize end);
void string_builder_reverse(StringBuilder* sb);
void string_builder_shrink(StringBuilder* sb);

#endif  //__STRINGBUILDER_H
