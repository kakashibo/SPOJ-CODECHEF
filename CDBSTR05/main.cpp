#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
inline void fastRead_int(int *a)
{
       register char c=0;
       while (c<33) c=getchar();
              *a=0;
       while (c>33)
       {
              *a=*a*10+c-'0';
              c=getchar();
       }
}
int main()
{
       int tc,n;
       long int sum=0;
       scanf("%d",&tc);
       while(tc--)
       {
              sum=0;
              scanf("%d",&n);
              int a[n];
              int summ[n];
              int t=0,t2=0;
              for(int i=0;i<n;i++){
                     fastRead_int(&t);
                     a[i]=t;
                     summ[i]=t+t2;
                     t2+=t;
                     cout<<summ[i]<<" ";
              }
              cout<<endl;
              for(int i=0;i<n;i++){
                     if(i+1==n)
                            break;
                     sum+=abs(a[i+1]-summ[i]);
              }
              long int sum2=0;
               for(int i=0;i<n;i++){

for(int j=i+1;j<n;j++){

sum2+=abs(a[i]-a[j]);
}
}
              printf("%ld %ld\n",sum,sum2);
       }
    return 0;
}
