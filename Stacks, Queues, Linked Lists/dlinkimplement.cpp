#include<iostream>
#include"doublelink.h"
using namespace std;
int main()
{
		links ob;
	cout<<"DOUBLYLINKEDLIST\nInsert element at end-(1)\nInsert element after a certain element-(2)\nINsert element before a certain element-(3)\nView list-(4)\nExit-(-1)";
	int choice,it,ele;
	while (true)
	{	cout<<"\nEnter choice:";
		cin>>choice;
		if(choice!=-1)
		{
			switch(choice)
			{
				case 1: cout<<"Enter item:";
						cin>>it;
						ob.insertN(it);
						break;
				case 2: cout<<"Enter element after which you want to insert:";
						cin>>ele;
						cout<<"Enter item to insert:";
						cin>>it;
						ob.insertAft(it,ele);
						break;
				case 3: cout<<"Enter element before which you want to insert:";
						cin>>ele;
						cout<<"Enter item to insert:";
						cin>>it;
						ob.insertBef(it,ele);
				case 4: cout<<"List is:";
						ob.show();
						break;
				default: cout<<"invalid enter again.";	
				}
		}
		else
		{
			cout<<"Okay.";
			break;
		}
	}
	return 0;
}
