#include <iostream>
#include <string.h>
using namespace std;


class angajat{
    string name,functia;
    int anul_angajarii, ore_lucrate, plata_ora;
    public:
    void citire();
    void afisare();
    int stagiu();
    double salariu_calc();
    double spor();
    double salariu_primit();
};

void angajat :: citire(){

    cout<< "Numele: "; cin>>name;
    cout<<"Functia: "; cin>>functia;
    cout<<"Anul angajarii:"; cin >> anul_angajarii;
    cout<< "Ore lucrate:"; cin >> ore_lucrate;
    cout<<"Plata pe ora:"; cin >> plata_ora;

}

void angajat :: afisare(){
    cout<< "Numele: " << name << endl;
    cout<<"Functia: " << functia << endl;
    cout<<"Anul angajarii" << anul_angajarii << endl;
    cout<< "Ore lucrate" << ore_lucrate << endl;
    cout<<"Plata pe ora" << plata_ora << endl;
}

int angajat :: stagiu() {
    return 2022-anul_angajarii;
}

double angajat :: salariu_calc(){
    return ore_lucrate  * plata_ora;
}

double angajat :: spor() {
    if (stagiu()>5 && stagiu()<=8) {
        return (15*salariu_calc())/100;
    }
    if(stagiu()>8) {
        return (25*salariu_calc())/100;
    }
}

double angajat :: salariu_primit() {
    return salariu_calc() + spor();
}


main() {
    int number;
  cout << "Introduceti nr de angajati : ";
  cin >> number;
  angajat total[number];

  for (int i=0;i<number;i++) {
      total[i].citire();
  }

  for (int i=0;i<number;i++) {
      total[i].afisare();
  }

  for (int i=0;i<number;i++) {
      if(total[i].stagiu()>10)
      {
        total[i].afisare();
      }
  }

  for (int i=0;i<number;i++) {
      if(total[i].salariu_calc()>1000)
      {
        total[i].afisare();
      }
  }

}
