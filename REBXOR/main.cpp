#include <iostream>
#include <stdio.h>
#include <limits.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
///Implementation : https://github.com/pin3da/
ll A[1000010];
ll temp[1000010];
const int MN = 20000000;
ll maxSubArraySum(ll a[],ll ini,ll size)
{
   ll max_so_far = a[ini], i;
   ll curr_max = a[ini];

   for (i = ini; i <= size; i++)
   {
        curr_max = max(a[i], curr_max^a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
int mains(int o){

  int i,n;
  n=o;
  ll x,y,k;
  ll j=0;
  //scanf("%d",&n);
  A[0]=0;
  for(i=0;i<n;i++){
    scanf("%lld",&j);
    A[i+1]=A[i]^j;
    temp[i+1]=j;
  }
  k = -1;
  for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
      if( (A[j]^A[i-1]) > k ){
	k = A[j]^A[i-1];
	x = i;
	y = j;
      }
    }
  }
  ll max1=-1;
  ll max2=-1;

       for(i=1;i<x;i++){
        for(j=i;j<x;j++){
            if( (A[j]^A[i-1]) > max1 ){
                max1 = A[j]^A[i-1];

            }
          }
        }
      A[y]=0;
      A[y+1]=temp[y+1];
      for(i=y+2;i<=n;i++)
           A[i]=temp[i]^A[i-1];

      for(i=y+1;i<=n;i++){
        for(j=i;j<=n;j++){

            if( (A[j]^A[i-1]) > max2 ){
                max2 = A[j]^A[i-1];

            }
          }
        }

  ll ans=(k+max(max2,max1));
  cout<<ans<<endl;

  //printf("%d\n%d %d\n",k,x,y);
  return 0;
}

struct trie {
  long int n;
  long int nodes[MN][2];

  void clear() {
    n = 1;
    nodes[0][0] = nodes[0][1] = -1;
  }

  void insert(long int x) {
    long int node = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (x & (1 << i)) != 0;
      if (nodes[node][next] == -1) {
        nodes[node][next] = n;
        nodes[n][0] = nodes[n][1] = -1;
        n++;
      }
      node = nodes[node][next];
    }
  }


  long int query(long int x) {
    long int node = 0;
    long int ans = 0;
    for (int i = 31; i >= 0; --i) {
       long int next = (x & (1 << i)) != 0;
      long int cool = 1;
      if (nodes[node][next ^ 1] == -1) {
        next ^= 1;
        cool = 0;
      }
      if (cool)
        ans += (1 << i);

      if (nodes[node][next ^ 1] == -1) while (true) {}
      node = nodes[node][next ^ 1];
    }
    return ans;
  }
};
long int maxx(long int  a, long int b) { return (a > b)? a : b; }
long int ar[800010];
long int bb[800010];
long int bbk[800010];
trie tree;
int main() {


  int tc=1; //cin >> tc;
  int r=-1,l=-1;
  long int bestr,bestl;
  while (tc--) {
    int n;cin >> n;
    if(n==2){
        long int c,v;
        cin>>c>>v;
        cout<<c+v<<endl;
        return 0;
    }
    //if(n<=10000){
    //    mains(n);
    //    return 0;
    //}
    tree.clear();
    tree.insert(0);
    long int now=0,pre=0;
    long int bestb=0;
    long int best = 0, accum = 0, t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      ar[i]=t;

      accum ^= t;
      now=tree.query(accum);

        if(now<pre){
            r=l=i;
        }
       if(best<now){
        best = now;
        bestr=i;
        bestl=l;
      }
      pre=now;
      bb[i]=best;
      tree.insert(accum);
    }
    //cout<<"B"<<bestr<<" "<<bestl;
    best = max(best, tree.query(0));
    //cout << best << endl;
     long int best1=-1;
     long int best2=-1;
    tree.clear();
    tree.insert(0);
    accum = 0, t;
    for (int i = n-1; i >=0;i--) {

      accum ^= ar[i];
      best1 = max(best1, tree.query(accum));
      bbk[i]=best1;
      tree.insert(accum);
    }

    long anss = 0;
    for(int i = 0 ; i< n-1; i++){
        anss = maxx(anss, bb[i]+bbk[i+1]);
    }
    printf("%ld",anss);

    return 0;


    best1 = max(best1, tree.query(0));
    accum = 0, t;
    tree.clear();
    tree.insert(0);
    for (int i = bestr+1; i < n; ++i) {

      accum ^= ar[i];
      best2 = max(best2, tree.query(accum));
      tree.insert(accum);
    }

    best2 = max(best2, tree.query(0));


    //cout<<best<<" "<<best1<<" "<<best2<<endl;
    long int ans=best+maxx(best1,best2);
    cout <<ans<< endl;

  }
  return 0;
}

