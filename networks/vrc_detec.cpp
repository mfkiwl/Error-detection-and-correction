#include<stdio.h>

int main(){
	char a[8],b[8],c[8],par[8],d[8];
	printf("enter 7 bits binary number\n");
	gets(a);
	gets(b);
	gets(c);
	printf("enter 7 bits vrc:");
	gets(d);
	int flag,i,odd,flag2=0;
	printf("enter 0 for even 1 for odd");
	scanf("%d",&odd);
	for(i=0;i<7;i++){
		flag = 0;
		if(a[i]=='1')
			flag++;
		if(b[i]=='1')
			flag++;
		if(c[i]=='1')
			flag++;
		if((flag%2==0 && odd==0)||(flag%2==1 && odd==1))
			par[i]='0';
		else
			par[i]='1';	
		if(par[i]!= d[i]){
			flag2=1;
			break;
		}				
	}
	//par[i]='\0';
	//printf("\nvrc = ");
	//puts(par);
	if(flag2)
		printf("Error");
	else
		printf("No Error");	
}
