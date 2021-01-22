//printf("\n1:create\n2:insert\n3:maximum\n4:minimum\n5:return parent of that child\n6:exit\n");

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

struct node *minimum(struct node *tree)
{
    while(tree->left!=NULL)
      tree=tree->left;
      return tree;
}

struct node *maximum(struct node *tree)
{
    while(tree->right!=NULL)
      tree=tree->right;
      return tree;
}

struct node *search_parent(struct node *tree,int x)
{
    struct node *temp=tree,*parent=NULL;
    if(tree==NULL || tree->key==x)
     return NULL;

     while(temp!=NULL)
     {
         if(temp->key==x)
          return parent;

        if(x>temp->key)
          {
              parent=temp;
              temp=temp->right;
          }
          else
          {
              parent=temp;
              temp=temp->left;
          }
     }
     return NULL;
     
}


int main() 
{
  struct node *tree = NULL,*temp=NULL;
  int ch,x,n;
  do
  {
      printf("\n1:create\n2:insert\n3:maximum\n4:minimum\n5:return parent of that child\n6:exit\n");
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

         case 3:temp=maximum(tree);
                printf("maximum value in a tree:%d\n",temp->key);
                break;

         case 4:temp=minimum(tree);
                printf("minimum value in a tree:%d\n",temp->key);
                break;

         case 5:printf("enter the node to be search\n");
                scanf("%d",&x);
                temp=search_parent(tree,x);
                if(temp!=NULL)
                  printf("parent of %d is %d\n",x,temp->key);
                  else
                printf("not found!\n");
                break;

        case 6:return 0;
     }

 }while(ch>0 && ch<=6);
 
 }