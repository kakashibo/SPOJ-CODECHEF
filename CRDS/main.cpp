#include <iostream>

using namespace std;

int main()
{
    long int ar[1000005];long int factor=5;
    ar[1]=2;
    for(int i=2;i<=1000000;i++){
       ar[i]=(ar[i-1]+factor)%1000007;
       factor=(factor+3)%1000007;
    }
    int a;
    int tc;
    cin>>tc;
    while(tc){
              cin>>a;
       cout<<ar[a]<<endl;
    }
    return 0;
}
