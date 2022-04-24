#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"
#include "Wektor.hh"
using namespace std;


Wektor UkladRownanLiniowych::Oblicz(UkladRownanLiniowych &UklRown){
 Wektor wolne;
 Macierz macierz;
 double tmp[ROZMIAR+1];

 wolne = this ->w;
 //cout<<macierz<<wolne;
 //macierz = macierz.zamien_kol_wiersz();
  tmp[ROZMIAR]=UklRown.M.wyzG();
  cout<<tmp[ROZMIAR]<<endl;
  for (int i = 0; i < ROZMIAR; ++i) {
       macierz = this->M;
        macierz = macierz.zamien_kol_z_wektorem(i,UklRown.w);
       
    tmp[i]=macierz.wyzG();

    cout<<tmp[i]<<endl;

    

    wolne[i]=tmp[i]/tmp[ROZMIAR];
    }
  return wolne;
}






istream& operator >> (istream &Strm, UkladRownanLiniowych &UklRown) {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j <=ROZMIAR; ++j) {
            
            if(j==ROZMIAR)
            {
                Strm >> UklRown.w[i];
            }
            else
            Strm >> UklRown.M(i,j);
            
        }
    }
    return Strm;
}

ostream& operator << (ostream &Strm,  UkladRownanLiniowych &UklRown) {
    
    Strm << endl << endl << "Macierz " << endl;
    Strm << UklRown.M;
    Strm << endl << "Wektor wyrazow wolnych " << endl;
    Strm << UklRown.w <<endl << endl;

    return Strm;
}