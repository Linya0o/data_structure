/**
 * Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 * File Name: main.c
 * Date     : 2022-12-03
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/string_searching.h"

int main(int argc, char *argv[]) {
    char *s = "goodgoogle";
    char *p = "google";
    int index = bf(s, p);
    printf("bf pos: %d\n", index);
    int pos = kmp(s, p);
    printf("kmp pos: %d\n", pos);

    return EXIT_SUCCESS;
}
