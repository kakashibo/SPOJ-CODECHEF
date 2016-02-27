#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char lab[1010][1010];
int dp[1010][1010];
int row,col;
int mrope=0;

bool isSafe(int i,int j){
        if(i>=0||i<=row-1||j>=0||j<=col-1){
              return true;
       }
       return false;
}
int maze(int i,int j,int rope)
{

     // cout<<i<<" | "<<j<<endl;
       //getchar();
       if(isSafe(i,j)){
              if(lab[i][j]=='.'){
                   lab[i][j]='v';

                     maze(i,j+1,rope+1);

                     maze(i+1,j,rope+1);

                     maze(i-1,j,rope+1);

                     maze(i,j-1,rope+1);
              }

       }
       //rope--;
       //cout<<"Rope "<<rope<<endl;
       if(mrope<rope)
              mrope=rope;
       return rope;


}

int main()
{
    int tc;

    cin>>tc;
    while(tc--){

       cin>>col>>row;
       memset(dp,0,sizeof(dp));
       for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                     cin>>lab[i][j];
              }
       }
       /*
       for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                            if(lab[i][j]=='.'){
                                          cout<<i<<" "<<j<<endl;
                                   int up=(j==0)?0:dp[i][j-1]+1;
                                   int left=(i==0)?0:dp[i-1][j]+1;
                                   dp[i][j]=max(up,left);
                            }

              }
       }
       */
       for(int i=0;i<row;i++){
                     int f=1;
              for(int j=0;j<col;j++){
                            if(lab[i][j]=='.'){
                                   maze(i,j,0);
                                   //f=0;
                                   //break;
                            }
                            //cout<<dp[i][j]<<" ";
              }
             // if(f==0)
                    // break;
              //cout<<endl;
       }
       if(mrope==0)
              cout<<"Maximum rope length is "<<mrope<<"."<<endl;
       else
       cout<<"Maximum rope length is "<<mrope-1<<"."<<endl;
       mrope=0;

    }


    return 0;
}
/*
1
7 6
#######
#.#.###
#.#.###
#.#.#.#
#.....#
#######
1
7 4
#......
####.##
##...##
###.###
1
7 6
#.#.##.
#.#.##.
######.
######.
###.##.
#......
*/