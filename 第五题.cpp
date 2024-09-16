#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N = 300010;
int n,l,r,k;
char c[N];
char s[N];
bool flg;
int main(){
    while(cin >> n)
    {
        //memset(s,0,sizeof(s));
        memset(c, 0, sizeof(c));
        for(int i=0;i<n;i++) cin>>c[i];
        int l, r, cnt;
        l = cnt = 0;
        r = n - 1;
        while(l <= r)
        {
            flg = false;
            for(int i = 0; i <= r - l; i ++)
            {
                if(c[l + i] < c[r - i])
                {
                    flg = true;
                    cnt ++;
                    break;
                }
                else if(c[l + i] > c[r - i])
                {
                    flg = false;
                    cnt ++;
                    break;
                }
            }
            if(flg) cout << c[l++];
            if(!flg) cout << c[r--];
            if(cnt % 80 == 0) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
