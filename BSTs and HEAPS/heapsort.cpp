#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
// need to update...
void heapsort(int n, int arr[])
{	int curr,l,r,big;
	for(int i=n-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		curr=0;
		while(true) 
		{ if(curr>=i-1) break;  //i-1 acts as my heap partition. 
		  l=2*curr+1;
	   	  r=2*(curr+1);
	   	  if (r>i-1 && l>i-1) break; // should be first.
		  else if(l>i-1) big=r;
	   	  else if(r>i-1) big=l;
		  else if(arr[r]>arr[l]) big=r;
		  else big=l;
		  if(arr[big]>arr[curr])
			{ swap(&arr[big],&arr[curr]);
			  curr=big; }
		  else
			break;
		 }
		
	}
}
void insHeap(int n,int i, int arr[], int ele) //correct function
{	if(i==0) { arr[0]=ele;
			return;}
	arr[i]=ele;
	int current,parent;
	current=i;
	while(true)
		{if(current==0) break; 
		if(current%2==1)
		 	parent=current/2; // impoertant as zero based indexing.
		else
			parent=current/2 - 1;
		if(arr[parent]<arr[current])
			{swap(&arr[parent],&arr[current]);
			current=parent;}
		else 
		{ break;
		}
	}
	
}
int main()
{	cout<<"HEAPS ";
	cout<<"\nEnter the length of the array:";
	int n,ele;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i+=1)
		{ cout<<"\nEnter element:";
		cin>>ele;
		insHeap(n,i,arr,ele);
		cout<<"\nUpdated heap:";
		for(int j=0;j<=i;j++)
			cout<<arr[j]<<" ";
		}
	cout<<"\nYour heap is:";
	for(int i=0;i<n;i+=1)
		cout<<arr[i]<<" ";
	cout<<"\nSorted heap is:";
	heapsort(n,arr);
	for(int i=0;i<n;i+=1)
		cout<<arr[i]<<" ";
	return 0;
}
