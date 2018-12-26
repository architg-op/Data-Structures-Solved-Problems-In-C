//
//  main.c
//  Reverse a Linked List
//
//  Created by Archit Garg on 09/12/18.
//  Copyright © 2018 Archit tech. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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

void push(node **head, char ch) {
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

void reverseList(node **head) {
    node *prev = NULL;
    node *curr = *head;
    node *next = *head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    struct node *head = NULL;
    push(&head, 'a');
    push(&head, 'b');
    push(&head, 'c');
    push(&head, 'd');
    push(&head, 'e');
    push(&head, 'f');
    reverseList(&head);
    printList(head);
    return 0;
}
