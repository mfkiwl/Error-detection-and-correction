#include<stdio.h>

int main(){
	char a[8];
	
	printf("enter 7 bit binary number");
	gets(a);
	int odd;
	printf("enter 0 for even 1 for odd");
	scanf("%d",&odd);
	int flag=0,p;
	for(int i=0;i<7;i++)
		if(a[i]=='1')
			flag++;
	if(odd==0)
	p=(flag%2);
	else
	{
		if(flag%2==0)
			p=1;
		else
			p=0;	
	}
	printf("lrc = %d",p);
	return 0;
			
}

