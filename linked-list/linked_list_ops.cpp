//
//  main.cpp
//  Linked Lists
//
//  Created by Gurwinder Singh on 23/06/20.
//  Copyright © 2020 Gurwinder Singh. All rights reserved.
//


#include <iostream>
#include <time.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};


Node* create_linked_list(int A[], int n) {
    Node *p = new Node;
    p->data = A[0];
    Node *head = p;
    for (int i = 1; i < n; i++) {
        Node *new_node = new Node;
        new_node->data = A[i];
        new_node->next = NULL;
        p->next = new_node;
        p = new_node;
    }
    
    return head;
}

void print_linked_list(Node* head) {
    Node *p = head;
    while (p != NULL) {
        cout << p->data << "\n";
        p = p->next;
    }
}

void recursive_print_linked_list(Node* head) {
    if (head != NULL) {
        cout << head->data << "\n";
        recursive_print_linked_list(head->next);
    }
}

int length_of_linked_list(Node* head) {
    int len = 0;
    Node *p = head;
    while (p != NULL) {
        // Do something.
        len++;
        p = p->next;
    }
    
    return len;
}


int main(int argc, const char * argv[]) {
    // Start time -- to measure total time taken in the program.
    clock_t c0, c1;
    c0 = clock();
    
    int A[] = {1,4,8,12};
    
    Node *head = create_linked_list(A, 4);
    
    print_linked_list(head);
    recursive_print_linked_list(head);
    
    printf("length of linked list: %d\n", length_of_linked_list(head));
    
    
    // Everything is done. Figure the total time taken.
    c1 = clock();
    printf("CPU time: %fs\n", (float) (c1 - c0) / CLOCKS_PER_SEC);
    return 0;
}
