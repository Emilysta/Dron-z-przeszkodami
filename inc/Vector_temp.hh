#pragma once
/*****************************************************************/
/*!
 * \file Vector_temp.hh
 * \brief Plik zawiera szablon klasy Vector i funkcji z nią związanych
 * */
#include <iostream>
#include <cmath>
#include <string>
#include <assert.h>

/*!
 * \brief Szablon klasy Vector i przeciążeń dla niej
 *  Klasa modelująca pojęcie Pointa.
 *  Korzystając z metod zawartych w funkcji można
 *  wyświetlić Point, obliczyć jego długość, dodatkowo
 *  korzystając z przeciążeń można wczytać Point od użytkownika,
 *  oraz wyświetlić go za pomocą przeciążenia.
 */
template <int SizeOfVector>
class Vector {
    ///Elementy Punktu
    double Vec[SizeOfVector];
    ///ilość stworzonych Wektorów 
    static int NumberOfVectors;
    ///ilość istniejących Wektorów 
    static int TogetherV;
  public:
    ///Konstruktor domyślny
    Vector();
    ///konstruktor dla Vector3D
    Vector(int x, int y, int z);
    ///konstruktor kopiujący
    Vector(const Vector &obj);
    ///Metoda obliczająca długość wektora
    double Length();
    ///destruktor
    ~Vector(){--NumberOfVectors;};
    /*!
    * Przeciążenie operatora indeksującego, które będzie zwracało 
    * zadane pole tablicy-vector. 
    */
    double  operator [] (int Ind) const {assert(Ind >= 0 && Ind < SizeOfVector); return Vec[Ind];}
    /*!
    * Przeciążenie operatora indeksującego, które będzie zwracało 
    * referencję do zadanego pola tablicy-Vector 
    */
    double& operator [] (int Ind)       {assert(Ind >= 0 && Ind < SizeOfVector); return Vec[Ind];}
    /*!
    *\brief Przeciążenie operatora + dla Vector<>
    * Przeciążenie operatora + dla dodawania wektorów
    * \return Wektor który jest sumą dwóch poprzednich
    */
    Vector<SizeOfVector> operator+(Vector<SizeOfVector> Arg2) const;
    /*!
    *\brief Przeciążenie operatora += dla Vector<>
    * Przeciążenie operatora += dla dodawania wektorów
    * \return Wektor który jest sumą wektora będącego argumentem i wartości poprzedniej wektora 
    */
    Vector<SizeOfVector> &operator+=(const Vector<SizeOfVector> &Arg2);
    /*!
    *\brief Przeciążenie operatora *= dla Vector<>
    * Przeciążenie operatora *= dla klasy Vector pozwala na
    * mnożenie przez liczbę zmienno przecinkową
    * \return Wektor którego elementy są pomnożone przez argument 
    */
    Vector<SizeOfVector>& operator*=(double en);
    /*!
    *\brief Przeciazenie operatora / dla Vector<>
    *
    * Przeciazenie operatora / dla klasy Vector<> pozwala na dzielenie
    * wektora przez liczbe calkowita.
    * \param Arg2 - dzielnik
    * \return Przeciazenie zwraca Vector<SIZE_OF_POINT> bedacy wynikiem dzielenia
    */
    Vector<SizeOfVector> operator/(int Arg2) const; 
    /*!
    *\brief Metoda zwraca ilosc aktualnie uzywanych obiektow klasy Vector
    *
    * Metoda zwraca ilosc aktualnie uzywanych obiektow klasy Vector
    * \return Zwraca wartosc pola NumberOfPoints
    */
    static int ReturnNumbOfVect() { return NumberOfVectors; }
    /*!
    *\brief Metoda zwraca ilosc stworzonych obiektow klasy Vector
    *
    * Metoda zwraca ilosc stworzonych obiektow klasy Vector
    * \return Zwraca wartosc pola Together
    */
    static int ReturnAllNumberOfVects() { return TogetherV; }
    /*!
    *\brief Metoda zwraca Vector z minusami
    *
    * \return Zwraca wektor o przeciwnym zwrocie.
    */
    Vector<SizeOfVector> Reverse();
};
/****************************************************************************************/
template <int SizeOfVector>
int Vector<SizeOfVector>::NumberOfVectors = 0;
/****************************************************************************************/
template <int SizeOfVector>
int Vector<SizeOfVector>::TogetherV = 0;
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector>::Vector()
{ 
  for(int i=0;i<SizeOfVector;i++)
    this->Vec[i]=0.0;
  ++NumberOfVectors;
  ++TogetherV;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector>::Vector(int x, int y, int z) 
{
  this->Vec[0] = x;
  this->Vec[1] = y;
  this->Vec[2] = z;
  ++NumberOfVectors;
  ++TogetherV;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector>::Vector(const Vector<SizeOfVector> &obj) 
{
  ++NumberOfVectors;
  ++TogetherV;
  for (int i = 0; i < SizeOfVector; ++i) 
  {
    Vec[i] = obj[i];
  }
}
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector> Vector<SizeOfVector>::operator/(int Arg2) const
{
  Vector<SizeOfVector> temp;
  for (int i = 0; i <SizeOfVector; i++) 
  {
    temp[i] = this->Vec[i] / Arg2;
  }
  return temp;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector> Vector<SizeOfVector>::operator+(Vector<SizeOfVector> Arg2) const 
{
  Vector<SizeOfVector> temp;
  for (int i = 0; i < SizeOfVector; i++) 
  {
    temp[i] = this->Vec[i] + Arg2[i];
  }
  return temp;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector>& Vector<SizeOfVector>::operator+=(const Vector<SizeOfVector> &Arg2)
{
  for (int i = 0; i < SizeOfVector; i++) 
    this->Vec[i] += Arg2[i];
  return *this ;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
Vector<SizeOfVector>& Vector<SizeOfVector>::operator*=(double en)
{
  for (int i = 0; i < SizeOfVector; i++) 
    this->Vec[i] *= en;
  return *this ;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
std::istream& operator >> (std::istream &Strm, Vector<SizeOfVector> &Vect)
{
  std::string help;
  double number;
    for(int i=0;i<SizeOfVector;i++)
    {

      std::cout<<"Enter the coordinates of vector: ";
      std::cin>>number;
      while (std::cin.fail()) 
      {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Incorrect format!" << std::endl;
        std::cout << "Enter the coordinates of vector: ";
        std::cin >> number;
      }
      Vect[i]=number;
    }
return Strm;
}
/****************************************************************************************/
template <int SizeOfVector>
inline
std::ostream& operator << (std::ostream &Strm,const Vector<SizeOfVector> &Vect)
{
    Strm<<"[";
    for(int i=0;i<SizeOfVector;i++)
    {
        Strm << Vect[i];
        if(i!=(SizeOfVector-1))
            Strm<<",";
    }
    Strm<<"]"<<std::endl;
   return Strm;
}
/****************************************************************************************/
template <int SizeOfVector>
inline

Vector<SizeOfVector> Vector<SizeOfVector>::Reverse()
{
  Vector<SizeOfVector> temp;
  for (int i = 0; i <SizeOfVector; i++) 
  {
    temp[i] = this->Vec[i] *(-1);
  }
  return temp;
}


