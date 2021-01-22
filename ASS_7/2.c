//printf("\n1:create\n2:inorder\n3:insert\n4:postorder\n5:preorder\n6:searching\n7:exit\n");

#include <stdio.h>
#include <stdlib.h>

struct node
 {
  int key;
  struct node *left, *right;
};

// Creation of simple node 
struct node *newNode(int item)
 {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
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

void postorder(struct node *root) 
{
  if (root != NULL)
   {
     postorder(root->left);
     postorder(root->right);
     printf("%d -> ", root->key);
  }
}

void preorder(struct node *root) 
{
  if (root != NULL)
   {
     printf("%d -> ", root->key);
     preorder(root->left);
     preorder(root->right);
  }
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

struct node *search(struct node *tree,int x)
{
    if(tree!=NULL)
      {
          if(tree->key==x)
            return tree;
        if(x < tree->key)
         return(search(tree->left,x));
         else
          return(search(tree->right,x));
      }
}



int main() 
{
  struct node *tree = NULL,*temp=NULL;
  int ch,x,n;
  do
  {
      printf("\n1:create\n2:inorder\n3:insert\n4:postorder\n5:preorder\n6:searching\n7:exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
     switch(ch)
     {
         case 1:printf("enter the data\n");
                scanf("%d",&x);
                tree=create(tree,x);
                break;

         case 2:printf("Inorder traversal: ");
                inorder(tree);
                break;

         case 3:printf("enter the data\n");
                scanf("%d",&x);
                tree=insert(tree,x);
                break;

         case 4:printf("postorder traversal: ");
                postorder(tree);
                break;

         case 5:printf("preorder traversal: ");
                preorder(tree);
                break;

        case 6:if(tree==NULL)
                 printf("tree is NULL\n");
                else
                 {
                   printf("enter key node to be search in a tree\n");
                   scanf("%d",&x);
                   temp=search(tree,x);
                    if(temp!=NULL)
                     printf("%d node is found\n",temp->key);
                    else
                     printf("sry keynode is found\n");
                 } 
                    break; 

        case 7:return 0;

     }

 }while(ch>0 && ch<=7);
 
 }