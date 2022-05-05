#include <iostream>
#include <cstring>
using namespace std;
int a[10008];
int check (int ans,int size,int k)
{
    int sumt=0;
    int i;
    int i_count=0;
    for (i=1;i<=size;++i)
    {
        sumt+=a[i];
        if (sumt>ans)
        {
            sumt=a[i];
            ++i_count;
        }
        if (i_count>=k)
        {
            return 0;
        }
    }
    return 1;
}
int main ()
{
	int t;
    int i,begin,end,ans;
    int n,m,maxd,sumd;
    cin>>t;
    while (t--)
    {
	    cin>>n>>m;
	    i;
	    maxd=-1;
	    sumd=0;
	    memset (a,0,sizeof(a));
	    for (i=1;i<=n ;i++ )
	    {
	        scanf ("%d",&a[i]);
	        if (maxd<a[i])
	        {
	            maxd= a[i];
	        }
	        sumd+= a[i];
	    }
	    begin=maxd;
	    end = sumd;
	    ans=9999999;
	    while (begin<=end)
	    {
	        int mid=(begin+end)/2;
	        if (check(mid,n,m))
	        {
	            if (ans>mid)
	            {
	                ans=mid;
	            }
	            end=mid-1;
	        }
	        else
	        {
	            begin=mid+1;
	        }
	    }
	    cout<<ans<<endl;
    }
    return 0;
}
