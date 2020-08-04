#include<iostream>
#define MAX 100
using namespace std;
int rear=0;
int front=0;
int arr[MAX];
void insert(int dat)
{
	if(rear==MAX && rear!=front)
		cout<<"Queue full.";
	else
	{
		if(rear==front && front!=0 && rear!=0)
		{
			rear=front=0;
			arr[rear++]=dat;
		}
		else
		{
			arr[rear++]=dat;
		}
	}
}
int del()
{
	if(front==rear)
		return -1;
	else
	{
		return(arr[front++]);
	}
}
void disp()
{
	if(front==rear)
		cout<<"Empty queue.";
	else
	{
		for(int i=front;i<rear;i++)
			cout<<arr[i]<<":";
	}
}
int main()
{
	insert(4);
	insert(2);
	insert(1);
	disp();
	
	cout<<"Element deleted is:"<<del()<<endl;
	int b,c;
	b=del();
	c=del();
	cout<<"Two more..."<<endl;
	disp();
	insert(9);
	cout<<"Front:"<<front<<endl<<"Rear:"<<rear<<endl;
	disp();
	
	return 0;
	
}

























