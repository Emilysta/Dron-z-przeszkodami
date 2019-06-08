#pragma once
#include "SceneObject.hh"
#include <memory>
/*****************************************************************/
/*!
 * \file Factory.hh
 * \brief Plik zawiera definicję klasy Factory i funkcji z nią związanych
 * */
enum Type { RO_Drone,RO_Obstacle};
/*!
 *\brief Klasa modeluje pojecie fabryki
 */

class Factory
{
    /*!
     * \brief Instancja fabryki 
     */
    static Factory* Instance;
    /*!
     * \brief Konstruktor 
     */
    Factory(){}
public:
    /*!
     * \brief Destruktor 
     */
    ~Factory()
    {
        if(Instance)
        {
            delete Instance;
            Instance=nullptr;
        }
    }
    /*!
     * \brief Funkcja zwracająca 
     * Instancje Fabryki
     */
    static Factory* getInstance();
    /*!
     * \brief Funkcja tworząca SceneObject
     * 
     * Funkcja tworzy obiekt sceny i zwraca wskaznik na
     * ten obiekt
     * \return Zwraca wskaznik na obiekt
     */
    shared_ptr<SceneObject> CreateObject(Type RO);
};
