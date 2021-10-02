/*
Problem Description:- 
In this problem statement we are provided with the pointer or reference to the head of a singly linked list,
invert the list, and return the pointer or reference to the head of the new reversed linked list.

Example:- 
Input:-    1->2->3->4->5
Output:-     5->4->3->2->1

Solution for Reversing a Linked List:-
If the linked list has only one or no element, then we return the current list as it is. And if there are two or more elements, 
then we can implement an iterative solution using three-pointers

We will create a function to reverse the linked list taking reference to the head node 
and as the only argument and return the head of the new linked list:
    Step 1: Define three nodes one with the reference to the head node and name it current, 
            and name the other two nodes temp and prev pointers as NULL.
    Step 2: Using a while loop we will traverse the linked list once until the next pointer does not become NULL.
    Step 3: While iterating, we perform the following operations: 
          temp = current->next;
          current->next = prev;
          prev = current;
          current = temp;
          
Time complexity:    O(N) because we iterate through each element at least once. 
Space complexity:   O(1) because no extra space was used here
*/

#include<bits/stdc++.h>
 
using namespace std;
 
struct node {
    int data;
    struct node *next;
};
 
// To create a demo we have to construct a linked list and this 
// function is to push the elements to the list. 
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
// Function to reverse the list
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
 
// To check our program 
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
 
// Driver function
int main() {
    struct node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 8);
    push(&head, 0);
    push(&head, 4);
    push(&head, 10);
    cout << "Linked List Before Reversing" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Linked List After Reversing"<<endl;
    printnodes(head);
    return 0;
}
