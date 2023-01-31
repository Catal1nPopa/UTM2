#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;


struct vector{
  float *element;
  long number;};

////////////////



void distance(vector *z)
{
  cout<<"Introduceti dimensiunea vectorului: \n";
  cin>> z->number;
  z->element = new float[z->number];
}

/////////////////

void elements(vector *z)
{
  int i;
  cout<<"Introduceti elementele vectorului: \n";
  for(i=0;i<z->number;i++)
  {
  cout<<"Elementul["<<i+1<<"]::  ";
  cin>>z->element[i];
  }
}



//////////////////////

delete_vector(vector *z)
{
  delete[] z->element;
  z->element = NULL;
  z->number = 0;
  cout <<"\nAti sters vectorul cu succes!!!\n";
}

//////////////////////

void show(vector *z)
{
  if(z->number != 0)
  {
    cout <<"Vectorul este: \n";
    for(int i=0; i<z->number; i++)
    cout << z->element[i] <<" ";

    if(z->number != 0)
    {
      cout << "\n\n Sunt "<<z->number<<" numere";
    }
    else
    {
      cout <<"\n !!!Nu sunt numere!!!";
    }
  }
  else
  {
    cout <<"\n Vectorul nu a fost creat";
  }
}


//////////////////

re_vector(vector *z)
{
  int new_dimension;

  cout <<"Introduceti dimensiunea noua a vectorului: \n";
  cin >>new_dimension;

  if(z->number > new_dimension)
  {
    for(int i=new_dimension+1; i<z->number; i++)
    {
      delete[] z->element;
      z->element == NULL;
    }
    z->number = new_dimension;
  }
}

//////////////////

check_element(vector *z)
{
  int position;

  cout <<"Introduceti pozitia elementului dorit: \n";
  cin >>position;

  if(position > z->number)
  {
    cout << "\n Nu exista element pe aceasta pozitie!!!";
  }
  else
  {
    cout <<"Elementul accesat este: ";
    for(int i=0; i<=z->number; i++)
    {
      if(i == position)
      {
        cout << z->element[i-1];
      }
    }
  }
}

/////////////////

suma(vector *z)
{

int sum=0;

for(int i=0; i<z->number;i++)
  if(z->element[i] < 0)
      sum+=z->element[i];
    cout<<"Suma elementelor negative ale vectorului este: "<<sum;
}

/////////////////////

void Menu()
{
cout<<"\n[1]-Initializarea vectorului\n";
cout<<"[2]-Afisare\n";
cout<<"[3]-Eliminarea vectorului\n";
cout<<"[4]-Modificarea dimensiunii vectorului\n";
cout<<"[5]-Acces la elementele vectorului\n";
cout<<"[6]-Suma elementelor negative\n";
cout<<"[7]-Crearea vectorului secundar\n";
cout<<"[8]-Suma a 2 vectori\n";
}


////////////////////////////////////////////////////////////

main()
{
  vector v,x;
  int i;
  
  int sum = 0;


  ///Menu

  menu:Menu();

  int choice;
  char confirm;

  do
  {

    cout<<"\n\nAlege optiunea dorita:\n";
    cin>>choice;

    switch(choice)
    {

      ///////Initializare

      case 1: system("cls");distance(&v),elements(&v);
        cout<<"\n";
        cout<<"\n Enter - Inapoi\n";

        case0: confirm = getch();
        system("cls");
        if (confirm == 13)
          goto menu;
        else
          goto case0;
        break;

      ////// Afisare

      case 2:
        system("cls");

        show(&v);
        cout<<"\n";
        cout<<"\n Enter - Inapoi\n";

        case1: confirm = getch();
        system("cls");
        if (confirm == 13)
          goto menu;
        else
          goto case1;
        break;

        ///// Eliminarea

        case 3: delete_vector(&v);
          cout<<"\n";
          cout<<"\n Enter - Inapoi\n";

          case2: confirm = getch();
          system("cls");
          if (confirm == 13)
            goto menu;
          else
            goto case2;
          break;

        ///// Modificarea

      case 4: re_vector(&v);
        cout<<"\n";
        cout<<"\n Enter - Inapoi\n";

        case3: confirm = getch();
        system("cls");
        if (confirm == 13)
          goto menu;
        else
          goto case3;
        break;

      ///////Accesarea

      case 5: check_element(&v);
        cout<<"\n";
        cout<<"\n Enter - Inapoi\n";

        case4: confirm = getch();
        system("cls");
        if (confirm == 13)
          goto menu;
        else
          goto case4;
        break;

      /////// Suma elementelor negative

      case 6: suma(&v);
        cout<<"\n";
        cout<<"\n Enter - Inapoi\n";

        case5: confirm = getch();
        system("cls");
        if (confirm == 13)
          goto menu;
        else
          goto case5;
        break;

        ///// Al 2-lea - vector

      case 7: system("cls");distance(&x),elements(&x);

        cout<<"\n";
        cout<<"\n Enter - Inapoi\n";

        case6: confirm = getch();
        system("cls");
        if (confirm == 13)
          goto menu;
        else
          goto case6;
        break;

      /////Adunarea vectorilor

      case 8:
        if((x.number == 0) || (v.number == 0))
          {
            cout<<"\n Nu exsita vectori in destul pentru operatiune\n";
            getch();
            goto menu;
          }
        else if(x.number == v.number)
          {
            cout<<"\nSuma vectorilor: \n";
            for(i=0; i<v.number; i++)
            {
              sum = x.element[i] + v.element[i];
              cout<<sum<<" ";
            }
          }
        else
          {
            cout <<"\n Vectorii sunt de dimensiune diferita!!\n";
          }
          // getch();
          // goto menu;

          cout<<"\n";
          cout<<"\n Enter - Inapoi\n";

          case7: confirm = getch();
          system("cls");
          if (confirm == 13)
            goto menu;
          else
            goto case7;
          break;


      default: cout<<"invalid"; break;
      system("cls");
    }
    cin>>confirm;
  }
  while (confirm == 13);
  return 0;

  }

///////////////////////////////////////////////////////////
