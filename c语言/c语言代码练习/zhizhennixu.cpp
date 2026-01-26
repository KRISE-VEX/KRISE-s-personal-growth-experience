#include<stdio.h>
void jie(int *a,int n)
{
	int *p1 = a,*p2 = a+n-1;
	while(p1<p2)
	{
		int temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;p2--;
	}
	
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i;int a[100];
		for(i = 0;i<n;i++) scanf("%d",&a[i]);
		jie(a,n);
		for(i = 0;i<n;i++) printf("%d ",a[i]);
	}
}
