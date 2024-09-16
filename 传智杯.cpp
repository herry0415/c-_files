#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int mark = 0;  
int head[N]; 
int dp[N]={0}; 
int color[N]={0}; 

struct tree
{
    int value; 
    int next;  
}edge[N];



void addedge(int x, int y,int pos)
{
    edge[pos].value = y;
    edge[pos].next = head[x];
    head[x] = pos;
}

int dfs1(int x,int father)
{
    int son=0;
    for(int i=head[x];i != -1;i = edge[i].next)
    {
        if(edge[i].value != father) // 避免回环
        {
            ++son;
            if(dfs1(edge[i].value,x)) return 1; 
        }
    }
    // son==0表示叶子节点 ； dp[x]==0 表示 x 这个点未被标记
    if(son == 0 || dp[x]==0)
    {
        if(dp[father] !=0) return 1; // 一个节点被多次标记，无解
        dp[x] = dp[father] = ++mark;
    }
    return 0;
}

void dfs2(int x,int father)
{
    for(int i=head[x];i != -1;i = edge[i].next)
    {
        if(edge[i].value != father) // 避免回环
        {
            if(dp[edge[i].value] == dp[x])
                color[edge[i].value] = color[x]; // 两个节点标记相同，则颜色相同
            else
                color[edge[i].value] = !color[x]; // 两个节点标记不同，则颜色不同
            dfs2(edge[i].value, x);
        }
    }
}

int main()
{
    int x,y,n,pos=1;
    scanf("%d",&n);
    memset(head, -1, sizeof(head));
    memset(edge, -1, sizeof(edge));
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        addedge(x, y,pos);
        ++pos;
        addedge(y, x,pos);
        ++pos;
    }
    if(dfs1(1,0) || dp[0])
    {
        printf("-1");
        return 0;
    }
    color[1]=1; 
    dfs2(1,0);
    for(int i=1;i<=n;++i)
    {
        printf("%c",color[i]?'R':'B');
    }
    return 0;
}

