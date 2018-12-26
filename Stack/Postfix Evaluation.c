//
//  main.c
//  PostFix Evaulation
//
//  Created by Archit Garg on 09/12/18.
//  Copyright © 2018 Archit tech. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int top;
    int *a;
    int size;
};

typedef struct Stack stack;

stack *createStack(int d) {
    stack *st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->a = (int*)malloc(sizeof(int) * d);
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

void push(stack *st, int val) {
    if (!isFull(st)) {
        st->a[++st->top] = val;
    }
}

void pop(stack *st) {
    if (!isEmpty(st)) {
        st->top--;
    }
}

int peek(stack *st) {
    return st->a[st->top];
}

void postfixEval(stack *st, char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            push(st, str[i] - '0');
        }
        else {
            int b = peek(st);
            pop(st);
            int a = peek(st);
            pop(st);
            switch (str[i]) {
                case '+':
                    push (st, a + b);
                    break;
                case '-':
                    push (st, a - b);
                    break;
                case '*':
                    push (st, a * b);
                    break;
                case '/':
                    push (st, a / b);
                    break;
                default:
                    break;
            }
        }
        i++;
    }
    printf("%d\n", peek(st));
}

int main() {
    stack *st = createStack(100);
    char exp[] = "231*+9-";
    postfixEval(st, exp);
    return 0;
}
