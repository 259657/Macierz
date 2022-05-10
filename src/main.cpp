#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main(int argc, char **argv)
{

  
  UkladRownanLiniowych<double,4>   UklRown;   // To tylko przykladowe definicje zmiennej

 
  cout << endl << " Start programu " << endl << endl;

    if (argc < 2) {
     cerr << endl;
     cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
     cerr << endl;
     return 1;
   }

   ifstream  PlikTestu(argv[1]);

   if (PlikTestu.is_open() == false) { 
     return 1;
   }
   cout << endl;
   cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
   cout << endl;

//  int x= 0; 
// while(x!= 2){
  PlikTestu >> UklRown;
  cout<< UklRown;


  UklRown.Oblicz(UklRown);
  Wektor<double,4>  wynik;
  wynik = UklRown.Oblicz(UklRown);
  cout<<"Odp :" << wynik << endl;
  //++x;
//}
   PlikTestu.close();
   

    LZespolona i;
    cin >> i;

    cout << i ;

    // Wektor<double,ROZMIAR> v;
    // Wektor<double,ROZMIAR> v2;
    // Wektor<double,ROZMIAR> v3;
  


//  cout<<"podaj  wektor"<<endl;
//    cin >> v2;
//    cin >> v;
//    v3 = v - v2;
//    cout << v3;
//   v3 = v+v2;
//   cout<<v3;
//   skalar= v3*v2 ;
//   cout<<skalar<<endl;
// cout<<"podaj macierz "<<endl;

/*
Macierz m;
cin>>m;
double t;

m.wyzG();
 
 cout<<m<<endl;
 */
 //cout<<t;
// m =m.zamien_kol_wiersz();
// cout<<"zamiana kolumn i weirszy"<<endl;
// cout<<m;
// cout<<"podaj  2 macierz "<<endl;
// cin>>m1;
// cout<<m1;
// cout<<"dodane macierze"<<endl;
// dod = m + m1;
// cout<<dod<<endl;
// m = m * 5;// 5 * m 
// cout<<m<<endl;

}
