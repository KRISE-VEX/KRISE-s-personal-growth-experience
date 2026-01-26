#include<stdio.h>
void sort(int a[],int n)
{
	for(int i = 1;i<n;i++)
	{
		int current = a[i];
		int j = i-1;
	
	while(j>=0&&a[j]>current)
	{
		a[j+1] = a[j];
		j--;
	}
	a[j+1]= current;
}
 } 
 int main()
 {
 	int n;scanf("%d",&n);
 	int a[100] = {1,10,3,5,7,8,2,4,6,9};
 	sort(a,n);
	 for(int i = 0;i<n;i++) printf("%d ",a[i]) ;
 }
