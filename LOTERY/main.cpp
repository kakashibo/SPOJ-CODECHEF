#include <iostream>
#include <numeric>
#include <cmath>
#include <stdio.h>
#define MOD 1000000007
using namespace std;
long long int P[10000][10000]={0};
long long int dp[1010][1010];
long long int lcmar[1010][1010];
//int gcdd[10000][10000]={0};
long int gcd(long int a, long int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long int lcm(long int a,long int b)
{
    //if(gcdd(a,b))
    long long int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

void cal(){

    for(int i=1;i<=1000;i++){
        dp[i][1]=i;lcmar[i][1]=i;
    }
    for(int i=2;i<=30;i++){
        for(int j=2;j<=i;j++){
            //cout<<dp[i-1][j]<<" "<<dp[i-1][j-1]<<endl;
            //cout<<i<<" "<<j<<endl;
            dp[i][j]=(long long int)((floor((dp[i][j-1]*dp[i-1][j-1])/(dp[i][j-1]-dp[i-1][j-1]))))%MOD;
            //dp[i][j]=((fabs(temp)));
            //cout<<dp[i][j]<<" ";
            //cout<<"->"<<i<<" | "<<j<<" "<<dp[i][j]<<endl;
            lcmar[i][j]=(lcm(lcmar[i][j-1],dp[i][j]))%MOD;
        }
        //cout<<endl;
    }
}


long int fun(long int n,long int k)
{

    if(n<k){
        return 1;
    }
    if(k==1){
        P[n][k]=n;
        if(n==0)return 1;
        return n;
    }

    if(P[n][k]!=0) return P[n][k];

    long long int t1=fun(n-1,k-1);
    long long int t2=fun(n,k-1);

    long long int temp=floor((((t1*t2)%MOD)/(t2-t1)%MOD)%MOD);
    P[n][k]=temp;
    return temp;
}
long int c[1000000],d[1000000];
int main()
{
    cal();
    long int t;
    cin>>t;
    //scanf("%ld",&t);
    long int n,k;
    cin>>n>>k;
   // scanf("%ld %ld",&n,&k);
    long long int a,b,m;
    cin>>a>>b>>m;
    //scanf("%ld %ld",&a,&b,&c);
    //fun(n,k);
    //long long int ans=findlcm(n,k);
    long int ans=lcmar[n][k];
    cout<<ans<<endl;
    //printf("%ld\n",ans);
    t--;
    for(int i=1;i<=t;i++){
        //cin>>c[i];
        scanf("%ld",&c[i]);
    }
    for(int i=1;i<=t;i++){
       // cin>>d[i];
        scanf("%ld",&d[i]);
    }

    for(int i=1;i<=t;i++){

        n = (1 + ((a * (ans) + c[i]) % m))%MOD;

        k = (1 + (((b *ans) + d[i]) % n))%MOD;
        //cout<<n<<" : "<<k<<endl;
       // if(n<k){
        //    cout<<"1"<<endl;
        //    continue;
        //}
        //fun(n,k);
        ans=lcmar[n][k];
        printf("%ld\n",ans);
        //cout<<ans<<endl;
    }

    return 0;
}












