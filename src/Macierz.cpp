
#include "Macierz.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
// template<typename T, int Rozmiar>
// std::istream& operator >> (std::istream &Strm, Macierz<T ,Rozmiar> &Mac){
//     for (int i = 0; i < ROZMIAR; ++i) {
//         for (int j = 0; j < ROZMIAR; ++j) {
//             Strm >> Mac(i,j);
//         }
//     }
//     return Strm;
// }
// template<typename T, int Rozmiar>
// std::ostream& operator << (std::ostream &Strm, const Macierz<T ,Rozmiar> &Mac){
//  for (int i = 0; i < ROZMIAR; ++i) {
//      Strm << "[";
//         for ( int j=0; j < ROZMIAR; ++j) {
//             Strm << " " << Mac(i,j) ;
//         }
//         cout<< " ]"<< endl;
//     }
//     return Strm;


// }
// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar>  Macierz<T ,Rozmiar> ::zamien_kol_wiersz(){
//     Macierz wynik;

//     for(int i = 0 ; i < ROZMIAR ; ++i ){
//         for(int j = 0 ; j < ROZMIAR ; ++j){
//             wynik.tab[i][j] = this->tab[j][i];
//         }
//     }

//   return wynik;
// }

// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::zamien_wiersze(int i, int j){
// Macierz<T ,Rozmiar> wynik;
// Wektor<T ,Rozmiar> tmp1;
// for(int c = 0 ; c < ROZMIAR ; ++c ){
//         for(int d = 0 ; d < ROZMIAR ; ++d){
//             wynik.tab[c][d] = this->tab[c][d];
//         }
//     }

// for(int a = 0;a < ROZMIAR ; ++a)
// {
//     tmp1[a]=this->tab[i][a];
// }
// for(int b = 0;b < ROZMIAR ; ++b)
// {
//     wynik.tab[i][b] = this->tab[j][b];
//     wynik.tab[j][b] =tmp1[b];
// }

// return wynik;

// }
// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::zamien_kol_z_wektorem(int i,Wektor<T ,Rozmiar> w){
// Macierz wynik;

// for(int c = 0 ; c < ROZMIAR ; ++c ){
//         for(int d = 0 ; d < ROZMIAR ; ++d){
//             wynik.tab[c][d] = this->tab[c][d];
//         }
//     }
//     wynik = wynik.zamien_kol_wiersz();
    
//     for(int j = 0 ; j < ROZMIAR; ++ j){
//         wynik.tab[i][j]=w[j];
//     }
    
//     wynik = wynik.zamien_kol_wiersz();
    

// return wynik;
// }
// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::zamien_kol(int i,int  j){
// Macierz wynik;

// for(int c = 0 ; c < ROZMIAR ; ++c ){
//         for(int d = 0 ; d < ROZMIAR ; ++d){
//             wynik.tab[c][d] = this->tab[c][d];
//         }
//     }
//     wynik = wynik.zamien_kol_wiersz();
    
//     wynik = wynik.zamien_wiersze(i,j);
    
//     wynik = wynik.zamien_kol_wiersz();
    

// return wynik;
// }

// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::operator + (Macierz<T ,Rozmiar> M){
//     Macierz wynik;
    
//     for(int i = 0 ; i < ROZMIAR ; ++i ){
//         for(int j = 0 ; j < ROZMIAR ; ++j){
//             wynik.tab[i][j] = this->tab[i][j] + M.tab[i][j];
//         }
//     }

//   return wynik;

// }

// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::operator - (Macierz<T ,Rozmiar> M){
//     Macierz wynik;
//     //if() musza miec ten sam rozmiar
//     for(int i = 0 ; i < ROZMIAR ; ++i ){
//         for(int j = 0 ; j < ROZMIAR ; ++j){
//             wynik.tab[i][j] = this->tab[i][j] - M.tab[i][j];
//         }
//     }

//   return wynik;

// }

// template<typename T, int Rozmiar>
// Macierz<T ,Rozmiar> Macierz<T ,Rozmiar>::operator * (double liczba){
// Macierz wynik;
//       for(int i = 0 ; i < ROZMIAR ; ++i ){
//         for(int j = 0 ; j < ROZMIAR ; ++j){
//             wynik.tab[i][j] = this->tab[i][j] * liczba;
//         }
//     }

//   return wynik;


// }

// template<typename T, int Rozmiar>
// T Macierz<T ,Rozmiar>::wyzG(){
// double det = 1;
// Macierz tmp;

 
//     for(int i = 0 ; i < ROZMIAR ; ++i ){
//         for(int j= 0 ; j < ROZMIAR ; ++j){
//             tmp.tab[i][j] = this->tab[i][j];
//         }
//     }

//     for(int i = 0 ; i < ROZMIAR ; ++i ){
//       if(tmp.tab[i][i] == 0){
          
//       for(int j=i+1; j <ROZMIAR; ++j) {   
//       if(tmp.tab[j][i] != 0){
          
//          for(int a = i; a < ROZMIAR;++a){
//           double zamien = tmp.tab[i][a];
//           tmp.tab[i][a] = tmp.tab[j][a];
//           tmp.tab[j][a] = zamien;
//          }
//          det *= (-1);
         
//       }
        
//       }
//     }

//       for (int b = i + 1; b < ROZMIAR; b++){
           
//            double mnoz =  tmp.tab[b][i] / tmp.tab[i][i];
//            for(int c = i+1; c < ROZMIAR; ++c){
//                tmp.tab[b][c] -= mnoz * tmp.tab[i][c];
//            }
//       }
//     }
//      for(int d=0;d < ROZMIAR; ++d){
//          det *= tmp.tab[d][d];
//      }
//     // cout<<det<<endl;
//      return det;

// }
