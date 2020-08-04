#include<iostream>
#include"cirqLink.h"
using namespace std;
int main()
{
	cirQ q;
	for(int i=0;i<10;i++)
		{q.ins(i);}
	//cout<<"k";
	q.disp();
	return 0;
}
