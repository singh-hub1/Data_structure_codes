//printf("\n1:insert\n2:search\n3:preorder\n4:inorder\n5:postorder\n6:exit\n");

#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree,int x)
{
    if(tree==NULL)
    {
        tree=(struct node *)malloc(sizeof(struct node));
        tree->left=tree->right=NULL;
        tree->data=x;
    }
    else
    {
        if(x < tree->data)
          tree -> left = insert(tree->left,x);
        else
         tree -> right=insert(tree->right,x);
    }
    return tree;
}

struct node *search(struct node *tree,int x)
{
    if(tree!=NULL)
      {
          if(tree->data==x)
            return tree;
        if(x<tree->data)
         return(search(tree->left,x));
         else
          return(search(tree->right,x));
      }
}

void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
         inorder(tree->left);
         printf("%d\t",tree->data);
         inorder(tree->right);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->data);
    }
}


int main()
{
    int ch,x,ans;
    struct node *tree=NULL,*temp=NULL;

    do
    {
        printf("\n1:insert\n2:search\n3:preorder\n4:inorder\n5:postorder\n6:exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
          switch(ch)
          {
              case 1:printf("enter the data to be insert in the tree\n");
                      scanf("%d",&x);
                      tree=insert(tree,x);
                       break;

              case 2:if(tree==NULL)
                       printf("tree is NULL\n");
                       else
                       {
                           printf("enter key node to be search in a tree\n");
                           scanf("%d",&x);
                           temp=search(tree,x);
                             if(temp!=NULL)
                               printf("%d node is found\n",temp->data);
                            else
                             printf("sry keynode is found\n");
                       } 
                        break; 

              case 3:if(tree==NULL)
                       printf("tree is NULL\n");
                       else
                        preorder(tree);
                        break;

              case 4:if(tree==NULL)
                       printf("tree is NULL\n");
                       else
                        inorder(tree);
                        break;

              case 5:if(tree==NULL)
                       printf("tree is NULL\n");
                       else
                        postorder(tree);
                        break;

              case 6:return 0;
             }
                       
          } while(ch>0 && ch<=6);
}