#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define LOG_INFO(...) \
    PRINT_FILE_LOC(stdout);\
    fprintf(stderr, "[INFO] ");\
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n")

#define LOG_WARN(...) \
    PRINT_FILE_LOC(stderr);\
    fprintf(stderr, "[WARN] ");\
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n")

#define LOG_FATAL(code, ...) \
    PRINT_FILE_LOC(stderr);\
    fprintf(stderr, "[ERROR] ");\
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n");\
    exit((code))

#define LOG_INFO_FILE(file, ...) \
    PRINT_FILE_LOC((file));\
    fprintf((file), "[INFO] ");\
    fprintf((file), __VA_ARGS__); \
    fprintf((file), "\n")

#define LOG_WARN_FILE(file, ...) \
    PRINT_FILE_LOC((file));\
    fprintf((file), "[WARN] ");\
    fprintf((file), __VA_ARGS__); \
    fprintf((file), "\n")

#define LOG_FATAL_FILE(code, file, ...) \
    PRINT_FILE_LOC((file));\
    fprintf((file), "[ERROR] ");\
    fprintf((file), __VA_ARGS__); \
    fprintf((file), "\n");\
    exit((code))

#endif  //__LOG_H
