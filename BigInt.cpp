#include "BigInt.h"
#include <iostream>
#include <string.h>
using namespace std;
struct Lista
{
    int valoare;
    Lista* next;     //lista dublu inlantuita
    Lista* previous;

};
Lista* getNumere(int n);
//---------------------------------------------------------------------------------
BigInt::BigInt(Lista* inceput, int x, char c1):
    cap(inceput),
    n(x),
    c(c1)                                    //constructorul de parametri cu lista de initializare
{

}
//-----------------------------------------------------
//constructorul fara parametri
BigInt::BigInt()
{

}
//--------------------------------------------
//constructorul de copiere
BigInt::BigInt(const BigInt &obiect1)
{
    n=obiect1.n;
    cap=obiect1.cap;
    c=obiect1.c;
}
//-----------------------------------------------
//operator overloading pe >>
istream& operator>> (istream& is, BigInt& obiect)
{
    char c;
    int n;
    cout<<"Introduceti semnul numarului "<<endl;
    is>>c;
    cout<<"Introduceti numarul de cifre "<<endl;
    is>>n;


    Lista* cap1=getNumere(n);
    obiect.cap=cap1;
    obiect.n=n;
    obiect.c=c;

    return is;
}
//-------------------------------------------------------------------
//operator overloading pe <<
ostream& operator<<(ostream& os, const BigInt& obiect)
{



    Lista* cap=obiect.cap;
    os<<"Numarul va fi"<<endl;
    if(obiect.c=='-')
        os<<obiect.c;
    while(cap!=NULL)
    {
        os<<cap->valoare;
        cap=cap->next;
    }
    return os;
}
char BigInt::getc()
{
    return c;
}
//-----------------------------------------------------------------
//operator overloading pe = pentru atribuirea unui obiect altuia
BigInt BigInt::operator=(const BigInt& obiect1)
{
    cap=obiect1.cap;
    c=obiect1.c;
    n=obiect1.n;
    BigInt obiect(cap, n,c);
    return obiect;
}
//-----------------------------------------------------
//operator overloading pe = pentru a face conversia de la int la obiect
BigInt BigInt:: operator=(long long int numar)
{
    Lista*prim=new Lista;
    prim->next=NULL;
    prim->previous=NULL;
    prim->valoare=0;
    int counter=1;
    char semn;
//BigInt obiect;
    if(numar!=0)
    {
        if (numar>0)
            semn='+';
        else
            semn='-';
        while(numar!=0)
        {
            prim->valoare=numar%10;
            numar=numar/10;
            if(numar!=0)
            {
                prim->previous=new Lista;
                prim->previous->next=prim;
                prim=prim->previous;
                prim->valoare=0;
                counter++;
            }
        }
        BigInt obiect(prim, counter, semn);
        return obiect;
    }
    else if(numar==0)
    {
        semn='+';
        BigInt obiect (prim, counter, semn);
        return obiect;
    }
}
//---------------------------------------------------------------
//operator overloading pe =, pentru a face conversia de la un sir de caractere la obiect
BigInt BigInt::operator=(char* s)
{
    cap=new Lista;//cout<<"Da";
    cap->next=NULL;
    cap->previous=NULL;
    cap->valoare=0;
    Lista *p=cap,*u=cap;
    if(s[0]>='0'&&s[0]<='9')
    {cap->valoare=s[0]-'0';
        for(int i=0; i<strlen(s); i++)
            {
                cap->next=new Lista;
                cap->next->previous=cap;
                cap=cap->next;
                cap->valoare=s[i+1]-'0';

            }
        cap=cap->previous;
        cap->next=NULL;
    }
    else
    {
        if(s[0]=='+')
            c='+';
        else c='-';
        cap->valoare=s[1]-'0';
        for(int i=1; i<strlen(s); i++)
            {
                cap->next=new Lista;
                cap->next->previous=cap;
                cap=cap->next;
                cap->valoare=s[i+1]-'0';

            }
            cap=cap->previous;
            cap->next=NULL;
    }
    n=strlen(s)-1;
    cap=p;
    return *this;
}
/*BigInt BigInt::operator=(char* sir)
{
    Lista*prim=new Lista;
    prim->next=NULL;
    prim->previous=NULL;
    prim->valoare=0;
    int counter=1;
    char semn;
    int i;
//BigInt obiect;
    int lungime=strlen(sir);
    if((sir[0]=='-')||(sir[0]=='+'))
    {
        semn=sir[0];
        counter=lungime-1;
        prim->valoare=sir[1];
        if(lungime>2)
        {
            for(i=2; i<lungime; i++)
            {
                prim->next=new Lista;
                prim->next->previous=prim;
                prim=prim->next;
                prim->valoare=sir[i]-'0';

            }

        }
        while(prim->previous!=NULL)
            prim=prim->previous;
        BigInt obiect(prim, counter, semn);
        return obiect;
    }
    else
    {
        semn='+';
        counter=lungime;
        prim->valoare=sir[0];
        if(lungime>1)
        {
            for(i=1; i<lungime; i++)
            {
                prim->next=new Lista;
                prim->next->previous=prim;
                prim=prim->next;
                prim->valoare=sir[i]-'0';

            }

        }
        while(prim->previous!=NULL)
            prim=prim->previous;


    }

    BigInt obiect(prim, counter, semn);
    return obiect;
}
*/

void inserare_sfarsit(int x, Lista* &cap);
Lista* getNumere(int n);
void afisare_BigInt(BigInt obiect);
//------------------------------------------------------------------
// functie care creeaza lista de cifre in dependenta de valorile introduse
Lista* getNumere(int n)
{
    int i, j;
    /*cout<<"Introduceti cate cifre va contine numarul"<<endl;
    cin>>n;*/
    cout<<"Introduceti cifrele, cu spatiu"<<endl;
    cin>>j;
    Lista* cap=new Lista;
    cap->valoare=j;
    cap->next=NULL;               //initializam capul listei cu prima cifra primita
    cap->previous=NULL;

//BigInt obiect(j);

    for (i=1; i<n; i++)
    {
        cin>>j;
        inserare_sfarsit(j, cap);
    }
    return cap;
}
//--------------------------------------
// se insereaza cate un element in lista
void inserare_sfarsit(int x, Lista* &cap)
{
    Lista *elem=new Lista;
    elem->valoare=x;
    elem->next=NULL;
    elem->previous=NULL;
    if (cap==NULL)
        cap=elem;
    else
    {
        Lista *ptr=cap;
        while(ptr->next!=NULL)
            ptr=ptr->next;

        ptr->next=elem;
        elem->previous=ptr;
    }

}
//--------------------------------------------
//functie ce afiseaza numarul primind ca parametru un obiect
void afisare_BigInt(BigInt obiect)
{
    Lista* cap=obiect.cap;
    cout<<"Numarul va fi"<<endl;
    if(obiect.c=='-')
        cout<<obiect.c;
    while(cap!=NULL)
    {
        cout<<cap->valoare;
        cap=cap->next;
    }
}
//--------------------------------------------------------------------
// functie ce efectueaza suma a doua numere aflate in listele celor 2 obiecte
BigInt operator+(BigInt obiect1, BigInt obiect2)
{
    char c1, c2, c3;
    c1=obiect1.c;
    c2=obiect2.c;
    Lista* ultim1=obiect1.cap;
    Lista* ultim2=obiect2.cap;
    while(ultim1->next!=NULL)       //parcurgerea primei liste pana la ultimul element
    {
        ultim1=ultim1->next;
    }

    while(ultim2->next!=NULL)       //parcurgerea listei a doua pana la ultimul element
    {
        ultim2=ultim2->next;
    }

    int counter=1;
    Lista* ultim3=new Lista;
    ultim3->valoare=0;
    ultim3->next=NULL;
    ultim3->previous=NULL;
    int y=0, i, x, k, l;

    k=ultim1->valoare;
    l=ultim2->valoare;
    int Max=max(obiect1.n, obiect2.n);
//cout<<Max<<endl;

    if(c1==c2)          //cazul cand ambele sunt fie pozitive, fie negative (se calculeaza suma modulelor lor si se scrie semnul dupa caz)
    {
        for(i=0; i<Max; i++)
        {
            x=k+l;

            if((x+y)<10)
            {
                ultim3->valoare=x+y;
                y=0;
            }
            else
            {
                ultim3->valoare=x+y-10;
                y=1;
            }

            if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
            {
                counter++;
                ultim3->previous=new Lista;
                ultim3->previous->next=ultim3;

                ultim3=ultim3->previous;
                ultim3->previous=NULL;
            }
//else break;


            if(ultim1->previous!=NULL)
            {
                ultim1=ultim1->previous;
                k=ultim1->valoare;
            }
            else
                k=0;
            if(ultim2->previous!=NULL)
            {
                ultim2=ultim2->previous;
                l=ultim2->valoare;
            }
            else
                l=0;

        }
        if (y!=0)
        {
            counter++;
            ultim3->previous=new Lista;
            ultim3->previous->next=ultim3;

            ultim3=ultim3->previous;
            ultim3->previous=NULL;
            ultim3->valoare=y;
        }
        if(c1=='-')
            c3='-';
        else
            c3='+';
    }

//if((c2=='-')&&(obiect1.n>obiect2.n))
//--------------------------------------
//cazul cand semnele sunt diferite (se efectueaza diferenta din modulul nr mai mare minus modulul numarului mai mic)
//daca numarul 1 are mai multe cifre, el e mai mare
    else if(obiect1.n>obiect2.n)

    {


        for(i=0; i<Max; i++)
        {
            x=k-l;
            if(x+y>=0)
            {
                ultim3->valoare=x+y;
                y=0;
            }
            else
            {
                ultim3->valoare=x+y+10;
                y=-1;
            }

            if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
            {
                ultim3->previous=new Lista;
                counter++;
                ultim3->previous->next=ultim3;
                ultim3=ultim3->previous;
                ultim3->previous=NULL;

            }


            if(ultim1->previous!=NULL)
            {
                ultim1=ultim1->previous;
                k=ultim1->valoare;
            }
            else
                k=0;
            if(ultim2->previous!=NULL)
            {
                ultim2=ultim2->previous;
                l=ultim2->valoare;
            }
            else
                l=0;

        }

        if(obiect1.c=='+')
            c3='+';
        else
            c3='-';
    }
//numarul 2 are mai multe cifre, deci e mai mare
    else if(obiect2.n>obiect1.n)
    {
        for(i=0; i<Max; i++)
        {
            x=l-k;
            if(x+y>=0)
            {
                ultim3->valoare=x+y;
                y=0;
            }
            else
            {
                ultim3->valoare=x+y+10;
                y=-1;
            }

            if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
            {
                ultim3->previous=new Lista;
                counter++;
                ultim3->previous->next=ultim3;
                ultim3=ultim3->previous;
                ultim3->previous=NULL;

            }


            if(ultim1->previous!=NULL)
            {
                ultim1=ultim1->previous;
                k=ultim1->valoare;
            }
            else
                k=0;
            if(ultim2->previous!=NULL)
            {
                ultim2=ultim2->previous;
                l=ultim2->valoare;
            }
            else
                l=0;




        }

        if(obiect2.c=='-')
            c3='-';
        else
            c3='+';

    }
    //au acelasi numar de cifre, deci parcurgem lista pana ajungem la valori diferite pe aceeasi pozitie,
    //si scadem din numarul mai mare pe cel mai mic, si scriem semnul dupa caz
    else if(obiect1.n==obiect2.n)
    {
        Lista* val1=obiect1.cap;
        Lista* val2=obiect2.cap;
        while((val1->valoare==val2->valoare)&&(val1->next!=NULL)&&(val2->next!=NULL))
        {
            val1=val1->next;
            val2=val2->next;
        }
        if(val1->valoare>=val2->valoare)
        {
            for(i=0; i<Max; i++)
            {
                x=k-l;
                if(x+y>=0)
                {
                    ultim3->valoare=x+y;
                    y=0;
                }
                else
                {
                    ultim3->valoare=x+y+10;
                    y=-1;
                }

                if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
                {
                    ultim3->previous=new Lista;
                    counter++;
                    ultim3->previous->next=ultim3;
                    ultim3=ultim3->previous;
                    ultim3->previous=NULL;

                }


                if(ultim1->previous!=NULL)
                {
                    ultim1=ultim1->previous;
                    k=ultim1->valoare;
                }
                else
                    k=0;
                if(ultim2->previous!=NULL)
                {
                    ultim2=ultim2->previous;
                    l=ultim2->valoare;
                }
                else
                    l=0;


            }

            if(c1=='+')
                c3='+';
            else
                c3='-';
        }
        else if(val2->valoare>val1->valoare)    //val2>val1
        {
            for(i=0; i<Max; i++)
            {
                x=l-k;
                if(x+y>=0)
                {
                    ultim3->valoare=x+y;
                    y=0;
                }
                else
                {
                    ultim3->valoare=x+y+10;
                    y=-1;
                }

                if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
                {
                    ultim3->previous=new Lista;
                    counter++;
                    ultim3->previous->next=ultim3;
                    ultim3=ultim3->previous;
                    ultim3->previous=NULL;

                }


                if(ultim1->previous!=NULL)
                {
                    ultim1=ultim1->previous;
                    k=ultim1->valoare;
                }
                else
                    k=0;
                if(ultim2->previous!=NULL)
                {
                    ultim2=ultim2->previous;
                    l=ultim2->valoare;
                }
                else
                    l=0;


            }
            if(c2=='-')
                c3='-';
            else
                c3='+';
        }


    }

    if ((ultim3->valoare==0)&&(ultim3->next!=NULL))
    {
        ultim3=ultim3->next;
        counter--;
    }
    if ((ultim3->valoare==0)&&(ultim3->next==NULL)&&(ultim3->previous==NULL))
    {
        c3='+';
    }

    BigInt obiect3(ultim3, counter, c3);

    return obiect3;

}
//-----------------------------------------------------------------
//operator overloading pe -
//se bazeaza pe cazuri ;la fel ca adunarea si utilizeaza codul din operator overloading pe adunare
BigInt operator-(BigInt obiect1, BigInt obiect2)
{
    char c1, c2, c4;
    c1=obiect1.c;
    c2=obiect2.c;
    Lista*ultim1=obiect1.cap;
    Lista*ultim2=obiect2.cap;

    while(ultim1->next!=NULL)       //parcurgerea primei liste pana la ultimul element
    {
        ultim1=ultim1->next;
    }

    while(ultim2->next!=NULL)       //parcurgerea listei a doua pana la ultimul element
    {
        ultim2=ultim2->next;
    }

    Lista*ultim4=new Lista;
    ultim4->next=NULL;
    ultim4->previous=NULL;
    ultim4->valoare=0;
    int i, Max=max(obiect1.n, obiect2.n);
    int y=0, k, l, x, counter=1;

    k=ultim1->valoare;
    l=ultim2->valoare;


    if((c1=='+')&&(c2=='-'))
    {
        for(i=0; i<Max; i++)
        {
            x=k+l;

            if((x+y)<10)
            {
                ultim4->valoare=x+y;
                y=0;
            }
            else
            {
                ultim4->valoare=x+y-10;
                y=1;
            }

            if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
            {
                counter++;
                ultim4->previous=new Lista;
                ultim4->previous->next=ultim4;

                ultim4=ultim4->previous;
                ultim4->previous=NULL;
            }



            if(ultim1->previous!=NULL)
            {
                ultim1=ultim1->previous;
                k=ultim1->valoare;
            }
            else
                k=0;
            if(ultim2->previous!=NULL)
            {
                ultim2=ultim2->previous;
                l=ultim2->valoare;
            }
            else
                l=0;

        }
        if (y!=0)
        {
            counter++;
            ultim4->previous=new Lista;
            ultim4->previous->next=ultim4;

            ultim4=ultim4->previous;
            ultim4->previous=NULL;
            ultim4->valoare=y;
        }

        c4='+';
    }


    else if((c1=='-')&&(c2=='+'))
    {
        for(i=0; i<Max; i++)
        {
            x=k+l;

            if((x+y)<10)
            {
                ultim4->valoare=x+y;
                y=0;
            }
            else
            {
                ultim4->valoare=x+y-10;
                y=1;
            }

            if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
            {
                counter++;
                ultim4->previous=new Lista;
                ultim4->previous->next=ultim4;

                ultim4=ultim4->previous;
                ultim4->previous=NULL;
            }


            if(ultim1->previous!=NULL)
            {
                ultim1=ultim1->previous;
                k=ultim1->valoare;
            }
            else
                k=0;
            if(ultim2->previous!=NULL)
            {
                ultim2=ultim2->previous;
                l=ultim2->valoare;
            }
            else
                l=0;

        }
        if (y!=0)
        {
            counter++;
            ultim4->previous=new Lista;
            ultim4->previous->next=ultim4;

            ultim4=ultim4->previous;
            ultim4->previous=NULL;
            ultim4->valoare=y;
        }

        c4='-';
    }
    else if(c1==c2)
    {
        if(obiect1.n>obiect2.n)
        {
            for(i=0; i<Max; i++)
            {
                x=k-l;
                if(x+y>=0)
                {
                    ultim4->valoare=x+y;
                    y=0;
                }
                else
                {
                    ultim4->valoare=x+y+10;
                    y=-1;
                }

                if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
                {
                    ultim4->previous=new Lista;
                    counter++;
                    ultim4->previous->next=ultim4;
                    ultim4=ultim4->previous;
                    ultim4->previous=NULL;

                }


                if(ultim1->previous!=NULL)
                {
                    ultim1=ultim1->previous;
                    k=ultim1->valoare;
                }
                else
                    k=0;
                if(ultim2->previous!=NULL)
                {
                    ultim2=ultim2->previous;
                    l=ultim2->valoare;
                }
                else
                    l=0;




            }

            if(c1=='+')
                c4='+';
            else
                c4='-';
        }

        else if(obiect2.n>obiect1.n)
        {
            for(i=0; i<Max; i++)
            {
                x=l-k;
                if(x+y>=0)
                {
                    ultim4->valoare=x+y;
                    y=0;
                }
                else
                {
                    ultim4->valoare=x+y+10;
                    y=-1;
                }

                if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
                {
                    ultim4->previous=new Lista;
                    counter++;
                    ultim4->previous->next=ultim4;
                    ultim4=ultim4->previous;
                    ultim4->previous=NULL;

                }


                if(ultim1->previous!=NULL)
                {
                    ultim1=ultim1->previous;
                    k=ultim1->valoare;
                }
                else
                    k=0;
                if(ultim2->previous!=NULL)
                {
                    ultim2=ultim2->previous;
                    l=ultim2->valoare;
                }
                else
                    l=0;




            }

            if(c2=='-')
                c4='+';
            else
                c4='-';

        }
        else if(obiect1.n==obiect2.n)
        {
            Lista* val1=obiect1.cap;
            Lista* val2=obiect2.cap;
            while((val1->valoare==val2->valoare)&&(val1->next!=NULL)&&(val2->next!=NULL))
            {
                val1=val1->next;
                val2=val2->next;
            }
            if(val1->valoare>=val2->valoare)
            {
                for(i=0; i<Max; i++)
                {
                    x=k-l;
                    if(x+y>=0)
                    {
                        ultim4->valoare=x+y;
                        y=0;
                    }
                    else
                    {
                        ultim4->valoare=x+y+10;
                        y=-1;
                    }

                    if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
                    {
                        ultim4->previous=new Lista;
                        counter++;
                        ultim4->previous->next=ultim4;
                        ultim4=ultim4->previous;
                        ultim4->previous=NULL;

                    }


                    if(ultim1->previous!=NULL)
                    {
                        ultim1=ultim1->previous;
                        k=ultim1->valoare;
                    }
                    else
                        k=0;
                    if(ultim2->previous!=NULL)
                    {
                        ultim2=ultim2->previous;
                        l=ultim2->valoare;
                    }
                    else
                        l=0;


                }

                if(c1=='+')
                    c4='+';
                else
                    c4='-';
            }
            else if(val2->valoare>val1->valoare)    //val2>val1
            {
                for(i=0; i<Max; i++)
                {
                    x=l-k;
                    if(x+y>=0)
                    {
                        ultim4->valoare=x+y;
                        y=0;
                    }
                    else
                    {
                        ultim4->valoare=x+y+10;
                        y=-1;
                    }

                    if((ultim2->previous!=NULL)||(ultim1->previous!=NULL))
                    {
                        ultim4->previous=new Lista;
                        counter++;
                        ultim4->previous->next=ultim4;
                        ultim4=ultim4->previous;
                        ultim4->previous=NULL;

                    }


                    if(ultim1->previous!=NULL)
                    {
                        ultim1=ultim1->previous;
                        k=ultim1->valoare;
                    }
                    else
                        k=0;
                    if(ultim2->previous!=NULL)
                    {
                        ultim2=ultim2->previous;
                        l=ultim2->valoare;
                    }
                    else
                        l=0;


                }
                if(c2=='-')
                    c4='+';
                else
                    c4='-';
            }

        }
    }

    while ((ultim4->valoare==0)&&(ultim4->next!=NULL))
    {
        ultim4=ultim4->next;
        counter--;
    }
    if ((ultim4->valoare==0)&&(ultim4->next==NULL)&&(ultim4->previous==NULL))
    {
        c4='+';
    }

    BigInt obiect4(ultim4, counter, c4);
    return obiect4;
}
//---------------------------------
//operator overloading pe *
BigInt operator*(BigInt obiect1, BigInt obiect2)
{
    char c1, c2, c5;
    c1=obiect1.c;
    c2=obiect2.c;
    Lista*ultim1=obiect1.cap;
    Lista*ultim2=obiect2.cap;
    if(c1==c2)
        c5='+';
    else
        c5='-';

    while(ultim1->next!=NULL)       //parcurgerea primei liste pana la ultimul element
    {
        ultim1=ultim1->next;
    }

    while(ultim2->next!=NULL)       //parcurgerea listei a doua pana la ultimul element
    {
        ultim2=ultim2->next;
    }
    int x, l, k, i, j, Max=0, y=0, z=0;
    k=ultim1->valoare;
    l=ultim2->valoare;

    int n1=obiect1.n, n2=obiect2.n;
   //ina se vor retine numerele obtinute la inmultirea, cifra cu cifra, a primului numar cu al doilea, care urmeaza a fi adunate
   //cifrele din a sunt retinute in revers, deci vor fi adunate in lista invers
    int**a=new int*[n2];
    for(i=0; i<n2; i++)    //alocare dinamica
        a[i]=new int[n1+1];


    for(i=0; i<n2; i++)
        for(j=0; j<n1+1; j++)
            a[i][j]=0;


    for(i=0; i<n2; i++)

    {
        for(j=0; j<n1; j++)

        {
            x=k*l;
            if((x+y)>=10)
            {
                a[i][j]=(x+y)%10;
                y=(y+x)/10;
            }
            else
            {
                a[i][j]=x+y;
                y=0;
            }
            if(ultim1->previous!=NULL)
            {
                ultim1=ultim1->previous;
                k=ultim1->valoare;
            }
            else
                break;

        }
        if(y!=0)   //a[i][n2]=new int;
        {
            a[i][j+1]=y;
            y=0;
        }

        if(ultim2->previous!=NULL)
        {
            ultim2=ultim2->previous;
            l=ultim2->valoare;
            // cout<<l<<endl;
            while(ultim1->next!=NULL)
            {
                ultim1=ultim1->next;
                k=ultim1->valoare;
            }
        }



    }

    for(i=0; i<n2; i++)
    {
        for(j=0; j<n1+1; j++)
            cout<<a[i][j]<<" ";
        cout<<endl<<endl;
    }


    Lista* ultim5=new Lista;
    ultim5->valoare=0;
    ultim5->next=NULL;
    ultim5->previous=NULL;
    int counter=1;

    int Max2=n1;
    for(i=0; i<n2; i++)
        Max2=Max2+1;


    cout<<Max2<<endl<<endl;
    y=0;

    for(i=0; i<Max2; i++)
    {
        counter++;
        ultim5->next=new Lista;
        ultim5->next->previous=ultim5;
        ultim5=ultim5->next;                    //initializam lista cu valori de 0, la care vor fi adunate cifrele din a
        ultim5->next=NULL;
        ultim5->valoare=0;
    }


    for(i=0; i<n2; i++)
    {
        for(j=0; j<n1+1; j++)
        {
            x=ultim5->valoare+a[i][j];
            if((x+y)<10)
            {
                ultim5->valoare=x+y;
                y=0;
            }
            else if((x+y)>=10)
            {
                ultim5->valoare=(x+y)%10;
                y=(x+y)/10;
                //cout<<"y este "<<y<<endl<<endl;


            }
            ultim5=ultim5->previous;


        }
        if(y!=0)
        {

            if((ultim5->valoare+y)<10)
            {
                ultim5->valoare=ultim5->valoare+y;
                y=0;
            }
            else
            {
                x=ultim5->valoare;
                ultim5->valoare=(x+y)%10;
                y=(x+y)/10;
                ultim5=ultim5->previous;
                ultim5->valoare=ultim5->valoare+y;
            }
        }
        for(int q=0; q<n1; q++)
            ultim5=ultim5->next;
                //mutam la penultimul element
    }


    while(ultim5->previous!=NULL)
        ultim5=ultim5->previous;

    while(ultim5->valoare==0)
    {
        ultim5=ultim5->next;
        counter--;
    }
    for(i=0; i<n2; i++)
        delete [] a[i];   //dezalocarea lui a

    delete [] a;

    BigInt obiect5(ultim5, counter, c5);
    return obiect5;
}
//--------------------------------------
//operator overloading pe >>
BigInt operator>>(BigInt, BigInt)
{
    cout<<"Introduceti semnul numarului"<<endl;
    char semn;
    cin>>semn;
    cout<<"Introduceti numarul de cifre"<<endl;
    int n;
    cin>>n;

    Lista* cap1=getNumere(n);       //creeaza lista

    BigInt obiect1(cap1, n, semn);
    return obiect1;

}
//--------------------------------------
//operator overloading pe /
//cheama repetitiv functia de operator overloading pe - pana obiect1 ajunge la 0
BigInt operator/(BigInt obiect1, BigInt obiect2)
{
    BigInt obiect=obiect1;
 char c;
   long long int counter=0;
if(obiect1.c==obiect2.c) c='+'; else c='-';
obiect1.c='+';   //facem scaderea pentru 2 numere pozitive
obiect2.c='+';
    while(obiect.c=='+')
    {
        obiect=obiect-obiect2;

        counter++;



    }



    BigInt obiect3;
    obiect3=counter;
    obiect3.c=c;                 //conversia de la int la obiect prin operator overloading =
    return obiect3;


}
//--------------------------------------
//aflam daca e palindrom, utilizand 2 vectori in care retinem numarul odata asa cum e el, a doua data invers
void palindrom(BigInt obiect)
{
    int n=obiect.n;
    int i;
    Lista*ptr=obiect.cap;
    int*aux1=new int[n];
    int*aux2=new int[n];
    for(i=0; i<n; i++)
    {
        aux1[i]=ptr->valoare;
        if(ptr->next!=NULL)
            ptr=ptr->next;
    }
    for(i=0; i<n; i++)
    {
        aux2[i]=ptr->valoare;
        if(ptr->previous!=NULL)
            ptr=ptr->previous;
    }
    int counter=0;
    for(i=0; i<n; i++)
        if(aux1[i]==aux2[i])
            counter++;
    if(counter==n)
        cout<<"Numarul este palindrom"<<endl;
    else
        cout<<"Numarul nu este palindrom"<<endl;

    delete [] aux1;
    delete [] aux2;
}
//-------------------------------------------
//se calculeaza paritatea in dependenta de ulltima valoare din lista%2
void paritate(BigInt obiect)
{
    Lista*ultim=obiect.cap;
    while(ultim->next!=NULL)
        ultim=ultim->next;
    if((ultim->valoare%2)==0)
        cout<<"Numarul este par"<<endl;
    else
        cout<<"Numarul este impar"<<endl;
}
//----------------------------------------
//se ridica la putere prin intermediul functiei de op overloading pe *
BigInt ridicare_la_putere(BigInt obiect, int m)
{
    if(m==0)
    {
        Lista*cap=new Lista;
        cap->valoare=1;
        cap->next=NULL;
        cap->previous=NULL;
        BigInt obiect1(cap, 1, '+' );
        return obiect1;
    }
    if (m==1)
        return obiect;

    int i;
    BigInt obiect2=obiect;
    for(i=2; i<=m; i++)
    {
        obiect2=obiect2*obiect;
    }
    return obiect2;
}
//------------------------------
//se parcurge lista adunand elementele
long long int suma_cifrelor(BigInt obiect)
{
    long long int k=0;
    Lista*prim=obiect.cap;
    int n=obiect.n;
    for(int i=0; i<n; i++)
    {
        k=k+prim->valoare;
        prim=prim->next;

    }
    return k;
}
BigInt::~BigInt()
{ n=0;
c=0;

    Lista*urmator;
    while(cap!=NULL)
    {
        urmator=cap->next;
        delete cap;
        cap=urmator;
    }


}
