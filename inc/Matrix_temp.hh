#pragma once
/*****************************************************************/
/*!
 * \file Matrix_temp.hh
 * \brief Plik zawiera definicję klasy Matrix i funkcji z nią związanych
 * */
#include "Vector_temp.hh"
#include <iostream>
#include <assert.h>
#include <cmath>
using namespace std;

/*****************************************************************/
/*!
 * \brief Definicja klasy Matrix i przeciążeń dla niej
 *  Klasa modelująca pojęcie Macierzy 2x2.
 *  Korzystając z metod zawartych w klasie można
 *  wyświetlić ją, obliczyć wyznacznik macierzy, dodatkowo
 *  korzystając z przeciążeń można zwrócić konkretne elementy
 *  macierzy.
 */
template < int Wymiar >
class Matrix {
  ///kat macierzy obrotu
  float alpha;
  ///elementy macierzy 
  double Tab[Wymiar][Wymiar];

public:
  ///konstruktor domyślny
  Matrix();
  ///destruktor
  ~Matrix()=default;
  ///metoda modyfikująca macierz2x2 dla obrotu o podany kąt
  void Matrix2x2(double beta);
  ///metoda modyfikujaca macierz3x3 dla osi obrotu X
  void Matrix3x3_X(double beta);
  ///metoda modyfikujaca macierz3x3 dla osi obrotu Y
  void Matrix3x3_Y(double beta);
  ///metoda modyfikujaca macierz3x3 dla osi obrotu Z
  void Matrix3x3_Z(double beta);
  ///metoda zwracająca kąt alpha macierzy rotacji
  float operator + () const {return alpha;}
  ///przeciążenie operatora funkcyjnego dla zwracania odpowiedniego elementu macierzy
  double operator () (int Wie,int Kol) const 
  {
    assert(Wie>= 0 && Wie< Wymiar && Kol>=0 && Kol <Wymiar); 
    return Tab[Wie][Kol];
  }
  ///przeciążenie operatora funkcyjnego dla zwracania odpowiedniego elementu macierzy
  double& operator () (int Wie, int Kol)
  {
    assert(Wie>= 0 && Wie< Wymiar && Kol>=0 && Kol <Wymiar);
    return Tab[Wie][Kol];
  }
  /*!
  *\brief Przeciazenie operatora * dla mnożenia macierz * macierz
  *
  * Przeciazenie operatora * dla klasy Matrix<> pozwala na mnożenie
  *  Macierzy przez drugą macierz, wynikiem jest inna macierz
  * \param Arg2 - macierz
  * \return Przeciazenie zwraca macierz bedaca wynikiem działania
  */
  Matrix<Wymiar> operator * (const Matrix<Wymiar> &M);
  /*!
  *\brief Przeciazenie operatora * dla mnożenia macierz * vector
  *
  * Przeciazenie operatora * dla klasy Matrix<> pozwala na mnożenie
  *  Macierzy przez wektor, wynikiem jest wektor
  * \param Arg2 - wektor
  * \return Przeciazenie zwraca wektor bedacy wynikiem działania
  */
  Vector<Wymiar> operator*(const Vector<Wymiar> &Arg2);
  };

/**************************************************************************/
template < int Wymiar >
Matrix<Wymiar>::Matrix()
{
    alpha=0;
    for(int i=0;i<Wymiar;i++)
        for(int j=0;j<Wymiar;j++)
            Tab[i][j]=1;
}
/**************************************************************************/
template < int Wymiar >
void Matrix<Wymiar>::Matrix2x2(double beta)
{
    if(Wymiar==2)
    {
        alpha=beta;
        Tab[0][0]=cos(alpha*M_PI/180.0);
        Tab[0][1]=-sin(alpha*M_PI/180.0);
        Tab[1][0]=sin(alpha*M_PI/180.0);
        Tab[1][1]=cos(alpha*M_PI/180.0);
    }

}
/**************************************************************************/
template < int Wymiar >
void Matrix<Wymiar>::Matrix3x3_X(double beta)
{
    if(Wymiar==3)
    {
        alpha=beta;
        Tab[0][0]=1.0;
        Tab[0][1]=0.0;
        Tab[0][2]=0.0;
        Tab[1][0]=0.0;
        Tab[1][1]=cos(alpha*M_PI/180.0);
        Tab[1][2]=-sin(alpha*M_PI/180.0);
        Tab[2][0]=0.0;
        Tab[2][1]=sin(alpha*M_PI/180.0);
        Tab[2][2]=cos(alpha*M_PI/180.0);
    }

}
/**************************************************************************/
template < int Wymiar >
void Matrix<Wymiar>::Matrix3x3_Y(double beta)
{
    if(Wymiar==3)
    {
        alpha=beta;
        Tab[0][0]=cos(alpha*M_PI/180.0);
        Tab[0][1]=0.0;
        Tab[0][2]=sin(alpha*M_PI/180.0);
        Tab[1][0]=0.0;
        Tab[1][1]=1.0;
        Tab[1][2]=0.0;
        Tab[2][0]=-sin(alpha*M_PI/180.0);
        Tab[2][1]=0.0;
        Tab[2][2]=cos(alpha*M_PI/180.0);
    }

}
/**************************************************************************/
template < int Wymiar >
void Matrix<Wymiar>::Matrix3x3_Z(double beta)
{
    if(Wymiar==3)
    {
        alpha=beta;
        Tab[0][0]=cos(alpha*M_PI/180.0);
        Tab[0][1]=-sin(alpha/180.0*M_PI);
        Tab[0][2]=0.0;
        Tab[1][0]=sin(alpha/180.0*M_PI);
        Tab[1][1]=cos(alpha*M_PI/180.0);
        Tab[1][2]=0.0;
        Tab[2][0]=0.0;
        Tab[2][1]=0.0;
        Tab[2][2]=1.0;
    }

}
/**************************************************************************/
/*!
 * Preciążenie operatora przesunięcia bitowego dla wyświetlania
 * macierzy obrotu.
 */
template < int Wymiar >
std::ostream& operator << (std::ostream &Strm, const Matrix<Wymiar> Mat)
{
     for(int i=0;i<Wymiar;i++)
     {
        for(int j=0;j<Wymiar;j++)
            Strm<<Mat(i,j)<<"\t";
        Strm<<endl;
     }
    return Strm;
}
/**************************************************************************/
/*!
 * Preciążenie operatora mnożenia dla mnożenia macierz*macierz
 */
template < int Wymiar >
Matrix<Wymiar> Matrix<Wymiar>::operator * (const Matrix<Wymiar> &M)
{
  Matrix<Wymiar> C;
  double sum=0;

  for(int i=0;i<Wymiar;i++)
  {
    for(int j=0;j<Wymiar;j++)
    {
      sum=0;
      for(int k=0;k<Wymiar;k++)
      {
        sum+=Tab[i][k]*M(k,j);
      }
      C(i,j)=sum;
    }
  }
 return C;
}
/****************************************************************************/
template <int Wymiar>
Vector<Wymiar> Matrix<Wymiar>::operator * (const Vector<Wymiar> &Arg2)
{
  Vector<Wymiar> temp;
  double suma;
  for (int i = 0; i < Wymiar; i++) 
  {
    for (int j = 0; j < Wymiar; j++) 
    {
      suma = 0;
      for (int k = 0; k < Wymiar; k++) 
      {
        suma += Tab[i][k] * Arg2[k];
      }
      temp[i] = suma;
    }
  }
  return temp;
}