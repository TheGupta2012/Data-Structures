#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"\nSearching element in an array\n";
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
	cout<<"\nEnter the number you want to search in the array:";
	int ele;
	bool found=false;
	cin>>ele;
	for(int i=0;i<n;i+=1)
	{
		if(ele==arr[i])
		{found=true;
		break;
		}
	}
	if(found) cout<<"\nElement exists.";
	else cout<<"\nElement does not exist.";
	return 0;
}
