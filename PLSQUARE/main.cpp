#include <iostream>
#include <stdio.h>
using namespace std;
int isPalin[210][210];
int isPalinv[210][210];
int dp[210][210];
char input[210][210];
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
              string s;
            cin>>s;
       for(int j=0;j<n;j++){

                    input[i][j]=s[j];
              }

       }
       //cout<<endl;

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
                     cout<<input[i][j]<<" ";
       }
       cout<<endl;
    }

    for(int i=0;i<n;i++){
       for(int j=0;j<=1;j++){
                     if(j==0)
              isPalin[i][j]=1;
              else
                  isPalin[i][j]=2;
       }
    }
    for(int i=0;i<=1;i++){
       for(int j=0;j<n;j++){
                     if(i==0)
              isPalinv[i][j]=1;
              else
                  isPalinv[i][j]=2;
       }
    }
    for(int i=0;i<n;i++){
       for(int j=2;j<n;j++){
             if(isPalin[i][j-1]>1){

                  if(input[i][j]==input[i][j-isPalin[i][j-1]]){
                     isPalin[i][j]=isPalin[i][j-1]+1;
                  }
                  else
                     isPalin[i][j]=2;
             }
             else{
                     isPalin[i][j]=2;

             }
       }
    }
    for(int i=0;i<n;i++){
       for(int j=2;j<n;j++){
                     cout<<"Pre:"<<isPalinv[j-1][i]<<" ";
             if(isPalinv[j-1][i]>1){
                   cout<<input[j][i]<<" "<<input[j-isPalinv[j-1][i]][i]<<" "<<isPalinv[j-1][i]<<endl;
                  if(input[j][i]==input[j-isPalinv[j-1][i]][i]){
                     isPalinv[j][i]=isPalinv[j-1][i]+1;
                  }
                  else
                     isPalinv[j][i]=2;
             }
             else{
                     isPalinv[j][i]=2;

             }
       }
    }

    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
                     cout<<isPalin[i][j]<<" ";

       }
       cout<<endl;
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
                     cout<<isPalinv[i][j]<<" ";

       }
       cout<<endl;
    }


    getchar();
    return 0;
}
/*
6
aabacd
abbccd
cccccc
abccba
vawqer
bnbuiu
4
babb
acaz
babx
fdhk
*/
