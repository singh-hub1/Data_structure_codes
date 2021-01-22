// printf("\n1:create\n2:insert\n3:mirror\n4:delete\n5:exit\n");

#include <stdio.h>
#include <stdlib.h>

struct node
 {
  int key;
  struct node *left, *right;
};
struct node *minimum(struct node *tree);

// Creation of simple node 
struct node *newNode(int item)
 {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert(struct node *node, int key)
 {
  if (node == NULL) 
    return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *create(struct node *node, int key)
 {
  if (node == NULL)
    return newNode(key);

if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void inorder(struct node *root) 
{
  if (root != NULL)
   {
     inorder(root->left);
     printf("%d -> ", root->key);
     inorder(root->right);
  }
}

struct node *delete(struct node *root,int n)
{
  struct node *temp,*succ;
  if(root==NULL)
   {
     printf("number is not found\n");
     return root;
   }
   if(n<root->key)
    root->left=delete(root->left,n);
    else if(n>root->key)
     root->right=delete(root->right,n);

     else
     {
        if(root->left!=NULL && root->right!=NULL) //2 children
         {
            succ=minimum(root->right);
            root->key=succ->key;
            root->right=delete(root->right,succ->key);
         }
         else
         {
           temp=root;
           if(root->left!=NULL)  //having left child
           root=root->left;
           else if(root->right!=NULL)  //having right child
           root=root->right;
            else
              root=NULL;  //no child
            free(temp);
          }
     }
          return(root);
}

struct node *minimum(struct node *tree)
{
    while(tree->left!=NULL)
      tree=tree->left;
      return tree;
}

struct node *mirror(struct node *root)
{
  if(root!=NULL)
  {
    mirror(root->left);
    mirror(root->right);
    struct node *temp=root->left;
    root->left=root->right;
    root->right=temp;
  }
  return root;
}

int ancestor(struct node *root,int x)
{
  if(root==NULL)
     return 0;
  if(root->key==x)
    return 1;
  
  if(ancestor(root->left,x)|| ancestor(root->right,x))
  {
    printf("ancestor is:%d\n",root->key);
    return 1;
  }
  return 0;
}

int main() 
{
  struct node *tree = NULL,*temp=NULL;
  int ch,x,n;
  do
  {
      printf("\n1:create\n2:insert\n3:mirror\n4:delete\n5:inorder\n6:find ancestor of a node\n7:exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
     switch(ch)
     {
         case 1:printf("enter the data\n");
                scanf("%d",&x);
                tree=create(tree,x);
                break;

         case 2:printf("enter the data\n");
                scanf("%d",&x);
                tree=insert(tree,x);
                break;

         case 3:tree=mirror(tree);
                  inorder(tree);
                  break;

         case 4:printf("enter the node to be delete\n");
                scanf("%d",&x);
                tree=delete(tree,x);
                break;

         case 5:inorder(tree);
                break;

        case 6: printf("enter the node to find ancestor\n");
                scanf("%d",&x);
                n=ancestor(tree,x);
                 if(n==0)
                  printf("no ancestor found!\n");
                break;
        case 7:return 0;
     }

 }while(ch>0 && ch<=7);
 
 }