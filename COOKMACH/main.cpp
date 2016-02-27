#include <iostream>
#include <math.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
       int x,y;
       cin>>x>>y;int count =0;
       if(x==y){
              printf("0\n");
              continue;
       }

       while(y%x!=0)
       {
              if(x&1){
                     x=(x-1)>>1; count ++;
              }
              else
              {
                     x=x>>1; count++;
              }

       }
       float lx=log10(x)/log10(2);
       float ly=log10(y)/log10(2);
       count+=abs(lx-ly);
       printf("%d\n",count);
    }


    return 0;
}
