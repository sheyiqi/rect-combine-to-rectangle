#include <iostream>
#include <vector>
#include <stdio.h>
#include "rect.h"
using namespace std;

bool IsRectIntersect(const Rect &rc1, const Rect &rc2)
{
    return ((std::max(rc1.getx1(), rc1.getx2()) >= std::min(rc2.getx1(), rc2.getx2())) && 
	    (std::max(rc2.getx1(), rc2.getx2()) >= std::min(rc1.getx1(), rc1.getx2())) && 
	    (std::max(rc1.gety1(), rc1.gety2()) >= std::min(rc2.gety1(), rc2.gety2())) && 
	    (std::max(rc2.gety1(), rc2.gety2()) >= std::min(rc1.gety1(), rc1.gety2())) );
}

Rect RecreateRect(const Rect &rc1, const Rect &rc2)
{
    return Rect( std::min(rc1.getx1(),rc2.getx1()), std::min(rc1.gety1(),rc2.gety1()), std::max(rc1.getx2(),rc2.getx2()), std::max(rc1.gety2(),rc2.gety2()) );
}

int main() 
{
//input zuobiao
    vector<double> vecRect;
    double dd;
    while(cin>>dd)
    {
	vecRect.push_back(dd);
		//if(dd =="dd")
		//	break;
    }

    //create rectangle
    vector<Rect> VecRect;
    for(unsigned int i=0; i < vecRect.size() ;i+=4)
    {
	Rect rc1(vecRect[i],vecRect[i+1],vecRect[i+2],vecRect[i+3]);
	VecRect.push_back(rc1);
	//rc1.showRect();
    }
    
    //cout << VecRect.size() <<endl;
    vector<Rect> test;
    while(test.size()!=VecRect.size())
    {
	test=VecRect;
	for(unsigned int i=0; i < VecRect.size(); i++)
	{
	    for(unsigned int j=0; j< VecRect.size(); j++)
	    {
		if(j==i)
		    continue;

		VecRect[i].showRect();
		VecRect[j].showRect();
	    if(IsRectIntersect(VecRect[i], VecRect[j]))
    	{
		    cout << "rc" << i << " intersected with rc" <<  j << endl;
		    if(i<j)
		    {
				VecRect[i]=RecreateRect(VecRect[i], VecRect[j]);
				VecRect[i].showRect();
				VecRect.erase(VecRect.begin()+j);
				j--;
		    }
		    else
		    {
				VecRect[i]=RecreateRect(VecRect[i], VecRect[j]);
				VecRect[i].showRect();
				VecRect.erase(VecRect.begin()+j);
				j--;
				i--;
		    }
		}
		else
		{
	    	    cout << "rc" << i << "isn`t intersected with rc" << j << endl;
		    VecRect[i].showRect();
		    VecRect[j].showRect();
		}
	    }
	    //i--;
	}
	cout << VecRect.size() << endl;
    }
	system("pause");
	return 0;
}
