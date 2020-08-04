#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"\nFinding Mean and Median of the numbers.\n";
	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	float arr[n];
	float sum=0;
	cout<<"\nEnter the elements...\n";
	for(int i=0;i<n;i+=1)
	{
		cout<<"Element "<<i+1<<":";
		cin>>arr[i];
		sum+=arr[i];
		}	
	sort(arr,arr+n);
	float mean=sum/n;
	cout<<"\nARRAY:- \n";
	for(int i=0;i<n;i+=1)
		cout<<arr[i]<<" ";
	cout<<"\nThe mean is "<<mean;
	if(n%2==1)
	{
		int index= (n+1)/2;
		cout<<"\nThe median is "<<arr[index-1];
	}
	else
	{
		int index1=n/2;
		int index2=index1+1;
		cout<<"\nThe median is "<<(arr[index1-1]+arr[index2-1])/2;
	}
	return 0;
}
