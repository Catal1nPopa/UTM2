#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#define MAX 3000
void AdList();
void curatire_list();
void FORD_DRUM(int);
void B_K();
void FORD();
////////////////////////////////////////////////////////////////////////
struct Lista_incidenta
{
  int v;
  int d;
  struct Lista_incidenta *next;
};

struct Graph
{
  int varf;
  int y;
  struct Lista_incidenta *first;
  struct Lista_incidenta *last;
}*Graph;

////////////////////////////////////////////////////////////////////////

int V,num_varfuri;

////////////////////////////////////////////////////////////////////////

void curatire_list()
{
  struct Lista_incidenta *c, *t;
  while(num_varfuri--)
  {
    c = Graph[num_varfuri].first;
    while(c != Graph[num_varfuri].last)
    {
      t = c->next;
      free(c);
      c = t;
    }
  }
  free(Graph);
}


////////////////////////////////////////////////////////////////////////



void AdList()
{
  int i,v,w;
  struct Lista_incidenta *c;
  if(Graph) curatire_list();
  printf("\n\t");
  printf("Dati numarul de varfuri a grafului\n");
  scanf("%d",&num_varfuri);
  Graph = (struct Graph*)malloc(num_varfuri * sizeof(struct Graph));
  printf("\n");
  printf("Introduceti lista de adiacenta: \n\n\r");
  for(i=0; i<num_varfuri; i++)
  {
    printf("%d| ",i+1);
    Graph[i].first = (struct Lista_incidenta*)malloc(sizeof(struct Lista_incidenta));
    Graph[i].last = Graph[i].first;
    Graph[i].last->next = NULL;
    Graph[i].last->v = -1;
    scanf("%d", &v);
    if(num_varfuri < v || v < 0)
    {
      system("cls");
      printf("\n\n\n\n\n\t\t\t");
      printf("Eroare!");
    }
    while(v)
    {
      Graph[i].last->v=v-1;
      Graph[i].last->next=(struct Lista_incidenta*)malloc(sizeof(struct Lista_incidenta));
      Graph[i].last=Graph[i].last->next;
      Graph[i].last->next=NULL;
      Graph[i].last->v=-1;
      scanf("%d", &v);
      if(num_varfuri < v || v < 0)
      {
        system("cls");
        printf("\n\n\n\n\n\t\t\t");
        printf("Eroare!");
      }
    }
  }
  system("cls");
  printf("\n\t");
  printf("Introduceti ponderea: \n\n\r");
  for(i=0; i<num_varfuri; i++)
  {
    Graph[i].last = Graph[i].first;
    while(Graph[i].last->v+1)
    {
      printf(" u%d%d| ", i+1, Graph[i].last->v+1);
      scanf("%d", &w);
      Graph[i].last->d=w;
      Graph[i].last = Graph[i].last->next;
    }
  }
}

////////////////////////////////////////////////////////////////////////

void FORD()
{
  int i,variable=1;
  struct Lista_incidenta *c;
  if(Graph == NULL) return;
  for(i=0; i<num_varfuri; i++)
  {
    Graph[i].y = -1;
    Graph[i].varf = MAX;
  }
  printf("\n\t");
  printf("Dati varful initial: \n");
  scanf("%d", &V);
  Graph[--V].varf = 0;
  while(variable)
  {
    variable=0;
    for(i=0; i<num_varfuri; i++)
    {
      c = Graph[i].first;
      while (c != Graph[i].last)
       {
        if(Graph[c->v].varf > Graph[i].varf+c->d)
        {
          Graph[c->v].varf = Graph[i].varf+c->d;
          Graph[c->v].y = i;
          variable = 1;
        }
        c = c->next;
      }
    }
  }

  for(i=0; i<num_varfuri; i++)
  {
    printf("\n\r Drumul minim din |%d| in |%d| este: ",V+1  , i+1);
    if(Graph[i].varf == MAX)
    {
      printf("Nu exista");
    }
    else
    {
      FORD_DRUM(i);
      printf(": Lungimea |%d|.\n",Graph[i].varf);
    }
  }
}

////////////////////////////////////////////////////////////////////////

void FORD_DRUM(int v)
{
    int k;
    if(v!=V)
    {
        k=v;
        FORD_DRUM(Graph[v].y);
    }
    if(k!=v) printf(": %d",v+1);
    else
    {
        printf("->%d",v+1);
        k++;
    }
}

////////////////////////////////////////////////////////////////////////


int main()
{
  int option;
  do
  {
    system("cls");
    printf("-----------------------Menu------------------\n");
    printf("\t 1) Introduceti graful.\n");
    printf("\t 2) Ford.\n");
    printf("\t 3) Bellman-Kalaba.\n");
    printf("\n");
    printf("\t 0) Inchide programul.\n");
    printf("--------------------------------------------\n");
    printf("\n\n\n");
    printf("Alegeti comanda: \n");
    scanf("%d", &option);
    switch (option)
     {
      case 1:
      {
        AdList();
        break;
      }
      case 2:
      {
        FORD();
        break;
      }
      case 3:
      {

        break;
      }
    }
      printf("\nTastati orice buton pentru continuare!\n");
      _getch();
  }
  while(option != 0);
}
