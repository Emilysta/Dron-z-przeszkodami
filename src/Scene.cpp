#include "Scene.hh"

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
  for (int k = NUMBER_OF_DRONES; k < NUMBER_OF_OBJECTS+NUMBER_OF_DRONES; ++k)
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
  MakeListOfDrones();
  MakeListOfSceneObjects();
  int i=0;
  for(auto object : SceneObjects )
  {
    object->Init();
    object->MoveByVector(Vector3D(20*i,0,0));
    object->Save(i);
    ++i;
  }
    IterOfDrones = Drones.begin();
  IterOfObjects= SceneObjects.begin();
}

void Scene::MakeListOfDrones()
{
  for(unsigned int i = 0; i<NUMBER_OF_DRONES; i++)
  {
    std::shared_ptr<Drone> Dr;
    Dr = std::make_shared<Drone>();
    Drones.push_back(Dr);
    SceneObjects.push_back(Dr);
  }
}

void Scene::MakeListOfSceneObjects()
{
  for(unsigned int i = 0; i<NUMBER_OF_OBJECTS; i++)
  {
    std::shared_ptr<Obstacle> Obj;
    Obj = std::make_shared<Obstacle>();
    SceneObjects.push_back(Obj);
  }
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