#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n;
    while (cin >> n)
    {
        LL sum = 0;
        for(LL i = sqrt(2 * n); i >= 2; i --)
        {
            if(2 * n - i * i + i > 0 && (2 * n - i * i + i) % (2 * i) == 0 )
                sum ++;
        }
        cout << sum + 1 << endl;
    }

    return 0;
}
