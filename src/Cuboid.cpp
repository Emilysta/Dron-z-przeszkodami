#include "Cuboid.hh"
#include <iomanip>

void Cuboid::Init() 
{
  P.push_back(Point3D(5, 5, 5));
  P.push_back(Point3D(5, -5, 5));
  P.push_back(Point3D(-5, 5, 5));
  P.push_back(Point3D(-5, -5, 5));

  P.push_back(Point3D(-5, 5, -5));
  P.push_back(Point3D(-5, -5, -5));
  P.push_back(Point3D(5, 5, -5));
  P.push_back(Point3D(5, -5, -5));

  P_glob = P;
}

void Cuboid::Init2() 
{
  P.push_back(Point3D(2, 2, 5));
  P.push_back(Point3D(2, -2, 5));
  P.push_back(Point3D(-2, 2, 5));
  P.push_back(Point3D(-2, -2, 5));

  P.push_back(Point3D(-2, 2, -7));
  P.push_back(Point3D(-2, -2, -7));
  P.push_back(Point3D(2, 2, -7));
  P.push_back(Point3D(2, -2, -7));
    P_glob = P;
}
Cuboid Cuboid::operator+(Vector3D Arg2) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] += Arg2;
  }
  Vec_Trans = Vec_Trans + Arg2;
  return (*this);
}


void Cuboid::SaveC(std::ostream &Strm)
{
  int Sides[6][4] = { {4, 5, 7, 6}, {6, 0, 2, 4}, {7, 6, 0, 1}, 
                      {5, 7, 1, 3}, {4, 5, 3, 2},{2, 3, 1, 0}};
  for (int i = 0; i < 6; ++i)
  {
    for (int j = 0; j < 4; ++j) 
    {
      for (int k = 0; k < 3; k++) 
      {
        Strm << std::setw(16) << std::fixed << std::setprecision(10)<< P_glob[Sides[i][j]](k);
      }
      Strm << std::endl;
    }
    Strm << '#';
    Strm << std::endl;
    Strm << std::endl;
  }

}
void Cuboid::operator-=(Vector3D Arg2)
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] -= Arg2;
  }
}

void Cuboid::operator+=(Vector3D Arg2)
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] += Arg2;
  }
}