#include <iostream>

using namespace std;

const int N = 10010;

typedef long long LL;

int n;
LL cnt[N][11] = {0};
LL s[N][11] = {0};

int main()
{
    cin >> n;
    
    for (int i = 1; i <= N; i ++ )
    {
        int tmp = i;
        while (tmp)
        {
            int t = tmp % 10;
            cnt[i][t] ++ ;
            tmp /= 10;
        }
    }
    for (int i = 1; i <= N; i ++ )
    {
        for (int j = 0; j <= 9; j ++)
        {
           cnt[i][j] += cnt[i - 1][j];
        }
    }
    
    while (n -- )
    {
        int num;
        cin >> num;
        for (int i = 0; i <= 9; i ++ ) cout << cnt[num][i] << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
}
