#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Rect
{
private:
	double x1,y1,x2,y2;
public:
	Rect(double BLx, double BLy, double TRx, double TRy)
	{
		this->x1=BLX;
		this->y1=BLy;
		this->x2=TRx;
		this->y2=TRy;
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
    bool IsRectIntersect(const Rect& rc1, const Rect& rc2)
    {
        return ((std::max(rc1.getx1(), rc1.getx2()) >= std::min(rc2.getx1(), rc2.getx2())) &&
                (std::max(rc2.getx1(), rc2.getx2()) >= std::min(rc1.getx1(), rc1.getx2())) &&
                (std::max(rc1.gety1(), rc1.gety2()) >= std::min(rc2.gety1(), rc2.gety2())) &&
                (std::max(rc2.gety1(), rc2.gety2()) >= std::min(rc1.gety1(), rc1.gety2())) );
    }
    Rect RecreateRect(const Rect &rc1, const Rect &rc2)
    {
        return Rect( std::min(rc1.getx1(), rc2.getx1()),
                     std::min(rc1.gety1(), rc2.gety1()),
                     std::min(rc1.getx2(), rc2.getx2()),
                     std::min(rc1.gety2(), rc2.gety2()));
    }
};
