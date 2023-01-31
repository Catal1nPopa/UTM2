#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

void red () {
  printf("\033[0;31m");
}

void green () {
  printf("\033[0;32m");
}
////////////////////////////////////////////////////////////////////////

int *create_array(int n)
{
  srand(time(NULL));
  int *array = malloc(n * sizeof(int));
  for(int i=0; i<n; i++)
  {
    array[i] = rand() % n + 1;
  }
  return array;
}

////////////////////////////////////////////////////////////////////////

void print_array(int *array, int n)
{
  {
    for(int i=0; i<n; i++)
      printf("arr[%d]: |%d|\n",i+1,*(array+i));
  }
}

////////////////////////////////////////////////////////////////////////

void free_array(int *array)
{
  free(array);
}

////////////////////////////////////////////////////////////////////////

void insertionSort(int *array, int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
     {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}


////////////////////////////////////////////////////////////////////////

void quick_sort(int *array, int n)
 {
    if (n < 2)
    {
        return;
    }
    int mid = array[n / 2];
    int *left = array;
    int *right = array + n - 1;
    while (left <= right) {
        if (*left < mid) {
            left++;
        }
        else if (*right > mid) {
            right--;
        }
        else {
            int t = *left;
            *left = *right;
            *right = t;
            left++;
            right--;
        }
    }
    quick_sort(array, right - array + 1);
    quick_sort(left, array + n - left);
}


////////////////////////////////////////////////////////////////////////
int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");
    printf("\033[0;33m   Laborator:  \033[0;31m  nr.5\n");
    printf("\033[0;33m   Grupa:    \033[0;31m    TI-211 \n");
    printf("\033[0;33m   A efectuat: \033[0;31m  Popa Catalin \n");
    printf("\033[0;33m   A verificat:\033[0;31m  Stratulat Stefan\n\n\n\n");
    green();
    printf("|----------------------//Menu\\--------------------------|\n");
    printf("|1.Initializeaza tabloul                                |\n");
    printf("|2.Afisarea tabloului                                   |\n");
    printf("|3.Eliberarea memoriei tabloului                        |\n");
    printf("|4.Sortarea tabloului - insertion sort                  |\n");
    printf("|5.Sortarea tabloului - quick sort                      |\n");
    printf("|0.Inchide programul                                    |\n");
    printf("|-------------------------------------------------------|\n");

    int command = 10;
    if(error_input_found)
    {
        printf("\n\nCommanda trebuie sa fie o optiune de mai sus!!![0-5]\n");
    }
    red();
    printf("\n\nSelectati commanda: ");
    scanf("%d",&command);

    if((command>5)||(command<0))
    {
        error_input_found = 1;
        goto menu_start;
    }
    return command;
}

//////////////////////////////////////////////////////////////////

int main()
{
  int n,i;
  int *ptr=0;
  int *array;
  int command=10;

    while(command)
    {
        command = menu();
        if(command == 1)
        {
          printf("Dati numarul de elemente:\n");
          scanf("%d",&n);
          ptr = create_array(n);


        }
        switch (command)
        {
            case 2:
            {
              if(ptr == NULL)
              {
                printf("Tabloul este null!!!\n");
              }
              else
              {
                print_array(ptr, n);
              }
              break;
            }
            case 3:
            {
              free(ptr);
              printf("Memoria a fost eliberata cu succes!\n");
              ptr = NULL;
              break;
            }
            case 4:
            {
                clock_t start = clock();
                insertionSort(ptr, n);
                clock_t end = clock();
                float time_t = (float)(end-start)/CLOCKS_PER_SEC;
                printf("%f", time_t);
                break;
            }
            case 5:
            {
              clock_t start = clock();
              quick_sort(ptr, n);
              clock_t end = clock();
              float time_t = (float)(end-start)/CLOCKS_PER_SEC;
              printf("%f", time_t);
                break;
            }
            }
             printf("\n\nTastati orice buton pentru continuare!\n");
             _getch();

    }
    return 0;
}
