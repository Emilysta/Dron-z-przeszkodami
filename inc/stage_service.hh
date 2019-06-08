#include "Vector3D.hh"
#include "lacze_do_gnuplota.hh"
#include "Scene.hh"
/*****************************************************************/
/*!
 * \file stage_service.hh
 * \brief Plik zawiera definicję funkcji DisplayMenu i SetLink
 */
#define NUMBER_OF_ROTORS 4
/*!
 *\brief Funkcja wyswietla menu uzytkownika
 */
void DisplayMenu();
/*!
 *\brief Funkcja wyswietla liczby utworzonych i istniejących obiektów
 */
void DisplayNumbers();
/*!
 *\brief Funkcja wyswietla współrzędne obecnego drona
 */
void Current(Scene *sc);
/*!
 *\brief Funkcja pozwalająca zmieniać drona
 */
void ChooseDrone(Scene *sc);
