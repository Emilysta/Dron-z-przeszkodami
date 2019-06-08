#include "Scene.hh"
#include "Factory.hh"
#include "stage_service.hh"
void Scene::SetLink() 
{
  std::string NameOfFile;
  for (int i = 0; i < NUMBER_OF_DRONES; ++i)
  {
    NameOfFile = "Korpus";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append(".dat");
    Link.DodajNazwePliku(NameOfFile.c_str());
    NameOfFile = "Camera";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append(".dat");
    Link.DodajNazwePliku(NameOfFile.c_str());
    NameOfFile = "Line";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append(".dat");
    Link.DodajNazwePliku(NameOfFile.c_str());
    for (int k = 0; k < NUMBER_OF_ROTORS; ++k) 
    {
      NameOfFile = "Rotor";
      NameOfFile.append(std::to_string(i));
      NameOfFile.append("_");
      NameOfFile.append(std::to_string(k));
      NameOfFile.append(".dat");
      Link.DodajNazwePliku(NameOfFile.c_str());
    }
  }
  for (int k = 0; k < NUMBER_OF_OBJECTS; ++k)
  {
    NameOfFile = "Obstacle";
    NameOfFile.append(std::to_string(k));
    NameOfFile.append(".dat");
    Link.DodajNazwePliku(NameOfFile.c_str());
  }
  Link.ZmienTrybRys(PzG::TR_3D);
  Link.UstawZakresY(-100, 100);
  Link.UstawZakresX(-100, 100);
  Link.UstawZakresZ(-100, 100);
  Link.Inicjalizuj();
}

void Scene::InitScene()
{
  SetLink();
  for (int i = 0; i < NUMBER_OF_DRONES; ++i)
  {
    MakeListOfDrones();
  }
  for (int i = 0; i < NUMBER_OF_OBJECTS; ++i)
  {
    MakeListOfSceneObjects();
  }

  unsigned int i=0;
  unsigned int k=0;
  for(auto object : SceneObjects )
  {
    object->Init();
    if(k<NUMBER_OF_DRONES)
      object->MoveByVector(Vector3D(20*k,13*k,0));
    else
      object->MoveByVector(Vector3D(20*k,13*k+50,20));
    
    object->Save(i);
    ++i;
    ++k;
    if(i==Drones.size())
    i=0;
  }
    IterOfDrones = Drones.begin();
  IterOfObjects= SceneObjects.begin();
}

void Scene::MakeListOfDrones()
{
  std::shared_ptr<Drone> drone_h = std::static_pointer_cast<Drone,SceneObject>(Factory::getInstance()->CreateObject(RO_Drone)); 
  Drones.push_back(drone_h);
  SceneObjects.push_back(drone_h);
}

void Scene::MakeListOfSceneObjects()
{
  std::shared_ptr<SceneObject> Obj = Factory::getInstance()->CreateObject(RO_Obstacle);
  SceneObjects.push_back(Obj);
}
void Scene::ChangeDrone() 
{
  IterOfDrones = std::next(IterOfDrones);
  if (IterOfDrones == Drones.end()) 
  {
    IterOfDrones = Drones.begin();
  }
}

void Scene::ChangeObject() 
{
  IterOfObjects = std::next(IterOfObjects);
  if (IterOfObjects == SceneObjects.end()) 
  {
    IterOfObjects = SceneObjects.begin();
  }
}
std::list<shared_ptr<SceneObject> > Scene::GetList()
{
  return SceneObjects;
}

void Scene::DisplayDrones() 
{
  int i = 1;
  for (auto drone : Drones) 
  {
    std::cout << "Drone " << i << ".  ";
    std::cout << "Coordinates: " << drone->GetCenter() << std::endl;
    ++i;
  }
  this->ChooseDrone();
}

void Scene::ChooseDrone() 
{
  int wybor;
  std::cout << "Your choice:  ";
  std::cin >> wybor;
  if (wybor > 0) 
  {
    if (wybor > std::distance(Drones.begin(), Drones.end())) 
    {
      std::cout << "There is no drone with this number!!!" << std::endl;
    } 
    else 
    {
      IterOfDrones = Drones.begin();
      std::advance(IterOfDrones, wybor - 1);
    }
  }
}

void Scene::AddObject()
{
  int number;
  std::cout << "Do you want to add a Drone (1) or Obstacle (0) >";
  std::cin >> number;
  switch(number)
  {
    case 1:
           {
            std::shared_ptr<SceneObject> object = Factory::getInstance()->CreateObject(RO_Drone);
            std::shared_ptr<Drone> drone = std::static_pointer_cast<Drone, SceneObject>(object);
            drone->Set(Link);
            Drones.push_back(drone);
            SceneObjects.push_back(object);
            break;
            }
    case 0: {
            std::shared_ptr<SceneObject> object = Factory::getInstance()->CreateObject(RO_Obstacle);
            std::shared_ptr<Obstacle> obstacle = std::static_pointer_cast<Obstacle, SceneObject>(object);
            obstacle->Set(Link);
            SceneObjects.push_back(obstacle);
            break;
            }

    default: {}
  }
}

void Scene::EditFiles()
{
  Link.UsunWszystkieNazwyPlikow();
  std::string NameOfFile;
  for (unsigned int i = 0; i < Drones.size(); ++i)
  {
    NameOfFile = "Korpus";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append(".dat");
    Link.DodajNazwePliku(NameOfFile.c_str());
    NameOfFile = "Camera";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append(".dat");
    Link.DodajNazwePliku(NameOfFile.c_str());
    NameOfFile = "Line";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append(".dat");
    fstream PlikWy;
    PlikWy.open(NameOfFile,ios::out| std::fstream::trunc);
    PlikWy.close();
    Link.DodajNazwePliku(NameOfFile.c_str());
    for (int k = 0; k < NUMBER_OF_ROTORS; ++k) 
    {
      NameOfFile = "Rotor";
      NameOfFile.append(std::to_string(i));
      NameOfFile.append("_");
      NameOfFile.append(std::to_string(k));
      NameOfFile.append(".dat");
      Link.DodajNazwePliku(NameOfFile.c_str());
    }
    for (unsigned int k = 0; k < SceneObjects.size()-Drones.size(); ++k)
    {
      NameOfFile = "Obstacle";
      NameOfFile.append(std::to_string(k));
      NameOfFile.append(".dat");
      Link.DodajNazwePliku(NameOfFile.c_str());
    }
  }
  int k = 0;
  for (auto drone : Drones) 
  {
    drone->Save(k);
    ++k;
  }
}

void Scene::RemoveDrone()
{
  if(Drones.size() > 1)
  {
    Current(this);
    char sign;
    std::cout<<"Do you really want to remove this drone? T/N  > ";
    std::cin >> sign;
    std::cout<<std::endl;
    switch (sign) {
      case 'T': {
        Drones.remove(WhichDrone());
        SceneObjects.remove(WhichDrone());
        IterOfDrones = Drones.begin();
        Current(this);
        EditFiles();
        break;
      }
      case 'N': {
        std::cout << "Drone hasn't been removed !!!" << std::endl;
        break;
      }
      default: {
        std::cout << "Incorrect choice !!!" << std::endl;
      }
    }
  }
  else
  {
    std::cout<<"You can't remove this drone because there is only one on the scene !!!"<<std::endl;
    std::cout<<"You can add drone by using a function and then remove this drone :) "<<std::endl;
  }
  
}