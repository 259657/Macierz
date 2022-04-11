#include "Wektor.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */




Wektor Wektor::operator+(Wektor v) {
    Wektor wynik;

    for (int i = 0; i < ROZMIAR; ++i) {
        wynik.rozmiar[i] = this->rozmiar[i] + v.rozmiar[i];
    }

    return wynik;
}

Wektor Wektor::operator-(Wektor v){
    Wektor wynik;
    for (int i = 0; i < ROZMIAR; ++i) {
        wynik.rozmiar[i] = this->rozmiar[i] - v.rozmiar[i];
    }

    return wynik;
}




istream &operator>>(std::istream &Strm, Wektor &Wek) {
    for (int i = 0; i < ROZMIAR; ++i)
    {
        Strm >> Wek[i];
    }
    cout << endl;
    return Strm;
}

std::ostream& operator << (std::ostream &Strm,  Wektor  &Wek){
Strm << "[";
for (int i = 0; i < ROZMIAR; ++i)
    {
        Strm <<" "<<Wek[i]<<" "; 
    }
    cout << "]"<< endl;


    return Strm;
}

double Wektor::operator*(Wektor v){
double  wynik = 0;
    for(int i = 0; i < ROZMIAR ; ++i){
        wynik += this->rozmiar[i]  * v.rozmiar[i];


    }
    return wynik;
}