#include <stdio.h>
char alphabet[26]="abcdefghijklmnopqrstuvwxyz";
int freq[26];
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
int my_min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	int T,n,p,i,j;
	char s_a[100],s_b[100];
	int score_a,score_b,k1,k2;
	T=qread();
	while(T--){
		n=qread();p=qread();
		gets(s_a);gets(s_b);
		for(i=0;i<26;++i) freq[i]=0;
		for(i=0;i<n;++i){
			for(j=0;j<26;++j){
				if(s_a[i]==alphabet[j]) freq[j]++;
			}
		}
		k1=0;
		for(i=0;i<26;++i){
			if(freq[i]>k1) k1=freq[i];
		}
		
		
		for(i=0;i<26;++i) freq[i]=0;
		for(i=0;i<n;++i){
			for(j=0;j<26;++j){
				if(s_b[i]==alphabet[j]) freq[j]++;
			}
		}
		k2=0;
		for(i=0;i<26;++i){
			if(freq[i]>k2) k2=freq[i];
		}
		
		if(k2==n&&p==1) score_b=n-1;
		else   score_b=my_min(k2+p,n);
		
		if(k1==n&&p==1) score_a=n-1;
		else   score_a=my_min(k1+p,n);
		
		if(score_a>score_b)      printf("Alice\n");
		else if(score_a<score_b) printf("Bob\n");
		else printf("Draw\n");
	}
	return 0;
}
