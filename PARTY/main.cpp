#include <iostream>
#include <stdio.h>
using namespace std;
int party[101][2];
int main()
{
    int budget,n;int i,j;
    while(scanf("%d%d",&budget,&n)&&(budget!=0&&n!=0)){
        for(i=0;i<n;i++)
            scanf("%d%d",&party[i][0],&party[i][1]);
        //cout<<budget<<n;
        int dp[550][101]={0};

        //for(i=0;i<n;i++)
           // dp[0][i]=1;

        for(i=1;i<=budget;i++)
            for(j=0;j<n;j++){
                    if(party[j][0]<=i)
                    {
                        if(i-party[j][0]>0)
                            dp[i][j]=party[j][1]+dp[i-party[j][0]][j-1];
                        else
                        dp[i][j]=party[j][1];
                    }
                    dp[i][j]=max(dp[i][j-1],dp[i][j]);


        }/*
        for(i=0;i<budget+20;i++){
            cout<<i<<" : ";
            for(j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int maxi=dp[budget][n-1];
        for(i=budget;i>=0;i--){
            if(maxi!=dp[i][n-1])
                break;
        }
        cout<<i+1<<" "<<dp[i+1][n-1]<<endl;


        //cout<<dp[dp[i]
    }
    getchar();
    return 0;
}
