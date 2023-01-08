#include <string.h>
#include "include/string_searching.h"

static void get_next(char p[], int next[]) {
    next[0] = -1, next[1] = 0;
    int j = 2, plen = strlen(p);
    // 生成next
    while (j < plen) {
        if (next[j - 1] != 0 && p[j-1] == p[next[j-1]]) {
            next[j] = next[j-1] + 1;
        } else if (p[0] == p[j-1]) {
            next[j] = 1;
        } else {
            next[j] = 0;
        }
        j++;
    }
}

int bf(char *s, char *p) {
    int i = 0, j = 0;
    int slen = strlen(s);
    int plen = strlen(p);
    while (i < slen && j < plen) {
        if (s[i] == p[j]) {
            i++, j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return j < plen ? -1 : i - j;
}

int kmp(char *s, char *p) {
    int slen = strlen(s);
    int plen = strlen(p);
    int next[plen];
    get_next(p, next);
    int i = 0, j = 0;
    while (i < slen && j < plen) {
        if (j == -1 || s[i] == p[j]) {
            i++, j++;
        } else {
            j = next[j];
        }
    }
    return j == plen ? i - j : -1;
}
