#include<stdio.h>
#include<memory.h>
#include<string.h>
int sta(char *a,char *b)
{
	int cnt = 0;
	while(*a!='\0')
	{
		if(memcmp(a,b,strlen(b))==0) cnt++;
		a++;
	}
	return cnt; 
}
int main()
{
	char a[1000],b[1000];
	gets(a),gets(b);
	printf("%d",sta(a,b));
}
