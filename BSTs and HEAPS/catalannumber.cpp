//finding out the nth catalan number through memoization and recursion
#include<iostream>
#include<vector>
int memo[10000]={0};
using namespace std;
int catalan(int n, int *memo)
{
	if(memo[n]!=0)
		return memo[n];
	else
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=(catalan(i-1,memo)*catalan(n-i,memo));	
		}
		return sum;
	}
}
int catalan1(int n)
{	memo[0]=1;
	memo[1]=1;
	memo[2]=2;	
	return catalan(n,memo);
}

int main()
{
	cout<<"\nCalculating the Nth catalan number:";
	int n;
	cin>>n;
	cout<<"The "<<n<<" catalan number is:"<<catalan1(n);
	return 0;
}
