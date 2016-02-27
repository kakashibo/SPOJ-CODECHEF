#include <iostream>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
// Implementation from http://rosettacode.org/wiki/Power_set
#define ARRAY_SIZE 4
using namespace std;




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

void function(){

}
int values[1000000];
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
         long int n,k;
         cin>>n>>k;
         if((n==k)||(n-k<k)){
            cout<<"-1"<<endl;

         }
         else {

            for(int i=k+1;i<=n;i++){
                cout<<i<<" ";
            }
            for(int i=1;i<=k;i++){
                cout<<i<<" ";
            }



         }
         cout<<endl;

    }
    return 0;
}
