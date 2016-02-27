#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<algorithm>
#include <string.h>

using namespace std ;

#define MAX 68

int range[MAX][MAX] ;
long long int dp[MAX][MAX];
int range2[MAX];

void dp_method(){

       memset(dp,0,sizeof(dp));
       dp[0][0]=1;dp[0][2]=0;dp[0][1]=0;dp[1][0]=1;dp[1][1]=1;dp[2][0]=1;dp[2][1]=2;dp[2][2]=1;
       int j,k,l,i;
       for( i=3;i<=63;i++)
       {
              dp[i][0]=1;
              for( j=1;j<i;j++)
              {

                     for(k=1;k<=j;k++)
                     {
                            dp[i][j]=dp[i-k][j]+dp[i][j];
                     }
                     for(l=0;l<=j;l++)
                            dp[i][j]=dp[i][j]+dp[i-k][l];

              }
              dp[i][i]=1;
       }
       for(i=1;i<=63;i++){
              for(j=0;j<i+1;j++)
               cout<<dp[i][j]<<" ";
              cout<<endl;
       }


}

int bf(int n,int j)
{
       int res=0;
       int count =0 ;
       while(n)
       {
       if(n&1)
       {
              ++count;
              res=max(res,count);
       }
       else
              count=0;
              n>>=1;
       }
       range[j][res]++ ;
}


int print_range(int n,int j)
{
       for(int i=0;i<=j;i++){
       //range2[i]=range[n]
              printf("%3d ",range[j][i]);
       }

}

void check()
{
       int f=0;
       for(int i=1;i<=21;i++){
              for(int j=0;j<i+1;j++)
              if(dp[i][j]!=range[i][j])
               {
                      cout<<"Wrong Answer at:"<<i<<" "<<j;
                      f=1;
                      break;
               }
       }
       if(f!=1)
              cout<<"Right Answr";

}

int main()
{
       /*
       int n=23 ;
       memset(range2,0,sizeof(range2));
       //scanf("%d",&n);
       for(int j=1;j<n;j++){

              for(int i=1<<j-1;i<(1<<j);i++)
                     bf(i,j);
              range[j][0]=1;

              for(int jj=1;jj<n;jj++)
                     range[j+1][jj]=range[j][jj];


              print_range(n,j);
              cout<<endl;
       }
       */
       dp_method();
       //check();



}