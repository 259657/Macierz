#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include "LZespolona.hh"
#include <iostream>

using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename T, int Rozmiar>
class Macierz {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
   T tab[Rozmiar][Rozmiar]; 
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */ 
  
  const T &operator()(int i, int j) const{return tab[i][j];} 
  T &operator()(int i,  int j){return tab[i][j];}

  Macierz<T ,Rozmiar>  operator + (Macierz<T ,Rozmiar>  M);
  Macierz<T ,Rozmiar>  operator - (Macierz<T ,Rozmiar>  M);
  Macierz<T ,Rozmiar>  zamien_kol_wiersz();
  Macierz<T ,Rozmiar>  zamien_wiersze(int i,int j);
  Macierz<T ,Rozmiar>  zamien_kol_z_wektorem(int i,Wektor<T ,Rozmiar>w);
  Macierz<T ,Rozmiar>  zamien_kol(int i,int j);
  Macierz<T ,Rozmiar>  operator * (double liczba);
  T wyzG();
    
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
std::istream& operator >> (std::istream &Strm, Macierz<T ,Rozmiar> &Mac){
    for (int i = 0; i < Rozmiar; ++i) {
        for (int j = 0; j < Rozmiar; ++j) {
            Strm >> Mac(i,j);
        }
    }
    return Strm;
}

template<typename T, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<T ,Rozmiar> &Mac){
 for (int i = 0; i < Rozmiar; ++i) {
     Strm << "[";
        for ( int j=0; j < Rozmiar; ++j) {
            Strm << " " << Mac(i,j) ;
        }
        cout<< " ]"<< endl;
    }
    return Strm;


}

template<typename T, int Rozmiar>
Macierz<T ,Rozmiar>  Macierz<T ,Rozmiar> ::zamien_kol_wiersz(){
    Macierz wynik;

    for(int i = 0 ; i < Rozmiar; ++i ){
        for(int j = 0 ; j < Rozmiar ; ++j){
            wynik.tab[i][j] = this->tab[j][i];
        }
    }
  return wynik;
}

template<typename T, int Rozmiar>
Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::zamien_wiersze(int i, int j){
Macierz<T ,Rozmiar> wynik;
Wektor<T ,Rozmiar> tmp1;

for(int c = 0 ; c < Rozmiar; ++c ){
        for(int d = 0 ; d < Rozmiar; ++d){
            wynik.tab[c][d] = this->tab[c][d];
        }
    }

    for(int a = 0;a < Rozmiar ; ++a)
     {
        tmp1[a]=this->tab[i][a];
     }
    for(int b = 0;b < Rozmiar; ++b)
     {
        wynik.tab[i][b] = this->tab[j][b];
     wynik.tab[j][b] =tmp1[b];
     }

return wynik;

}
template<typename T, int Rozmiar>
Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::zamien_kol_z_wektorem(int i,Wektor<T ,Rozmiar> w){
Macierz<T ,Rozmiar> wynik;

for(int c = 0 ; c < Rozmiar; ++c ){
        for(int d = 0 ; d < Rozmiar ; ++d){
            wynik.tab[c][d] = this->tab[c][d];
        }
    }
    wynik = wynik.zamien_kol_wiersz();
    
    for(int j = 0 ; j < Rozmiar; ++ j){
        wynik.tab[i][j]=w[j];
    }
    
    wynik = wynik.zamien_kol_wiersz();
    

return wynik;
}
template<typename T, int Rozmiar>
Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::zamien_kol(int i,int  j){
Macierz<T ,Rozmiar> wynik;

for(int c = 0 ; c < Rozmiar; ++c ){
        for(int d = 0 ; d < Rozmiar ; ++d){
            wynik.tab[c][d] = this->tab[c][d];
        }
    }
    wynik = wynik.zamien_kol_wiersz();
    
    wynik = wynik.zamien_wiersze(i,j);
    
    wynik = wynik.zamien_kol_wiersz();
    

return wynik;
}

template<typename T, int Rozmiar>
Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::operator + (Macierz<T ,Rozmiar> M){
    Macierz<T ,Rozmiar> wynik;
    
    for(int i = 0 ; i < Rozmiar ; ++i ){
        for(int j = 0 ; j < Rozmiar; ++j){
            wynik.tab[i][j] = this->tab[i][j] + M.tab[i][j];
        }
    }

  return wynik;

}

template<typename T, int Rozmiar>
Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::operator - (Macierz<T ,Rozmiar> M){
    Macierz<T ,Rozmiar> wynik;
    
    for(int i = 0 ; i < Rozmiar; ++i ){
        for(int j = 0 ; j < Rozmiar; ++j){
            wynik.tab[i][j] = this->tab[i][j] - M.tab[i][j];
        }
    }

  return wynik;

}

template<typename T, int Rozmiar>
Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::operator * (double liczba){
Macierz wynik;
      for(int i = 0 ; i < Rozmiar ; ++i ){
        for(int j = 0 ; j < Rozmiar ; ++j){
            wynik.tab[i][j] = this->tab[i][j] * liczba;
        }
    }

  return wynik;


}

template<typename T, int Rozmiar>
T Macierz<T ,Rozmiar>::wyzG(){
T det ;
det = 1.0;
Macierz<T ,Rozmiar> tmp;

 
    for(int i = 0 ; i < Rozmiar; ++i ){
        for(int j= 0 ; j < Rozmiar ; ++j){
            tmp.tab[i][j] = this->tab[i][j];
        }
    }

    for(int i = 0 ; i < Rozmiar ; ++i ){
      if(tmp.tab[i][i] == 0){
          
      for(int j=i+1; j <Rozmiar; ++j) {   
      if(tmp.tab[j][i] != 0){
          
         for(int a = i; a < Rozmiar;++a){
          T zamien = tmp.tab[i][a];
          tmp.tab[i][a] = tmp.tab[j][a];
          tmp.tab[j][a] = zamien;
         }
         det *= (-1);
         
      }
        
      }
    }

      for (int b = i + 1; b < Rozmiar; b++){
           
           T mnoz =  tmp.tab[b][i] / tmp.tab[i][i];
           for(int c = i+1; c < Rozmiar; ++c){
               tmp.tab[b][c] -= mnoz * tmp.tab[i][c];
           }
      }
    }
     for(int d=0;d < Rozmiar; ++d){
         det *= tmp.tab[d][d];
     }
    
     return det;

}

#endif
