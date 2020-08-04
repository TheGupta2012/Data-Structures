#include<bits/stdc++.h>
#include<stack>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
void DFSgraph(int ADM[100][100], int n, vector<string> v)
{
	stack <int> ST;
	bool visited[n]= {false};
	
	visited[0]=true;
	ST.push(0);
	cout<<v[0]<<" ";
	int flag;
	while(!ST.empty())
	{	int current = ST.top();
		for(int k=0;k<n;k+=1)
		{   flag=0;
			if(ADM[current][k]==1 && visited[k]==false)
				{	ST.push(k);
					visited[k]=true;
					cout<<v[k]<<" ";
					flag=1;
					break; // break the loop to go to the just found element.
				}
		}
		if(flag!=1) // to incorporate the fact that there may be a node for which all the 
					// nodes have been visited pop that node.
			ST.pop();
		else continue;
	}
}
bool pathDFS(int i, int j, int ADM[100][100],int n)
{
	stack <int> ST;
	bool visited[n]= {false};
	visited[i]=true;
	ST.push(i);
	int flag;
	while(visited[j]!=true && !ST.empty())
	{	int current = ST.top();
		for(int k=0;k<n;k+=1)
		{   flag=0;
			if(ADM[current][k]==1 && visited[k]==false)
				{	ST.push(k);
					visited[k]=true;
					flag=1;
					break;
				}
		}
		if(flag!=1) ST.pop();
		else continue;
	}
	return (visited[j]);
}
int main()
{
	ios::sync_with_stdio(false);
	//making graphs->
	cout<<"\nGRAPHS...\nImplementing paths and cycles...";
	cout<<"\nEnter the no. of vertices:";
	int n;
	cin>>n;
	string ele;
	vector <string> V;
	cout<<"\nEnter the name of node:\n";
	for(int i=0;i<n;i++)
	{	cout<<"Vertex "<<i+1<<":";
		cin>>ele;
		V.push_back(ele);
	} 
	cout<<"\nYour vertices are:\n";
	tr(V,it)
	{cout<<it-V.begin()<<":"<<*it<<endl;
	}
	char type;
	y:cout<<"\nEnter D for directed graph and U for undirected graph:";
	cin>>type;
	if( type!='D' && type!='U' ) 
		{cout<<"Invalid.\nEnter again.";
		goto y;}
	cout<<"\nEnter the relation between the vertices:";
	int ADM[100][100];
	int copy[100][100];
	for(int q=0;q<n;q++)
	{	for(int w=0;w<n;w++)
		  ADM[q][w]=copy[q][w]=0;
		 
	}
	string v1,v2;
	int count=0;
	int i,j;
	while(true)
	{	if((type=='U' && count==n*(n-1)/2) ||(type=='D' && count==(n)*(n-1)))
	  		{cout<<"Max edges are reached.";
	  		break;}
		s:cout<<"\nName of V1:";
		cin>>v1;
		cout<<"Name of V2:";
		cin>>v2;
		count+=1;
		i=find(V.begin(),V.end(),v1)-V.begin();
		j=find(V.begin(),V.end(),v2)-V.begin();
		if (i==n || j==n)
			{cout<<"\nNo such vertex pair exists.\nEnter again.";
			goto s;}
		ADM[i][j]=1;
		copy[i][j]=1;
		if(type=='U') 
			{ADM[j][i]=1;
			copy[j][i]=1;}
		cout<<"\nEnter 1 for more edges or -1 for exit:";
		int ch1;
		cin>>ch1;
		if(ch1==-1) break;	
	}
	cout<<"\nThe adjacency matrix is:\n";
	for(int f=0;f<n;f++)
	{    for(int g=0;g<n;g++)
			{cout<<ADM[f][g]<<" ";}
		cout<<endl;
	}
	cout<<"\nEnter two nodes for the path search:";
	string V1,V2;
	cout<<"\nNODE1:";
	cin>>V1;
	cout<<"\nNODE2:";
	cin>>V2;
	int p,q;
	p=find(V.begin(),V.end(),V1)-V.begin();
	q=find(V.begin(),V.end(),V2)-V.begin();
	if(pathDFS(p,q,ADM,n)==true) cout<<"\nPath exists.";
	else cout<<"\nNO PATH.";
	cout<<"\nThe Depth First Search of your graph is:";
	DFSgraph(ADM,n,V);
	return 0;
}
