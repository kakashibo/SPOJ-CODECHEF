#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){

       int day;long long int k;
       scanf("%d %lld",&day,&k);
       long long int consume,consume1;
       cin>>consume;
       for(int i=1;i<day;i++){
              cin>>consume1;
              if(consume%k==0){
                     consume+=consume1;
              }
              else{
                     consume+=(consume1+1);
              }
             // cout<<consume<<" ";

       }
       double kk=k;
       double div=consume/kk;
       //cout<<div<<"-";
       if(div>(long long int)div){

              cout<<(long long int)(div)+1<<endl;
       }
       else
       {
             cout<<(long long int)(div)<<endl;

       }


    }
    return 0;
}
