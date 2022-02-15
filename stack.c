#include<stdio.h>
#include<stdlib.h>

int max=0;

struct node
{
    int data;
    struct node *link;
}; 
int push(struct node **q,int num)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->link=*q;
    *q=temp;
    if(max<num)
    {
        max=num;
    }
printf("\n element inserted successfully.");    
return 0;
}

int pop(struct node **q)
{
    struct node *temp;
    if(*q==NULL)
    {
        printf("\nno element in the stack - deletion unsuccessfull");
        return 0;
    }
    else
    {
        temp=*q;
        *q=temp->link;
         temp->link=NULL;
         printf("\n elemente deleted successfully");
         return temp->data;
    }

}

int display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->link;
    }
    return 0;
}
int peek(struct node **q)
{  struct node *temp;
   temp=*q;
   
    if(temp==NULL)
    {
        printf("\nno element in the stack");
    }
    else
    {
        printf("\n%d is the peek element",temp->data);
    }
    return 0;
}

int get_max(struct node **q)
{   max=0;
    struct node *temp;
    temp=*q;
    while(temp!=NULL)
    {
        if(max<temp->data)
        {
            max=temp->data;
        }
    }
    return max;
}

int main()
{
    struct node *p=NULL;
    printf("\n1.implementing stack");
    int num,choice;
    
    while(1)
    {
        printf("\n1.push element  2.pop element  3.get peek  4.max element of stack  5.display stack  6.exit  - ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nenter the number");scanf("%d",&num);push(&p,num);break;

            case 2:
            pop(&p);break;

            case 3:
            peek(&p);break;

            case 4:
            printf("\n%d is max element of the stack",get_max(&p));break;

            case 5:
            display(p);break;

            case 6:
            return 0;break;

            default :
            printf("\n please select valid choice");
        }

    }
    return 0;
}
