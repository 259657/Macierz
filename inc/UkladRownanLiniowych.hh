#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"

using namespace std;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename T, int Rozmiar>
class UkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  Macierz<T ,Rozmiar> macierz;
  Wektor<T ,Rozmiar> wektor_wyraz_wolnych;
  Wektor<T ,Rozmiar> Oblicz(UkladRownanLiniowych &UklRown);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
// /*
//  * To przeciazenie trzeba opisac. Co ono robi. Jaki format
//  * danych akceptuje. Jakie jest znaczenie parametrow itd.
//  * Szczegoly dotyczace zalecen realizacji opisow mozna
//  * znalezc w pliku:
//  *    ~bk/edu/kpo/zalecenia.txt 
//  */
template<typename T, int Rozmiar>
Wektor<T ,Rozmiar> UkladRownanLiniowych<T ,Rozmiar>::Oblicz(UkladRownanLiniowych<T ,Rozmiar> &UklRown){
 Wektor<T ,Rozmiar> wolne;
 Macierz<T ,Rozmiar> macierz;
 T tmp[Rozmiar+1];

 wolne = this ->wektor_wyraz_wolnych;
 
  tmp[Rozmiar]=UklRown.macierz.wyzG();
  
  for (int i = 0; i < Rozmiar; ++i) {
       macierz = this->macierz;
        macierz = macierz.zamien_kol_z_wektorem(i,UklRown.wektor_wyraz_wolnych);
       
    tmp[i]=macierz.wyzG();

    wolne[i]=tmp[i]/tmp[Rozmiar];
    }
  return wolne;
}



template<typename T, int Rozmiar>
istream& operator >> (istream &Strm, UkladRownanLiniowych<T ,Rozmiar> &UklRown) {
    for (int i = 0; i < Rozmiar; ++i) {
        for (int j = 0; j <=Rozmiar; ++j) {
            
            if(j==Rozmiar)
            {
                Strm >> UklRown.wektor_wyraz_wolnych[i];
            }
            else
            Strm >> UklRown.macierz(i,j);
            
        }
    }
    return Strm;
}
template<typename T, int Rozmiar>
ostream& operator << (ostream &Strm,  UkladRownanLiniowych<T ,Rozmiar> &UklRown) {
    
    Strm <<  "Macierz " << endl;
    Strm << UklRown.macierz;
    Strm <<  "Wektor wyrazow wolnych " << endl;
    Strm << UklRown.wektor_wyraz_wolnych <<endl;

    return Strm;
}


#endif
