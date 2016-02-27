#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int check(long long int a){
       int n=0;
       while(a%10==0){
              n++;
              a/=10;
       }
       return n;
}
int main()
{
    int n;long long int tk=1;
    cin>>n;
    while(n--){

       long long int num;scanf("%lld",&num);
       //num=tk;
       int a=0;int b=0;
       while(num%10==0){
              num/=10;
              a++;
       }
       while(num%5==0){

                     num=num/5;
                     b++;
       }
       if(!(b%2==0))
         num=num*2;
       long long int ans=num*pow(10,a+b);
       cout<<ans<<endl;
       //tk++;
      // if(tk==200)
             // break;
    }
    return 0;
}
