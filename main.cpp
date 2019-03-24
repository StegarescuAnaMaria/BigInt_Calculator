#include <iostream>
#include "BigInt.h"
#include <string.h>
using namespace std;
struct Lista
{
    int valoare;
    Lista* next;
    Lista* previous;

};
void inserare_sfarsit(int x, Lista* &cap);
Lista* getNumere(int n);
void afisare_BigInt(BigInt obiect);
int main()
{ int n; char c1, c2;
cout<<"Introduceti semnul primului numar"<<endl;
cin>>c1;
cout<<"Introduceti cate cifre va contine primul numar"<<endl;
    cin>>n;
Lista* cap1=getNumere(n);       //creeaza lista

BigInt obiect1(cap1, n, c1);



//afisare_BigInt(cap);

int m;
cout<<"Introduceti semnul celui de-al doilea numar"<<endl;
cin>>c2;
cout<<"Introduceti cate cifre va contine al doilea numar"<<endl;
cin>>m;
Lista* cap2=getNumere(m);

BigInt obiect2(cap2, m, c2);


BigInt obiect3=obiect1+obiect2;
//obiect3=obiect1+obiect2;
cout<<"Se afiseaza numarul-suma"<<endl;
afisare_BigInt(obiect3);
BigInt obiect4=obiect1-obiect2;
//obiect4=obiect1-obiect2;
cout<<"Se afiseaza numarul-diferenta"<<endl;
afisare_BigInt(obiect4);
BigInt obiect5=obiect1*obiect2;
//obiect5=obiect1*obiect2;
cout<<"Se afiseaza numarul-produs"<<endl;
afisare_BigInt(obiect5);
BigInt obiect6=obiect1/obiect2;
cout<<"Se afiseaza numarul-cat"<<endl;
afisare_BigInt(obiect6);
//obiect6=obiect1/obiect2;

cout<<"Se afiseaza daca numarul 1 e palindrom"<<endl;
palindrom(obiect1);
cout<<"Se afiseaza paritatea primului numar"<<endl;
paritate(obiect1);

cout<<"Introduceti puterea la care va fi ridicat numarul 1"<<endl;
int p;
cin>>p;
BigInt obiect7=ridicare_la_putere(obiect1, p);
cout<<"Se afiseaza numarul 1 ridicat la puterea "<<p<<endl;
afisare_BigInt(obiect7);
cout<<"Se afiseaza suma cifrelor primului numar"<<endl;
long long int k=suma_cifrelor(obiect1);
cout<<k;

    int lungime;
    cout<<"Introduceti numarul de caractere pentru sirul pentru care se va face conversia "<<endl;
    cin>>lungime;
    char* sir=new char[lungime];
    cout<<"Introduceti sirul de caractere "<<endl;
        cin>>sir;


    BigInt obiect8;
    obiect8=sir;
    afisare_BigInt(obiect8);


    long long int numar;
    cout<<"Introduceti un numar intreg"<<endl;
    cin>>numar;

    BigInt obiect9;
    obiect9=numar;
    cout<<"Numar"<<endl;
    afisare_BigInt(obiect9);

    return 0;
}





