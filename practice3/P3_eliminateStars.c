#include<stdio.h>
int visit[1027][1027];
int n,m;
char q[1027][1027];
int my_min(int a,int b)
{
    return a<b?a:b;
}
int my_max(int a,int b)
{
    return a>b?a:b;
}
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
int MyAdd(int x,int y)
{
	if(y==0) return x;
	return MyAdd(x^y,(x&y)<<1);
}
int dfs(int a,int b)
{
    int x;
    int y; 
    visit[a][b]=1;
    int dx[4]={-1,1,0,0},k;
    int dy[4]={0,0,-1,1};
    for(k=0;k<4;k++)
    {
        x=MyAdd(a,dx[k]);y=MyAdd(b,dy[k]);
        if(x>=0&&y>=0&&x<n&&y<m&&q[x][y]==q[a][b]&&visit[x][y]==0)
        {
            dfs(x,y);
        }
    }

}

int main()
{
    int T;
    T=qread();
    while(T--)
    {
        scanf("%d %d",&n,&m);
        getchar();
        int i,j,k;
        int sumEnergy=0;
        i=0;
        while(i<n)
        {
            for(j=0;j<m;j++)
                scanf("%c",&q[i][j]);
            getchar();
			i=MyAdd(i,1);
        }
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                visit[i][j]=0;
        for(i=0;i<n;++i){
        	j=0;
            while(j<m)
            {
            	if(visit[i][j]==0)
            	{
            		dfs(i,j);
            		sumEnergy=MyAdd(sumEnergy,1);
            	}
            	++j;
            }
		}
        printf("%d\n",sumEnergy);
    }
}

