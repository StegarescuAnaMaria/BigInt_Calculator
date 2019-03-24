#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>

using namespace std;
class BigInt
{
    public:
        BigInt(struct Lista*, int, char);
        BigInt();
       friend BigInt operator+(BigInt obiect1, BigInt obiect2);
friend void afisare_BigInt(BigInt obiect);
friend BigInt operator-(BigInt obiect1, BigInt obiect2);
friend BigInt operator*(BigInt obiect1, BigInt obiect2);
BigInt(const BigInt &);
friend BigInt operator/(BigInt obiect1, BigInt obiect2);
friend void palindrom(BigInt obiect);
friend void paritate(BigInt obiect);
friend BigInt ridicare_la_putere(BigInt obiect, int m);
friend long long int suma_cifrelor(BigInt);
char getc();
BigInt operator=(long long int numar);
BigInt operator=(char* sir);
BigInt operator=(const BigInt& obiect1);
friend istream& operator>> (istream& is, BigInt& obiect);
friend ostream& operator<<(ostream& os, const BigInt& obiect);
~BigInt();

    protected:

    private:
        char c;
        struct Lista* cap;      //pointer catre capul listei
        int n;     //nr elemente pe care il contine lista
};

#endif // BIGINT_H
