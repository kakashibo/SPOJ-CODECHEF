#include <iostream>
#define MOD 1000000007
#define gc getchar_unlocked
#include <stdio.h>
using namespace std;

void scan_integer( int &x )
{
    register int c = getchar_unlocked();

    x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if( neg )
        x=-x;
}

bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}
long long int a[1010]={0},b[1010]={0},dp[1010][1010]={0};
void ans(){
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(i==1)
            {
                dp[i][j]=(dp[1][j-1]+dp[0][j]);
                dp[i][j]=(dp[i][j])%MOD;
            }
            else
            {
                dp[i][j]=(dp[i][j-1]+(dp[i-1][j-1]*dp[0][j]));
                dp[i][j]=(dp[i][j])%MOD;
            }

        }
    }

}

int main()
{
    long int n,m,c;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++){
        int t;
        scanf("%ld",&t);
        a[t]++;
    }
    for(int i=0;i<m;i++){
        int t;
         scanf("%ld",&t);
        b[t]++;
    }
    for(int i=1;i<=1000;i++)
        dp[0][i]=a[i]*b[i];
    ans();
    for(int i=1;i<=c;i++)
        cout<<dp[i+1][1000]<<" ";
    return 0;
}
