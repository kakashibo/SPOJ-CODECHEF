#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
int ans[10000000010];
int ar[1000010];
int main()
{
    int n,q;
    cin>>n>>q;
    int c=0;
    for(int i=0;i<n;i++){
        scanf("%d",&ar[c++]);
    }
    while(q--){
       int l,r,t;
       scanf("%d",&l);

       //scanf("%d%d%d",&t,&l,&r);
       if(l==2){
              int x=0,y=0;
              scanf("%d",&x,&y);
             ar[x]=y;
       }
       if(l==3){
              int t;
              scanf("%d",&t);
       }
       if(l==4){
              int x=0,y=0;
              scanf("%d",&x,&y);
       }
       if(l==5){
              set<int> s(ar+l-1, ar + r-1);

               printf("%d\n",s.size());
       }
       //
    }
    return 0;
}
