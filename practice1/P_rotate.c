#include <stdio.h>
int a[12];
int b[4];
int nextpos(int x,int size)
{
    int pos=x+1;
    if(pos>=size) pos-=size;
    return pos;
}
int main()
{
	int T,i,j,tmp;
	int max31,max22,s_inner,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a[0]);scanf("%d",&a[1]);scanf("%d",&a[2]);scanf("%d",&a[3]);
		scanf("%d",&a[11]);scanf("%d",&b[0]);scanf("%d",&b[1]);scanf("%d",&a[4]);
		scanf("%d",&a[10]);scanf("%d",&b[3]);scanf("%d",&b[2]);scanf("%d",&a[5]);
		scanf("%d",&a[9]);scanf("%d",&a[8]);scanf("%d",&a[7]);scanf("%d",&a[6]);
		s_inner=b[0]+b[1]+b[2]+b[3];
		max31=0;
		for(i=0;i<12;++i){
			for(j=0;j<4;++j){
				tmp=a[i]+a[nextpos(i,12)]+a[nextpos(nextpos(i,12),12)]+b[j];
				if(tmp>max31) max31=tmp;
			}
		}
		max22=0;
		for(i=0;i<12;++i){
			for(j=0;j<4;++j){
				tmp=a[i]+a[nextpos(i,12)]+b[j]+b[nextpos(j,4)];
				if(tmp>max22) max22=tmp;
			}
		}
		ans=max31;
		if(max22>ans) ans=max22;
		if(s_inner>ans) ans=s_inner;
		printf("%d\n",ans);
	}
}
