#include <iostream>
using namespace std;


class Soft
{
    string name_file;
    string anexa;
    int data;
    int time_ore,time_minute;
    double size;
    string directoriu;

    public:
    Soft(string name_file1, string anexa1, int data1, int time_ore1, int time_minute1, double size1, string directoriu1)
    {
        name_file = name_file1;
        anexa = anexa1;
        data = data1;
        time_ore = time_ore1;
        time_minute = time_minute1;
        size = size1;
        directoriu = directoriu1;
    }

     void change_name(string);
     void change_anexa(string);
     void change_directoriu(string);

    // Soft(const char*);
    void citire();
    void afisare();

     ~Soft(){cout <<"\n// Fisierul a fost distrus\\\\\n" <<endl;}
};



// Soft::Soft(char* name)
// {
//     name_file = name;
// }

void Soft::afisare()
{
    cout << " \nName | "<<name_file<< endl; 
    cout << " \nAnexa | "<<anexa<< endl; 
    cout << " \nData | "<<data<< endl; 
    cout << " \nOra | "<<time_ore<< " : "<<time_minute<< endl; 
    cout << " \nMarimea | "<<size<< endl; 
    cout << " \nDirectoriu | "<<directoriu<< endl; 
}

void Soft::change_name(string new_name)
{
    name_file = new_name;
}

void Soft::change_anexa(string new_anexa)
{
    anexa = new_anexa;
}

void Soft::change_directoriu(string new_directoriu)
{
    directoriu = new_directoriu;
}

int main()
{
    string name_name, anexa1, directoriu1;
    Soft *a;
    
    ///Crearea obiectului folosind memoria dinamica si constructor cu parametri
    a = new Soft("test","exe",12,4,21,200,"folder");
    a->afisare();

    cout << "\n////////////////////////" <<endl;
    ///Schimbuarea numelui fisierului
    cout <<"\nDati denumirea noua: \n";
    cin >> name_name;
    a->change_name(name_name);
    a->afisare();

    cout << "\n////////////////////////" <<endl;
    ///Schimbuarea anexeifisierului
    cout <<"\nDati anexa noua: \n";
    cin >> anexa1;
    a->change_anexa(anexa1);
    a->afisare();

    cout << "\n////////////////////////" <<endl;
    ///Schimbuarea directoriului fisierului
    cout <<"\nDati directoriul nou: \n";
    cin >> directoriu1;
    a->change_directoriu(directoriu1);
    a->afisare();


    delete a;
}

