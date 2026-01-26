#include<stdio.h>
int sta (char *all,char *sub)
{
	int cnt = 0;
	while(*all!='\0')
	{
		char *p1 = all,*p2 = sub;
		while(*p1!='\0'&&*p2!='\0'&&*p1==*p2)
		{
			p1++;
			p2++; 
		}
		if(*p2=='\0') cnt++;
		all++;
	}
	return cnt;
}
int main()
{
	char a[1000],b[1000];
	gets(a),gets(b);
	printf("%d",sta(a,b));
}
