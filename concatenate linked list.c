#include<stdio.h>     //concatenate one linked list at the end of other
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
    if(*q==NULL)
    {
        r=malloc(sizeof(struct node));
        r->data=num;
        r->link=NULL;
        *q=r;
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

    }
    return 0;
}

int concatnate(struct node **p,struct node **q)
{
    struct node *temp,*temp1,*r;
    temp=*p; temp1=*q;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    while(temp1!=NULL)
    {
        temp->link=malloc(sizeof(struct node));
        temp=temp->link;
        temp->data=temp1->data;
        temp1=temp1->link;
    }
    temp->link=NULL;
    return 0;
}
int display(struct node *q)
{
    printf("\n");
    while(q!=NULL)
    {
        printf(" %d ",q->data);
        q=q->link;
    }
    return 0;
}

int main()
{
    struct node *root1,*root2;
    root1=root2=NULL;

    addnode(&root1,5);
    addnode(&root1,4);
    addnode(&root1,3);
    addnode(&root1,2);
    addnode(&root1,1);
    addnode(&root1,0);

    addnode(&root2,6);
    addnode(&root2,7);
    addnode(&root2,8);
    addnode(&root2,9);
    addnode(&root2,10);
    addnode(&root2,11);

    display(root1);
    display(root2);

    concatnate(&root1,&root2);

    display(root1);

    return 0;

}
