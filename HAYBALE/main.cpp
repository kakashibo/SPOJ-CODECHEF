#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

int main()
{
    int ar[10000];
    int a,b;
    int no;
    cin>>no;
    for(int i=0;i<no;i++){
       scanf("%d%d",&a,&b);
       ar[a]+=1;
       ar[b+1]=-1;
    }
    ///Cumulative Sum
    for(int i=1;i<no;i++){
       ar[i]+=ar[i-1];
    }
    sort(ar,ar+no);
    for(int i=1;i<no;i++){
       cout<<ar[i]<<" ";
    }

    return 0;
}