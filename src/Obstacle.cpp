#include "Obstacle.hh"

void Obstacle::MoveByVector(const Vector3D &vec)
{
  for (long unsigned int i = 0; i < P_glob.size(); ++i) 
  {
    P_glob[i] += vec;
  }
  Center+=vec;
  Vec_Trans += vec;
}
void Obstacle::Rotation(double Angle1) 
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
void Obstacle::Init()
{
  P.push_back(Point3D(5, 5, 0));
  P.push_back(Point3D(5, -5, 0));
  P.push_back(Point3D(-5, 5, 0));
  P.push_back(Point3D(-5, -5, 0));

  P.push_back(Point3D(-5, 5, -5));
  P.push_back(Point3D(-5, -5, -5));
  P.push_back(Point3D(5, 5, -5));
  P.push_back(Point3D(5, -5, -5));

  P_glob = P;

  SetCenter(Point3D(0,0,-2.5));
  SetRadius(7.5);
  SetHeight(P[0](2)-P[4](2));
}
void Obstacle::SaveX(std::ostream &Strm)
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
void Obstacle::Save(int i)
{
  std::fstream PlikWy;
  std::string NameOfFile;
  NameOfFile = "Obstacle";
  NameOfFile.append(std::to_string(i));
  NameOfFile.append(".dat");
  PlikWy.open(NameOfFile, std::fstream::out);
  SaveX(PlikWy);
  PlikWy.close();
}

Obstacle Obstacle::operator+(Vector3D Arg2) 
{
  for (long unsigned int i = 0; i < P.size(); ++i) 
  {
    P_glob[i] += Arg2;
  }
  return (*this);
}

void Obstacle::Enlarge(double en)
{
  for (long unsigned int i = 0; i < P_glob.size(); ++i) 
  {
    P[i] *= en;
    P_glob[i] = P[i] + Vec_Trans;
  }
  Vec_Trans *= en;
}

void Obstacle::SetCenter(const Point3D& point)
{
  Center = point;
}
void Obstacle::SetRadius(const double &r)
{
  Radius = r;
}
void Obstacle::SetHeight(const double &h)
{
  Height = h;
}

void Obstacle::SaveCenter(std::ostream &Strm)
{
  for(int k=0;k<3;++k)
    {Strm << std::setw(16) << std::fixed << std::setprecision(10)<< Center(k);}
    Strm << std::endl;
}