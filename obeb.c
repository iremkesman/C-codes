#include <stdio.h>
int obeb(int a,int b)
{
   if(b==0)
        return a;
   else
        return obeb(b,a%b);
}
int main()
{
  int n1,n2;
  printf("OBEB bulmak istediginiz iki sayiyi giriniz:");
  scanf("%d %d",&n1,&n2);
  printf(" %d ve %d sayilarinin obeb'i %d 'dir",n1,n2,obeb(n1,n2));
  return 0;
}
