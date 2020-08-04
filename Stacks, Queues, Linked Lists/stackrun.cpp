#include<iostream>
#include"stacks.h"
using namespace std;
int main()
{
	st s;
	for(int i=0;i<10;i++)
		s.push(i);
	s.disp();
	for(int i=0;i<5;i++)
		s.pop();
	cout<<"\nPopped 5 times...\n";
	s.disp();
	return 0;
	
}
