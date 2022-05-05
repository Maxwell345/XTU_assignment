#include <stdio.h>
#include <string.h>
void my_fill_array(int *a,int source,int dest,int value)
{
	int q;
	for(q=source;q<=dest;++q) a[q]=value;
}
int weektonum(char *day)
{
	if(strcmp(day,"Mon")==0) return 1;
	if(strcmp(day,"Tue")==0) return 2;
	if(strcmp(day,"Wen")==0) return 3;
	if(strcmp(day,"Thur")==0) return 4;
	if(strcmp(day,"Fri")==0) return 5;
	if(strcmp(day,"Sat")==0) return 6;
	if(strcmp(day,"Sun")==0) return 7;
}
void writeweek(int w)
{
	if(w==1) printf("Mon");
	if(w==2) printf("Tue");
	if(w==3) printf("Wen");
	if(w==4) printf("Thur");
	if(w==5) printf("Fri");
	if(w==6) printf("Sat");
	if(w==7) printf("Sun");
}
int vacant(int *agenda,int from,int lastlength)
{
	int z;
	for(z=from;z<=from+lastlength-1;++z){
		if(agenda[z]==1) return 0;
	}
	return 1;
}
int main()
{
	int K,n,t,cnt;
	int s,e,i,j;
	char d[7];
	int curriculum[8][13];
	scanf("%d",&K);
	while(K--){
		cnt=0;
		for(i=1;i<=5;++i) my_fill_array(curriculum[i],1,11,0);
		scanf("%d%d",&n,&t);
		while(n--){
			scanf("%s",d);
			scanf("%d%d",&s,&e);
			my_fill_array(curriculum[weektonum(d)],s,e,1);
		}
		for(i=1;i<=5;++i){
			for(j=1;j<=4-t+1;++j){
				if(vacant(curriculum[i],j,t))
				{
					cnt++;
				}
			}
			for(j=5;j<=8-t+1;++j){
				if(vacant(curriculum[i],j,t))
				{
					cnt++;
				}
			}
			for(j=9;j<=11-t+1;++j){
				if(vacant(curriculum[i],j,t))
				{
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
		for(i=1;i<=5;++i){
			for(j=1;j<=4-t+1;++j){
				if(vacant(curriculum[i],j,t))
				{
					writeweek(i);printf(" %d %d\n",j,j+t-1);
				}
			}
			for(j=5;j<=8-t+1;++j){
				if(vacant(curriculum[i],j,t))
				{
					writeweek(i);printf(" %d %d\n",j,j+t-1);
				}
			}
			for(j=9;j<=11-t+1;++j){
				if(vacant(curriculum[i],j,t))
				{
					writeweek(i);printf(" %d %d\n",j,j+t-1);
				}
			}
		}
	}
	return 0;
}
