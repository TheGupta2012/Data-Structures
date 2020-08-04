#include<bits/stdc++.h>
#define MAX 10
using namespace std;
int Q[MAX];
int front=0;
int rear=0;
void insert(int ele)
{	if(rear!=MAX)
		Q[rear++]=ele;
	else cout<<"\nQueue is full.";
}
void del()
{	
	if(front==rear)
	{
		cout<<"\nEmpty queue.";
		if(front!=0)
			front=rear=0;
	}
	
	else
	{
		cout<<endl<<Q[front++]<<" was deleted.";
		if(front==rear)
			front=rear=0;
	}
}
void show()
{
	if(front==rear)
		cout<<"\nEmpty queue.";
	else
	{  cout<<"\n Queue is (front->rear) :"; 
	for(int i=front;i<rear;i++)
			cout<<Q[i]<<" ";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int choice;
	cout<<"\n\t\t\t\t\t\tQUEUE USING AN ARRAY";
	cout<<"\nOPERATIONS->\n 1.Insert element\n 2.Delete from queue\n 3.Show queue\n 4.(-1) to exit.";
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
				case(2):{ del();
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
