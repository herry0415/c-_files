#include<iostream>
using namespace std;
int main()
{
	int n,y,m,d,total=0;
	char ch;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int z; 
		cin>>y>>ch>>m>>ch>>d;
		for(int j=y;;j++)
		{
			z=j;
			if(m<=2)
			{
				if(j%4==0&&j%100!=0)
				{
					total+=366;
				}
				else if(j%400==0)
				{
					total+=366;
				}
				else
				{
					total+=365;
				}
				if(total%7==0)
				{
					cout<<z+1<<endl;
					break;
				}
			}
			else
			{
				if((j+1)%4==0&&(j+1)%100!=0)
				{
					total+=366;
				}
				else if((j+1)%400==0)
				{
					total+=366;
				}
				else
				{
					total+=365;
				}
				if(total%7==0)
				{
					cout<<z+1<<endl;
					break;
				}
			}
		}
	}
	return 0;
}