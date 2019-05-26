#pragma once
#include <unistd.h>
#include <memory>
#include "Prism.hh"
#include "SceneObject.hh"
#include "lacze_do_gnuplota.hh"
#define NUMBER_OF_ROTORS 4
/*****************************************************************/
/*!
 * \file Drone.hh
 * \brief Plik zawiera definicję klasy Drone i funkcji z nią związanych
 * */
/*!
 * \brief Klasa modeluje pojecia drona
 *
 * Klasa modeluje pojecie drona skladajacego sie z kadlubu oraz 4 wirnikow.
 */
class Drone : public SceneObject {
  /*!
   * \brief Pole przechowuje 4 obiektu typu Prism bedace wirnikami
   *
   * Pole przechowuje 4 obiektu typu Prism bedace wirnikami
   */
  Prism Rotor[NUMBER_OF_ROTORS];
  /*!
   * \brief Pole przechowuje obiekt Cuboid bedacy korpusem drona
   *
   * Pole przechowuje obiekt Cuboid bedacy korpusem drona
   */
  Cuboid Korpus;
  /*!
   * \brief Pole przechowuje kat obrotu wzgledem poczatkowego polozenia
   *
   * Pole przechowuje kat obrotu wzgledem poczatkowego polozenia
   */
  double Angle = 0;
  Cuboid Korpus2;


 public:
 Drone(){TypeOfID=1;}
  /*!
   * \brief Metoda pozwala na animacje ruchu drona na wprost
   *
   * Metoda pozwala na animacje ruchu drona na wprost z uwzglednieniem stopnia
   * wznoszenia lub opadania
   * \param Lacze - lacze do programu GNUPlot przez
   * ktore ma byc rysowany dron
   */
  int Move(PzG::LaczeDoGNUPlota Link,int i,std::list<std::shared_ptr<SceneObject>> SceneObjects);
  /*!
   * \brief Metoda pozwala na przemieszczenie drona o zadany wektor
   *
   * Metoda pozwala na przemieszczenie drona o zadany wektor
   * \param vec - wektor przemieszczenia
   */
  void MoveByVector(const Vector3D &vec);
  /*!
   * \brief Metoda pozwala na animacje obrotu drona wokol wlasnej osi
   *
   * Metoda pozwala na animacje obrotu drona wokol wlasnej osi
   * \param Lacze - lacze do programu GNUPlot przez
   * ktore ma byc rysowany dron
   */
  void Rotation(PzG::LaczeDoGNUPlota Link,int i);
  /*!
   * \brief Metoda pozwala na zapis wspolrzednych drona do plikow
   *
   * Metoda pozwala na zapis wspolrzednych poszczegolnych elementow drona do
   * osobnych plikow w celu ich pozniejszego narysowania poprzez program GNUPlot
   */
  void Save(int i);
  /*!
   * \brief Metoda pozwala na inicjalizacje obiektow skladajacych sie na drona
   *
   * Metoda pozwala na inicjalizacje obiektow skladajacych sie na drona
   */
  void Init();
  /*!
   * \brief Metoda pozwala na animacje obrotu rotorow drona
   *
   * Metoda pozwala na animacje obrotu rotorow drona
   * \param Lacze - lacze do programu GNUPlot przez
   * ktore ma byc rysowany dron
   */
  void Animation(PzG::LaczeDoGNUPlota Link,int i);
  /*!
  * \brief Metoda aktualizujaca pozycje rotorow w odniesieniu do korpusu
  * 
  * Metoda aktualizujaca pozycje rotorow w odniesieniu do korpusu. Zmienia ona pole 
  * offset w obiekcie Graniastoslup, tak by rotor znajdowal sie na wierzcholku korpusu
  */
  void UpdateRotors();
  /*!
   *\brief Metoda pozwala na powiększenie/pomniejszenie obiektu
   *
   * Metoda skaluje obiekt
   * \param en - powiększenie/pomniejszenie
   * \param i - numer pliku do którego ma zostać zapisany dron
   * \param Link - łacze do GNUPlota
   */
  void Enlarge(double en,PzG::LaczeDoGNUPlota Link,int i);
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
   * \return Zwraca wysokość bryły
   */
  double GetHeight() { return Height;}

  void SaveCenter(std::ostream &Strm);

    /*!
   * \brief Metoda sprawdzająca, czy wystepuje zderzenie z innym obiektem sceny.
   * Metoda pozwala na sprawdzenie, czy wystepuje kolizja poruszającego się 
   * drona z innym obiektem sceny.
   * 
   * \retval true - metoda zwraca true, gdy występuje zderzenie
   * \retval false - metoda zwraca false, gdy zderzenie nie występuje
   */
  bool IsCollision(std::list<std::shared_ptr<SceneObject>> SceneObjects);
};