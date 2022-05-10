#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

using namespace std;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename T, int Rozmiar>
class Wektor { 
   T rozmiar[Rozmiar];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    

Wektor<T ,Rozmiar> operator+(Wektor<T ,Rozmiar> &v);
Wektor<T ,Rozmiar> operator-(Wektor<T ,Rozmiar> v);
Wektor<T ,Rozmiar> operator*(T liczba);
T operator*(Wektor<T ,Rozmiar> v);


const T &operator[](int i)const{return rozmiar[i];}
T &operator[](int i){return rozmiar[i];}


};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template<typename T, int Rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<T ,Rozmiar> &Wek){
    for (int i = 0; i < Rozmiar; ++i)
    {
        Strm >> Wek[i];
    }
    cout << endl;
    return Strm;
}


template<typename T, int Rozmiar>
std::ostream& operator << (std::ostream &Strm,  Wektor<T ,Rozmiar> &Wek){
Strm << "[";
for (int i = 0; i < Rozmiar; ++i)
    {
        Strm <<" "<<Wek[i]<<" "; 
    }
    cout << "]"<< endl;


    return Strm;
}


template<typename T, int Rozmiar>
Wektor<T ,Rozmiar> Wektor<T, Rozmiar>::operator+(Wektor<T ,Rozmiar> &v) {
    Wektor<T, Rozmiar>  wynik;

    for (int i = 0; i < Rozmiar; ++i) {
        wynik.rozmiar[i] = this->rozmiar[i] + v.rozmiar[i];
    }

    return wynik;
}

template<typename T, int Rozmiar>
Wektor<T ,Rozmiar> Wektor<T ,Rozmiar>::operator-(Wektor<T ,Rozmiar>  v){
    Wektor<T , Rozmiar >  wynik;
    for (int i = 0; i < Rozmiar; ++i) {
        wynik.rozmiar[i] = this->rozmiar[i] - v.rozmiar[i];
    }

    return wynik;
}

template<typename T, int Rozmiar>
T Wektor<T ,Rozmiar>::operator*(Wektor<T ,Rozmiar> v){
T wynik = 0;
    for(int i = 0; i < Rozmiar ; ++i){
        wynik += this->rozmiar[i]  * v.rozmiar[i];


    }
    return wynik;
}

template<typename T, int Rozmiar>
Wektor<T ,Rozmiar> Wektor<T ,Rozmiar>::operator*(T liczba){
 Wektor<T ,Rozmiar>  wynik;
    for(int i = 0; i < Rozmiar ; ++i){
        wynik.rozmiar[i] = this-> rozmiar[i] * liczba;
    }
    return wynik;
}





#endif
