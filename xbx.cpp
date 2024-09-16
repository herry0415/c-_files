#include<cstdio>
int m,n;
int put(int m,int n)
{
	if(m==0||n==1){
		printf("输出01");
		return 1; 
	}
	
	
    if(m >= n)
    return put(m,n-1)+put(m-n,n);
    else
    return put(m,n);
}
int main()
{
	scanf("%d %d",&m,&n);
	printf("%d\n",put(m,n));
	return 0;
}