#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it= v.begin() ; it!=v.end();it++)
using namespace std;
void weight_union(int *arr, int i, int j)
{
	
	while(arr[i]>0)
	    i=arr[i];
	while(arr[j]>0)
		j=arr[j];
	if(i==j)
	{cout<<"Cycle detected."<<endl;
	 return;
	}
	// now select which is the more weighted parent.
	int temp = arr[i]+arr[j];
	if(arr[i]<=arr[j])
	{
		arr[i]=temp;
		arr[j]=i;//parent of j is i
	}
	else
	{
		arr[j]=temp;
		arr[i]=j;//parent of i is j
	}
}
int main()
{
	// ARRAY REPRESENTATION OF DISJOINT SETS.
	cout<<"\nEnter the no. of vertices:";
	
	int v;
	cin>>v;
	int arr[v+1],start,end,weight;;
	for(int i=0;i<=v;i++) 
		arr[i]=-1;
	cout<<"\nEnter the edges (start,end,weight)(start=-1 for exit loop):\n";
	vector < pair < pair <int,int> ,int > > edges;
	while(true)
	{
		cin>>start;
		if(start==-1)
			{cout<<"\nOkay";
			break;}
		cin>>end>>weight;
		edges.push_back({{start,end},weight});
	}
	cout<<"\nEdges inserted.";
	cout<<"\nThey are:\n";
	tr(edges,it)
	{	cout<<(it->first).first<<" "<<(it->first).second<<","<<it->second<<endl;
		weight_union(arr,(it->first).first,(it->first).second);
		cout<<"Array state:"<<endl;
		for(int i=1;i<=v;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}
/*1 2 1
3 4 2
5 6 3
7 8 4
2 4 5
2 5 6
1 3 7
6 8 8
5 7 9
-1*/

