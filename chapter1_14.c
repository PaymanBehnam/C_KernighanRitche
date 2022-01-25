#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
    char input[1000];
    char delet[1000];
    char repeat[1000];
    int state,i,n,j,c,m,flage,max,z,k,s,e,l;
    for(j=0;j<=1000;++j){
	input[j]=0;
	delet[j]=0;
	repeat[j]=0;}
    state=OUT;
    i=-1;
    while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n')
	    state=OUT;
	else if(state==OUT)
	    state=IN;	    
    	if(state==IN)
	    input[++i]=c;    
    }	    
    delet[0]=input[0];    
    for(n=1;input[n]!=0;++n){
	flage=0;
        for(m=0;delet[m]!=0;++m){
    	    if(input[n]==delet[m])
		flage=1;}	
	if(flage==0)
	    delet[m]=input[n];
    }
    for(z=0;delet[z]!=0;++z){
	s=0;
	for(k=0;input[k]!=0;++k){
	    if(delet[z]==input[k])
		++s;
	}	
	repeat[z]=s;
    }		
    for(e=0;delet[e]!=0;++e){
	printf("%c\t",delet[e]);
	for(l=0;l<=repeat[e]-1;++l)
	    printf("*");
	printf("\n");
	}    
}
	