
#include<bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
typedef long long LL;

LL inverse(LL x, LL y)
{
    LL ans = 1;
    for (; y >>= 1; x = x * x % N)
        if (y & 1) ans = ans * x % N;
    return ans;
}

int main() {
    LL n,sum;
    cin >> n;
	LL t = sqrt(n);
	sum = (LL)((t * (t + 1) % N) % N) * (2 * t % N + 1) % N * inverse(6, N - 2) % N;  
	cout<<sum;
}         