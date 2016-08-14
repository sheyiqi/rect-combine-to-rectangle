#include <iostream>
using namespace std;
class Rect
{
private:
	double x1,y1,x2,y2;
public:
	Rect(double blx1, double bly1, double trx2, double try2)
	{
		this->x1=blx1;
		this->y1=bly1;
		this->x2=trx2;
		this->y2=try2;
	}
	double getx1() const
	{
		return this->x1;
	}
	double getx2() const
	{
		return this->x2;
	}
	double gety1() const
	{
		return this->y1;
	}
	double gety2() const
	{
		return this->y2;
	}
	void showRect() const
	{
		cout << "(" << getx1() << "," << gety1() << ")" << " "
			 << "(" << getx2() << "," << gety2() << ")" << endl;
	}
};