#include <stdio.h>
#include <math.h>
#include <string.h>
char paint[25][25];
void DrawDiamond(int x,int y)
{
	paint[x][y]='/';
	paint[x][y+1]='\\';
	paint[x+1][y]='\\';
	paint[x+1][y+1]='/';
}
int get_border(char *row)
{
	int pos;
	for(pos=24;pos>=0;--pos)
	{
		if(row[pos]!=32) break;
	}
	return pos;
}
int main()
{
	int n,i,j,m;
	int cnt,linesize;
	
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		m=(int)ceil(sqrt((double)n));
		memset(paint,32,sizeof(paint));
		cnt=n;
		for(i=0;i<m;++i){
			for(j=0;j<i+1;++j)
			{
				if(cnt<=0) goto enough;
				DrawDiamond(i,m-1-i+2*j);
				cnt--;
			}
		}
		for(i=0;i<m-1;++i){
			for(j=0;j<m-1-i;++j)
			{
				if(cnt<=0) goto enough;
				DrawDiamond(m+i,i+1+2*j);
				cnt--;
			}
		}
		enough:
		for(i=0;i<2*m;++i){
			linesize=get_border(paint[i]);
			for(j=0;j<=linesize;++j){
				putchar(paint[i][j]);
			}
			if(linesize>=0) putchar('\n');
		}
	}
	return 0;
}
