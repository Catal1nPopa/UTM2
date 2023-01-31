#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Telefoane
{
    char *denumire[15];
    char pret[10];
} Telefoane;

Telefoane * create_array(int n)
{
    Telefoane * x = calloc(sizeof(Telefoane),n);
    return x;
}

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
void add_element(Telefoane *x, int num, int pos)
{
    printf("Introduceti datele telefonului \n");
    printf("Denumirea: ");
    scanf("%s",&x[pos].denumire);
    printf("Pretul: ");
    scanf("%s",&x[pos].pret);
}
void delete_array(Telefoane * x)
{
    free(x);
    printf("\nMemoria a fost eliberata cu succes!\n");
}

void print_array(Telefoane * x, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("Telefonul: %d\n",i);
        printf("Denumirea: %s\n", x[i].denumire);
        printf("Pretul: %s\n", x[i].pret);
    }
}

void search_by_key(Telefoane * x, int n)
{
    int key;
    char cauta[10];
    printf("Cauta dupa: 1)Denumire \n 2)Pret\n");
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
//sortare dupa marimea denumirii
void sortare(Telefoane *x, int n)
{
    Telefoane au;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n - 1 - i); j++)
        {
            if(stricmp(x[j].denumire,x[j+1].denumire))
            {
                au = x[j];
                x[j] = x[j +1];
                x[j + 1] = au;
            }
        }
    }
}



void add_element_pos(Telefoane *x, int n)
{
    printf("\nDati pozitia: \n");
    int a;
    scanf("%d",&a);
    for(int i=n-1; i>=a; i--)
    {
        x[i] = x[i-1];
    }
    x = realloc(x, n* sizeof(Telefoane));
    citire_array(x,a);
}

void delete_element(Telefoane *x, int n)
{
    int pozitie;
    printf("Dati pozitia: \n");
    scanf("%d",&pozitie);
    for(int i = pozitie - 1; i < n - 1; i++)
    {
        x[i] = x[i + 1];
    }
    n--;
    x = realloc(x, n*sizeof(Telefoane));
}

int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");
    printf("---------Menu---------\n");
    printf("1) Creaza tablou\n");
    printf("2) Initializeaza tablou\n");
    printf("3) Afiseaza tablou\n");
    printf("4) Elibereaza tablou\n");
    printf("5) Cauta in tablou un element\n");
    printf("6) Sortarea elementelor\n");
    printf("7) Adaugare element la sfarsit\n");
    printf("8) Adaugare element la inceput\n");
    printf("9) Adaugare element pe o poztitie dorita\n");
    printf("10) Stergerea elementului de pe o pozitie\n");
    printf("0) Opriti programul");
    int command = 100;
    printf("\n\nSelectati commanda: ");
    scanf("%d",&command);

    if((command>10)||(command<0))
    {
        error_input_found = 1;
        goto menu_start;
    }
    return command;
}

int main()
{

    int command=100;
    Telefoane * x = NULL;
    int n,pos;
    while(command)
    {
        command = menu();
        switch(command)
        {
        case 1:
        {
            printf("Dati n=");
            scanf("%d",&n);
            x = create_array(n);
            break;
        }
        case 2 ... 10:
        {
            if(x == NULL)
            {
                printf("\nTabloul este NULL!\n");
                break;
            }
            switch(command)
            {
            case 2:
            {
                citire_array(x,n);
                break;
            }
            case 3:
            {
                print_array(x,n);
                break;
            }
            case 4:
            {
                delete_array(x);
                x = NULL;
                n = 0;
                break;
            }
            case 5:
            {
                search_by_key(x,n);
                break;
            }
            case 6:
            {
                sortare(x,n);
                break;
            }
//            case 7:
//            {
//                n++;
//                add_end(x,n);
//                break;
//            }
//            case 8:
//            {
//                n++;
//                add_start(x,n,pos);
//                break;
//            }
//            case 9:
//            {
//                n++;
//                add_element_pos(x,n);
//                break;
//            }
            case 10:
            {
                delete_element(x,n);
                n--;
                break;
            }
            }
            printf("\n\nApasati orice buton pentru continuare!\n");
            _getch();
        }
        }
    }
    return 0;
}
