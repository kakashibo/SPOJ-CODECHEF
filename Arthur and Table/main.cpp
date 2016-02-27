#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<limits.h>
#include<map>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
#define PII pair<int, int>
#define mk(x,y) make_pair((x),(y))
#define MAXN 10
struct node{
	int l,d;
	bool operator < (const node &rhs) const{
		return this->l<rhs.l;
	}
}p[MAXN];

int main()
{
    int cnt[250];
    int cost[250];
    int n;
    cin>>n;
    int ar[100005];
     memset(cost,0,sizeof(cost));.
     memset(ar,0,sizeof(ar));
    for(int i=0;i<n;i++){
           int l;
              cin>>l;
       ar[l]++;


    }
    int avail[250];
     memset(avail,0,sizeof(avail));
    for(int i=0;i<n;i++){
       int r;
       cin>>r;
       cost[r]++;
        avail[r]++;

    }
    cost[200]=200*cost[200];
    for(int i=199;i>=1;i--){
       cost[i]=cost[i+1]+cost[i]*i;

    }
   //for(int j=1;j<=200;j++)
     //  cout<<cost[j]<<" ";


    int ans=INT_MAX;
    for(int i=1;i<=100005;i++){
        if(ar[i]==0)
              continue;

       int total=0;

       total+=cost[i+1];
       int num=ar[i];
       int num2=num-1;
       int k=num;

              for(int j=1;j<=i;j++){
                     if(avail[i]!=0){
                            total+=i*min(avail[i],num2);
                            num2-=max(0,avail[i]-num2);
                     }
                     if(num2==0)
                            break;
              }
       ans=min(total,ans);
       for(int j=0;j<k;j++){
              avail[ar[j]]++;
       }


    }
    cout<<ans;



    return 0;
}








