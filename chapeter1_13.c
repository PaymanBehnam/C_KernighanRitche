#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
    char kalame[1000];
    int tool[1000];
    char delet[1000];
    int repeat[1000];
    int c,i=-1,j=-1,state,t=0,l,z,s,max,n,e,flage,m,k,w;
    state=OUT;
    for(l=0;l<=1000;++l){
	kalame[l]=0;
	tool[l]=0;
	delet[l]=0;}
    while((c=getchar())!=EOF){
	if(c==' '||c=='\t'||c=='\n'){
	    state=OUT;
	    t=0;}
	else if(state==OUT){
	    state=IN;
	    ++j;}
	if(state==IN){
	    kalame[++i]=c;
	    tool[j]=++t;}	    	    
    }	    
    max=tool[0];
    for(n=1;tool[n]!=0;++n){
	if(tool[n]>=max)
	    max=tool[n];
    }	    
    delet[0]=tool[0];
    for(n=1;tool[n]!=0;++n){
	flage=0;
	for(m=0;delet[m]!=0;++m){
	    if(tool[n]==delet[m])
		flage=1;}
	    if(flage==0)
		delet[m]=tool[n];
    }			
    for(z=0;delet[z]!=0;++z){
	s=0;
	for(k=0;tool[k]!=0;++k){
	    if(delet[z]==tool[k])
		++s;
	}				
	repeat[z]=s;
    }
    for(e=0;delet[e]!=0;++e){
	printf("%icharacter\t",delet[e]);
	for(l=0;l<=repeat[e]-1;++l)
	    printf("*");	
	printf("\n");
    }
}    	












    	        
    