#include<bits/stdc++.h>
using namespace std;
const int N = 300010;
int n,m;
int a[N],s[N];
vector<int> alls;
vector<pair<int,int>> add,query;
int find(int x){
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid = l + r >>1;
        if(alls[mid]>=x) r = mid;
        else l = mid + 1;
    }
    return r+1;
}
int main(){
    cin>>n>>m;
    // 初始设置数据
    for(int i=1;i<=n;i++){
        int x,c;
        scanf("%d %d",&x,&c);
        add.push_back({x,c});
        alls.push_back(x);
    }
    // 询问
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    // 排序去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for(auto t:add){
        int x = find(t.first);
        a[x] = t.second;
    }
    
    for(int i=1;i<= alls.size(); i++) s[i] = s[i-1] + a[i];
    
    for(auto t:query){
        int l = find(t.first);
        int r = find(t.second);
        printf("%d\n",s[l]-s[r]);
    }
    return 0;
}