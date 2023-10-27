#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b) 
{ return (a > b) ? a : b; }
 
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
 
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main()
{
	int items;
	cout<<"Enter number of items : ";
	cin>>items;
	int weight[items],profit[items];
	for(int i=0; i<items; i++)
	{
		cout<<i+1<<") Enter weight : ";
		cin>>weight[i];
		cout<<i+1<<") Enter profit : ";
		cin>>profit[i];
	}
	int W;
	cout<<"\nEnter bag capacity : ";
	cin>>W;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout <<"Max Profit : "<< knapSack(W, weight, profit, n) <<"\n";
    return 0;
}
