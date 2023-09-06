/***********************************************************
 > Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 > File Name: main.c
 > Date     : 2022-12-03
 > Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/stack.h"

bool is_operator(int ch);
int rank(int ch);
void transform(char *exp, char s2[]);
int calculate(char *exp);

int main(int argc, char *argv[]) {
    // 逆波兰式求值（Reverse Polish Notation, RPN）
    char *str = "9+(3-1)*3+4/2";
    char ret[20] = { 0 };
    transform(str, ret);
    puts(ret);
    printf("ret: %d\n", calculate(ret));

    return EXIT_SUCCESS;
}

bool is_operator(int ch) {
    return strchr("+-*/", ch);
}

int rank(int ch) {
    if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return 0;
}

void transform(char *exp, char ret[]) {
    Stack s = init_stack(20);
    size_t i = 0;
    while (*exp) {
        switch (*exp) {
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6': case '7':
            case '8': case '9': ret[i++] = *exp; break;
            case '(': push(s, *exp); break;
            case ')': {
                int ch;
                while ((ch = pop(s)) != '(') ret[i++] = ch;
                break;
            }
            case '+': case '-': case '*': case '/':
                while (!empty(s) && is_operator(top(s)) && rank(top(s)) >= rank(*exp)) ret[i++] = pop(s);
                push(s, *exp);
                break;
        }
        exp++;
    }
    while (!empty(s)) ret[i++] = pop(s);
    destroy(s);
    puts("");
}

int calculate(char *exp) {
    int ret;
    Stack s = init_stack(20);
    while (*exp) {
        if (is_operator(*exp)) {
            int b = pop(s);
            int a = pop(s);
            switch(*exp) {
                case '*': ret = a * b; break;
                case '/': ret = a / b; break;
                case '+': ret = a + b; break;
                case '-': ret = a - b; break;
            }
            push(s, ret);
        } else push(s, *exp-'0');
        exp++;
    }
    return ret;
}
