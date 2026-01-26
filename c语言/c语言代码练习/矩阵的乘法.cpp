#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i = 0;i<m;i++)
	for(int j = 0;j<n;j++)
	for(int k = 0;k<z;k++)
	c[i][j]+=a[i][k]*a[k][j]; 
	return 0;
}

