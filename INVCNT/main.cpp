#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
int tree[10000005];
int maxVal;

int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int ar[200010];
int main()
{
    int tc;int i,j;
    cin>>tc;
    while(tc--){
        int n;
        memset(tree , 0 , sizeof (tree));
        cin>>n;
        maxVal=0;
        for(i=0;i<n;i++){
            scanf("%d",&ar[i]);
            maxVal=max(maxVal,ar[i]);
        }
        long long int sum=0;
        for(i=n-1;i>=0;i--)
        {
            sum+=read(ar[i]-1);
            //cout<<"inversion:"<<sum<<endl;
            //for(j=0;j<maxVal;j++)
               // cout<<tree[j]<<" ";
            update(ar[i],1);
            //cout<<endl;
            //for(j=0;j<maxVal;j++)
             //cout<<tree[j]<<" ";
             //cout<<endl;
        }
        cout<<sum<<endl;
        //getchar();
    }

    return 0;
}


