#include <stdio.h>
int my_abs(int a)
{
	return a>=0?a:-a;
}
int manh_dist(int x1,int y1,int x2,int y2)
{
	return my_abs(x1-x2)+my_abs(y1-y2);
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
int cnt[20003];
int main()
{
	int T,n,s,e;
	int res,i,pianyi,temp;
	int x_s,y_s,x_e,y_e;
	T=qread();
	while(T>0) {
        T--;
        n=qread();
        s=qread();
        if(s<=(n*(n+1))/2)
        {
        	x_s=1;
        	for(i=0;i<n;++i){
        		if((i*(i+1))/2<s&&s<=((i+1)*(i+2))/2)
        		{
        			y_s=i+1;
        			pianyi=((i+1)*(i+2))/2-s;
        			break;
				}
			}
			x_s+=pianyi;y_s-=pianyi;
		}
		else
		{
			x_s=n;temp=n*n-s+1;
			for(i=0;i<n-1;++i){
				if((i*(i+1))/2 < temp&&temp<=((i+1)*(i+2))/2)
				{
					y_s=n-i;
					pianyi=((i+1)*(i+2))/2-temp;
					break;
				}
			}
			x_s-=pianyi;y_s+=pianyi;
		}
        e=qread();
        if(e<=(n*(n+1))/2)
        {
        	x_e=1;
        	for(i=0;i<n;++i){
        		if((i*(i+1))/2<e&&e<=((i+1)*(i+2))/2)
        		{
        			y_e=i+1;
        			pianyi=((i+1)*(i+2))/2-e;
        			break;
				}
			}
			x_e+=pianyi;y_e-=pianyi;
		}
		else
		{
			x_e=n;temp=n*n-e+1;
			for(i=0;i<n-1;++i){
				if((i*(i+1))/2<temp&&temp<=((i+1)*(i+2))/2)
				{
					y_e=n-i;
					pianyi=((i+1)*(i+2))/2-temp;
					break;
				}
			}
			x_e-=pianyi;y_e+=pianyi;
		}
		res=manh_dist(x_s,y_s,x_e,y_e);
        printf("%d\n",res);
    }
}

