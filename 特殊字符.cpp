#include<iostream>
#include<cstring>
using namespace std;
char input(int i,int j,char a[])
{
	int t;
    for(int m=0;m<=j-i;m++)
	{
	for(int k=i;k<j-m;k++)
	{
		if(a[k]>a[k+1])
		{
			t=a[k];
			a[k]=a[k+1];
			a[k+1]=t;
		}
	}
    }
}
int main()
{
    char a[10010];
    cin.getline(a,10010);
    int alen,left=0,len=1,right;
    alen=strlen(a);
    for(int i=0;i<alen;i++)
    {
    	if(a[i]>='0'&&a[i]<='9')
    	{
    		if(a[i+1]>='0'&&a[i+1]<='9')
    		{
    			len++;
			}
			else
			{
				right=left+len-1;
				input(left,right,a);
				for(int j=left;j<left+len;j++)
				{
					cout<<a[j];
				}
				left=i+1;
				len=1;
				continue;
			}
		}
		if(a[i]>='a'&&a[i]<='z')
    	{
    		if(a[i+1]>='a'&&a[i+1]<='z')
    		{
    			len++;
			}
			else
			{
				right=left+len-1;
				input(left,right,a);
				for(int j=left;j<left+len;j++)
				{
					cout<<a[j];
				}
				left=i+1;
				len=1;
				continue;
			}
		}
		if(a[i]>='A'&&a[i]<='Z')
    	{
    		if(a[i+1]>='A'&&a[i+1]<='Z')
    		{
    			len++;
			}
			else
			{
				right=left+len-1;
				input(left,right,a);
				for(int j=left;j<left+len;j++)
				{
					cout<<a[j];
				}
				left=i;
				len=1;
				continue;
			}
		}
		if(!(a[i]>='0'&&a[i]<='9')&&!(a[i]>='a'&&a[i]<='z')&&!(a[i]>='A'&&a[i]<='Z'))
    	{
    		if(!(a[i+1]>='0'&&a[i+1]<='9')&&!(a[i+1]>='a'&&a[i+1]<='z')&&!(a[i+1]>='A'&&a[i+1]<='Z'))
    		{
    			len++;
			}
			else
			{
				right=left+len-1;
				input(left,right,a);
				for(int j=left;j<left+len;j++)
				{
					cout<<a[j]<<9;
				}
				left=i;
				len=1;
				continue;
			}
		}
	}
	return 0;
}