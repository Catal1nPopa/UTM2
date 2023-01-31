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
    array[i] = rand()% n + 1;
  }
  // array=(int*)realloc(array, n*sizeof(int));
  return array;
}

////////////////////////////////////////////////////////////////////////

// int *create_array(int n)
// {
//   srand(time(NULL));
//   int *array = malloc(n * sizeof(int));
//   int i, p, count;
//   int temp = 0;
//
//   for(count=0;count<n;count++)
//   {
//          array[count]=rand()% n+1;
//      }
//
//   while(temp < n)
//   {
//     int r = rand()% n + 1;
//
//     for(i = 0; i < temp; i++)
//     {
//       if(array[i] == r)
//       {
//         break;
//       }
//     }
//     if(i == temp)
//     {
//       array[temp++] = r;
//     }
//   }
//
//   array=(int*)realloc(array, n*sizeof(int));
//   return array;
// }

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

int linear_search(int *array, int n, int values)
{
  for (int i = 0; i < n; i++)
    {
        if (array[i] == values)
        return i+1;
    }
  return -1;
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

int binary_search(int *array,int variable, int start, int end)
{
  while(start <= end)
  {
    int mid = start + (end - start) / 2;
    if(array[mid] == variable)
      {
        return mid;
      }
    if(array[mid] < variable)
      {
        start = mid + 1;
      }
    else
      {
        end = mid - 1;
      }
  }
  return -1;
}


////////////////////////////////////////////////////////////////////////
int menu()
{
    int error_input_found = 0;
menu_start:
    system("cls");

    printf("\n\n");
    printf("\033[0;33m   Laborator:  \033[0;31m  nr.5\n");
    printf("\033[0;33m   Grupa:    \033[0;31m    TI-211 \n");
    printf("\033[0;33m   A efectuat: \033[0;31m  Popa Catalin \n");
    printf("\033[0;33m   A verificat:\033[0;31m  Stratulat Stefan\n\n\n\n");
    green();
    printf("|----------------------//Menu\\--------------------------|\n");
    printf("|1.Initializeaza tabloul                                |\n");
    printf("|2.Afisarea tabloului                                   |\n");
    printf("|3.Eliberarea memoriei tabloului                        |\n");
    printf("|4.Cautare dupa linear search                           |\n");
    printf("|5.Cautare dupa binary search                           |\n");
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
  int *ptr;
  int command=100;

    while(command)
    {
        command = menu();
        if(command == 1)
        {
          printf("Dati numarul de elemente:\n");
          scanf("%d",&n);


        ptr = create_array(n);
            // ptr = array;

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
                printf("\nMemoria a fost eliberata cu succes!\n");
                ptr = NULL;
              break;
            }
            case 4:
            {
              int variable,res;
              // printf("Introduceti variabila cautata: \n");
              // scanf("%d",&variable);
              clock_t start = clock();
              for(i=0; i<10000; i++)
              {
                variable = rand()% n + 1;
                res = linear_search(ptr, n, variable);
              }
              // if(res == -1)
              // {
              //   printf("Elementul nu este prezent\n");
              // }
              // else
              // {
              //   printf("Elementul se afla pe pozitia: |%d|\n", res);
              // }

                clock_t end = clock();
                float time_t = (float)(end-start)/CLOCKS_PER_SEC;
                printf("%f", time_t);
                break;
            }
            case 5:
            {
              int variable,res;
              // printf("Introduceti variabila cautata: \n");
              // scanf("%d",&variable);
                clock_t start = clock();
                quick_sort(ptr, n);

                for(i=0; i<10000; i++)
                {
                  variable = rand()% n + 1;
                  res = binary_search(ptr, variable, 0, n);
                }

              // if(res != -1)
              // {
              //   printf("Elementul se afla pe pozitia: |%d|\n", res+1);
              // }
              // else
              // {
              //   printf("Elementul nu este prezent\n");
              // }

                clock_t end = clock();
                float time_t = (float)(end-start)/CLOCKS_PER_SEC;
                printf("%f", time_t);
                break;
            }
            }
              red();
             printf("\n\nTastati orice buton pentru continuare!\n");
             _getch();

    }
    return 0;
}
