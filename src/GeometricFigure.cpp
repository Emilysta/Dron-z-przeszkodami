#include "GeometricFigure.hh"
#include <iomanip>

void GeometricFigure::MoveByVector(const Vector3D &vec)
{
  for (long unsigned int i = 0; i < P_glob.size(); ++i) 
  {
    P_glob[i] += vec;
  }
  Vec_Trans += vec;
}
void GeometricFigure::Rotation(double Angle1) 
{
  Matrix3x3 Rot_Mat;
  Rot_Mat.Matrix3x3_Z(Angle1);
  Angle += Angle1;
  if (Angle >= 360)
    Angle -= 360;
  else if (Angle <= -360)
    Angle += 360;
  for (long unsigned int i = 0; i < P_glob.size(); ++i) 
  {
    P[i] = P[i] * Rot_Mat;
    P_glob[i] = P[i] + Vec_Trans;
  }
}
void GeometricFigure::Save(std::ostream &Strm)
  {
  for (long unsigned int i = 0; i < P_glob.size(); i++) 
  {
    if (i % 2 == 0) Strm << std::endl;
    for (int j = 0; j < 3; j++) 
    {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << P_glob[i](j);
    }
    Strm << std::endl;
  }
  Strm << std::endl;
  for (int i = 0; i < 2; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << P_glob[i](j);
    }
    Strm << std::endl;
  }
}
GeometricFigure GeometricFigure::operator+(Vector3D Arg2) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] += Arg2;
  }
  return (*this);
}
void GeometricFigure::Enlarge(double en)
{
  for (long unsigned int i = 0; i < P_glob.size(); ++i) 
  {
    P[i] *= en;
    P_glob[i] = P[i] + Vec_Trans;
  }
}