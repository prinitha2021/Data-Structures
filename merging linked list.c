#include<stdio.h>  //Merge two sorted linked lists
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
  r=(struct node *)malloc(sizeof(struct node));
  r->data=num;
  r->link=NULL;
  if(*q==NULL)
  { 
      *q=r;
  }
  else
  {
      temp=*q;
      while(temp->link!=NULL)
      {
          temp=temp->link;
      }
      temp->link=r;
  }
  return 0;

}

int merge(struct node **a,struct node **b,struct node **c)
{
    struct node *p,*q,*r,*temp;
    p=*a;q=*b;r=*c;

    if(p==NULL&&q==NULL)
    {
        printf("\nboth lists are empty.");
        return 0;
    }
    else 
    {
        while(p!=NULL&&q!=NULL)
      {   
          if(*c==NULL)
           {
               temp=malloc(sizeof(struct node));
               *c=temp;
           }
           else
           {
               temp->link=malloc(sizeof(struct node));
               temp=temp->link;
           }

           if(p->data<=q->data)
           {
               temp->data=p->data;
               p=p->link;
           }
           else
           {
               temp->data=q->data;
               q=q->link;
           }
        }
        while(p!=NULL)
         {
            temp->link=malloc(sizeof(struct node));
            temp=temp->link;
            temp->data=p->data;
            p=p->link;
         }
          while(q!=NULL)
         {
            temp->link=malloc(sizeof(struct node));
            temp=temp->link;
            temp->data=q->data;
            q=q->link;
         }
         temp->link=NULL;
         return 0;
    
    }

    


}


 int display(struct node *q)
  { while(q!=NULL)
  {
      printf("%d ",q->data);
      q=q->link;      
  }

  }


int main()
{
    struct node *head1,*head2,*head3;
    head1=head2=head3=NULL;
    int i,n1,n2,num;
    printf("no of nodes for list 1 ");
    scanf("%d",&n1);
    for(i=1;i<=n1;i++)
     {
         printf("enter data %d -",i);
         scanf("%d",&num);
         addnode(&head1,num);
     }

     printf("no of nodes for list 2 ");
    scanf("%d",&n2);
    for(i=1;i<=n2;i++)
     {
         printf("enter data %d -",i);
         scanf("%d",&num);
         addnode(&head2,num);
     }

     display(head1);printf("\n"); 
     display(head2);printf("\n");

     merge(&head1,&head2,&head3);
     display(head3);

     return 0;
}
