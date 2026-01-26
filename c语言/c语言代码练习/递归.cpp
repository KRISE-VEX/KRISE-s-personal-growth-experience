#include<bits/stdc++.h>
using namespace std;
int jie(int n)
{
	if(n==1) return 1;
	else return 2*(jie(n-1)+1);
}
int main()
{
  	int n;
	 while(~scanf("%d",&n))
	 {
	 	printf("%d\n",jie(n));
	  } 
	return 0;
}

