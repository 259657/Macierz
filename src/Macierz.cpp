
#include "Macierz.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac){
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            Strm >> Mac(i,j);
        }
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
 for (int i = 0; i < ROZMIAR; ++i) {
     Strm << "[";
        for ( int j=0; j < ROZMIAR; ++j) {
            Strm << " " << Mac(i,j) ;
        }
        cout<< " ]"<< endl;
    }
    return Strm;


}

Macierz Macierz::zamien_kol_wiersz(){
    Macierz wynik;

    for(int i = 0 ; i < ROZMIAR ; ++i ){
        for(int j = 0 ; j < ROZMIAR ; ++j){
            wynik.tab[i][j] = this->tab[j][i];
        }
    }

  return wynik;
}

Macierz Macierz::operator + (Macierz M){
    Macierz wynik;
    //if() musza miec ten sam rozmiar
    for(int i = 0 ; i < ROZMIAR ; ++i ){
        for(int j = 0 ; j < ROZMIAR ; ++j){
            wynik.tab[i][j] = this->tab[i][j] + M.tab[i][j];
        }
    }

  return wynik;

}

Macierz Macierz::operator - (Macierz M){
    Macierz wynik;
    //if() musza miec ten sam rozmiar
    for(int i = 0 ; i < ROZMIAR ; ++i ){
        for(int j = 0 ; j < ROZMIAR ; ++j){
            wynik.tab[i][j] = this->tab[i][j] - M.tab[i][j];
        }
    }

  return wynik;

}

Macierz Macierz::operator * (double liczba){
Macierz wynik;
      for(int i = 0 ; i < ROZMIAR ; ++i ){
        for(int j = 0 ; j < ROZMIAR ; ++j){
            wynik.tab[i][j] = this->tab[i][j] * liczba;
        }
    }

  return wynik;


}
