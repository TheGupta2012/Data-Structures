#include<bits/stdc++.h>
#define MAX 15
using namespace std;
int st[MAX];
int top=0;
void insert(int ele)
{
	if(top==MAX)
		{cout<<"\nst overflow.";
		return;}
	else
	{
		st[top++]=ele;
	}
}
void pop()
{
	if(top==0)
		{
		cout<<"\nStack underflow.";
		return;}
	else
	{ 
		cout<<endl<<st[--top]<<" was popped.";
	}
}
void show()
{
	if(top==0)	cout<<"\nStack underflow.";
	else
	{	cout<<"\nThe stack is: ";
		for(int i=0;i<top;i++)
			cout<<st[i]<<" ";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int choice;
	cout<<"\n\t\t\t\t\t\tSTACK USING AN ARRAY";
	cout<<"\nOPERATIONS->\n 1.Insert element\n 2.Delete/Pop from stack\n 3.Show stack\n 4.(-1) to exit.";
	while(1)
	{
		cout<<"\n Enter choice:";
		cin>>choice;
		if(choice==-1)	break;
		else
		{
			switch(choice)
			{
				case(1):{ int ele;
						cout<<"\nEnter the element:";
						cin>>ele;
						insert(ele);
					break;
				}
				case(2):{ pop();
					break;
				}
				case (3):{ show();
					break;
				}
				default:{
					break;
				}
					}		
			}
	}
	return 0;
}
