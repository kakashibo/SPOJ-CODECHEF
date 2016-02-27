#include <iostream>
#include <stdio.h>
using namespace std;
long int place[100005],high[100005];
int dp[100005];
int main()
{
   // cout << "Hello world!" << endl;
    int trees;
    cin>>trees;
    int i;
    for(i=0;i<trees;i++)
        cin>>place[i]>>high[i];
    //place[i]=10000000000;

   // high=0;
    long int b;

    dp[0]=1;
    b=0;
    for(i=1;i<trees;i++)
    {
    	//cout<<high[i]<<" "<<place[i]-place[i-1]<<" ";
        if(place[i]-place[i-1]>high[i]+b){
            dp[i]=dp[i-1]+1;
            b=0;
        }
        else if( place[i+1]-place[i] > high[i]||i==trees-1){
            dp[i]=dp[i-1]+1;
            b=high[i];
        }
        else{
            dp[i]=dp[i-1];
            b=0;
        }
           // cout<<dp[i]<<"| "<<b<<endl;
    }
    cout<<dp[trees-1]<<endl;




    return 0;
}
