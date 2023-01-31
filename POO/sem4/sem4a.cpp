#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;


class fractie
{
    int numarator, numitor;

    public:

    fractie(int x = 0 , int y = 1)
        {
            if(y < 0)
                {
                    x = -x;
                    y = -y;
                }
            numarator = x;
            numitor = y;
        }
///////////////////////////////////////////
    fractie operator+(fractie n1)
    {
        fractie frac(0,1);
        frac.numitor = numitor * n1.numitor;
        frac.numarator = numarator * n1.numitor + numitor * n1.numarator;
        return frac;
    }
///////////////////////////////////////////
        fractie operator+(int num)
    {
        fractie frac;
        frac.numitor = numitor;
        frac.numarator = numarator + num + numitor * numitor;
        return frac;
    }
///////////////////////////////////////////
        fractie operator-(fractie n1)
    {
        fractie frac;
        frac.numitor = numitor * n1.numitor;
        frac.numarator = numarator * n1.numitor - numitor * n1.numarator;
        return frac;
    }
///////////////////////////////////////////
        fractie operator-(int num)
    {
        fractie frac;
        frac.numitor = numitor;
        frac.numarator = numarator + num + numitor * numitor;
        return frac;
    }
///////////////////////////////////////////
        fractie operator*(fractie n1)
    {
        fractie frac;
        frac.numitor = numitor * n1.numitor;
        frac.numarator = numarator * n1.numarator;
        return frac;
    }
///////////////////////////////////////////
        fractie operator*(int num)
    {
        fractie frac;
        frac.numitor = numitor;
        frac.numarator = numarator * num;
        return frac;
    }
///////////////////////////////////////////
        fractie operator/(fractie n1)
    {
        fractie frac;
        frac.numitor = numitor * n1.numarator;
        frac.numarator = numarator * n1.numitor;
        return frac;
    }
///////////////////////////////////////////
        fractie operator/(int num)
    {
        fractie frac;
        frac.numitor = numitor;
        frac.numarator = numarator * num;
        return frac;
    }
/////////////////////////////////////////// prefix
        fractie operator++()
    {
        numitor = numitor;
        numarator++;;
        return *this;
    }
/////////////////////////////////////////// postfix
        fractie operator++(int)
    {
        fractie frac = *this;
        ++numarator;
        numitor = numitor;
        return frac;
    }
/////////////////////////////////////////// prefix
        fractie operator--()
    {
        numitor = numitor;
       
        numarator --;
        return *this;
    }
/////////////////////////////////////////// postfix
        fractie operator--(int)
    {
        fractie frac = *this;

        --numarator;
        numitor = numitor;
        return frac;
    }
//////////////////////////////////////////

    friend ostream& operator<<(ostream &out, const fractie &n1)
        {
            out << n1.numarator << "/" << n1.numitor << endl;
        }

//////////////////////////////////////////
    
    friend istream& operator>>(istream &in,fractie &n1)
        {
            cout << "\nDati numaratorul: \n";
            in >> n1.numarator;
            cout << "\nDati numitorul: \n";
            in >> n1.numitor;
            return in;
        }
//////////////////////////////////////////
    int operator ==(fractie n1)
    {
        if(n1.numarator == numarator && n1.numitor == numitor)
            return 1;
        else    
            return 0;
    }
//////////////////////////////////////////
    int operator !=(fractie n1)
    {
        if(n1.numarator != numarator && n1.numitor != numitor)
            return 1;
        else    
            return 0;
    }
//////////////////////////////////////////
    int operator >=(fractie n1)
    {
        if(numarator >= n1.numarator && numitor >= n1.numitor)
            return 1;
        else    
            return 0;
    }
//////////////////////////////////////////
    int operator >(fractie n1)
    {
        if(numarator > n1.numarator && numitor > n1.numitor)
            return 1;
        else    
            return 0;
    }
//////////////////////////////////////////
    int operator <(fractie n1)
    {
        if(numarator < n1.numarator && numitor < n1.numitor)
            return 1;
        else    
            return 0;
    }
};

int main()
{
    fractie f1(5, 2), f2(3, 2);
    cout << "fractia 1: \n" << f1<<endl;
    cout << "fractia 2: \n" << f2<<endl;
    // operatorul --;
    cout << "\nOperator --: \n";
    cout << f2--;
    cout << f2;

    // operatorul ++;
    cout << "\nOperator ++: \n";
    cout << f1++;
    cout << f1;

    //
    cout << "\nf1/f2: \n";
    fractie f;
    f = f1/f2;
    cout << f;


    return 0;
}






