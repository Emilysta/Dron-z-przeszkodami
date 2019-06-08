#include "Drone.hh"

int Drone::ExistingNumberDr = 0;
int Drone::CreatedNumberDr = 0;

void Drone::Save(int i)
{
  std::fstream PlikWy;
  std::string NameOfFile;
  NameOfFile = "Korpus";
  NameOfFile.append(std::to_string(i));
  NameOfFile.append(".dat");
  PlikWy.open(NameOfFile, std::fstream::out | std::fstream::trunc);
  Korpus.SaveC(PlikWy);
  PlikWy.close();
  NameOfFile = "Camera";
  NameOfFile.append(std::to_string(i));
  NameOfFile.append(".dat");
  PlikWy.open(NameOfFile, std::fstream::out | std::fstream::trunc);
  Korpus2.SaveC(PlikWy);
  PlikWy.close();
  NameOfFile = "Line";
  NameOfFile.append(std::to_string(i));
  NameOfFile.append(".dat");
  PlikWy.open(NameOfFile,ios::out|ios::app);
  SaveCenter(PlikWy);
  PlikWy.close();
  for (int j = 0; j < NUMBER_OF_ROTORS; ++j) 
  {
    NameOfFile = "Rotor";
    NameOfFile.append(std::to_string(i));
    NameOfFile.append("_");
    NameOfFile.append(std::to_string(j));
    NameOfFile.append(".dat");
    PlikWy.open(NameOfFile, std::fstream::out| std::fstream::trunc);
    Rotor[j].SaveP(PlikWy);
    PlikWy.close();
  }
  
}

void Drone::Init()
{
  Korpus.Init();
  Korpus2.Init2();
  Vector3D vec = Vector3D();
  for (int i = 0; i < NUMBER_OF_ROTORS; ++i) 
  {
    Rotor[i].Init();
  }
  Rotor[0].SetLocatcion(Vector3D(5, 5, 7));
  Rotor[1].SetLocatcion(Vector3D(5, -5, 7));
  Rotor[2].SetLocatcion(Vector3D(-5, 5, 7));
  Rotor[3].SetLocatcion(Vector3D(-5, -5, 7));

  SetRadius(8.5); //Ustawienie promienia okręgu na 10 jednostek
  SetCenter(Point3D(0,0,0)); 
  SetHeight(16);

}
int Drone::Move(PzG::LaczeDoGNUPlota Link,int i,std::list<std::shared_ptr<SceneObject>> SceneObjects) 
{
  Vector3D ruch_uz, ruch_kon;
  double kat;
  int ilosc_klatek;
  std::cout << "Enter the number of moving units > ";
  std::cin >> ruch_uz[0];
  ilosc_klatek = abs(ruch_uz[0])*4;
  std::cout << "Enter the climb angle > ";
  std::cin >> kat;
  ruch_kon[0] = ruch_uz[0] * cos(Angle * M_PI / 180);
  ruch_kon[1] = ruch_uz[0] * sin(Angle * M_PI / 180);
  ruch_kon[2] = tan(kat * M_PI / 180) * abs(ruch_uz[0]);
  for (int klatka = 0; klatka < ilosc_klatek; ++klatka) 
  {
    Korpus.MoveByVector(ruch_kon / ilosc_klatek);
    Korpus2.MoveByVector(ruch_kon / ilosc_klatek);
    Center+=(ruch_kon / ilosc_klatek);
    if(IsCollision(SceneObjects))
      {
        Korpus.MoveByVector((ruch_kon / ilosc_klatek).Reverse());
        Korpus2.MoveByVector((ruch_kon / ilosc_klatek).Reverse());
        Center+=((ruch_kon / ilosc_klatek).Reverse());
        return 0;
      }
    for (int i = 0; i < NUMBER_OF_ROTORS; ++i) 
    {
      Rotor[i].MoveByVector(ruch_kon / ilosc_klatek);
    }
    Animation(Link,i);
    Save(i);
    Link.Rysuj();
    usleep(2000);
  }
  return 1;
}
void Drone::MoveByVector(const Vector3D& vec)
{
  Korpus.MoveByVector(vec);
  Korpus2.MoveByVector(vec);
  for (int k = 0; k < NUMBER_OF_ROTORS; ++k) 
  {
  Rotor[k].MoveByVector(vec);
  }
  Center+=vec;
}
void Drone::Rotation(PzG::LaczeDoGNUPlota Link,int i) 
{
  double angle;
  std::cout << "Enter the rotation angle > ";
  std::cin >> angle;
  Angle += angle;
  if (Angle >= 360) //minimalizacja pracy
    Angle -= 360;
  else if (Angle <= -360)
    Angle += 360;

  for (int klatka = 0; klatka < abs(angle); ++klatka) 
  {
    Korpus.Rotation(1);
    Korpus2.Rotation(1);
    for (int i = 0; i < NUMBER_OF_ROTORS; ++i) 
    {
      Rotor[i].Rotation(1);
    }
    Animation(Link,i);
    Save(i);
    Link.Rysuj();
    usleep(20000);
  }
}

void Drone::Animation(PzG::LaczeDoGNUPlota Link,int i ) 
{
  UpdateRotors();
  Rotor[0].RotationOfRotor(10);
  Rotor[1].RotationOfRotor(-10);
  Rotor[2].RotationOfRotor(-10);
  Rotor[3].RotationOfRotor(10);

  Save(i);
  Link.Rysuj();
  usleep(1000);
}

void Drone::UpdateRotors() 
{
  for (int i = 0; i < NUMBER_OF_ROTORS; ++i) 
  {
    Rotor[i].SetOffset(Korpus[i]);
  }
}

void Drone::Enlarge(double en,PzG::LaczeDoGNUPlota Link,int i) 
{
  Korpus.Enlarge(en);
  Korpus2.Enlarge(en);
  for (int i = 0; i < NUMBER_OF_ROTORS; ++i) 
  {
    Rotor[i].Enlarge(en);
  }
  double r=Radius*en;
  SetRadius(r);
  r=Height*en;
  SetHeight(r);
  Save(i);
  Link.Rysuj();
  usleep(1000);
}
void Drone::SetCenter(const Point3D& point)
{
  Center = point;
}
void Drone::SetRadius(const double &r)
{
  Radius = r;
}
void Drone::SetHeight(const double &h)
{
  Height = h;
}

void Drone::SaveCenter(std::ostream &Strm)
{
  for(int k=0;k<3;++k)
    {Strm << std::setw(16) << std::fixed << std::setprecision(10)<< Center(k);}
        Strm << std::endl;
}
bool Drone::IsCollision(std::list<std::shared_ptr<SceneObject>> SceneObjects)
{
  for( std::shared_ptr<SceneObject> object : SceneObjects)
  {
    if(this==object.get())
    {
      continue;
    }
    if(GetRadius()+object->GetRadius() > GetCenter().Length2D(object->GetCenter()))
    {
      if(abs(GetCenter()(2)-object->GetCenter()(2)<GetHeight()))
      { 
        std::cout<< "Collision follows!!!\n ";
        return true; 
      }
    }
  }
  return false;
}
std::shared_ptr<Drone> Drone::CreateDrone()
{
  shared_ptr<Drone> new_drone(new Drone());
  return new_drone;
}

void Drone::Set(PzG::LaczeDoGNUPlota &Link)
{
  Vector3D position;
  std::cout <<"enter the position of drone"<<std::endl;
  std::cin>>position;
  Init();
  MoveByVector(position);
  int i = RetExistingNumberDr();
  Save(i);
  string NameOfFile;
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
