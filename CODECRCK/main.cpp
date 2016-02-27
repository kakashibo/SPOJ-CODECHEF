#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#define MODD 1000000010
//#define MOD 1000000010
using namespace std;

long long power(long int a, long int b, long int MOD=1000000007)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long int powers (long long int a, long long int b) {

    long long int ans=1ll;

    while(b) {

        if(b&1)ans=(ans*a)%MODD;

        a=(a*a)%MODD;

        b=b/2;

    }

    return ans;

    }
double powa(int a,long int b){

    double ans=b;
    for(int i=1;i<b;i++){
            //cout<<" - > "<<b<<endl;
         //ans=(ans*b)%1000000007;
    }
    return b;


}
int main()
{
    long long int i;long long int k;long long int s;
    double ans=0;double a,b;
    double a1,b1;
    double x,y;

    x=sqrt(2);
    y=sqrt(3);
    double x1=(x-x*y);
    int x2=16;
    cin>>i>>k>>s;
    cin>>a>>b;

    //cout<<power(x2,-6)<<endl;
    //cout<<powers(x2,-6)<<endl;
    //cout<<(double)pow(x2,-6)<<endl;
    //cout<<(long)pow(x2,6)<<endl;
    //cout<<(long)pow(x2,.5)<<endl;
    //cout<<pow(32,0.5)<<endl;
    //cout<<power(32,0.5)<<endl;
    //cout<<powa(32,0.5);
    long int ap=0;
    if(i<=k)
    {
        if((k-i)%2==0)
        {

            ap=(4*(k-i)/2)-s;
            a1=a*pow(2,ap);
            b1=b*pow(2,ap);

        }
        else
        {

            ap=(4*(k-i-1)/2)-s;
            double temp=pow(2,ap);
            a1=(a*temp*x*(1-y)+b*temp*x*(1+y));
            b1=(a*temp*x*(1+y)-b*temp*x*(1-y));
        }

    }
    else
    {
        if((i-k)%2==0)
        {
            ap=-(4*(i-k)/2)-s;
            double temp=pow(2,ap);
            a1=a*temp;
            b1=b*temp;
        }
        else
        {

            ap=-(4*(i-k+1)/2)-s;
            double temp=pow(2,ap);
            a1=((a*x*(1-y)*temp)+(b*x*(1+y)*temp));
            b1=((a*x*(1+y)*temp)-(b*x*(1-y)*temp));
        }
    }

	ans = (a1+b1);
    printf("%lf",a1+b1);

    return 0;
}