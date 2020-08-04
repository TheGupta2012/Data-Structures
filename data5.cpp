#include<bits/stdc++.h>
#define For(i,n) for(int i=0;i<n;i++)
using namespace std;
void merged(float a[],int n,float b[], int m)
{	cout<<"\nMerged arrays are:";
	int k,i,j;
	i=j=k=0;
	while(k<n+m)
	{
		if(a[i]<b[j] || j==m)
			{ cout<<a[i]<<" ";
			i+=1;
			k+=1;}
		else if(a[i]>b[j] || i==n)
			{
				cout<<b[j]<<" ";
				j+=1;
				k+=1;
			}
		else
		{
			cout<<a[i]<<" "<<b[j]<<" ";
			i+=1;
			j+=1;
			k+=2;
		}
	}
}
void selection (float a[],int n)
{
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
}
int main()
{
	cout<<"\nMerging two sorted arrays...\n";
	int n,m;
	cout<<"Enter the size of array 1:";
	cin>>n;
	float a[100000];
	cout<<"\nEnter the elements of array 1...\n";
	for(int i=0;i<n;i+=1)
	{
		cout<<"Element "<<i+1<<":";
		cin>>a[i];
	}
	cout<<"Enter the size of array 2:";
	cin>>m;
	float b[100000];
	cout<<"\nEnter the elements of array 2...\n";
	for(int i=0;i<m;i+=1)
	{
		cout<<"Element "<<i+1<<":";
		cin>>b[i];
	}
	selection(a,n);
	selection(b,m);
	cout<<"\nThe sorted arrays are:";
	cout<<"\nArray 1: ";
	For(i,n)
		cout<<a[i]<<" ";
	cout<<"\nArray 2: ";
	For(i,m)
		cout<<b[i]<<" ";
	merged(a,n,b,m);
	return 0;
}
