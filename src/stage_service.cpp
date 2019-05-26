#include "stage_service.hh"
#include "Point3D.hh"
#include "SceneObject.hh"

void DisplayMenu() 
{
  std::cout << "The number of all created Point3D and Vector3D objects: ";
  std::cout <<Point3D::ZwrocLacznaIloscPointow() + Vector3D::ReturnAllNumberOfVects() << std::endl; 
  std::cout << "The number of all existing Point3D and Vector3D objects: ";
  std::cout << Point3D::ZwrocIloscPointow() + Vector3D::ReturnNumbOfVect() << std::endl;
  std::cout << "\to - drone rotation (you can change drone orientation) " << std::endl;
  std::cout << "\ts - straight flight" << std::endl;
  std::cout << "\td - display menu" << std::endl;
  std::cout << "\tc - change drone" << std::endl;
  std::cout << "\te - enlargement/reduction" << std::endl << std::endl;
  std::cout << "\tq - end of the program" << std::endl;
}
void DisplayNumbers()
{
  std::cout << "The number of all created Point3D and Vector3D objects: ";
  std::cout <<Point3D::ZwrocLacznaIloscPointow() + Vector3D::ReturnAllNumberOfVects() << std::endl; 
  std::cout << "The number of all existing Point3D and Vector3D objects: ";
  std::cout << Point3D::ZwrocIloscPointow() + Vector3D::ReturnNumbOfVect() << std::endl;
  std::cout << "The number of all created SceneObjects: ";
  std::cout << SceneObject::RetCreatedNumber() << std::endl; 
  std::cout << "The number of all existing SceneObjects: ";
  std::cout << SceneObject::RetExistingNumber() << std::endl;
}
void Current(Scene *sc)
{
  std::cout << "Current drone:" << std::endl;
  std::cout << "Drone " << sc->Ind() + 1 << ".  ";
  std::cout << "Coordinates: " << sc->WhichDrone()->GetCenter() << std::endl;
}
void ChooseDrone(Scene *sc) 
{
  std::cout << "Current drone:" << std::endl;
  std::cout << "Drone " << sc->Ind() + 1 << ".  ";
  std::cout << "Coordinates: " << sc->WhichDrone()->GetCenter() << std::endl;

  std::cout << "0. Don't change drone, leave the current" << std::endl;
  sc->DisplayDrones();
  DisplayMenu();
}