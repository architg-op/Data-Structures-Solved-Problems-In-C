//
//  main.c
//  Check if Linked List is Palindrome or Not
//
//  Created by Archit Garg on 09/12/18.
//  Copyright © 2018 Archit tech. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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

int peek(stack *st) {
    return st->a[st->top];
}

struct Node {
    char data;
    struct Node *next;
};

typedef struct Node node;

node *createNode(int d) {
    node *n = (node*)malloc(sizeof(node));
    n->data = d;
    n->next = NULL;
    return n;
}

void add(node **head, char ch) {
    node *n = createNode(ch);
    if (*head == NULL) {
        *head = n;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void printList(node *head) {
    while (head != NULL) {
        printf("%c ",head->data);
        head = head->next;
    }
    printf("\n");
}

void checkPalindrome(node *head) {
    stack *st = createStack(10);
    node *temp = head;
    while (temp != NULL) {
        push(st, temp->data);
        temp = temp->next;
    }
    temp = head;
    int f = 0;
    while (!isEmpty(st)) {
        if (peek(st) != temp->data) {
            f = 1;
            break;
        }
        temp = temp->next;
        pop(st);
    }
    if (f == 0) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }
}

int main() {
    struct node *head = NULL;
    add(&head, 'r');
    add(&head, 'a');
    add(&head, 'd');
    add(&head, 'a');
    add(&head, 'r');
   // add(&head, 'r');
  //  printList(head);
    checkPalindrome(head);
    return 0;
}
