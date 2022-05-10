#include "LZespolona.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;



LZespolona LZespolona::operator + (LZespolona  Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator - (LZespolona  Skl2)const
{
LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}




LZespolona LZespolona::operator * (LZespolona  Skl2)const
{

LZespolona  Wynik;

  Wynik.re = this->re * Skl2.re + this->im*Skl2.im*(-1);
  Wynik.im = this->im * Skl2.re +this->re*Skl2.im;
  return Wynik;

}

LZespolona  LZespolona::operator *= (int liczba)const{
  LZespolona  Wynik;
  Wynik.re = this->re * liczba;
  Wynik.im = this->im * liczba;
  return Wynik;

}
LZespolona   LZespolona::operator *= (LZespolona  Skl2)const{
  LZespolona  Wynik;
  Wynik = (*this) * Skl2;
  return Wynik;
}
LZespolona   LZespolona::operator -= (LZespolona  Skl2)const{
  LZespolona  Wynik;
  Wynik = (*this) - Skl2;
  return Wynik;
}

LZespolona LZespolona::operator / (double mod)const
{
 LZespolona Wynik;
 Wynik.re = this->re / mod;
 Wynik.im = this->im / mod;
 return Wynik;
}

LZespolona LZespolona::operator / (LZespolona  Skl2)const
{
 LZespolona Wynik;
 double mod;
 mod = Skl2.Modul2();

  if(mod == 0){
    throw domain_error("Nie mozna dzielic przez 0");
    
  }
 Wynik = (*this) * Skl2.Sprzerzenie();
 Wynik = Wynik/mod;
 return Wynik;
}


LZespolona LZespolona::Sprzerzenie(){
 this->im *= -1;
 return (*this);
}


double LZespolona::Modul2(){
  return (pow(this->re,2)+pow(this->im,2));
}

double Modul2(LZespolona liczba){
  return (pow(liczba.Re(),2)+pow(liczba.Im(),2));
}

void LZespolona::Wyswietl(){
cout<<this->re << showpos << this->im << "i"<<endl;
}


LZespolona &LZespolona::operator = (double liczba){
 this -> re = liczba;
 this -> im = 0;
 return *this;
}

LZespolona &LZespolona::operator = (int liczba){
 this -> re = liczba;
 this -> im = 0;
 return *this;
}

std::istream& operator >> (std::istream& wejscie, LZespolona& liczba){
char nawias;
char i;
char naw2;

wejscie>>nawias;
if(wejscie.fail()){ 
  return wejscie;
}
if(nawias != '('){
  wejscie.setstate(ios::failbit);
  return wejscie;
}

wejscie >> liczba.Re();
if(wejscie.fail()){
  return wejscie;
}
wejscie >> liczba.Im();
if(wejscie.fail()){
  return wejscie;
}
wejscie >> i;
if(wejscie.fail()){
  return wejscie;
}
if(i != 'i'){
  wejscie.setstate(ios::failbit);//
  return wejscie;
}
wejscie >> naw2;
if(wejscie.fail()){
  return wejscie;
}
if(naw2 != ')'){
  wejscie.setstate(ios::failbit);
  return wejscie;
}

return wejscie;

}


std::ostream& operator << (std::ostream& wyjscie, LZespolona liczba){
  
  wyjscie <<"(";
  /*if( liczba.im == 1  )
  {

    wyjscie<<noshowpos<<liczba.re<<"+"<<"i"<<")";

  }else if(liczba.im == -1 ){
    wyjscie<<noshowpos<<liczba.re<<"-"<<"i"<<")";;
  }
  else*/
  wyjscie<<noshowpos<<liczba.Re()<<showpos<<liczba.Im()<<"i"<<")";
  return wyjscie;
}
bool LZespolona::operator == (LZespolona Skl2){
  if(this->re == Skl2.re  && this->im == Skl2.im  ){

  return 1;
}
else

return 0;
}


bool LZespolona::operator == (double liczba){
  if(this->re == liczba   ){
  
  return 1;
}
else

return 0;
}

bool LZespolona::operator != (double liczba){
  if(this->re != liczba   ){
  
  return 1;
}
else

return 0;
}
