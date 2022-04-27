#include <stdio.h>
int abs(int m)
{
	return m>=0?m:-m;
}
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	int a,b,c,d;
	int t,p,q,factor;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		p=abs((b-a)*d+(d-c)*b-a*d-(b-a)*(d-c));
		q=abs(2*b*d);
		factor=gcd(p,q);
		p/=factor;
		q/=factor;
		if(p==0) printf("0\n");
		else printf("%d/%d\n",p,q);
	}
	return 0;
}
