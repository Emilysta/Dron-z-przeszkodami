#pragma once
/*****************************************************************/
/*!
 * \file Point.hh
 * \brief Plik zawiera definicję klasy Point i funkcji z nią związanych
 */
#include <iostream>
#include <cmath>
#include <string>
#include <assert.h>
#include "Vector_temp.hh"
#include "Matrix_temp.hh"
/*******************************************************************/
/*! 
 * \brief Definicja klasy Point i przeciążeń dla niej
 * Klasa ta opisuje pojęcie Punktu w układzie współrzędnych.
 * Metody tej klasy pozwalają na:
 *   - wyświetlenie punktu w postaci (x,y),
 *   - rotację punktu o kąt alpha.
 */
template <int SIZE_OF_POINT>
class Point {
  ///Współrzędne punktu zapisane w tablicy
  double Coor[SIZE_OF_POINT];
  /*!
   *\brief Pole przechowuje ilosc uzywanych obiektow klasy Point3D
   *
   * Pole przechowuje ilosc uzywanych obiektow klasy Point3D
   */
  static int NumberOfPoints;
  /*!
   *\brief Pole przechowuje ilosc stworzonych obiektow klasy Point3D
   *
   * Pole przechowuje ilosc stworzonych obiektow klasy Point3D
   */
  static int Together;

public:
  /*!
   *\brief Konstruktor domyślny
   * Konstruktor domyślny dla klasy Point
   */
  Point();
  /*!
   *\brief Konstruktor kopiujacy
   * Konstruktor kopiujacy dla klasy Point
   */
  Point(const Point &obj);
  /*!
   *\brief Konstruktor parametryczny dla obiektu Point3D
   *Konstruktor parametryczny dla obiektu Point3D
   */
  Point(int x, int y, int z);
  /*!
   *\brief Destruktor obiektu Point
   *
   * Destruktor obiektu Point
   */
  ~Point() { --NumberOfPoints; }
  ///przeciążenie operatora funkcyjnego dla zwracania odpowiedniego elementu Punktu
  double  operator () (int Ind) const {assert(Ind >= 0 && Ind < SIZE_OF_POINT); return Coor[Ind];}
  ///przeciążenie operatora funkcyjnego dla zwracania odpowiedniego elementu Punktu
  double& operator () (int Ind)       {assert(Ind >= 0 && Ind < SIZE_OF_POINT); return Coor[Ind];}
  /*!
   *\brief Przeciazenie operatora * dla Point<>
   * Przeciazenie operatora * dla klasy Point<> pozwala na wykonywanie 
   * operacji typu Point<SIZE_OF_POINT> * Matrix<SIZE_OF_POINT>.
   * \param Arg2 - macierz obrotu
   * \return Przeciazenie zwraca Punkt<SIZE_OF_POINT> 
   * bedacy wynikiem działania
   */
  Point<SIZE_OF_POINT> operator * (const Matrix<SIZE_OF_POINT> &M) const;
  /*!
   *\brief Przeciazenie oepratora - dla Point<>
   *
   * Przeciazenie operatora - dla Point<> pozwala na wykonywanie
   * operacji typu Point<SIZE_OF_POINT> - Vector<SIZE_OF_POINT>.
   * \param Arg2 - skladnik ktory ma zostac odjęty
   * \return Przeciazenie zwraca wynik odejmowania.
   */
  Point<SIZE_OF_POINT> operator - (const Vector<SIZE_OF_POINT> &Arg2) const;
  Point<SIZE_OF_POINT> &operator -= (const Vector<SIZE_OF_POINT> &Arg2);
  /*!
   *\brief Przeciazenie oepratora + dla Point<>
   *
   * Przeciazenie operatora + dla Point<> pozwala na wykonywanie
   * operacji typu Point<SIZE_OF_POINT> + Vector<SIZE_OF_POINT>.
   * \param Arg2 - skladnik ktory ma zostac dodany
   * \return Przeciazenie zwraca wynik dodawania.
   */
  Point<SIZE_OF_POINT> operator + (const Vector<SIZE_OF_POINT> &Arg2) const;
  /*!
   *\brief Przeciazenie oepratora += dla Point<>
   *
   * Przeciazenie operatora += dla Point<> pozwala na wykonywanie
   * operacji typu Point<SIZE_OF_POINT> += Point<SIZE_OF_POINT>.
   * \param Arg2 - skladnik ktory ma zostac dodany
   * \return Przeciazenie zwraca wynik dodawania.
   */
  Point<SIZE_OF_POINT> &operator += (const Vector<SIZE_OF_POINT> &Arg2);
    /*!
   *\brief Przeciazenie oepratora *= dla Point<>
   *
   * Przeciazenie operatora *= dla Point<> pozwala na wykonywanie
   * mnożenia elementów klasy point przez liczbe będącą argumentem
   * \param en - skladnik, przez który mnożymy 
   * \return Przeciazenie zwraca wynik mnożenia.
   */
  Point<SIZE_OF_POINT> &operator *= (double en);
  /*!
   *\brief Metoda zwraca ilosc aktualnie uzywanych obiektow klasy Point
   *
   * Metoda zwraca ilosc aktualnie uzywanych obiektow klasy Point
   * \return Zwraca wartosc pola NumberOfPoints
   */
  static int ZwrocIloscPointow() { return NumberOfPoints; }
  /*!
   *\brief Metoda zwraca ilosc stworzonych obiektow klasy Point
   *
   * Metoda zwraca ilosc stworzonych obiektow klasy Point
   * \return Zwraca wartosc pola Together
   */
  static int ZwrocLacznaIloscPointow() { return Together; }

  double Length2D(const Point<SIZE_OF_POINT> &point2);
};
/*************************************************************************************************/
template <int SIZE_OF_POINT>
int Point<SIZE_OF_POINT>::NumberOfPoints= 0;

template <int SIZE_OF_POINT>
int Point<SIZE_OF_POINT>::Together= 0;
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT>::Point() 
{
  for (int i = 0; i < SIZE_OF_POINT; i++) 
  {
    this->Coor[i] = 0;
  }
  ++NumberOfPoints;
  ++Together;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT>::Point(const Point &obj) 
{
  ++NumberOfPoints;
  ++Together;
  for (int i = 0; i < SIZE_OF_POINT; ++i) 
  {
    Coor[i] = obj(i);
  }
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT>::Point(int x, int y, int z) 
{
  this->Coor[0] = x;
  this->Coor[1] = y;
  this->Coor[2] = z;
  ++NumberOfPoints;
  ++Together;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT> Point<SIZE_OF_POINT>::operator * (const Matrix<SIZE_OF_POINT> & M) const
{
  Point<SIZE_OF_POINT> pom;
  double help[SIZE_OF_POINT];
  for(int i = 0; i < SIZE_OF_POINT; i++)
    help[i]=Coor[i];
  for(int i = 0; i < SIZE_OF_POINT; i++)
  {
    for(int j = 0; j < SIZE_OF_POINT; j++)
      pom(i)+=(M(j,i)*help[j]);
  } 
  return pom;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT> Point<SIZE_OF_POINT>::operator - (const Vector<SIZE_OF_POINT> &Arg2) const 
{
  Point<SIZE_OF_POINT> temp;
  for (int i = 0; i < SIZE_OF_POINT; i++)
  {
    temp(i) = this->Coor[i] - Arg2[i];
  }
  return temp;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT> Point<SIZE_OF_POINT>::operator + (const Vector<SIZE_OF_POINT> &Arg2) const 
{
  Point<SIZE_OF_POINT> temp;
  for (int i = 0; i < SIZE_OF_POINT; i++) 
  {
    temp(i) = this->Coor[i] + Arg2[i];
  }
  return temp;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT>& Point<SIZE_OF_POINT>::operator+=(const Vector<SIZE_OF_POINT> &Arg2) 
{
  for (int i = 0; i < SIZE_OF_POINT; i++) 
    this->Coor[i] += Arg2[i];
  return *this;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT>& Point<SIZE_OF_POINT>::operator-=(const Vector<SIZE_OF_POINT> &Arg2) 
{
  for (int i = 0; i < SIZE_OF_POINT; i++) 
    this->Coor[i] -= Arg2[i];
  return *this;
}
/*************************************************************************************************/
template <int SIZE_OF_POINT>
Point<SIZE_OF_POINT>& Point<SIZE_OF_POINT>::operator*=(double en) 
{
  for (int i = 0; i < SIZE_OF_POINT; i++) 
    this->Coor[i] *= en;
  return *this;
}
/*************************************************************************************************/
/*!
 * Przeciązenie operatora przesunięcia bitowego dla wyświetlania
 * punktu w postaci: (x,y,...)
 */
template <int SIZE_OF_POINT>
std::ostream& operator << ( std::ostream& Strm,const Point<SIZE_OF_POINT> &P)
{
    Strm<<"(";
    for(int i=0;i<SIZE_OF_POINT;i++)
    {
        Strm<<P(i);
        if(i!=(SIZE_OF_POINT-1))
            Strm<<",";
    }
    Strm<<")";
    return Strm;
}
/*************************************************************************************************/
/*!
 * Przeciązenie operatora przesunięcia bitowego dla wczytywania
 * punktu od użytkownika
 */
template <int SIZE_OF_POINT>
std::istream& operator >> ( std::istream& Strm,Point<SIZE_OF_POINT> &P)
{
  char tab[3]={'x','y','z'};
  double number=0;
  for(int i=0;i<SIZE_OF_POINT;i++)
    {
        std::cout<<"Enter the "<<tab[i]<<"-coordinate of the point: ";
        cin>>number;
        while (std::cin.fail()) 
        {
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          std::cout << "Incorrect format!" << std::endl;
          std::cout << "Enter the number of figure you want to edit" << std::endl;
          std::cin >> number;
        }
      P(i)=number;
    }
  return Strm;
}
/*************************************************************************************************/
/*!
 * \brief Metoda obliczjąca odległość pomiędzy dwoma Punktami w 2D
 * 
 * \return Zwraca obliczoną odległość pomiędzy punktami
 */
template <int SIZE_OF_POINT>
double Point<SIZE_OF_POINT>::Length2D(const Point<SIZE_OF_POINT> &point2)
{
  double length=0;
  length=sqrt((Coor[0]-point2(0))*(Coor[0]-point2(0))+(Coor[1]-point2(1))*(Coor[1]-point2(1)));
  return length;
}