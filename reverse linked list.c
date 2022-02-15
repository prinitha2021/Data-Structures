#include<stdio.h>  //Print in Reverse
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int addnode(struct node **q,int num)
 {
     struct node *temp,*r;
     temp=*q;
     r=malloc(sizeof(struct node));
     r->data=num;
     r->link=temp;
     *q=r;
     return 0;
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
 int main()
{   struct node *p;
    p=NULL;

    int n,i,num;
    printf("number of nodes  ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
     {   printf("enter data %d - ",i);
         scanf("%d",&num);
         addnode(&p,num);
     }
     printf("\nprinting the nodes in the reverse order.  ");
     display(p);

     return 0;
}
