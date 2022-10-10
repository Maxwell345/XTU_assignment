#include <stdio.h>
typedef struct{
	double realPart,imagPart;
}CNUM;

int main()
{
	CNUM zz,res;
	double a,b,c,d;
	int n;
	n=1000;
	zz.realPart=1.00;zz.imagPart=3.1415926*0.001;
	res.realPart=1.00;res.imagPart=0.00;
	while(n--){
		a=res.realPart;b=res.imagPart;
		c=zz.realPart;d=zz.imagPart;
		res.realPart=(a*c-b*d);res.imagPart=(a*d+b*c);
	}
	printf("result:%.6f + %.6f i\n",res.realPart,res.imagPart);
}
