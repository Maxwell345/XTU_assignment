#include <stdio.h>
int remove_zero;
int getstep(int m,int ck)
{
    return m/ck;
}
int getremain(int mm,int kk)
{
    return mm%kk;
}
int main()
{
    int i,h,f,T,step;
    int n,k,p,res,j;
    int gewei[10][10];
    for(i=0;i<10;++i){
        for(j=0;j<10;++j){
            gewei[i][j]=(i*j)%10;
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        res=0;
        while(n>=k){
            h=n%10;f=k%10;
            p=-1;
            for(i=0;i<10;++i){
                if(gewei[f][i]==h)
                {
                    p=i;
                    break;
                }
            }
            if(p==-1||n-k*p<k){
                step=getstep(n,k);
                n=getremain(n,k);
                res+=step;
                goto ans;
            }
            else
            {
                n-=(p*k);res+=p;
                remove_zero=0;
                while(n%10==0&&n>0){
                    n/=10;remove_zero=1;
                }
                if(remove_zero) res++;
            }
        }
        ans:
            printf("%d %d\n",res,n);
    }
}
