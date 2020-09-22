#include<bits/stdc++.h>
#define all(c) c.begin(),c.end()
using namespace std;
typedef long long int lli;
bool comp( pair <pair<lli,lli> , float> a, pair <pair<lli,lli> , float> b)
{
    return (a.second>b.second);
}
int main()
{
ios::sync_with_stdio(0);
lli n;
cout<<"Enter the number of items :";
cin>>n;
cout<<"Enter the weight of knapsack:";
lli w;
cin>>w;
lli wi,pi;
cout<<"Enter the values of the weights and profits of elements pairwise :\n";
vector < pair <pair<lli,lli> , float> > ele;
//signature : {{profit,weight}, ratio}
for(lli i=0;i<n;i++)
{
    cout<<"Element "<<i+1<<" \nWeight:";
    cin>>wi;
    cout<<"Price:";
    cin>>pi;
    ele.push_back({{pi,wi},float(pi)/wi});
}
sort(all(ele),comp);
cout<<"Elements sorted by profit/weight ratio are:\n";
cout<<"P  W  P/W\n";
for(auto K:ele)
{
    cout<<K.first.first<<","<<K.first.second<<","<<K.second<<endl;
}
float profit = 0;
int count = 1;
for(auto k:ele)
{
    if((w-(k.first.second))>=0)
    {   cout<<"Element "<<count<<" is taken whole.\n";
        profit += k.first.first;
        w -= k.first.second;
    }
    else
    {   float frac = float(w)/(k.first.second);
        profit+= (frac)*(k.first.first);
        cout<<"Fraction of element "<<count<<" is "<<frac<<endl;
        break;
    }
    count++;
}
cout<<"knapsack full\nTotal profit is "<<profit;
return 0;
}
