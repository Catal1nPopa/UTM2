#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

int AddToArray(tree *node, int arr[], int i);
tree *CreateNode(int data);
tree *Insert(tree *node, int data);
void PrintPreorder(tree *node);
int count(tree *node);
int compare(const void * a, const void * b);

//---------------------------------------------------------------------------
int main()
{
    int i;
    int size;
    int *arr=NULL;
    tree *root=NULL;

    printf("***TEST PROGRAM***\n");
    root = Insert(root, 4);
    root = Insert(root, 3);
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert (root, 8);
    root = Insert (root, 7);
    size = count(root);

    printf("\n***BINARY TREE (PREORDER)***\n");
    PrintPreorder(root);
    printf("\nThe binary tree countain %d nodes", size);

    printf("\n\n***ARRAY***\n");
    arr = calloc(size, sizeof(int));
    AddToArray(root, arr, 0);
    qsort(arr,size,sizeof(int),compare);

    for (i=0; i<size; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}
//---------------------------------------------------------------------------

int compare(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int AddToArray(tree *node, int arr[], int i)
{
    if(node == NULL)
        return i;
     arr[i] = node->data;
     i++;
     if(node->left != NULL)
          AddToArray(node->left, arr, i);
     if(node->right != NULL)
          AddToArray(node->right, arr, i);

     arr[i] = node->data;
     i++;
}

tree *CreateNode(int data)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node -> data = data;
    node -> left = node -> right = NULL;
    return node;
}

tree *Insert(tree *node, int data)
{
    if(node==NULL)
    {
        tree *temp;
        temp = CreateNode(data);
        return temp;
    }

    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }

    /* Else there is nothing to do as the data is already in the tree. */
    return node;
}

void PrintPreorder(tree *node)
{
    if(node==NULL)
    {
        return;
    }
    printf("%d ",node->data);
    PrintPreorder(node->left);
    PrintPreorder(node->right);
}

int count(tree *node)
{
    int c = 1;

    if (node == NULL)
        return 0;
    else
    {
        c += count(node->left);
        c += count(node->right);
        return c;
     }
}
