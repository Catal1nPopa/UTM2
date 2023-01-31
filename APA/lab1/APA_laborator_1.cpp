#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int count = 0;

int fib1(int num)
    {
        if((num == 0) || (num == 1))
        {
            count++;
            return(num);
        }
        else
        {  
            count = count + 3;
           return(fib1(num-1) + fib1(num-2));
        }
    }

int fib2(int num)
{
    int count2 = 0;
     int n1 = 0, n2 = 1, n;
    for(int i = 0; i < num; i++)
    {
        count2 =count2 + 3;
        cout << n1 << " ";
        n = n1 + n2;
        count2++;
        n1 = n2;
        count2++;
        n2 = n;
        count2++;
    }
    cout << "\nNumarul de iteratii este:\n  " << count2 << endl;

}

int fib3(int num)
{
    num = num - 1;
    int i = 1,j = 0,k = 0,h = 1,t = 1;
    int count3 = 0;

    while(num > 0)
    {
        if(num%2 != 0)
        {
            t = h*j;
            j = i*h+j*k+t;
            i = i*k+t;
            count3 = count3 + 7;
            
        }
        {
            t = h*h;
            h = 2*k*h+t;
            k = k*k+t;
            num = (num / 2); 
            count3 = count3 + 7;
        }
    } 
    
    cout << "\nNumarul de iteratii este:  \n" << count3 << endl;
    return j;

}

int main()
{
    int num,num1,i=0;
    // int count=0;
    cout << " Dati numarul: ";
    cin >> num;
    cout <<"//////////////////////////////\n";
///////////////////////////////////
    
      cout <<"\n1-Metoda Iteratiei\n";
        fib2(num);
      cout <<"\n//////////////////////////////\n";
///////////////////////////////////
          cout <<"\n2-Metoda Recursiei\n";
        while(i < num)
        {
            cout << " " << fib1(i);
            i++;
        }
        cout << "\n Numarul de iteratii: ";
        cout << count;
        cout <<"\n//////////////////////////////\n";
/////////////////////////////////////
    cout <<"\n3-Metoda 3";

    cout << "\nSeria Fibonacci(Metoda 3):     \n" << fib3(num) << endl;
cout <<"//////////////////////////////\n";

///////////////////////////////////////////// 

return 0;

}