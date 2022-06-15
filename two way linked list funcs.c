#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data;
    struct dataNode* next;
    struct dataNode* prev;
} node;

node* enter_numbers();
node* enter_num_middle(node* head,int num);
node* enter_num_front(node* head,int num);
node* enter_num_tail(node* head,int num);
int choose_number();
int main()
{
    int num;
    node* curr;
    node* head1 = enter_numbers();
    num = choose_number();
    head1 = enter_num_front(head1,num);
    head1 =enter_num_middle(head1,num);
    enter_num_tail(head1,num);
    curr = head1;
    if (curr == NULL)
        return 0;
    printf("%d ", curr->data); // print the list
    curr = curr->next;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
int choose_number()
{
    int num=-1;
    while (num<0)
    {
       printf("please enter a positive number you want to add\n");
       scanf("%d",&num);
    }
    return num;
    
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
            return EXIT_FAILURE;
        }
        temp->data = number;
        temp->next = head;
        if (head != NULL)
            head->prev = temp;
        head = temp;
        head->prev = NULL;
        scanf("%d", &number);
    }
    return head;
}
node* enter_num_front(node* head,int num)
{
    node* itr,*temp;
    itr = head;
   if(itr->data > num)
   {
        temp = (node*)malloc(sizeof(node));
        temp->data = num;
        temp->next = itr;
        temp->prev = itr->prev; // NULL
        itr->prev = temp;
        head=temp;
        
   }
    return head;
}

node* enter_num_middle(node* head,int num)
{
    if(head==NULL)
        return NULL;
    node* itr,*temp;
    itr = head;
    while (itr!=NULL)
    {
        if(itr->data <= num && itr->next->data >= num)
        {
            temp = (node*)malloc(sizeof(node));
            temp->data = num;
            temp->prev = itr;
            temp->next = itr->next;
            itr->next->prev = temp;
            itr->next=temp;
            return head;
        }
        else
            itr=itr->next;
    }

}


node* enter_num_tail(node* head,int num)
{
    if(head==NULL)
        return NULL;
    node* itr,*temp,*tail;
    itr = head;
    tail = head;
	while (tail!=NULL && tail->next != NULL) // find tail 
    {
        tail = tail->next;
    }

    if(tail->data <= num)
    {
        temp = (node*)malloc(sizeof(node));
        temp->data = num;
        temp->next = tail->next; // NULL
        temp->prev = tail;
        tail->next = temp;
    }
    return head;
}
