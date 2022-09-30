int findPlus(char *formula)
{
	int i;
	for(i=0;formula[i];++i){
		if(formula[i]=='+') return i;
	}
	return -1;
}
void getRightPart(char *dest,char *src,int idx)
{
	int i;
	for(i=0;src[idx+i+1];++i){
		dest[i]=src[idx+i+1];
		dest[i+1]='\0';
	}
}
void cutGetLeft(char *src,int idx)
{
	src[idx]='\0';
}
void processFormula(char *f,char *num_b)
{
	int pos;
	pos=findPlus(f);
	getRightPart(num_b,f,pos);
	cutGetLeft(f,pos);
}
