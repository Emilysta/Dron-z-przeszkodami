#pragma once
#include "Cuboid.hh"
/*!
 *\brief Klasa modeluje pojecie Graniastoslupa (Prism)
 */

class Prism : public GeometricFigure {
  /*!
   * \brief Pole przechowuje przesuniecie obiektu wzgledem srodka ukladu
   * wspolrzednych
   *
   * Pole przechowuje przesuniecie obiektu wzgledem srodka ukladu wspolrzednych
   */
  Vector3D offset;

 public:
  /*!
   * \brief Metoda pozwala na inicjalizacje obiektu Prism o ustalonych
   * wierzcholkach
   *
   * Metoda pozwala na inicjalizacje obiektu Prism o ustalonych
   * wierzcholkach
   */
  void Init();
  /*!
   * \brief Metoda pozwala na poczatkowego ustawienie obiektu
   *
   * Metoda pozwala na poczatkowego ustawienei obiektu z uwzglednieniem jego
   * przesuniecia wzgledem srodka ukladu wspolrzednych
   * \param offset - oddalenie od srodka ukladu wspolrzednych
   */
  void SetLocatcion(Vector3D offset);
  /*!
   * \brief Metoda pozwala na obrot obiektu wzgledem swojego srodka
   *
   * Metoda pozwala na obrot obiektu wzgledem swojego srodka o zadany kat
   * \param kat - kat obrotu
   */
  void RotationOfRotor(double angle);
  /*!
   * \brief Metoda pozwala na ustawienie pola offset
   *
   * Metoda pozwala na ustawienie pola offset, oraz wykonuje operacje
   * offset[2]+=2 \param Arg - offset ktory ma zostac ustawiony
   */
  void SetOffset(Point3D Arg);
  /*!
   * \brief Przeciazenie pozwala na dodanie Vector3D do kazdego wierzcholka
   *
   * Przeciazenie pozwala na dodanie Vector3D do kazdego wierzcholka. Pozwala to
   * na przesuniecie bryly o zadany wektor.
   * \param Arg2 - wektor przesuniecia
   * \return Graniastoslup(Prism) przesuniety o wektor Arg2
   */
  Prism operator+(Vector3D Arg2);
  void operator-=(Vector3D Arg2); 
  void operator+=(Vector3D Arg2);
  void SaveP(std::ostream &Strm);
};