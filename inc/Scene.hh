#pragma once
#include "Factory.hh"
#include "Drone.hh"
#include "Obstacle.hh"
#include <memory>
#define NUMBER_OF_DRONES 2
#define NUMBER_OF_OBJECTS 2
/*****************************************************************/
/*!
 * \file Scene.hh
 * \brief Plik zawiera definicję klasy Scene i funkcji z nią związanych
 * */
/*!
 *\brief Kklasa przechowuje drona i Link do łącza GNUPlot
 */
class Scene {
  /*!
   *\brief Pole przechowuje drony do sterowania
   */
  std::list<std::shared_ptr<Drone>> Drones;
  /*!
   *\brief Pole jest iteratorem listy Drones
   */
  std::list<std::shared_ptr<Drone>>::iterator IterOfDrones;
  /*!
   *\brief Pole przechowuje przeszkody do sprawdzenia na drodze przelotu
   */
  std::list<std::shared_ptr<SceneObject>> SceneObjects;
    /*!
   *\brief Pole jest iteratorem listy SceneObjects
   */
  std::list<std::shared_ptr<SceneObject>>::iterator IterOfObjects;
    /*!
   *\brief Pole przechowuje lącze do GNUPot
   */
  PzG::LaczeDoGNUPlota Link;
  /*!
   * \brief Metoda pozwala na stworzenie listy z dronami
   * i jednoczesne dołączenie ich do lisy obiektów sceny.
   */
  void MakeListOfDrones();
  /*!
   * \brief Metoda pozwala na stworzenie listy z obiektami 
   * sceny: dronami i przeszkodami.
   */
  void MakeListOfSceneObjects();
 public:
  /*!
   * \brief Konstruktor domyślny
   * Konstruktor ten inicjalizuje scene i ustawia łącze do GNUPlot.
   */
  Scene(){InitScene();}
  /*!
   * \brief Destruktor
   * Destruktor ten czyśli listy przez co usuwa wszystkie obiekty
   */
  ~Scene()
  {
    Drones.clear();
    SceneObjects.clear();
  }
  /*!
   * \brief Metoda pozwala na ustawienie łacza do GNUPlot.
   */
  void SetLink();
  /*!
   * \brief Metoda pozwala na zwrócenie łacza do GNUPlot.
   */
  PzG::LaczeDoGNUPlota& GetLink(){return Link;}
  /*!
   * \brief Metoda pozwala na zainicjalizowanie obu list.
   */
  void InitScene();
  /*!
   * \brief Metoda zwraca aktualnie wskazywanego drona z listy Drony
   *
   * Metoda zwraca aktualnie wskazywanego drona z listy Drony
   * \return Wskaznik na obiekt Dron z listy Drony
   */
  std::shared_ptr<Drone> WhichDrone() {return *IterOfDrones;};
  /*!
   * \brief Metoda zwraca indeks drona jako integer
   *
   * Metoda zwraca indeks drona jako integer
   * \return liczba(integer) bedacy indeksem drona na liscie
   */
  int Ind() {return std::distance(Drones.begin(),IterOfDrones);}

    /*!
   * \brief Metoda pozwala na przesuniecie iteratora ItDrony na kolejny na
   * liscie Drony
   *
   * Metoda pozwala na przesuniecie iteratora ItDrony na kolejny na liscie
   *  Drony.
   * W przypadku konca listy, wraca na jej poczatek.
   */
  void ChangeDrone();
  /*!
   * \brief Metoda pozwala na przesuniecie iteratora ItObiekty na kolejny na
   * liscie Obiekty
   *
   * Metoda pozwala na przesuniecie iteratora ItObiekty na kolejny na liscie
   * Obiekty.
   * W przypadku konca listy, wraca na jej poczatek.
   */
  void ChangeObject();
  /*!
   * \brief Metoda pozwala na zwrócenie listy obiektów
   *
   * \return Metoda zwraca listę obietków sceny,.
   */
  std::list<shared_ptr<SceneObject>> GetList();
  /*!
   * \brief Metoda wyświetlająca informacje o dronie
   */
  void DisplayDrones();
  /*!
   * \brief Metoda pozwala na zmianę drona,
   * którym obecnie operujemy
   */
  void ChooseDrone();
  /*!
   * \brief Metoda pozwala dodawać obiekt do sceny
   */
  void AddObject();
  /*!
   * \brief Metoda pozwala usuwać obiekt ze sceny
   */
  void RemoveDrone();
  /*!
   * \brief Metoda pozwala zmienić pliki dodane do łącza GNUPlot
   */
  void EditFiles();
};

