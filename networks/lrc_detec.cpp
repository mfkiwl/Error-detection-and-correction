#include<stdio.h>

int main(){
	char a[9];
	
	printf("enter 7 bit binary number");
	gets(a);
	printf("enter lrc bit");
	scanf("%c",&a[7]);
	a[8]='\0';
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
	if(p==(int)(a[7]-'0'))
	printf("No Error");
	else
	printf("Error");
	return 0;
			
}

