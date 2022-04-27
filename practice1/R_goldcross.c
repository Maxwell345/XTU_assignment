#include <stdio.h>
int w[108][108];
int getsum(int row,int col,int width,int height)
{
	int y,x,res=0;
	for(x=1;x<=width;++x){
		res+=w[row][x];
	}  
	for(y=1;y<=height;++y){
		if(y==row) continue;
		res+=w[y][col];
	}
	return res;
}
int main()
{
	int T,n,m,i,j;
	int ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				scanf("%d",&w[i][j]);
			}
		}
		ans=0;
		
		for(i=2;i<=n-1;++i){
			for(j=2;j<=m-1;++j){
				if(getsum(i,j,m,n)>ans){
					ans=getsum(i,j,m,n);
				}
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
