#include<stdio.h>
long long DP[105][105][15];
int qread()
{  
    register int x,flag;
    x=0;flag=1;
    register char c=getchar();
    
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*flag;
}
void TableInit(int row,int col)
{
    int t, i, j, k, l;
    for(i = 1; i <= row;++i)
    {
        DP[i][i][1] = 1;
        for(j = 2; j <= col;++j)
        {
            for( k = j; k <= i;++k)
            {
                for( l = k - 1; l > 0;--l)
                {
                    DP[i][k][j] += DP[i - k][l][j - 1];
                }
            }
        }
    }
}
long long My_Add(long long x, long long y)
{
	if (y == 0)
        return x;
	else
        return My_Add( x ^ y, (x & y) << 1);
}
int main()
{
    TableInit(100,10);
    long long ans;
    int T, n, m,idx;
    T=qread();
    while(T--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(idx= 0; idx<= n;++idx)
        {
            ans=My_Add(ans,DP[n][idx][m]);
        }
        printf("%I64d\n", ans);
    }
}
