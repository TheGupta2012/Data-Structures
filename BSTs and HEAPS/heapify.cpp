#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void Maxheapify(int n,int arr[]) // almost same as the deletion procedure but faster, O(n) time complexity.
{	int l,r,big,curr;
	//key point is to traverse the array from behind and look from top to down and keep adjusting.
	for(int i=n-1;i>=0;i-=1)
	{	curr=i;
		while(true)
		{ if(curr>n-1) break;
		l=2*curr+1;
		r=2*(curr+1);
		if(l>n-1 && r>n-1) break;
		else if(r>n-1) big=l;
		else if(l>n-1) big=r;
		else if (arr[r]>arr[l]) big=r;
		else big=l;
		if(arr[big]>arr[curr])
			{ swap(&arr[big],&arr[curr]);
			  curr=big;
			}
		else break;
	    }
	}
}
void Minheapify(int n,int arr[]) // almost same as the deletion procedure but faster, O(n) time complexity.
{	int l,r,small,curr;
	//key point is to traverse the array from behind and look from top to down and keep adjusting.
	for(int i=n-1;i>=0;i-=1)
	{	curr=i;
		while(true)
		{ if(curr>n-1) break;
		l=2*curr+1;
		r=2*(curr+1);
		if(l>n-1 && r>n-1) break;
		else if(r>n-1) small=l;
		else if(l>n-1) small=r;
		else if (arr[r]>arr[l]) small=r;
		else small=l;
		if(arr[small]<arr[curr])
			{ swap(&arr[small],&arr[curr]);
			  curr=small;
			}
		else break;
	    }
	}
}
int main()
{
	cout<<"\nHEAPPPPIIIFFYYYYYY.\n";
	int n;
	cout<<"\nEnter array size:";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the array:";
	for(int i=0;i<n;i+=1)
	{
		cin>>arr[i];
	}
	cout<<"\nHeap is:";
	Minheapify(n,arr);
	for(int  i=0;i<n;i+=1)
		cout<<arr[i]<<" ";
	return 0;
}
