#include <stdio.h>
typedef struct{
	int px;
	int py;
}pointpos;
int getupid(pointpos UL,int side)
{
	return (2*side+1)*UL.px+UL.py;
}
int getleftid(pointpos leftside,int side)
{
	return (2*side+1)*leftside.px+side+leftside.py;
}
int countSquaresBySticks(int *edges,int side)
{
	int flag,cnt;
	int x,y,i,w;
	pointpos v;
	cnt=0;
	for(w=1;w<=side;++w){
		for(x=0;x<=side-w;++x){
			for(y=0;y<=side-w;++y){
				flag=1;
				for(i=0;i<w;++i)
				{
					v.px=x;v.py=y+i;
					if(!edges[getupid(v,side)]){
						flag=0;break;
					}
					v.px=x+i;v.py=y;
					if(!edges[getleftid(v,side)]){
						flag=0;break;
					}
					v.px=x+w;v.py=y+i;
					if(!edges[getupid(v,side)]){
						flag=0;break;
					}
					v.px=x+i;v.py=y+w;
					if(!edges[getleftid(v,side)]){
						flag=0;break;
					}
				}
				if(flag) cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	int T,n,m;
	int i,j,ans;
	int sticks[5150];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=0;i<2*n*(n+1);++i) sticks[i]=1;
		while(m--){
			scanf("%d",&j);
			sticks[j-1]=0;
		}
		ans=countSquaresBySticks(sticks,n);
		printf("%d\n",ans);
	}
	return 0;
}
