#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
int dp[2001][2001];
int main()
{
    //cout << "Hello world!" << endl;
char a[2001],b[2001];
    //
    int tc;

    cin>>tc;
    while(tc--)
    {

         scanf("%s",a);
        scanf("%s",b);

        int lena=strlen(a);
        int lenb=strlen(b);
       // cout<<a.length();
        //int dp[a.length()][b.length()];
        //memset(dp,0,sizeof(dp));
       // /for(int i=0)
        for(int i=0;i<=lena;i++)
            dp[i][0]=i;

        for(int j=0;j<=lenb;j++)
             dp[0][j]=j;
         //dp[0][0]=1;
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
            	int temp1;

            	//cout<<a[i-1]<<b[j-1]
                	if(a[i-1]==b[j-1])
                     	temp1=dp[i-1][j-1]+1;
                     	else
                            temp1=dp[i-1][j-1];

                    int temp=min(dp[i-1][j]+1,dp[i][j-1]+1);
                    dp[i][j]=min(temp,temp1);

            }
        }
/*
        for(int i=0;i<lena+1;i++)
        {
            for(int j=0;j<lenb+1;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        */
        cout<<dp[lena][lenb]<<endl;



    }
    return 0;
}
