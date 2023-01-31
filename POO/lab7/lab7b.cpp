

//  Create a parameterized class MultiMap - a multi-association list that contains the
//   fields key and list of values. That is, one key can correspond to several values.
//   The class must contain constructors, destructor, add, removeByKey, getLength,
//   getByKey, getByValue functions, [] and I/O operators.

//  Создать параметризированный класс MultiMap – мульти-ассоциативный список, который
// содержит поля ключ и список значений. То есть, одному ключу может соответствовать
//  несколько значений. Класс должен содержать конструкторы, деструктор, функции add,
//   removeByKey, getLength, getByKey, getByValue, операторы [] и ввода/вывода.

// Creați o clasă parametrizată MultiMap - o listă cu mai multe asociații care conține
// câmpurile cheie și lista de valori. Adică, o cheie poate corespunde mai multor valori.
//  Clasa trebuie să conțină funcții constructori, destructor, add, removeByKey,
//  getLength, getByKey, getByValue, [] și operatori I/O.

//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <list>

template <typename Key, typename Value>
class MultiMap
{
    Key x;
    Value y;

public:
    MultiMap(Key x1, Value y1)
    {
        x = x1;
        y = y1;
    }

    MultiMap();

    void afisare()
    {
        cout << "Key: " << x << "|---| " << y << endl;
    }

    ~MultiMap()
    {
        x = 0;
        y = ' ';
    }
    // template <class>
    // friend std::istream &operator>>(std::istream &is, MultiMap<Key, Value> &i);
    template <class>
    friend std::ostream &operator<<(std::ostream &os, MultiMap<Key, Value> &o);
    void getByKey(int);
    void getByValue(string);
};

template <typename Key, typename Value>
void operator<<(std::ostream &os, MultiMap<Key, Value> &o)
{
    return o.afisare();
}

// template <typename Key, typename Value>
// std::istream &operator>>(std::istream &is, MultiMap<Key, Value> &i)
// {
//     Key a;
//     Value b;

//     std::cout << "Get key: ";
//     is >> a;
//     std::cout << "Get value: ";
//     is >> b;
// //    // i.add(val);
// //     return is;
// }

template <typename Key, typename Value>
void MultiMap<Key, Value>::getByKey(int key)
{
    if (key == x)
    {
        cout << " " << y;
    }
}

template <typename Key, typename Value>
void MultiMap<Key, Value>::getByValue(string key)
{
    if (key == y)
    {
        cout << " " << x;
    }
}

void print_menu()
{
    system("cls");
    cout << "Alege o comanda" << endl;
    cout << "1.Creare si afisare lista" << endl;
    cout << "2. Cautare dupa key" << endl;
    cout << "3. Cautare dupa value" << endl;
    cout << "4. Stergere element" << endl;
    cout << "5. Exit" << endl;
    cout << ">";
}

int get_variant(int count)
{
    int variant;
    string s;
    getline(cin, s);

    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count)
    {
        cout << "Incorrect input. Try again: ";
        getline(cin, s);
    }
    return variant;
}

int main()
{
    MultiMap<int, string> t1(1, "Sasa");
    MultiMap<int, string> t2(1, "Ion");
    MultiMap<int, string> t3(2, "Sandu");
    MultiMap<int, string> t5(1, "Valeria");
    MultiMap<int, string> t4(3, "Ion");

    int variant;
    do
    {
        print_menu();

        variant = get_variant(5);

        switch (variant)
        {
        case 1:
        {
            cout << "\nAfisare date: \n";
            cout << t1;
            cout << t2;
            cout << t5;
            cout << t3;
            cout << t4;
            cout << "\n";
            break;
        }
        case 2:
        {
            int k;
            cout << "\nIntroduceti key: ";
            cin >> k;

            if (k == 1)
            {
                cout << "Datele sub key 1: " << endl;
                t1.getByKey(1);
                t5.getByKey(1);
                t2.getByKey(1);
            }
            else if (k == 2)
            {
                cout << "Datele sub key 2: " << endl;
                t3.getByKey(2);
            }
            else
            {
                cout << "Datele sub key 3: " << endl;
                t4.getByKey(3);
            }
            cout << "\n";
            break;
        }
        case 3:
        {
            string k;
            cout << "\nIntroduceti value: ";
            cin >> k;

            if (k == "Sasa")
            {
                cout << "Key cu value: " << k << endl;
                t1.getByValue(k);
            }
            else if (k == "Ion")
            {
                cout << "Key cu value: " << k << endl;
                t2.getByValue(k);
                t4.getByValue(k);
            }
            else if (k == "Sandu")
            {
                cout << "Key cu value: " << k << endl;
                t3.getByValue(k);
            }
            else if (k == "Valeria")
            {
                cout << "Key cu value: " << k << endl;
                t4.getByValue(k);
            }
            else
            {
                cout << "\nNu este un astfel de nume!!!!" << endl;
            }
            cout << "\n";
            break;
        }
        case 4:
        {
            int k;
            cout << "\nIntroduceti ID la valoarea care doriti sa o stergeti: ";
            cin >> k;

            if (k == 1)
            {
                t1.~MultiMap();
                cout << "\nElementul a fost sters!!!";
            }
            else if (k == 2)
            {
                t2.~MultiMap();
                cout << "\nElementul a fost sters!!!";
            }
            else if (k == 3)
            {
                t3.~MultiMap();
                cout << "\nElementul a fost sters!!!";
            }
            else if (k == 4)
            {
                t4.~MultiMap();
                cout << "\nElementul a fost sters!!!";
            }
            else if (k == 5)
            {
                t5.~MultiMap();
                cout << "\nElementul a fost sters!!!";
            }

            break;
        }
        }

        if (variant != 5)
            system("pause");
    } while (variant != 5);

    return 0;
}
