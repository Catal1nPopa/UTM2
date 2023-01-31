#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define COUNT 10

//////////////////////////////////////////////////////////////////

typedef struct BinaryTreeNode
{
  int data;
  struct BinaryTreeNode * left;
  struct BinaryTreeNode * right;
}BinaryTreeNode;


typedef struct BinaryTree
{
  struct BinaryTreeNode * root;
}BinaryTree;

//////////////////////////////////////////////////////////////////

BinaryTreeNode * newTreeNode(int data)
{
    BinaryTreeNode * tree_node = calloc(sizeof(BinaryTreeNode),1);
    tree_node->data = data;
    return tree_node;
}

//////////////////////////////////////////////////////////////////

BinaryTree * create_binary_tree()
{
    BinaryTree * local = calloc(sizeof(BinaryTree),1);
    local->root = NULL;
    return local;
}

//////////////////////////////////////////////////////////////////

void insert_new_node(BinaryTreeNode *current_node, BinaryTreeNode * new_node )
{
    if(current_node)
    {
        if(current_node->data > new_node->data)
        {
            if(current_node->left)
            {
                insert_new_node(current_node->left,new_node);
            }
            else
            {
                current_node->left = new_node;
            }
        }
        else
        {
            if(current_node->right)
            {
                insert_new_node(current_node->right,new_node);
            }
            else
            {
                current_node->right = new_node;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////

void insert_data_in_binary_tree(BinaryTree *insert)
{
  int data;
    if(insert)
    {
      printf("Introduceti data: \n");
      scanf("%d",&data);
        BinaryTreeNode * new_node = newTreeNode(data);
        if(insert->root)
        {
            insert_new_node(insert->root,new_node);
        }
        else
        {
            insert->root = new_node;
        }
    }

}

//////////////////////////////////////////////////////////////////

//parcurgere in inordine (SVD)
void inorder(BinaryTreeNode * nodes)
{
    if (nodes != NULL)
    {
        inorder(nodes->left);
        printf("|%d|", nodes->data);
        inorder(nodes->right);
    }
}

//////////////////////////////////////////////////////////////////

//parcurgere in preordine (VSD)

void preorder(BinaryTreeNode * nodes)
{
  if(nodes != NULL)
  {
    printf("|%d|",nodes->data);
    preorder(nodes->left);
    preorder(nodes->right);
  }
}

//////////////////////////////////////////////////////////////////

//parcurgere in postordine (SDV)

void postorder(BinaryTreeNode * nodes)
{
  if(nodes != NULL)
  {
    postorder(nodes->left);
    postorder(nodes->right);
    printf("|%d|",nodes->data);
  }
}

//////////////////////////////////////////////////////////////////

void Tree2D(BinaryTreeNode * node, int space)
{
    if (node == NULL)
        return;
    space += COUNT;

    Tree2D(node->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);

    Tree2D(node->left, space);
}

void print2(BinaryTreeNode *node)
{
   Tree2D(node, 0);
}

//////////////////////////////////////////////////////////////////

void frunze(BinaryTreeNode *root)
{
    if(!root)
    {
      return;
    }
    if(root->left == NULL && root->right == NULL)
    {
      printf("|%d| ",root->data);
      return;
    }

    if(root->left)
    {
      frunze(root->left);
    }
    if(root->right)
    {
      frunze(root->right);
    }
}

//////////////////////////////////////////////////////////////////

void DeleteNode(BinaryTreeNode *node)
{
  if(node)
  {
    DeleteNode(node->left);
    DeleteNode(node->right);
    free(node);
  }
}

//////////////////////////////////////////////////////////////////

void clear_tree(BinaryTree *tree)
{
  if(tree)
  {
    if(tree->root)
    {
      DeleteNode(tree->root);
      tree->root = NULL;
    }
  }
}

//////////////////////////////////////////////////////////////////

void DeleteTree(BinaryTree *tree)
{
  if(tree)
  {
    clear_tree(tree);
    free(tree);
  }
}

//////////////////////////////////////////////////////////////////

int TreeH(BinaryTreeNode * node)
{
	if(node == NULL)
	{
		return -1;
	}
	else
	{
		int mLeft = TreeH(node->left);
		int mRight = TreeH(node->right);
		if(mLeft>mRight)
		{
			return (mLeft+1);
		}
		else
		{
			return (mRight+1);
		}
	}
}

//////////////////////////////////////////////////////////////////

BinaryTreeNode *search(BinaryTreeNode *node, int key,int num)
{
	if (node == NULL)
	{
		return NULL;
	}
	if(node->data == key)
	{
		printf("Nodul -%d- :\n",key);
		printf("Adancimea este : %d\n",num);
		return node;
	}
	if(node && key<node->data)
	{
		num+=1;
		search(node->left,key,num);
	}
	else
	{
		num+=1;
		search(node->right,key,num);
	}
  // printf("%d\n",num );
}

//////////////////////////////////////////////////////////////////

void TreeDepth(BinaryTreeNode * node, int key,int counter)
{
	BinaryTreeNode *current_node = NULL;
	current_node = search(node,key,counter);
}

//////////////////////////////////////////////////////////////////

int HTree(BinaryTreeNode *node)
{
	int left,right;
    if(node == 0)
		{
			return 0;
		}
    if (node->left != NULL)
    {
         left = HTree(node->left);
    }
    else
		{
			left = -1;
		}
    if (node->right != NULL)
    {
         right = HTree(node->right);
    }
    else
		{
			right = -1;
		}
    int max = left > right ? left : right;
    return max+1;
}

//////////////////////////////////////////////////////////////////

void NodeHkey(BinaryTreeNode * node,int key)
{
    BinaryTreeNode *current_node = NULL;
    int counter = 0;
    current_node = search(node,key,counter);
		printf("Inaltimea nodului este %d",HTree(current_node));
}

//////////////////////////////////////////////////////////////////

int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");
    printf("|--------------------------------------|\n");
    printf("|      A efectuat: Popa Catalin        |\n");
    printf("|      Grupa:         TI-211           |\n");
    printf("|      A verificat: Stratulat Stefan   |\n");
    printf("|--------------------------------------|\n");
    printf("|----------------------//Menu\\-------------------------|\n");
    printf("|1.Creaza arborele                                     |\n");
    printf("|2.Afisarea elementelor                                |\n");
    printf("|3.Calculara adancimii arborelui                       |\n");
    printf("|4.Cautarea unui nod in baza unei chei de cautare      |\n");
    printf("|5.Calcularea adancimii unui nod                       |\n");
    printf("|6.Calcularea inaltimii unui nod                       |\n");
    printf("|7.Afisarea tuturor frunzelor arborelui                |\n");
    printf("|8.Curatirea elementelor arborelui                     |\n");
    printf("|9.Eliberarea memoriei arborelui                       |\n");
    printf("|0.Opriti programul                                    |\n");
    printf("|------------------------------------------------------|\n");

    int command = 100;
    if(error_input_found)
    {
        printf("\n\nCommanda trebuie sa fie o optiune de mai sus!!![0-9]\n");
    }
    printf("\n\nSelectati commanda: ");
    scanf("%d",&command);

    if((command>9)||(command<0))
    {
        error_input_found = 1;
        goto menu_start;
    }
    return command;
}

//////////////////////////////////////////////////////////////////

int main()
{

  int num,key;
   BinaryTree *tree = NULL;
    int command=100;
    while(command)
    {
        command = menu();
        if(command == 1)
        {
          if(tree != NULL)
          {
            DeleteTree(tree);
          }
            tree = create_binary_tree();
          printf("Dati numarul de noduri\n");
          scanf("%d",&num);
          for(int i=0; i<num; i++)
          {
            insert_data_in_binary_tree(tree);
          }
        }
        switch (command)
        {
            case 2:
            {
              if(tree == NULL)
              {
                printf("Arborele este null\n");
              }
              else
              {
                print2(tree->root);
              printf("\nIn inordine(SVD):\n");
              inorder(tree->root);
              printf("\nIn postordine(SDV):\n");
              postorder(tree->root);
              printf("\nIn preordine(VSD):\n");
              preorder(tree->root);
              // int s = sizeof(tree);
              // printf("\n%lu",s);
            }
                break;
            }
            case 3:
            {
                printf("Adancimea arborelui este: %d\n",TreeH(tree->root));
                break;
            }
            case 4:
            {
                printf("Dati un nod cautat:\n");
                scanf("%d",&key);
                if(search(tree->root,key,0))
                {
                  printf("Nodul este prezent in arbore\n");
                }
                else
                {
                  printf("Nodul respectiv nu este in arbore\n");
                }
                break;
            }
            case 5:
            {
              printf("Introduceti nodul :\n ");
    					scanf("%d",&key);
    					TreeDepth(tree->root,key,0);
                break;
            }
            case 6:
            {
              printf("Introduceti nodul: \n");
              scanf("%d",&key);
              NodeHkey(tree->root,key);
                break;
            }
            case 7:
            {
              printf("\nFrunzele sunt:\n");
              frunze(tree->root);
                break;
            }
            case 8:
            {
                clear_tree(tree);
                printf("Elementele arborelui au fost curatite\n");
                break;
            }
            case 9:
            {
                DeleteTree(tree);
                tree = NULL;
                printf("\nMemoria a fost eliberata cu succes!");
                printf("\nArborele a fost sters\n");
                break;
            }
            }
             printf("\n\nTastati orice buton pentru continuare!\n");
             _getch();

    }
    return 0;
}


//////////////////////////////////////////////////////////////////
