#include<stdio.h>  //Reverse a linked list
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

 int display(struct node *q)
 {
     while(q!=NULL)
      {
          printf("%d ",q->data);
          q=q->link;
      }
      return 0;
 }
 int add_node(struct node **q,int num)
 {
     struct node *temp,*r;
     temp=*q;
     if(*q==NULL)
     {
         r=malloc(sizeof(struct node));
         r->data=num;
         r->link=NULL;
         *q=r;
         return 0;
     }
     else
     {
         temp=*q;
         while(temp->link!=NULL)
         {
             temp=temp->link;
         }
         r=malloc(sizeof(struct node));
         r->data=num;
         r->link=NULL;
         temp->link=r;
         return 0;
     }

 }

 int reverse(struct node **q)
 {
     struct node *temp,*r,*s;
     r=NULL;s=NULL;temp=*q;
     while(temp!=NULL)
     {
         s=r;
         r=temp;
         temp=temp->link;
         r->link=s;
     }
     *q=r;
     return 0;
 }

 int main()
{   struct node *p;
    p=NULL;

    int n,i,num;
    printf("number of nodes  ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
     {   printf("enter data %d - ",i);
         scanf("%d",&num);
         add_node(&p,num);
     }

     printf("\nbefore reversing the list   ");
     display(p);

     reverse(&p);

      printf("\nafter reversing the list   ");
     display(p);

     return 0;

}
