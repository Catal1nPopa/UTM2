#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<iostream>
#include<time.h>
#include <vector>
using namespace std;

int it;
int it2;
// int array[n];

///////////////Partition
int partition(int array[], int p, int r)
{
    int array2 = array[p];
    int i = p - 1;
    int j = r + 1;
    int count;

    do
    {
        do
        {
            j--;
        }
        while(array2 < array[j]);

        do
        {
            i++;
        }
        while(array2 > array[i]);

        if(i < j)
        {
            count = array[i];
            array[i] = array[j];
            array[j] = count;
        }
    }
    while(i < j);
    it = i + j;
    return j;
}

/////////////Quicksort

void quicksort(int array[], int p, int r)
{
    if(p < r)
    {
        int mid = partition(array, p, r);
        quicksort(array, p, mid);
        quicksort(array, mid + 1, r);
    }
}

////////////Printare array
void print_array(int array[], int num)
{
    for(int i = 0; i < num; i++)
    {
        cout << array[i] << ' ';
    }
    cout << "\n\n";
}


////////////Merge
const int n = 100;
int array2[n];


void merge(int x1, int x2, int x3, int x4)
{
    int i,j;
    for(j = x1; j <= x2; j++)
    {
        for(i = x3; i <= x4; i++)
        {
            if(array2[i] < array2[j])
            {
                array2[i] +=array2[j];
                array2[j] -=array2[j];
                array2[i] -=array2[j];
                it2 = j + i;
            }
        }
    }
}


/////////////
void insert(int i, int j)
{
     if(array2[i] > array2[j])
        {
            array2[i] = array2[i] + array2[j];
            array2[j] = array2[i] - array2[j];
            array2[i] = array2[i] - array2[j];
        }
}


//////////////Merge sort

int merge_sort(int i, int j)
{
    if(j - i <= 1)
    {
        insert(i,j);
    }
    else
    {
        merge_sort(i,(i+j)/2);
        merge_sort(1+(i+j)/2, j);
        merge(i,(i+j)/2,1+(i+j)/2,j);
    }
// return array2;
}


int main()
{
    rand();

        int array[250];
        int size;
        cout << "Dati o marime a tabloului: \n";
        cin >> size;

    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%500; 
    }

    cout << " Alegeti metoda de sortare: \n";
    cout << "1. Quick sort \n 2.Merge sort\n";
    int chose;
    cin >> chose;

    if(chose == 1)
    //////////////////Quick sort
    {

        cout << "\nTabloul initial este: \n";
        print_array(array,size);

        quicksort(array, 0, size - 1);

        cout << "\n\nTabloul sortat este: \n";
        print_array(array, size);

        cout << "\n\nNumarul de iteratii este: " << it << endl;
    }

    else if(chose == 2)
    /////////////////////Merge sort
    {
        cout << "\nTabloul initial esteL \n";
        print_array(array,size);

        for(int i = 0; i < size; i++)
        {
            merge_sort(0, size-1);
        }

        cout << "\n\nTabloul sortat este: \n";
        merge_sort(0, size-1);
        print_array(array, size);

        cout << "\n\nNumarul de iteratii este: " << it2 << endl;

    }

    else
    {
        cout << "\n Numarul introdus este gresit!!!\n";
    }

    return 0;

}