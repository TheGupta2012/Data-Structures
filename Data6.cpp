#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"\nPROGRAM TO STORE MARKS OF 10 STUDENTS IN 5 SUBJECTS.";
	int marks[10][5];
	cout<<"\nEnter marks...";
	for(int i=0;i<10;i++)
	{
		cout<<"\nEnter the marks of student "<<i+1<<":\n";
		for(int j=0;j<5;j++)
		{
			cout<<"Subject "<<j+1<<":";
			cin>>marks[i][j];
		}
	}
	cout<<"\nThe marks are:";
		for(int i=0;i<10;i++)
	{
		cout<<"\nStudent "<<i+1<<":\n";
		for(int j=0;j<5;j++)
		{
			cout<<"Subject "<<j+1<<":";
			cout<<marks[i][j];
		}
	}
	return 0;
	
	
	
}
