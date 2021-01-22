//printf("\n1:create\n2:insert\n3:count_non_leaf_nodes\n4:count_leaf_nodes\n5:count_total_nodes\n6:exit\n");

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

int count_non_leaf_nodes(struct node *tree)  //jiska baccha hai
{
    static int c;
    if(tree==NULL||(tree->left==NULL && tree->right==NULL))
        return 0;
   return 1+count_non_leaf_nodes(tree->left)+count_non_leaf_nodes(tree->right);
    
   
}

int count_leaf_nodes(struct node *tree)  //jiska baccha nai hai
{
    static int c;
    if(tree!=NULL)
    {
        if(tree->left==NULL && tree->right==NULL)
          ++c;
        else
        {
            count_leaf_nodes(tree->left);
            count_leaf_nodes(tree->right);
        }
    }
    return c;
}

int count_total_nodes(struct node *tree)
{
    if(tree==NULL)
     return 0;
     else
      return(1+count_total_nodes(tree->left)+count_total_nodes(tree->right));
}



int main() 
{
  struct node *tree = NULL,*temp=NULL;
  int ch,x,n;
  do
  {
      printf("\n1:create\n2:insert\n3:count_non_leaf_nodes\n4:count_leaf_nodes\n5:count_total_nodes\n6:exit\n");
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

         case 3:x=count_non_leaf_nodes(tree);
                 printf("total nos of non leaf nodes:%d\n",x);
                 break;

         case 4:x=count_leaf_nodes(tree);
                 printf("total nos of leaf nodes:%d\n",x);
                 break;

         case 5:x=count_total_nodes(tree);
                 printf("total nos of nodes in a tree:%d\n",x);
                 break;

        case 6:return 0;
     }

 }while(ch>0 && ch<=6);
 
 }