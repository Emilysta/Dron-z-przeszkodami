#pragma once
#include "Vector3D.hh"
#include "Point3D.hh"

/*****************************************************************/
/*!
 * \file SceneObject.hh
 * \brief Plik zawiera definicję klasy SceneObject i funkcji z nią związanych
 * */
/*!
 *\brief Klasa modeluje pojecie obiektu sceny
 */
class SceneObject
{
  static int ExistingNumber;
  static int CreatedNumber;

 protected:
  /*!
   * \brief Pole sluzy do identyfikacji klasy pochodnej
   *
   * Pole sluzy do identyfikacji klasy pochodnej\n
   * 0-przeszkoda\n
   * 1-dron\n
   */
  int TypeOfID;
  /*!
   * \brief Pole przechowuje wspolrzedne srodka obiektu
   *
   * Pole przechowuje wspolrzedne srodka obiektu w globalnym ukladzie
   * wspolrzednych
   */
  Point3D Center;
  /*!
   *\brief Pole przechowuje promień obiektu
   */
  double Radius;
  /*!
   *\brief Pole przechowuje wysokość obiektu
   */
  double Height;
 public:
  SceneObject() 
  {
    ++ExistingNumber;
    ++CreatedNumber;
  }
  ~SceneObject() 
  { 
    --ExistingNumber; 
  }
  SceneObject(SceneObject const &obj)
  {
    ++ExistingNumber;
  }
  static int RetExistingNumber() { return ExistingNumber; }
  static int RetCreatedNumber() { return CreatedNumber; }
  /*!
   * \brief Metoda pozwala na zwrocenie pola TypeOfID
   *
   * Metoda pozwala na zwrocenie pola TypeOfID
   * \return wartosc TypeOfID
   */
  virtual int ID() const { return TypeOfID; }
  /*!
   * \brief Metoda pozwala na wybor odpowiedniej metody zapisu w klasach
   * pochodnych
   *
   *  Metoda pozwala na wybor odpowiedniej metody zapisu w klasach pochodnych
   */
  virtual void Save(int i) {}
  /*!
   * \brief Metoda pozwala na wybor odpowiedniej metody zapisu w klasach
   * pochodnych
   *
   *  Metoda pozwala na wybor odpowiedniej metody zapisu w klasach pochodnych
   */
  virtual void Save(std::ostream &Strm) {}
  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody Init w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody Init w klasach
   * pochodnych
   */
  virtual void Init() {}
  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody MoveByVector w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody MoveByVector w klasach
   * pochodnych
   */
  virtual void MoveByVector(const Vector3D& vec) {}
  /*!
   * \brief Metoda pozwala na ustawienie środka obiektu.
   * \param point - środek bryły
   */
   virtual void SetCenter(const Point3D& point) {}
  /*!
   * \brief Metoda pozwala na ustawienie promienia obiektu.
   * \param r - promień bryły
   */
  virtual void SetRadius(const double &r) {}
  /*!
   * \brief Metoda pozwala na ustawienie wysokości obiektu.
   * \param h - wysokość bryły
   */
   virtual void SetHeight(const double &h) {}
  /*!
   * \brief Metoda zwraca wartosc pola Center
   *
   * Metoda zwraca wartosc pola Center
   * \return Wartosc pola Center
   */
  virtual Point3D GetCenter() {return Center;}
    /*!
     * \brief Metoda pozwala na zwrócenie promienia obiektu.
     * \return Zwraca promień bryły
     */
   virtual double GetRadius() {return Radius;}
    /*!
     * \brief Metoda pozwala na zwrócenie wysokości obiektu.
     * \return Zwraca wysokość bryły
     */
  virtual double GetHeight() {return Height;}

  virtual void SaveCenter(std::ostream &Strm) {}

};

