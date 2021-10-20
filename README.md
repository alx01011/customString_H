# Assignment 2: A String Module

## General info

Implemented some of `string.h` standard library functions in module `mystring`. 

1. `strlen()` as `ms_length()`
2. `strcpy()` as `ms_copy()`
3. `strncpy()` as `ms_ncopy()`
4. `strcat()` as `ms_concat()`
5. `strncat()` as `ms_nconcat()`
6. `strstr()` as `ms_search()`

### Side notes

In every function, the assert macro is used to check whether the pointers provided are **NULL** therefore perfom no operations and exit with an error code.

