#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Telefoane
{
    char denumire[15];
    char pret[10];
} Telefoane;

void citire_array(Telefoane * x, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("Introduceti datele telefonului -[%d]-:\n", i);
        printf("Denumirea: ");
        scanf("%s",&x[i].denumire);
        printf("Pretul: ");
        scanf("%s",&x[i].pret);
    }
}

void print_array(Telefoane * x, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("\nTelefonul: %d\n",i);
        printf("Denumirea: %s\n", x[i].denumire);
        printf("Pretul: %s\n", x[i].pret);
    }
}

void search_by_key(Telefoane * x, int n)
{
    int key;
    char cauta[10];
    printf("\nCauta dupa: \n1)Denumire \n 2)Pret\n");
    scanf("%d",&key);

    if(key == 1)
    {
        printf("Dati denumirea:");
        scanf("%s",&cauta);
        for(int j=0; j<n; j++)
        {
            if(strcmp(x[j].denumire,cauta) == 0)
            {
                printf("Elementul cautat se afla pe pozitia: %d\n",j);
                break;
            }
        }
    }
    else if(key == 2)
    {
        printf("Dati pretul:");
        scanf("%s",&cauta);
        for(int j=0; j<n; j++)
        {
            if(strcmp(x[j].pret,cauta) == 0)
            {
                printf("Elementul cautat se afla pe pozitia: %d\n",j);
                break;
            }
        }
    }
}

int main()
{
    int num;
    printf("Dati numarul de telefoane: \n");
    scanf("%d",&num);
    Telefoane tel[num];
    citire_array(tel,num);
    printf("-------------------------------------------------");
    print_array(tel,num);
    printf("-------------------------------------------------");
    search_by_key(tel,num);
    printf("-------------------------------------------------");
    search_by_key(tel,num);
    return 0;
}
