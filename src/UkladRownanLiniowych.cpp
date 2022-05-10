#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
using namespace std;

// template<typename T, int Rozmiar>
// Wektor<T ,Rozmiar> UkladRownanLiniowych<T ,Rozmiar>::Oblicz(UkladRownanLiniowych<T ,Rozmiar> &UklRown){
//  Wektor<T ,Rozmiar> wolne;
//  Macierz<T ,Rozmiar> macierz;
//  double tmp[ROZMIAR+1];

//  wolne = this ->wektor_wyraz_wolnych;
//  //cout<<macierz<<wolne;
//  //macierz = macierz.zamien_kol_wiersz();
//   tmp[ROZMIAR]=UklRown.macierz.wyzG();
//   //cout<<tmp[ROZMIAR]<<endl;
//   for (int i = 0; i < ROZMIAR; ++i) {
//        macierz = this->macierz;
//         macierz = macierz.zamien_kol_z_wektorem(i,UklRown.wektor_wyraz_wolnych);
       
//     tmp[i]=macierz.wyzG();

//     //cout<<tmp[i]<<endl;

    

//     wolne[i]=tmp[i]/tmp[ROZMIAR];
//     }
//   return wolne;
// }





// template<typename T, int Rozmiar>
// istream& operator >> (istream &Strm, UkladRownanLiniowych<T ,Rozmiar> &UklRown) {
//     for (int i = 0; i < ROZMIAR; ++i) {
//         for (int j = 0; j <=ROZMIAR; ++j) {
            
//             if(j==ROZMIAR)
//             {
//                 Strm >> UklRown.wektor_wyraz_wolnych[i];
//             }
//             else
//             Strm >> UklRown.macierz(i,j);
            
//         }
//     }
//     return Strm;
// }
// template<typename T, int Rozmiar>
// ostream& operator << (ostream &Strm,  UkladRownanLiniowych<T ,Rozmiar> &UklRown) {
    
//     Strm <<  "Macierz " << endl;
//     Strm << UklRown.macierz;
//     Strm <<  "Wektor wyrazow wolnych " << endl;
//     Strm << UklRown.wektor_wyraz_wolnych <<endl;

//     return Strm;
// }