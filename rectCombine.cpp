#include <vector>
#include <stdio.h>
#include "rect.h"
#include "testdata.hpp"
using namespace std;

int main() 
{
    //input zuobiao
    ofstream fout("output.txt");
    int maxnum=sizeof(rc)/sizeof(rc[0]);
    for(int k=0; k<=rc[maxnum-1].flag;k++)
    {
        vector<Rect> VecRect;
        for(int i=0; i<maxnum; i++)
        {
            if(rc[i].flag == k && k!=0)
            {
                Rect recttest(rc[i].x1, rc[i].y1, rc[i].x2, rc[i].y2);
                VecRect.push_back(recttest);
            }
        }
        vector<Rect> test;
        //create rectangle
        while(test.size()!=VecRect.size())
        {
        	test=VecRect;
        	for(unsigned int i=0; i < VecRect.size(); i++)
        	{
        	    for(unsigned int j=0; j< VecRect.size(); j++)
        	    {
        	    	if(j==i)
        	    	    continue;
        
        	        if(VecRect[i].IsRectIntersect(VecRect[i], VecRect[j]))
                	{
        	    	    if(i<j)
        	    	    {
        	    			VecRect[i]=VecRect[i].RecreateRect(VecRect[i], VecRect[j]);
        	    			VecRect.erase(VecRect.begin()+j);
        	    			j--;
        	    	    }
        	    	    else
        	    	    {
        	    			VecRect[i]=VecRect[i].RecreateRect(VecRect[i], VecRect[j]);
        	    			VecRect.erase(VecRect.begin()+j);
        	    			j--;
        	    			i--;
        	    	    }
        	    	}
        	    }
        	}
        }
        fout << "ex" << k << ":" << endl;
        for (int i=0; i<VecRect.size(); i++)
        {
            fout << "rectangle" << i+1 << ":" << endl;
            fout << "(" << VecRect[i].getx1() << "," << VecRect[i].gety1() << ")" << " "
                << "(" << VecRect[i].getx2() << "," << VecRect[i].gety2() << ")" << endl;
        }
        fout << endl;
    }
	fout.close();
	return 0;
}
