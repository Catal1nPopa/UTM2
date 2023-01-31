#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int x,y,n,a[30][30],*b;

void matricea_adiacenta()
{
    printf("Numarul de varfuri: ");
    scanf("%d",&n);
    for (x=1; x<=n; x++)
    {
        for (y=1; y<=n; y++)
        {
            printf(" %d->%d = ",x,y);
            scanf("%d",&a[x][y]);
        }
    }
}

int DFS (int s)
{
    int i;
    b[s]=1;
    for(i=1; i<=n; i++)
        if(a[s][i] !=0 && b[i]==0)
        {
            printf("\n %d - %d", s, i);
            DFS(i);
        }
    return 0;
}
int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");
    printf("|----------------------//Menu\\-------------------------|\n");
    printf("|1.Matricea de adiacenta                               |\n");
    printf("|2.Graful de acoperire                                 |\n");
    printf("|0.Inchide programul                                   |\n");

    int command = 4;
    if(error_input_found)
    {
        printf("\n\nCommanda trebuie sa fie o optiune de mai sus!!![0-2]\n");
    }
    printf("\n\nSelectati commanda: ");
    scanf("%d",&command);

    if((command>2)||(command<0))
    {
        error_input_found = 1;
        goto menu_start;
    }
    return command;
}


int main()
{

    int command=10;
    while(command)
    {
        command = menu();
        switch(command)
        {
          case 1:
          {
              matricea_adiacenta();
              system("PAUSE");
              break;
          }
          case 2:
          {
              int varf;
              printf("Cu care varf incepeti: ");
              scanf("%d",&varf);
              b = calloc(n+1, sizeof(int));
              DFS(varf);
              printf("\n");
              free(b);
              system("PAUSE");
              break;
          }

          case 0:
          {
              printf(" Programul este inchis\n");
              return 0;
          }
        }
    }

    return 0;
}
