# include<iostream>
using namespace std;

struct items
{
	float wt;
	float val;
	float density;
};

int main()
{
	float ttlwt=0, ttlprofit=0, bagwt;
	cout<<"Enter bag capacity : ";
	cin>>bagwt;
	cout<<"Enter number of available items : ";
	int n;
	cin>>n;
	items itm[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter weight : ";
		cin>>itm[i].wt;
		cout<<"Enter value : ";
		cin>>itm[i].val;
		itm[i].density = itm[i].val /  itm[i].wt;
	}
	cout<<"weight \tvalue \tdensity\n";
	for(int i=0; i<n; i++)
	{
		cout<<itm[i].wt<<"\t"<<itm[i].val<<"\t"<<itm[i].density<<"\n";
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1-i; j++)
		{
			if(itm[j].density<itm[j+1].density)
			{
				float tmpwt = itm[j].wt;
				itm[j].wt = itm[j+1].wt;
				itm[j+1].wt = tmpwt;
				float tmpval = itm[j].val;
				itm[j].val = itm[j+1].val;
				itm[j+1].val = tmpval;
				float tmpd = itm[j].density;
				itm[j].density = itm[j+1].density;
				itm[j+1].density = tmpd;
			}
		}
	}
	cout<<"Sorted data\n";
	cout<<"weight \tvalue \tdensity\n";
	for(int i=0; i<n; i++)
	{
		cout<<itm[i].wt<<"\t"<<itm[i].val<<"\t"<<itm[i].density<<"\n";
	}
	
	cout<<"weight \tvalue \tdenst \tttlwt \tprofit\n";
	for(int i=0; i<n; i++)
	{
		if(ttlwt+itm[i].wt <= bagwt)
		{
			ttlwt = ttlwt+itm[i].wt;
			ttlprofit = ttlprofit + itm[i].val;
			cout<<itm[i].wt<<" \t"<<itm[i].val<<" \t"<<itm[i].density<<" \t"<<ttlwt<<" \t"<<ttlprofit<<"\n";
		}
		else
		{
			float tempwt = bagwt - ttlwt;
			float tempval = tempwt * itm[i].density;
			ttlwt = ttlwt+tempwt;
			ttlprofit = ttlprofit + tempval;
			cout<<tempwt<<" \t"<<tempval<<" \t"<<itm[i].density<<" \t"<<ttlwt<<" \t"<<ttlprofit<<"\n";
			break;
		}
	}
	return 0;
}
