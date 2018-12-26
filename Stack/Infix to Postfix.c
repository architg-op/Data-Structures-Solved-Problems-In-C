//
//  main.c
//  infix to PostFix
//
//  Created by Archit Garg on 09/12/18.
//  Copyright © 2018 Archit tech. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    char *a;
    int size;
};

typedef struct Stack stack;

stack *createStack(int d) {
    stack *st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->a = (char*)malloc(sizeof(char) * d);
    st->size = d;
    return st;
};

int isFull(stack *st) {
    if (st->top == st->size - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(stack *st) {
    if (st->top == -1) {
        return 1;
    }
    return 0;
}

void push(stack *st, char ch) {
    if (!isFull(st)) {
        st->a[++st->top] = ch;
    }
}

void pop(stack *st) {
    if (!isEmpty(st)) {
        st->top--;
    }
}

int isOperand(int ch) {
    if ((ch >= 65 && ch <=90) || (ch >= 97 && ch <= 112)) {
        return 1;
    }
    return 0;
}

int peek(stack *st) {
    return st->a[st->top];
}

int prec(char ch) {
    switch (ch) {
        case '+' :
        case '-' : return 1;
            break;
        case '*' :
        case '/' : return 2;
            break;
        case '^' : return 3;
        default : return 0;
    }
}



void infixToPostFix(stack *st, char *str) {
    char *newstr = (char*)malloc(sizeof(char) * strlen(str));
    int i = 0;
    int k = 0;
    while (str[i] != '\0') {
        if (isOperand(str[i])) {
            newstr[k++] = str[i];
        }
        else if (str[i] == '(') {
            push(st, str[i]);
        }
        else if (str[i] == ')') {
            while (peek(st) != '(') {
                newstr[k++] = peek(st);
                pop(st);
            }
            pop(st);
        }
        else {
            if(isEmpty(st)) {
                push(st, str[i]);
            }
            else {
                if (prec(peek(st)) < prec(str[i])) {
                    push (st, str[i]);
                }
                else {
                    while (prec(peek(st)) >= prec(str[i]) && !isEmpty(st) && peek(st) != '(') {
                        newstr[k++] = peek(st);
                        pop(st);
                    }
                    push(st, str[i]);
                }
            }
        }
        i++;
    }
    while (!isEmpty(st)) {
        newstr[k++] = peek(st);
        pop(st);
    }
    i = 0;
    while (i < k) {
        printf("%c",newstr[i]);
        i++;
    }
}

int main() {
    stack *st = createStack(100);
    char *str = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostFix(st, str);
    return 0;
}
