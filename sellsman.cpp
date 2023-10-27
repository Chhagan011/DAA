#include<iostream>
using namespace std;

int input[10][10];
int v,cost, infi = 99999;

void inpt()
{
	cout<<"Enter number of vertices : .\n";
	cin>>v;
	cout<<"Enter input matrix.\n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			if(i == j)
				input[i][j] = infi;
			else
			{
				cout<<"input["<<i<<"]["<<j<<"] = ";
				cin>>input[i][j];
			}
		}
	}
	cout<<"\nInput matrix is as follows.\n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			cout<<input[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void rowrdn()
{
	for(int i=0; i<v; i++)
	{
		int min=999;
		for(int j=0; j<v; j++)
		{
			if(input[i][j] < min && input[i][j] != infi)
				min = input[i][j];
		}
		for(int j=0; j<v; j++)
		{
			if(input[i][j] != infi)
				input[i][j] -= min;
		}
		input[i][v] = min;
	}
	cout<<"\nRow reduced matrix is as follows.\n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<=v; j++)
		{
			cout<<input[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void colrdn()
{
	for(int i=0; i<v; i++)
	{
		int min=999;
		for(int j=0; j<v; j++)
		{
			if(input[j][i] < min && input[j][i] != infi)
				min = input[j][i];
		}
		for(int j=0; j<v; j++)
		{
			if(input[j][i] != infi)
				input[j][i] -= min;
		}
		input[v][i] = min;
	}
	cout<<"\nColumn reduced matrix is as follows.\n";
	for(int i=0; i<=v; i++)
	{
		for(int j=0; j<=v; j++)
		{
			cout<<input[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cost=0;
	for(int i=0; i<v; i++)
	{
		cost += input[v][i];
		cost += input[i][v];
	}
	cout<<"Redused cost is : "<<cost<<"\n";
}

int path(int n1)
{
	int r1[10][10];
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			r1[i][j] = input[i][j];	
		}
	}
}


int main()
{
	inpt();
	rowrdn();
	colrdn();
	path(1);
}
