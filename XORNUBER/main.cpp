#include <iostream>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
bool fun (int x)
{
       return x && (!(x&(x-1)));
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
       long long int n;int sets;long long int t,max,ans;
       //cin>>n;
       long long int k,q,z,l;
       int f=1;
       //cin>>n;
       	scanf("%lld",&n);
k=ceil(log(n)/log(2));
q=floor(log(n)/log(2));


z=pow(2,k)-1;
l=pow(2,q)-1;

if(n==z)
{

printf("%lld\n",l);
}
else printf("-1\n");
continue;
       long long int m=n>>1;
       if(m^(m+1)==n)
       cout<<m<<endl;
       else
       cout<<-1<<endl;
       continue;
       if(n==1)
              {
                     cout<<"2"<<endl;
                     continue;
              }
       if(n==3)
              {
                     cout<<"1"<<endl;
                     continue;
              }
       if(n==7)
              {
                     cout<<"3"<<endl;
                     continue;
              }
       for(int i=0;i<31;i++){
                     cout<<pow(2,i)<<" ";
             	if(n+1==pow(2,i))
              {
                     cout<<pow(2,i-1)-1<<"\n";
                     f=0;
                     break;
              }
       }
       if(f==1)
              cout<<"-1"<<endl;




    }

    return 0;
}
