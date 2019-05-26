#pragma once
#include "GeometricFigure.hh"
/*****************************************************************/
/*!
 * \file cuboid.hh
 * \brief Plik zawiera definicję klasy Cuboid i funkcji z nią związanych
 * */
/*!
 *\brief Klasa modeluje pojecie prostopadloscianu, bedacego Obiektem
 *graficznym
 */
class Cuboid: public GeometricFigure {
 public:
  /*!
   *\brief Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   *
   * Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   */
  void Init();
  /*!
   *\brief Przeciazenie operatora dodawania dla klasy Prostopadloscian i
   * Wektor3D
   *
   * Przeciazenie pozwala na przesuniecie prostopadloscianu o zadany wektor
   * \param Arg2 - Wektor3D przesuniecia
   * \return Prostopadloscian po przesuniecie o wektor Arg2
   */
  Cuboid operator+(Vector3D Arg2);
  /*!
   *\brief Przeciazenie pozwala na dostep do wspolrzednych poszczegolnych
   * wierzcholkow prostopadloscianu.
   *
   * Przeciazenie pozwala na dostep do wspolrzednych poszczegolnych
   * wierzcholkow prostopadloscianu.
   * \param Ind - Indeks wierzcholka
   * \return Wektor3D danego wierzcholka
   */
  Point3D operator[](int Ind) { assert(Ind >= 0 && Ind < 8); return P[Ind]; }
  /*!
  *\brief Metoda pozwala na zapis wierzcholkow do strumienia wyjsciowego
  *
  * Metoda pozwala na zapis wierzcholkow do strumienia wyjsciowego. 
  * Formatowanie jest przystosowane dla programu GnuPlot
  * \param Strm - strumien wyjsciowy
  */
  void SaveC(std::ostream &Strm);
  /*!
   *\brief Metoda inicjaliuzuje wierzcholki Kamery do zadanych
   * wartosci
   *
   * Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   */
  void Init2(); 
  void operator-=(Vector3D Arg2);
  void operator+=(Vector3D Arg2);
};
