#include<stdio.h>
int main()
{
	int n;scanf("%d",&n);
	int a[10] = {1,6,3,7,4,2,5,8,9,10};
	for(int i = 0;i<9;i++)
	{
		int ma = i;
	for(int j = i;j<10;j++)
	{
		if(a[j]<a[ma]) ma = j;
	}
	if(ma!=i) {
		int temp = a[ma];
		a[ma] = a[i];
		a[i] = temp;
	}
	}
	for(int i = 0;i<10;i++) printf("%d ",a[i]);
}
