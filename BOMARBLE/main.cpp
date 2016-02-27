#include <iostream>

using namespace std;

int main()
{
    int ar[10010];
    ar[1]=5;int diff=4;int factor=3;
    for(int i=2;i<=10000;i++){
       diff=diff+factor;
       ar[i]=ar[i-1]+diff;
    }
    int no;
    while(cin>>no&&no!=0){
       cout<<ar[no]<<endl;
    }
    return 0;
}
