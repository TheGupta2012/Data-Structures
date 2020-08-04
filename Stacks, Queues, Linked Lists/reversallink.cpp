//Reversing a link lsit...
#include<iostream>
#include"LINKS.h"
using namespace std;
int main()
{
	links link;
	for(int i=1;i<=10;i++)
		link.insert(i*i);
	cout<<"Original ink list is:\n";
	link.disp(link.head);
	struct node* H = link.reverse(link.head);
	link.disp(link.H);
	link.insert(8);
	//link.disp();
	//link.reverse();
	
	
}

