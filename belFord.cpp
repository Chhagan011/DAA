#include<iostream>
using namespace std;

int v, startv;
int weight[20][20], isavail[20][20];
int d[20];		//dist from starting vertex

void inpt()
{
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"\nEnter 1 if edge exists else 0.\n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			if(i == j)
				isavail[i][j] = 0;
			else
			{
				cout<<i<<" to "<<j<<" : ";
				cin>>isavail[i][j];
			}
		}
	}
	cout<<"Enter weights of edges. \n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			weight[i][j] = 999;
			if(i == j)
				weight[i][j] = 0;
			else if(isavail[i][j] == 1)
			{
				cout<<i<<" to "<<j<<" : ";
				cin>>weight[i][j];
			}
		}
	}
}

void display()
{	
	cout<<"Weights are \n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			cout<<weight[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void belFord()
{
	cout<<"\nEnter starting vertex : ";
	cin>>startv;
	for(int i=0; i<v; i++)
	{
		d[i] = weight[startv][i];
	}
	cout<<"\nThe initial distances are.\n";
	for(int i=0; i<v; i++)
	{
		cout<<startv<<" to "<<i<<" = "<<d[i]<<"\n";
	
	}
	for(int itr=0; itr<v-1; itr++)
	{
		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
			{
				if(d[j] > d[i] + weight[i][j])
					d[j] = d[i] + weight[i][j];
			}
		}
	}
	cout<<"\nThe final distances are.\n";
	for(int i=0; i<v; i++)
	{
		cout<<startv<<" to "<<i<<" = "<<d[i]<<"\n";
	
	}
}

int main()
{
	inpt();
	display();
	belFord();
	return 0;
}
