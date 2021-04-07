#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class TwoDPoint{
private:
	int x,y;
public:
	TwoDPoint(){
		x=0;
		y=0;
	}
	TwoDPoint(int xx,int yy){
		x=xx;
		y=yy;
	}
	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
	double distance(TwoDPoint& other) const{
		return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
	}
    friend ostream& operator<<(ostream& out, const TwoDPoint& point);
};
class ThreeDPoint:public TwoDPoint{
private:
	int z;
public:
	ThreeDPoint():TwoDPoint(0,0){
		z=0;
	}
	ThreeDPoint(int xx,int yy,int zz):TwoDPoint(xx,yy){
		z=zz;
	}
	int getZ() const{
		return z;
	}
    double distance(ThreeDPoint& other){
        return sqrt((this->getX()-other.getX())*(this->getX()-other.getX())+(this->getY()-other.getY())*(this->getY()-other.getY())+(this->getZ()-other.getZ())*(this->getZ()-other.getZ()));
    }
    friend ostream& operator<<(ostream& out, const ThreeDPoint& point);
};
ostream& operator<<(ostream& out, const TwoDPoint& point)
{
    out << '(' << point.getX() << ',' << point.getY() << ')';
    return out;
}
ostream& operator<<(ostream& out, const ThreeDPoint& point)
{
    out << '(' << point.getX() << ',' << point.getY() << ',' << point.getZ() << ')';
    return out;
}

int main()
{
  //2-D Point
  TwoDPoint pa1, pa;
  int pa2_x, pa2_y;
  cin >> pa2_x >> pa2_y;
  TwoDPoint pa2(pa2_x,pa2_y);
  cout << "Distance between " << pa1 << " and " << pa2 <<" is "<<pa1.distance(pa2) << endl;
  
  //3-D Point
  ThreeDPoint pb1;
  int pb2_x, pb2_y, pb2_z, pb3_x, pb3_y, pb3_z;
  cin >> pb2_x >> pb2_y >> pb2_z;
  cin >> pb3_x >> pb3_y >> pb3_z;
  ThreeDPoint pb2(pb2_x, pb2_y, pb2_z), pb3(pb3_x, pb3_y, pb3_z);
  cout << "Distance between " << pb1 << " and " << pb2 <<" is "<<pb1.distance(pb2) << endl;
  cout << "Distance between " << pb1 << " and " << pb3 <<" is "<<pb1.distance(pb3) << endl;
  return 0;
}
