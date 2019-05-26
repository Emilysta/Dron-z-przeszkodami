#include <fstream>
#include <vector>
#include <iomanip>
#include "Matrix3x3.hh"
#include "Point3D.hh"
#include "Vector3D.hh"
/*****************************************************************/
/*!
 * \file GeometricFigure.hh
 * \brief Plik zawiera definicję klasy GeometricFigure i funkcji z nią związanych
 * */
/*!
*\brief Klasa modeluje pojecie figury geometrycznej(obiektu) w 3 wymiarach
*/
class GeometricFigure {
 protected:
 /*!
  *\brief Pole przechowuje oryginalne punkty poszczegolnych wierzcholkow
  *
  * Pole przechowuje oryginalne punkty poszczegolnych wierzcholkow
  */
  std::vector<Point3D> P;
   /*!
  *\brief Pole przechowuje punkty poszczegolnych wierzcholkow w 
  * globalnym ukladzie odniesienia
  *
  * Pole przechowuje punkty poszczegolnych wierzcholkow w 
  * globalnym ukladzie odniesienia
  */
  std::vector<Point3D> P_glob;
  /*!
  *\brief Pole przechowuje Point o jaki sa przesuniete wierzcholki w 
  * stosunku do lokalnego ukladu odniesienia.
  * 
  * Pole przechowuje Point o jaki sa przesuniete wierzcholki w 
  * stosunku do lokalnego ukladu odniesienia.
  */
  
  Vector3D Vec_Trans=Vector3D();
  /*!
  *\brief Pole przechowuje kat o jaki figura jest obrocona
  *
  * Pole przechowuje kat o jaki figura jest obrocona.
  */
  double Angle=0;

 public:
 /*!
 *\brief Metoda przesuwa obiekt o zadany Point
 *
 * Metoda przesuwa obiekt o zadany Point3D
 * \param Wek - Point przesuniecia
 */
  void MoveByVector(const Vector3D& vec);
  /*!
  *\brief Metoda obraca obiekt o zadany kat
  *
  * Metoda obraca obiekt o zadany kat w lokalnym ukladzie odniesienia
  * po czym dokonuje zmian w globalnym ukladzie odniesienia. Point
  * przesuniecia jest dodawany do pola Point_Trans.
  * \param Kat - Kat obrotu w stopniach
  */
  void Rotation(double Angle1);
  /*!
  *\brief Metoda pozwala na zapis wierzcholkow do strumienia wyjsciowego
  *
  * Metoda pozwala na zapis wierzcholkow do strumienia wyjsciowego. 
  * Formatowanie jest przystosowane dla programu GnuPlot
  * \param Strm - strumien wyjsciowy
  */
  void Save(std::ostream &Strm);
  /*!
  *\brief Przeciazenie operatora + dla GeometricFigure i Point3D
  *
  * Przeciazenie pozwala na dodanie Pointa do Obiektu, powodujac 
  * tym jego przesuniecie o ten Point
  * \param Arg2 - Point przesunienia
  * \return GeometricFigure po przesuniecie
  */
  GeometricFigure operator+(Vector3D Arg2);
  /*!
   *\brief Metoda pozwala na powiększenie/pomniejszenie obiektu
   *
   * Metoda skaluje obiekt
   * \param en - powiększenie/pomniejszenie
   */
  void Enlarge(double en);
};
