#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF (1<<30)
#define value first
#define count second
int ar[1000010];
int l[10000010];
int r[10000010];
int s[10000010];
typedef pair<int,int> ct;
ct pairs[10000010];
ct rpairs[10000010];
int n;
int find(int k) {
    // binary search
    int L = 0, R = n+1;
    while (R - L > 1) {
        int M = L + R >> 1;
        (pairs[M].value <= k ? L : R) = M;
    }
    return pairs[L].count;
}
char ans[1000010];
void toggle(int i){
       if(ans[i]=='D')
              ans[i]='C';
       else
              ans[i]='D';
}
/*
9 5
4 2 3 1 3 4 1 3 4
*/
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
    l[0]=1;r[n-1]=1;
    for (int i = 1; i < n; i++)
    {
      s[i] = 1; // Initialize span value

      // Traverse left while the next element on left is smaller than price[i]
      for (int j = i-1; (j>=0)&&(ar[j]<ar[i]); j--)
          s[i]++;
       l[i]=s[i];
    }
    for (int i = n-2; i >= 0; i--)
    {
      s[i] = 1; // Initialize span value

      // Traverse left while the next element on left is smaller than price[i]
      for (int j = i+1; (j<=n-1)&&(ar[i]>=ar[j]); j++)
          s[i]++;
       r[i]=s[i];
    }
    //for (int i = 0; i < n; i++){
      // cout<<l[i]<<" : "<<r[i]<<endl;
    //}
    pairs[0].value = -INF;
    pairs[0].count = 0;
    for (int i = 1; i <= n; i++) {
        pairs[i].value = ar[i-1];
        pairs[i].count = (r[i-1] * l[i-1]);
    }
    sort(pairs,pairs + n + 1);
    for (int i = 1; i <= n; i++) {

        pairs[i].count += pairs[i-1].count;
        //cout<<pairs[i].count<<" ";
    }
    int k;
    char type[2];
    for (int i = 0; i < m; i++) {

        scanf("%s%d%s", &type, &k, ans + i);
        //cout<<"Find : "<<find(k)<<endl;
        if(type[0]=='>'){
              if((((n*(n+1)/2)-find(k))%2==0))
                     toggle(i);

        }
        else if(type[0]=='<'){
              if((find(k-1))%2==0)
                     toggle(i);

        }
        else{
              if((find(k)-find(k-1))%2==0)
                     toggle(i);


        }

    }
    ans[m] = '\0';
    printf("%s\n", ans);

    return 0;
}
