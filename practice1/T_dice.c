#include <stdio.h>
#include <string.h>
int dec3dig(int x,int y,int z)
{
	return 100*x+10*y+z;
}
int dec2bit(int h,int f)
{
	return h*10+f;
}
int main()
{
	int T,i,j,k;
	int dice1[6],dice2[6],dice3[6];
	int p[1000];
	int q1,q2,q3,res;
	scanf("%d",&T);
	while(T--){
		for(i=0;i<6;++i) scanf("%d",&dice1[i]);
		for(i=0;i<6;++i) scanf("%d",&dice2[i]);
		for(i=0;i<6;++i) scanf("%d",&dice3[i]);
		memset(p,0,sizeof(p));
		for(i=0;i<6;++i){
			for(j=0;j<6;++j){
				for(k=0;k<6;++k)
				{
					q1=dice1[i];q2=dice2[j];q3=dice3[k];
					p[q1]=p[q2]=p[q3]=1;
					p[dec2bit(q1,q2)]=p[dec2bit(q2,q1)]=1;
					p[dec2bit(q1,q3)]=p[dec2bit(q3,q1)]=1;
					p[dec2bit(q2,q3)]=p[dec2bit(q3,q2)]=1;
					p[dec3dig(q1,q2,q3)]=p[dec3dig(q1,q3,q2)]=1;
					p[dec3dig(q2,q1,q3)]=p[dec3dig(q2,q3,q1)]=1;
					p[dec3dig(q3,q1,q2)]=p[dec3dig(q3,q2,q1)]=1;
				}
			}
		}
		res=0;
		for(i=0;i<1000;++i){
			if(p[i]) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
