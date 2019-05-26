
#include "stage_service.hh"
#include "Scene.hh"
int main() 
{
  Scene *sc=new Scene();// scena 
  sc->GetLink().Rysuj();
  DisplayMenu();
  Current(sc);
  char wybor;
  while (1) 
  {
    std::cin >> wybor;
    switch (wybor) 
    {
      case 'o':
      {
       sc->WhichDrone()->Rotation(sc->GetLink(),sc->Ind());
        sc->WhichDrone()->Save(sc->Ind());
        sc->GetLink().Rysuj();
        break;
      }
      case 's': 
      {
        sc->WhichDrone()->Move(sc->GetLink(),sc->Ind(),sc->GetList());
        sc->WhichDrone()->Save(sc->Ind());
        sc->GetLink().Rysuj();
        break;
      }
      case 'd': 
      {
        DisplayMenu();
        Current(sc);
        break;
      }
      case 'e': 
      {
        double en;
        cout<<"Enter the enlargement/reduction: ";
        cin>>en;
        while(cin.fail())
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout<<"Enter the enlargement/reduction again(as numbers): ";
          cin>>en;  
        }
        sc->WhichDrone()->Enlarge(en,sc->GetLink(),sc->Ind());
        sc->WhichDrone()->Save(sc->Ind());
        sc->GetLink().Rysuj();
        break;
      }
      case 'q': 
      {
        delete sc;
        DisplayNumbers();
        return 0;
      }
      case 'c': 
      {
        ChooseDrone(sc);
      }
    }
  }
}
