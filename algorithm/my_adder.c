#include <stdio.h>
int tempa[10];
int tempb[10];
int res[10];
int bindec(int *dig)
{
	int j,s;
	s=0;
	for(j=0;j<10;++j){
		s<<=1;
		s+=dig[j];
	}
	return s;
}
int main()
{
	int a,b,i;
	int ans,cin,ga,gb;
	scanf("%d%d",&a,&b);
	ga=a;gb=b;
	for(i=9;i>=0;--i){
		tempa[i]=a&1;
		a>>=1;
	}
	for(i=9;i>=0;--i){
		tempb[i]=b&1;
		b>>=1;
	}
	cin=0;
	printf("a = 0b");for(i=0;i<10;i++){printf("%d",tempa[i]);}printf("=%d\n",ga);
	printf("b = 0b");for(i=0;i<10;i++){printf("%d",tempb[i]);}printf("=%d\n",gb);
	for(i=9;i>=0;--i){
		res[i]=tempa[i]^tempb[i]^(cin);
		cin = ( cin&(tempa[i]^tempb[i]) )|( tempa[i]&tempb[i] );
	}
	printf("a+b=0b");for(i=0;i<10;i++){printf("%d",res[i]);}
	ans=bindec(res);
	printf("=%d\n",ans);
	if(cin) printf("OVERFLOWED!\n");
	else    printf("didn\'t overflow\n");
}
