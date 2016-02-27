#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int long ar[1000010];
int badp[1000010];
vector<pair<int,int> > a;
int main()
{

       //for(int i=0;i<100000;i++)badp[i]=-1;
       int N,K;
       int ans=0;
       scanf("%d%d",&N,&K);
       int j,l,m;
       for(int i=1;i<=N;i++){


             scanf("%ld",&ar[i]);
             	for(j=i-1;j>0;j--)
              {
                     bool get={false};
                     for(l=i;l>=j;l--)
                     {
                            for(m=l-1;m>=j;m--)
                            {
                                   if(ar[m]%ar[l]==K) get=true;
                            }
                     }
                     if(get==true) ans+=1;
              }
       }
       cout<<(N*(N+1)/2)-ans<<endl;
       return 0;
       for(int i=0;i<N;i++){

              for(int j=i+1;;j++){
                     //cout<<j<<endl;
                     if(j>N-1)
                            break;
                     if(ar[i]%ar[j]==K){
                            a.push_back(make_pair(i,j));
                            badp[ar[i]]=ar[j];
                            badp[ar[j]]=0;
                            //cout<<ar[i]<<" : "<<ar[j]<<endl;
                     }
              }


       }
       int t[10000];
       int count=0;
       vector<int> d;
       vector<int> :: iterator it;
       for(int i=0;i<N;i++){

              d.clear();
              d.push_back(i);
              for(int j=i+1;;j++){
                if(j>N-1)
                     break;
                d.push_back(j);
                for (unsigned i=0; i<a.size(); i++){
                     int t=a.at(i);
                     if(bdap[t]!=0){
                            if(bdap[t])
                     }

                }

              }

       }







    return 0;

}
