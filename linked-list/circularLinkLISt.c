#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first;
void create(int a[], int n)
{
    int i = 0;
    struct node *temp, *last;
    first = (struct node *)malloc(sizeof(struct node *));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node *));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Display(struct node *p)
{
    do
    {
       printf("%d ", p->data);
        p = p->next;
    } while (p!=first);
    
}

int main()
{
    int a[] = {1, 2, 3, 4, 6};
    create(a, 5);
    Display(first);
    return 0;
}
