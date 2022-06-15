#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data;
    struct dataNode* next;
} node;

node* merge_sort(node* head1, node* head2);
node* enter_numbers();
void printList(node* head);
int main()
{
    node* head1 = enter_numbers();
    node* head2 = enter_numbers();
    node* mergedNode = merge_sort(head1,head2);
    printf("mergedNode: ");
    printList(mergedNode);
    printList(head1);
    printList(head2);
    

    return 0;
}


node* merge_sort(node* head1, node* head2)
{
    if (head1 == NULL && head2!=NULL)
        return head2;

    else if (head2 == NULL && head1!=NULL)
        return head1;
    
    if(head1==NULL && head2 == NULL)
        return NULL;
    
    node* mergedHead = (node*)malloc(sizeof(node));
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    if (head1->data <= head2->data)
    {
        mergedHead->data = head1->data;
        mergedHead->next = NULL;
        head1 = head1->next;
    } 
   else
   {
        mergedHead->data = head2->data;
        mergedHead->next = NULL;
        head2 = head2->next;
       
   }
   
   node* mergedTail = mergedHead;
   while (head1 != NULL && head2 != NULL)
   {   
       node* temp = (node*)malloc(sizeof(node));
       if (head1->data <= head2->data)
       {
           temp->data = head1->data;
           head1 = head1->next;
       }
       else
       {
           temp->data = head2->data;
           head2 = head2->next;
       }
       
    mergedTail->next = temp;
    mergedTail = temp;
   }
   
   
    if (head1 != NULL)
        mergedTail->next = head1;
        
    else if (head2 != NULL)
        mergedTail->next = head2;
        
    return mergedHead;
}
node* enter_numbers()
{
    int number = 0;
    node* head = NULL, * temp = NULL;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0)
    {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
        temp->data = number;
        temp->next = head;
        head = temp;
        scanf("%d", &number);
    }
    return head;
}
void printList(node* head)
{
    node* curr = head;
    if (curr == NULL)
        return;
    printf("%d ", curr->data); // print the list
    curr = curr->next;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


