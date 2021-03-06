#pragma once
#include "Cuboid.hh"
#include "lacze_do_gnuplota.hh"
#include "SceneObject.hh"
#include <iomanip>
#include <memory>


/*****************************************************************/
/*!
 * \file Obstacle.hh
 * \brief Plik zawiera definicję klasy Obstacle i funkcji z nią związanych
 * */
/*!
 *\brief Klasa modeluje pojecie przeszkody, bedacej Obiektem
 *geometrycznym konkretnie prostopadłościanem
 */
class Obstacle: public SceneObject
{ 
  /*!
   * \brief Pole przechowuje ilość istniejących obiektów Obstacle
   *
   * Pole przechowuje ilość istniejących obiektów Obstacle
   */
  static int ExistingNumberOb;
  /*!
   * \brief Pole przechowuje ilość stworzonych obiektów Obstacle
   *
   * Pole przechowuje ilość stworzonych obiektów Obstacle
   */
  static int CreatedNumberOb;
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
  /*!
   *\brief Konstruktor domyślny.
   *
   * Konstruktor ten ustawia pole TypeOfID na 
   * wartość 0 oznaczającą że obiekt jest przeszkodą.
   */
  Obstacle()
  {    
    ++ExistingNumberOb;
    ++CreatedNumberOb;
  }



 public:
   /*!
   *\brief Destruktor.
   */
  ~Obstacle() 
  { 
    --ExistingNumberOb; 
  }
  /*!
   *\brief Konstruktor kopiujący.
   */
  Obstacle(Obstacle const &obj)
  {
    ++ExistingNumberOb;
  }
  /*!
   *\brief Metoda zwraca środek przeszkody.
   *
   * Metoda zwraca środek przeszkody.
   */
  Point3D ReturnCenter() { return Center; }
  /*!
   *\brief Metoda przesuwa obiekt o zadany Point.
   *
   * Metoda przesuwa obiekt o zadany Point3D.
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
   *\brief Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   *
   * Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   */
  void Init();
  /*!
   *\brief Metoda inicjaliuzuje wierzcholki prostopadloscianu
   * korzystając z podanych przez uzytkownika wartosci
   */
  void Init(double d, double s,double h);
  /*!
  *\brief Metoda zapisuje obiekt do streamu
  */
  void SaveX(std::ostream &Strm);
   /*!
  *\brief Metoda zapisuje obiekt 
  */
  void Save(int i);
  /*!
   *\brief Przeciazenie operatora dodawania dla klasy przeszkoda i
   * Vector3D
   *
   * Przeciazenie pozwala na przesuniecie prostopadloscianu o zadany wektor
   * \param Arg2 - Wektor przesuniecia
   * \return Zwraca przeszkodę po przesunieciu o wektor Arg2
   */
  Obstacle operator+(Vector3D Arg2);
  /*!
   *\brief Przeciazenie pozwala na dostep do wspolrzednych poszczegolnych
   * wierzcholkow przeszkody.
   *
   * Przeciazenie pozwala na dostep do wspolrzednych poszczegolnych
   * wierzcholkow przeszkody.
   * \param Ind - Indeks wierzcholka
   * \return Wektor3D danego wierzcholka
   */
  Point3D operator[](int Ind) { assert(Ind >= 0 && Ind < 8); return P[Ind]; }
 /*!
 *\brief Metoda pozwala na skalowanie obiektu
 *
 * Metoda pozwala na skalowanie obiektu
 */
  void Enlarge(double en);
  /*!
   * \brief Metoda pozwala na ustawienie środka obiektu.
   * \param point - środek bryły
   */
   void SetCenter(const Point3D& point);
  /*!
   * \brief Metoda pozwala na ustawienie promienia obiektu.
   * \param r - promień bryły
   */
  void SetRadius(const double &r);
  /*!
   * \brief Metoda pozwala na ustawienie wysokości obiektu.
   * \param h - wysokość bryły
   */
   void SetHeight(const double &h);
  /*!
   * \brief Metoda zwraca wartosc pola Center
   *
   * Metoda zwraca wartosc pola Center
   * \return Wartosc pola Center
   */
  Point3D GetCenter() { return Center; }
  /*!
   * \brief Metoda pozwala na zwrócenie promienia obiektu.
   * \return Zwraca promień bryły
   */
  double GetRadius() { return Radius;}
  /*!
   * \brief Metoda pozwala na zwrócenie wysokości obiektu.
   * \return Zwraca wysokość bryły.
   */
  double GetHeight() { return Height;}
  /*!
  *\brief Metoda zapisuje środek obiektu do streamu.
  */
  void SaveCenter(std::ostream &Strm);
  /*!
  *\brief Metoda tworząca obiekt.
  */
  static std::shared_ptr<Obstacle> CreateObstacle();
  /*!
  *\brief Metoda pozwalająca ustawić wymiary/przesuniecie obiektu.
  */
  void Set(PzG::LaczeDoGNUPlota &Link);
  /*!
  *\brief Metoda zwracająca ilość istniejących przeszkod.
  */
  static int RetExistingNumberOb() { return ExistingNumberOb; }
  /*!
  *\brief Metoda zwracająca ilość stworzonych przeszkod.
  */
  static int RetCreatedNumberOb() { return CreatedNumberOb; }
};