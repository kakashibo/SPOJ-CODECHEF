#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
void ans(){
    long int m;double p,ans,r1=0,temp;
    double mill=1000000000;
    scanf("%ld %lf",&m,&p);
    temp=(1+(pow((-1),m-1)*(pow(p,m))))/(1+p);
    printf("%lf %lf\n",mill*temp,mill*(1-temp));

}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ans();
    }
    return 0;
}
