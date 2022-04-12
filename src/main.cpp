#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

 
  cout << endl << " Start programu " << endl << endl;
  Wektor v,v2,v3;
  Macierz m,m1,m2,dod;
//   double skalar;
//   cin>>v;
//   cout<<v;
// cout<<"podaj drugi wektor"<<endl;
//   cin>>v2;
//   cout<<v2;
//   v3 = v+v2;
//   cout<<v3;
//   skalar= v3*v2 ;
//   cout<<skalar<<endl;
cout<<"podaj macierz "<<endl;
cin>>m;
cout<<m;

// m =m.zamien_kol_wiersz();
// cout<<"zamiana kolumn i weirszy"<<endl;
// cout<<m;

cout<<"podaj  2 macierz "<<endl;
cin>>m1;
cout<<m1;

cout<<"dodane macierze"<<endl;
dod = m + m1;
cout<<dod<<endl;
m = m * 5;// 5 * m
cout<<m<<endl;
}
