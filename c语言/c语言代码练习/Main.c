#include<stdio.h>
int jie(char *a,char *b)
{
   if(b[0]=='\0') return 0;
   int cnt = 0;
   while(*a!='\0')
   {
      char *p1 = a,*p2 = b;
      while(*p1!='\0'&&*p2!='\0'&&*p1==*p2) 
      {
         p1++;
         p2++;
      }
      if(*p2=='\0') cnt++;
      a++;
   }
   return cnt;
}
int main()
{
   char a[1000],b[1000];
   gets(a),gets(b);
   printf("%d\n",jie(a,b));
}



