#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>
#include <stdlib.h>

#define log_info(...) \
    fprintf(stdout, "[INFO] ");\
    fprintf(stdout, __VA_ARGS__); \
    fprintf(stdout, "\n")

#define log_warn(...) \
    fprintf(stdout, "[WARN] ");\
    fprintf(stdout, __VA_ARGS__); \
    fprintf(stdout, "\n")

#define log_err(code, ...) \
    fprintf(stderr, "[ERROR] ");\
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n");\
    exit((code))

#define log_info_file(file, ...) \
    fprintf((file), "[INFO] ");\
    fprintf((file), __VA_ARGS__); \
    fprintf((file), "\n")

#define log_warn_file(file, ...) \
    fprintf((file), "[WARN] ");\
    fprintf((file), __VA_ARGS__); \
    fprintf((file), "\n")

#define log_err_file(code, file, ...) \
    fprintf((file), "[ERROR] ");\
    fprintf((file), __VA_ARGS__); \
    fprintf((file), "\n");\
    exit((code))

#endif  //__LOG_H
