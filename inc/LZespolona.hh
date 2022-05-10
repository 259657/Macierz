#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>



class LZespolona {
  
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  

public :

 double &Re(){return re;}
 double &Im(){return im;}

LZespolona  operator + (LZespolona  Skl2)const;
LZespolona  operator - (LZespolona  Skl2)const;
LZespolona  operator * (LZespolona  Skl2)const;
LZespolona  operator *= (int liczba)const;
LZespolona  operator *= (LZespolona  Skl2)const;
LZespolona  operator -= (LZespolona  Skl2)const;
LZespolona operator / (double mod)const;
LZespolona  operator / ( LZespolona  Skl2)const;
LZespolona Sprzerzenie();
LZespolona &operator = (double liczba);
LZespolona &operator = (int liczba);
double Modul2();
bool operator == (LZespolona Skl2);
bool operator == (double liczba);
bool operator != (double liczba);
void Wyswietl();

};

std::istream& operator >> (std::istream& wejscie, LZespolona& liczba);


std::ostream& operator << (std::ostream& wyjscie, LZespolona liczba);


#endif
