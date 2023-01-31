
//Popa Catalin TI-211

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Student
{
    string nume;
    string familie;
    int age;
    double nota_medie;
    string universitate;
    int n,check1,check2;
    double medie_totala;

    public:
        Student()
        {
            nume = " ";
            familie = " ";
            age = 0;
            nota_medie = 0;
            universitate = " ";
            n = 3;
            check1=0;
            check2=0;
            medie_totala = 0;

        }

        Student(string nume1, string familie1, int age1, double medie, string universitate1)
        {
            nume = nume1;
            familie = familie1;
            age = age1;
            nota_medie = medie;
            universitate = universitate1;
        }

        Student(Student&);

    void citire();
    void afisare();
    void sortare();
    void medie_totala1();

  
    ~Student()
        {
            cout << "\n!! Memoria a fost eliberata !!\n" << endl;
        }
};

// Student::~Student()
// {
// 	delete[] nume;
// }

void Student :: medie_totala1()
{
    double m = (medie_totala/check1);
    cout << "\nMedia totala per studentii acceptati este: \n" <<m<<endl;
}

Student :: Student(Student &c)
{
    nume = c.nume;
    familie = c.familie;
    age = c.age;
    nota_medie = c.nota_medie;
    universitate = c.universitate;
}


void Student::citire()
{

    for(int i=0; i<n; i++)
    {
        cout << "\n-------------------------------\n";
    cout << "\nIntroduceti numele studentului: ";
    cin >> nume;
    cout << "\nIntroduceti familia studentului: ";
    cin >> familie;
    cout << "\nIntroduceti varsta studentului: ";
    cin >> age;
    cout << "\nIntroduceti universitatea dorita: ";
    cin >> universitate;
    cout << "\nIntroduceti nota medie a studentului: ";
    cin >> nota_medie;

    if(nota_medie <= 7)
    {
        cout <<"\n---Studentul nu este acceptat---!!\n";
        check2++;
    }
    else
    {
        cout <<"\n ---Studentul este acceptat--- !!\n";
        check1++;
        medie_totala = medie_totala + nota_medie;
    }
    }

}


void Student::afisare()
{
    cout << "\nNume student: " << nume<< endl;
    cout << "\nFamilie student: " <<familie<< endl;
    cout << "\nVarsta: " <<age<< endl;
    cout << "\nNota medie student: " <<nota_medie<< endl;
    cout << "\nUniversitatea dorita:  " <<universitate<< endl;
    
    if(nota_medie <= 7)
    {
        cout <<"\n---Studentul nu este acceptat---!!\n";
    }
    else
    {
        cout <<"\n ---Studentul este acceptat--- !!\n";
    }
    
}

void Student::sortare()
{
    cout << "\nNumarul studentilor acceptati sunt: \n"<<check1<<endl;
    cout << "\nNumarul studentilor neacceptati sunt: \n"<<check2<<endl;

}

void menu()
{
    cout <<"\n//////////////////////////////////////////////////\n";
    cout <<"\n////////////////////Menu//////////////////////////\n";
    cout <<"\n///////////1.Constructor cu parametri/////////////\n";
    cout <<"\n//////////2.Constructor fara parametri.///////////\n";
    cout <<"\n//////////////////////////////////////////////////\n";
}

int main()
{
    int count;
    
    menu();
    cout << "\n Alegeti metoda:\n1.Cu parametri.\n2. Fara parametri.\n";
    cin >> count;
    if(count == 1)
    {
        //Constructor cu parametri
        cout << "\n\nConstrcutor cu parametri: \n";
        Student *students;
        students = new Student("Ion", "Popa", 18, 8.9, "UTM");
        students->afisare();
        delete students;
    }
    else if (count == 2)
    {
        //constructor fara parametri
        cout << "\n\nConstrcutor fara parametri: \n";
        Student n1;
        n1.citire();

        cout <<"\n-------------------\n";
        n1.sortare();
        n1.medie_totala1();

    }
    else
    {
        cout << "\n Numarul nu este valid!!\n";
    }
}