#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"\nSorting an array...\n";
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	float a[100000];
	cout<<"\nEnter the elements...\n";
	for(int i=0;i<n;i+=1)
	{
		cout<<"Element "<<i+1<<":";
		cin>>a[i];
	}
	int min,minind,temp;
	for(int i=0;i<n;i+=1)
	{	min=a[i];
		minind=i;
		for(int j=i+1;j<n;j+=1)
		{
			if(a[j]<min)
				{min=a[j];
				minind=j;}
		}
		
		if(minind!=i)
		{
			temp=a[i];
			a[i]=a[minind];
			a[minind]=temp;
		}
	}
	cout<<"\nThe sorted array is:";
	for(int i=0;i<n;i+=1)
		cout<<a[i]<<" ";
	return 0;
}
