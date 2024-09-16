#include<iostream>
#include<string>
using namespace std;
int main()
{
	string sput;
	string snew;
	string sold;
	getline(cin,sput);
	getline(cin,snew);
	getline(cin,sold);
	int newlen=snew.length();
	int oldlen=sold.length();
	int a;
	while(a=(sput.find(snew)) !=-1)
	{
		cout<<a<<" "<<newlen<<" "<<snew<<endl;
		sput.replace(a,newlen,snew);
		cout<<"after:"<<endl;
		cout<<a<<" "<<newlen<<" "<<snew<<endl;
	}
	cout<<sput<<endl;
	return 0;
}
