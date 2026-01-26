#include<stdio.h>
#include<string.h>
void jie(char *a,char *b)
{
	if(strcmp(a,b)<0) strcpy(a,b);
}
int main()
{
	int n;scanf("%d",&n);
	getchar(); 
	char c[100],ans[100];
	gets(ans);
	for(int i = 1;i<n;i++)
	{
		gets(c);
		jie(ans,c);
	}
	printf("%s",ans);
}
