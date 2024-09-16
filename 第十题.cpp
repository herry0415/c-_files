#include<iostream>
#include<cmath>
using namespace std;

bool check(int n)
{
	for(int i = 2; i * i <= n; i ++)
	{
		if(n % i == 0) return false;
	}
	return true;
}
void func(int i, int n)
{
	if(n == 1)
	{
		if(check(i)) cout << i << endl;
		return ;
	}
	if(check(i))
	{
		func(i * 10 + 1, n - 1);
		func(i * 10 + 3, n - 1);
		func(i * 10 + 5, n - 1);
		func(i * 10 + 7, n - 1);
		func(i * 10 + 9, n - 1);
	}
}
int main()
{
	int n;
	cin >> n;
	func(2, n);
	func(3, n);
	func(5, n);
	func(7, n);
	
	return 0;
}
