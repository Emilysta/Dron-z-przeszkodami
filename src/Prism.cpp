#include "Prism.hh"
#include <iomanip>
void Prism::Init() 
{
  P.push_back(Point3D(2, 2, 2));
  P.push_back(Point3D(-2, 2, 2));
  P.push_back(Point3D(3, 0, 2));
  P.push_back(Point3D(-3, 0, 2));
  P.push_back(Point3D(2, -2, 2));
  P.push_back(Point3D(-2, -2, 2));

  P.push_back(Point3D(2, -2, -2));
  P.push_back(Point3D(-2, -2, -2));
  P.push_back(Point3D(3, 0, -2));
  P.push_back(Point3D(-3, 0, -2));
  P.push_back(Point3D(2, 2, -2));
  P.push_back(Point3D(-2, 2, -2));

  P_glob = P;
}

void Prism::RotationOfRotor(double angle) 
{
  Matrix3x3 Rot_Mat;
  Rot_Mat.Matrix3x3_Z(angle);
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    this->P[i] = this->P[i] - this->offset;
    this->P[i] = this->P[i] * Rot_Mat;
    this->P[i] = this->P[i] + this->offset;
    P_glob[i] = P[i] + Vec_Trans;
  }
}
void Prism::SetOffset(Point3D Arg) 
{
  offset[0]=Arg(0);
  offset[1]=Arg(1);
  offset[2]=Arg(2);
  offset[2] += 2;
}
void Prism::SetLocatcion(Vector3D offset) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    this->P[i] += offset;
  }
  this->P_glob = this->P;
  this->offset = offset;
}
Prism Prism::operator+(Vector3D Arg2) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] += Arg2;
  }
  Vec_Trans = Vec_Trans + Arg2;
  return (*this);
}
void Prism::operator-=(Vector3D Arg2) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] -= Arg2;
  }
}
void Prism::operator+=(Vector3D Arg2) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] += Arg2;
  }
}

void Prism::SaveP(std::ostream &Strm)
{
  int Sides[6][4] = { {10, 0, 2, 8}, {8, 6, 4, 2}, {6, 7, 5, 4}, 
                      {7, 9, 3, 5}, {9, 11, 1, 3}, {11, 10, 0, 1}};

  int Pod[2][6] ={ {11, 10, 8, 6, 7, 9}, {3, 5, 4, 2, 0, 1}};
  
 for (int i = 0; i < 1; ++i)
  {
    for (int j = 0; j < 6; ++j) 
    {
      for (int k = 0; k < 3; k++) 
      {
        Strm << std::setw(16) << std::fixed << std::setprecision(10)<< P_glob[Pod[i][j]](k);
      }
      Strm << std::endl;
    }
    Strm << std::endl;
  }

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
    Strm << std::endl;
  }

  for (int i = 1; i < 2; ++i)
  {
    for (int j = 0; j < 6; ++j) 
    {
      for (int k = 0; k < 3; k++) 
      {
        Strm << std::setw(16) << std::fixed << std::setprecision(10)<< P_glob[Pod[i][j]](k);
      }
      Strm << std::endl;
    }
    Strm << std::endl;
  }
}
