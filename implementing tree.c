#include<stdio.h>      // implementation of a tree iterative method.
#include<stdlib.h>
int flag=1;
struct node
{
    struct node *leftchild;
    int data;
    struct node *rightchild;
};

/*int addnode(struct node **q,int num)
{
    struct node *temp,*r,*parent;

    if(*q==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->leftchild=NULL;
        temp->data=num;
        temp->rightchild=NULL;
        *q=temp;return 0;
    }
    else
    {
        temp=*q;
        while(temp!=NULL)
        {   flag=0;
                 r=malloc(sizeof(struct node));
                 r->leftchild=NULL;
                 r->data=num;
                 r->rightchild=NULL;
                     if(num<temp->data)
                         {   
                              parent=temp;
                              temp=temp->leftchild;
                              while(temp!=NULL)
                                  { 
                                    if(num<temp->data)
                                     {   parent=temp;
                                         temp=temp->leftchild;flag=1;
                                     }
                                     else
                                      {   parent=temp;
                                          temp=temp->rightchild;flag=2;
                                      }

                                 }
                                 if(flag==1||flag==0)
                                  {
                 
                                      parent->leftchild=r;return 0;
                                  }
                                 else if(flag==2)
                                  { 
                  
                                       parent->rightchild=r;return 0;

                                   }
                         }
                else
                  {
                      parent=temp;
                     temp=temp->rightchild;
                         while(temp!=NULL)
                         { 
                             if(num<temp->data)
                                 {   parent=temp;
                                     temp=temp->leftchild;flag=1;
                                  }
                              else
                                 {   parent=temp;
                                     temp=temp->rightchild;flag=2;
                                 }

                         }
                         if(flag==1||flag==0)
                         {
                 
                              parent->leftchild=r;return 0;
                         }
                         else if(flag==2)
                         { 
                  
                              parent->rightchild=r;return 0;

                          }
                 }
        }
    }
    return 0;
}*/

int addnode(struct node **q,int num)
{
    struct node *temp,*parent,*r;
    r=malloc(sizeof(struct node));
    r->leftchild=NULL;
    r->data=num;
    r->rightchild=NULL;
    if(*q==NULL)
    {
        *q=r;return 0;
    }
    else
    {
        temp=*q;
        while(temp!=NULL)
        {
            if(num<temp->data)
            {
                parent=temp;
                temp=temp->leftchild;flag=1;
            }
            else if(num>temp->data)
            {
                parent=temp;
                temp=temp->rightchild;flag=2;
            }
        }
        if(flag==1)
        {
            parent->leftchild=r;return 0;
        }
        else if(flag==2)
         {
             parent->rightchild=r;return 0;
         }
    }

}

int inorder(struct node *q)
{
    if(q!=NULL)
    {
        inorder(q->leftchild);

        printf(" %d ",q->data);

        inorder(q->rightchild);
    }
    return 0;
}



int main()
{
    struct node *root=NULL;

    int arr[25],num,n,i;
    printf("\nenter number of nodes");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nenter number %d - ",i+1);
        scanf("%d",&num);
        addnode(&root,num);
        printf("\ninorder traversal ");inorder(root);

    }

    

    printf("\n\n\ninorder traversal ");
    inorder(root);

      
      

    return 0;
}
