#include <stdio.h>
#include "my_split.h"
int compare_note(char *op)
{
	if(op[0]=='a'&&op[1]=='d'&&op[2]=='d') return 1;
	return 0;
}
int validplus(char *dignum)
{
	int i;
	for(i=0;dignum[i];++i){
		if(dignum[i]<48||dignum[i]>57) return 0;
	}
	return 1;
}
char mod_ten(char num)
{
	while(num>=10)num-=10;
	return num;
}
char quotient_ten(char m)
{
	int cnt=0;
	while(m>=10){m-=10;cnt++;}
	return cnt;
}
char bit_add(char x,char y)
{
	if(y==0) return x;
	return bit_add(x^y,(x&y)<<1);
}
char char_add(char a,char b,char c)
{
	return mod_ten(bit_add(bit_add(a-48,b-48),c-48))+48;
}
char char_carry(char a,char b,char c)
{
	return quotient_ten(bit_add(bit_add(a-48,b-48),c-48))+48;
}
int getlen(char *numstring)
{
	int i;
	for(i=0;numstring[i];++i);
	return i;
}
void align(char *shorter,int longer)
{
	int i,j,L1,L2;
	L1=getlen(shorter);L2=longer;shorter[L2]='\0';
	for(i=L2-1;i>=L2-L1;--i) shorter[i]=shorter[i-(L2-L1)];
	for(j=L2-L1-1;j>=0;--j) shorter[j]=((1<<5)|(1<<4));
}
int main()
{
	int T,length1,length2,i,z;
	char num1[200];
	char num2[100];
	char ans[100];
	char carry[100];
	printf("Hello,World!\n");
	printf("ADD for BIG INTEGER\n");
	scanf("%d",&T);
	while(T--){
		putchar('\n');
		scanf("%s",num1);
		if(!findPlus(num1)){
			printf("ERROR:can\'t find plus mark!\n");
			continue;
		}
		else{
			processFormula(num1,num2);
		}
		if(validplus(num1)&&validplus(num2)){
			length1=getlen(num1);length2=getlen(num2);
			if(length1!=length2){
				if(length1<length2) align(num1,length2);
				else                align(num2,length1);
			}
			z=getlen(num1)-1;
			ans[z+1]='\0';
			ans[z]=char_add(num1[z],num2[z],((1<<5)|(1<<4)));
			carry[z]=char_carry(num1[z],num2[z],((1<<5)|(1<<4)));
			for(i=z-1;i>=0;--i){
				ans[i]=char_add(num1[i],num2[i],carry[i+1]);
				carry[i]=char_carry(num1[i],num2[i],carry[i+1]);
			}
			if(carry[0]!=((1<<5)|(1<<4))) putchar(carry[0]);
			printf("%s\n",ans);
		}else printf("ERROR:wrong number inputted!\n");
	}
 	return 0;
}
