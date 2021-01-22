/*1. Write a C program to create binary search tree of integers and perform following
operations:
• Preordertraversal
• Post ordertraversal*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node;

void create(node **r)
{
    int n, i;
    node *cur, *newnode, *par;
    printf("How many nodes u wants to enter :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        scanf("%d", &newnode->data);
        if (*r == NULL)
        {
            *r = newnode;
            cur = newnode;
            cur->left = cur->right = NULL;
        }
        else
        {
            cur = *r;
            while (cur != NULL)
            {
                par = cur;
                if (cur->data >= newnode->data)
                {
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                }
            }
            if (par->data >= newnode->data)
            {
                par->left = newnode;
            }
            else
            {
                par->right = newnode;
            }
        }
    }
}


void preorder(node *r)
{
    if (r == NULL)
        return;
    printf("%d ", r->data);
    preorder(r->left);
    preorder(r->right);
}
void postorder(node *r)
{
    if (r == NULL)
        return;
    preorder(r->left);
    preorder(r->right);
    printf("%d ", r->data);
}
void main(int argc, char *argv[]) //command line argument//
{
    node *root = NULL;
    printf("Create a BST : ");
    create(&root);
    printf("\nPREORDER : ");
    preorder(root);
    printf("\nPOSTORDER : ");
    postorder(root);
}