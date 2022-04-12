#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>
// schemat
//zarys klasy


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
   double tab[ROZMIAR][ROZMIAR];
   //lub wektor wektorow Wketor tab[ROZMIAR] jeszcze nwm
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */ 
  const double &operator()(int i, int j) const{return tab[i][j];} 
  double &operator()(int i,  int j){return tab[i][j];}

  Macierz operator + (Macierz M);
  Macierz operator - (Macierz M);
  Macierz zamien_kol_wiersz();
  Macierz operator * (double liczba);

  
  //zamianawiersza/kolumy
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
