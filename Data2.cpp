#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"\nInserting and deleting an element in an array.\n";
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	float arr[100000];
	cout<<"\nEnter the elements...\n";
	for(int i=0;i<n;i+=1)
	{
		cout<<"Element "<<i+1<<":";
		cin>>arr[i];
	}
	cout<<"\n Choices-> \n 1. Insert an element\n 2. Delete an element\n (-1) for exit \n";
	int choice;
	while(true )
	{	cout<<"\nEnter choice:";
	cin>>choice;
	if(choice==1)
	{
		int index,ele;
		x:cout<<"\nEnter the index after which you want to insert:";
		cin>>index;
		if(index>n)
			{ cout<<"\nIvalid index.\nEnter again.";
			goto x;}
		cout<<"\nEnter the element.";
		cin>>ele;
		for(int i=n-1;i>index;i-=1)
		{ arr[i+1]=arr[i];
		}
		arr[index+1]=ele;
		n++;
		cout<<"\nThe updated array is:\n";
		for(int i=0;i<n;i+=1)
		{	cout<<arr[i]<<" ";
		}
		
	}
	if(choice==2)
	{
		cout<<"\nEnter the element you want to delete->";
		int del;
		bool flag= false;
		cin>>del;
		int index;
		for(int i=0;i<n;i+=1)
		{ if(arr[i]==del)
			{
				index=i;
				flag=true;
				break;
			}
		}
		if(flag==false) cout<<"\nElement does not exist.";
		else
		{
			for(int i=index;i<n-1;i+=1)
			{ arr[i]=arr[i+1];
			}
			n--;
			cout<<"\Element deleted.\nUpdated array is:";
			for(int i=0;i<n;i+=1)
				cout<<arr[i]<<" ";
		}
	
	}
	if(choice==-1) break;
}
return 0;
}
		
