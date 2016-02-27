#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
using namespace std;

int main()
{
    char a[105],b[105];
    int tc,K;
    cin>>tc;
    while(tc--){

       scanf("%s",a);
       scanf("%s",b);

       int len_a=strlen(a);
       int len_b=strlen(b);
       cin>>K;

       int dp[K+1][len_a][len_b];

       int i,j,k;
       memset(dp,-2,sizeof(dp));
       //--------------------------- Intial
       for(i=0;i<len_a;i++)
              for(j=0;j<len_b;j++)
                     dp[0][i][j]=0;
       //---------------------------

       for(i=1;i<=K;i++){
              for(j=0;j<len_a;j++)
              {
                     for(k=0;k<len_b;k++){

                               if(k-1>=0&&j-1>=0){
                                   dp[i][j][k]=max(dp[i][j-1][k],dp[i][j][k-1]);
                                   if(a[j]==b[k]){

                                          if(i-1==0)
                                                 dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+a[j]);
                                          else if(dp[i-1][j-1][k-1]!=-1)
                                                 dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+a[j]);
                                   }
                                 //  cout<<dp[i][j][k]<<" ";
                            //getchar();

                              }
                              else{
                                if(a[j]==b[k])
                                    if(i-1==0)
                                      dp[i][j][k]=a[j];
                                    else
                                       dp[i][j][k]=-1;
                                else
                                   dp[i][j][k]=-1;
                                int up=j-1==-1?-1:dp[i][j-1][k];
                                int left=k-1==-1?-1:dp[i][j][k-1];
                                dp[i][j][k]=max(dp[i][j][k],max(up,left));

                              }


                     }
              }
       }
      /*
       for(i=1;i<=K;i++){
             cout<<"K :"<<i<<endl;
              for(j=0;j<len_a;j++)
              {
                     for(k=0;k<len_b;k++)
                     cout<<dp[i][j][k]<<" ";
                     cout<<endl;
              }
       }
      */
       int ans=dp[K][len_a-1][len_b-1];
       if(ans==-1)
              cout<<"0"<<endl;
       else
              cout<<dp[K][len_a-1][len_b-1]<<endl;

     //*/

    }
    getchar();
    return 0;
}
