#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
vector<pair <string,string> > relations; 
int countemp(string person)
{
	int counter;
	counter=0;
	tr(relations,it)
	{
		if(it->second==person)
		{
			counter++;
			counter+=countemp(it->first);
		}
	}
	return counter;
}
int main()
{	string name,boss;
	relations.reserve(100);
	cout<<"Enter the no. of employee:";
	int no;
	cin>>no;
	int i=0;
	while(no--)
	{
		cout<<"\n Enter name:";
		cin>>name;
		cout<<" Enter boss:";
		cin>>boss;
		relations.push_back(make_pair(name,boss));
	}
	cout<<"\nYour list is:";
	tr(relations,it)
	{
		cout<<"\nname :"<<it->first;
		cout<<"  boss :"<<it->second;
	}
	cout<<"\nThe number of employees working under sally is:"<<countemp("sally");
	return 0;
}

