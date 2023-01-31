#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define COUNT 10


void red () {
  printf("\033[0;31m");
}

void green () {
  printf("\033[0;32m");
}

void white()
{
  printf("\033[0m");
}
//////////////////////////////////////////////////////////////////

typedef struct BinaryTreeNode
{
  char *marca;
  char *culoare;
  int anul;
  char *tip_tractiune;
  int putere;
  int key;
  struct BinaryTreeNode * left;
  struct BinaryTreeNode * right;
}BinaryTreeNode;

//////////////////////////////////////////////////////////////////

typedef struct BinaryTree
{
  struct BinaryTreeNode * root;
}BinaryTree;


//////////////////////////////////////////////////////////////////

BinaryTreeNode * newTreeNode(char *marca_m, char *culoare_m,char *type, int a,int p, int key)
{
    BinaryTreeNode * new_node = calloc(sizeof(BinaryTreeNode),1);

    new_node->marca = calloc(sizeof(char),10);
    strcpy(new_node->marca, marca_m);

    new_node->culoare = calloc(sizeof(char),10);
    strcpy(new_node->culoare, culoare_m);

    new_node->tip_tractiune = calloc(sizeof(char),10);
    strcpy(new_node->tip_tractiune,type);

    new_node->anul = a;

    new_node->putere = p;

    new_node->key = key;
    return new_node;
}

//////////////////////////////////////////////////////////////////

struct BinaryTree * create_binary_tree()
{
    BinaryTree * my_binary = malloc(sizeof(struct BinaryTree));
    my_binary->root = NULL;
    return my_binary;
}

//////////////////////////////////////////////////////////////////

void insert_new_node(BinaryTreeNode *current_node, BinaryTreeNode * new_node )
{
    if(current_node)
    {
        if(current_node->key > new_node->key)
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

void insert_data_in_binary_tree(BinaryTree *insert, BinaryTreeNode **arr,int i)
{
  char *marca_m, *culoare_m, *type;
  int a,puterea,key;

  printf("Marca: \n");
  marca_m = calloc(sizeof(char),10);
  scanf("%s", marca_m);

  printf("Culoarea masinii: \n");
  culoare_m = calloc(sizeof(char),10);
  scanf("%s", culoare_m);

  printf("Tipul tractiunii: \n");
  type = calloc(sizeof(char),10);
  scanf("%s",type);

  printf("Anul masinii\n");
  scanf("%d", &a);

  printf("Puterea masinii(cati caluti): \n");
  scanf("%d", &puterea);

  printf("Key: \n");
  scanf("%d",&key);

  BinaryTreeNode *new_node = newTreeNode(marca_m, culoare_m,type, a, puterea,key);
  arr[i] = new_node;
  if(insert->root)
    {
        insert_new_node(insert->root, new_node);
    }
    else
    {
      insert->root = new_node;
    }
}

//////////////////////////////////////////////////////////////////

//parcurgere in inordine (SVD)
void inorder(BinaryTreeNode * nodes)
{

    if (nodes != NULL)
    {
        inorder(nodes->left);
        printf("\n");
        printf("Key : |%d|\n", nodes->key);
        printf("Marca : |%s|\n", nodes->marca);
        printf("Culoare : |%s|\n", nodes->culoare);
        printf("Tipul tractiunii : |%s|\n", nodes->tip_tractiune);
        printf("Anul : |%d|\n", nodes->anul);
        printf("Puterea : |%d| (cai putere)\n", nodes->putere);
        printf(".................................................\n");
        inorder(nodes->right);
    }
    else
    {
      return;
    }
}

//////////////////////////////////////////////////////////////////

//parcurgere in preordine (VSD)

void preorder(BinaryTreeNode * nodes)
{
  if(nodes != NULL)
  {

    printf("|%d|",nodes->key);
    printf("Key : |%d|\n", nodes->key);
    printf("Marca : |%s|\n", nodes->marca);
    printf("Culoare : |%s|\n", nodes->culoare);
    printf("Tipul tractiunii : |%s|\n", nodes->tip_tractiune);
    printf("Anul : |%d|\n", nodes->anul);
    printf("Puterea : |%d| (cai putere)\n", nodes->putere);
    printf(".................................................\n");
    preorder(nodes->left);
    preorder(nodes->right);

  }
  else
  {
    return;
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
    printf("Key : |%d|\n", nodes->key);
    printf("Marca : |%s|\n", nodes->marca);
    printf("Culoare : |%s|\n", nodes->culoare);
    printf("Tipul tractiunii : |%s|\n", nodes->tip_tractiune);
    printf("Anul : |%d|\n", nodes->anul);
    printf("Puterea : |%d| (cai putere)\n", nodes->putere);
    printf(".................................................\n");
  }
  else
  {
    return;
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
    printf("%d[%s|%d]\n", node->key, node->marca, node->anul);

    Tree2D(node->left, space);
}

void print2(BinaryTreeNode *node)
{
   Tree2D(node, 0);
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

BinaryTreeNode *search(BinaryTreeNode *nodes, int cauta, int kek)
{
  if (nodes == NULL)
	{
		printf("!Nu exista element cu cheia respectiva!\n");
    return NULL;
	}
	if(nodes->key == cauta)
	{
    printf(".................................................\n");
    printf("Key : |%d|\n", nodes->key);
    printf("Marca : |%s|\n", nodes->marca);
    printf("Culoare : |%s|\n", nodes->culoare);
    printf("Tipul tractiunii : |%s|\n", nodes->tip_tractiune);
    printf("Anul : |%d|\n", nodes->anul);
    printf("Puterea : |%d| (cai putere)\n", nodes->putere);
    printf(".................................................\n");
		return nodes;
	}
  if(kek%2 == 0)
  {
	if(nodes && cauta < nodes->key)
	{
		search(nodes->left,cauta,kek);
	}
	if(nodes && cauta > nodes->key)
	{
		search(nodes->right,cauta,kek);
	}
  }
  else if(kek%2 !=0)
  {
    if(nodes && cauta < nodes->key)
  	{
  		search(nodes->right,cauta,kek);
  	}
  	if(nodes && cauta > nodes->key)
  	{
  		search(nodes->left,cauta,kek);
  	}
  }

}


//////////////////////////////////////////////////////////////////

void mirror(BinaryTreeNode* node)
{
  if (node == NULL)
    return;
  else
  {
    BinaryTreeNode* temp;

    mirror(node->left);
    mirror(node->right);

    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
}


//////////////////////////////////////////////////////////////////

void DFS(BinaryTreeNode *node, int key_search)
{
  if(node == NULL)
    return;

  if(node->key == key_search)
  {
    printf(".................................................\n");
    printf("Key : |%d|\n", node->key);
    printf("Marca : |%s|\n", node->marca);
    printf("Culoare : |%s|\n", node->culoare);
    printf("Tipul tractiunii : |%s|\n", node->tip_tractiune);
    printf("Anul : |%d|\n", node->anul);
    printf("Puterea : |%d| (cai putere)\n", node->putere);
    printf(".................................................\n");
  }
  else
  {
    DFS(node->left, key_search);
    DFS(node->right, key_search);
  }
}

//////////////////////////////////////////////////////////////////
void current_Level(BinaryTreeNode *node, int level);
int height(BinaryTreeNode *node);

//////////////////////////////////////////////////////////////////

void level_Order(BinaryTreeNode *node)
{
    int h = height(node);
    int i;
    for (i = 1; i <= h; i++)
        current_Level(node, i);
}

//////////////////////////////////////////////////////////////////

void current_Level(BinaryTreeNode *node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        {
          printf(".................................................\n");
          printf("Key : |%d|\n", node->key);
          printf("Marca : |%s|\n", node->marca);
          printf("Culoare : |%s|\n", node->culoare);
          printf("Tipul tractiunii : |%s|\n", node->tip_tractiune);
          printf("Anul : |%d|\n", node->anul);
          printf("Puterea : |%d| (cai putere)\n", node->putere);
          printf(".................................................\n");
        }

    else if (level > 1) {
        current_Level(node->left, level - 1);
        current_Level(node->right, level - 1);
    }
}

//////////////////////////////////////////////////////////////////

int height(BinaryTreeNode *node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


//////////////////////////////////////////////////////////////////

void sort_array(BinaryTreeNode ** arr, int size)
{
	BinaryTreeNode * temp;

	for(int i=0;i<size;i++)
	{
		arr[i]->left = NULL;
		arr[i]->right = NULL;
	}


	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]->key>arr[j]->key)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

		}
	}
}

//////////////////////////////////////////////////////////////////

BinaryTreeNode * balance_tree2(BinaryTreeNode ** arr, int start, int end, int kek)
{
	if(start<end){
		int mid = (start + end)/2;
		BinaryTreeNode * node = arr[mid];
    if(kek%2 == 0)
    {
      node->left =  balance_tree2(arr, start, mid, kek);
      node->right = balance_tree2(arr, mid+1, end, kek);
    }
    else
    {
      node->right =  balance_tree2(arr, start, mid, kek);
      node->left = balance_tree2(arr, mid+1, end, kek);
    }

  return node;
	}
 else
{
	return NULL;
}
}

void balance_tree(BinaryTree * tree, BinaryTreeNode ** arr, int size,int kek)
{
	int start = 0, end = size;
  tree->root = balance_tree2(arr, start, end,kek);

}



int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");
    green();
    printf("|--------------------------------------|\n");
    printf("|      A efectuat: Popa Catalin        |\n");
    printf("|      Grupa:         TI-211           |\n");
    printf("|      A verificat: Stratulat Stefan   |\n");
    printf("|--------------------------------------|\n");
    white();
    printf("|----------------------//Menu\\--------------------------|\n");
    printf("|1.Creaza arborele                                      |\n");
    printf("|2.Afisarea elementelor                                 |\n");
    printf("|3.Cautarea unui nod in baza campului cheie + afisarea  |\n");
    printf("|4.Parcurgerea in inordine                              |\n");
    printf("|5.Parcurgerea in preordine                             |\n");
    printf("|6.Parcurgerea in postordine                            |\n");
    printf("|7.Parcurgerea in adancime (DFS)                        |\n");
    printf("|8.Parcurgerea in largime (BFS)                         |\n");
    printf("|9.Balansarea arborelui                                 |\n");
    printf("|10.Oglindirea arborelui                                |\n");
    printf("|11.Curatarea elementel arborelui                       |\n");
    printf("|12.Eliberarea memoriei arborelui                       |\n");
    printf("|-------------------------------------------------------|\n");

    int command = 100;
    if(error_input_found)
    {
        printf("\n\nCommanda trebuie sa fie o optiune de mai sus!!![0-12]\n");
    }
    red();
    printf("\n\nSelectati commanda: ");
    scanf("%d",&command);

    if((command>12)||(command<0))
    {
        error_input_found = 1;
        goto menu_start;
    }
    return command;
}

//////////////////////////////////////////////////////////////////

int main()
{

  int num,key,kek=0;
   BinaryTree *tree = NULL;
   BinaryTreeNode **array = NULL;
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
            //tree_2 = create_binary_tree();
          printf("Dati numarul de masini: \n");
          scanf("%d",&num);
          array = calloc(num, sizeof(BinaryTreeNode*));
          for(int i=0; i<num; i++)
          {
            printf("Masina: [%d]\n", i);
            insert_data_in_binary_tree(tree,array,i);
            printf("\n");
          }
        }
        switch (command)
        {
            case 2:
            {
              if(tree == NULL)
              {
                printf("Arborele este null\n");
                break;
              }
              else
              {
                printf("\n\n************************************************\n");
                print2(tree->root);
                printf("\n\n************************************************\n");

                break;
              }
            }
            case 3:
            {
              if(tree == NULL)
              {
                printf("Arborele este null\n");
              }
              else
              {
                printf("Introduceti cheia cautata: \n");
                scanf("%d", &key);
                search(tree->root,key,kek);
              }
                break;
            }
            case 4:
            {
                inorder(tree->root);
                break;
            }
            case 5:
            {
                preorder(tree->root);
                break;
            }
            case 6:
            {
                postorder(tree->root);
                break;
            }
            case 7:
            {
              printf("Introduceti cheia:\n");
              scanf("%d", &key);
              clock_t start = clock();
              DFS(tree->root,key);
              clock_t end = clock();
              float time_t = (float)(end-start)/CLOCKS_PER_SEC;
              printf("%f",time_t);
                break;
            }
            case 8:
            {
                clock_t start = clock();
                level_Order(tree->root);
                clock_t end = clock();
                float time_t = (float)(end-start)/CLOCKS_PER_SEC;
                printf("%f",time_t);
                break;
            }
            case 9:
            {
              sort_array(array,num);
              balance_tree(tree,array,num,kek);
                break;
            }
            case 10:
    	      {
              if(tree == NULL)
              {
                printf("Arborele este null!\n");
              }
              else
              {
                mirror(tree->root);
                kek++;
                printf("Oglindirea a avut loc cu succes!\n");
              }
    	          break;
    	      }
    				case 11:
    	      {
              clear_tree(tree);
              printf("Elementele arborelui au fost curatite\n");
    	        break;
    	      }
    				case 12:
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


/////////////
