#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define MAX 1000006
#define inf 0x7fffffff
#include <cmath>
//int arr[N];
long long int tree[10];
long long int narray[10];
long long int lazy[100];
void update_tree(long long int node, long long int a, long long int b, long long int i, long long int j, long long int value) {
       if(a > b || a > j || b < i) // Current segment is not within range [i, j]
              return;
       if(a == b) { // Leaf node
              tree[node] = min(value,tree[node]);
              return;
       }
       if(a>=i && b<=j)
       {
              tree[node]=min(value,tree[node]);
              //cout<<"ajhaj"<<tree[node]<<" ";
       }
       update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
       update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
      // cout<<"\n->"<<node<<" : "<<tree[node]<<endl;
       tree[node] = min(tree[node*2], tree[node*2+1]); // Updating root with max value
}
void make_array(long long int node, long long int a, long long int b) {
       if(a > b )
              return;
       if(a == b) { // Leaf node
              narray[a] = tree[node];
              return;
       }

       make_array(node*2, a, (a+b)/2); // Updating left child
       make_array(1+node*2, 1+(a+b)/2, b); // Updating right child
      // cout<<"\n->"<<node<<" : "<<tree[node]<<endl;
       tree[node] = min(tree[node*2], tree[node*2+1]);
}
void update1(long long int node,long long int s,long long int e,long long int i,long long int j,long long int val)
{
       if(node<MAX && lazy[node]!=201)
       {
              tree[node]=min(lazy[node],tree[node]);
              if(s!=e)
              {
                     lazy[2*node]=min(lazy[2*node],lazy[node]);
                     lazy[2*node+1]=min(lazy[node],lazy[2*node+1]);
              }
              lazy[node]=201;
       }
       if(s>e || s>j || e<i)
              return;
       if(s>=i && e<=j)
       {
              tree[node]=min(val,tree[node]);
              if(s!=e)
              {
                     lazy[2*node]=min(val,lazy[2*node]);
                     lazy[2*node+1]=min(val,lazy[2*node+1]);
              }
              return;
       }

       update1(node*2,s,(s+e)/2,i,j,val);
       update1(1+node*2,1+(s+e)/2,e,i,j,val);
       //if(in<MAX)
              tree[node]=min(tree[2*1+node*2],tree[2*1+node*2+1]);
}
long long int k[100001][501];
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
void printnap(int k[100][100],int n,int s){

              for ( int i = 0 ; i < n+1 ; i++ ) {
              for ( int j = 0 ; j < s+1 ; j++ ) {
                     printf("%d " , k[i][j]);
              }
              printf("\n");
              }

}
long long int knapsack ( long long int s , long long int n , long long int size[] , long long int value[] ) {
       //s=k

        //memset(k,0,sizeof(k));

       for ( long long int i = 0 ; i < n+1 ; i++ ) {

              for ( long long int j = 0 ; j < s+1 ; j++ ) {
                     if ( i == 0 || j == 0 ) {
                     k[i][j] = 0;
                     }
                     else if ( size[i-1] <= j ) {
                                 // if(used[i-1]==0){
                                  //  if(value[i-1]+k[i-1][j-size[i-1]]>k[i-1][j])
                                   //       used[i-1]=1;
                                   k[i][j] = max( value[i-1]+k[i-1][j-size[i-1]] , k[i-1][j]);
                                   //value[i-1]=0;
                                 // }

                                 // else
                                  //    k[i][j] = max( k[i-1][j-size[i-1]] , k[i-1][j]);

                     }
                     else {
                            k[i][j] = k[i-1][j];
                     }
              }

       }
        /*
       for ( int i = 0 ; i < n+1 ; i++ ) {
              for ( int j = 0 ; j < s+1 ; j++ ) {
                     printf("%d " , k[i][j]);
              }
              printf("\n");
              }
              */

              return k[n][s];
}
vector < pair<long long int,long long int> > tval;
vector < pair<int,pair <int,int > > > real;
vector < pair<int,pair <int,int > > > :: iterator rt;
vector < pair<long long int,long long int> >:: iterator it;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){

              long long int n;long long int k;long long int m;
              //scanf("%lld %lld %lld",&n,&k,&m);
              n=read_int();
              k=read_int();
              m=read_int();
              long long int val[n],sum=0;
              long long int wt[n],val2[n],pos[n];
              int counter=0;
              for(int i=0;i<n;i++){
                    // scanf("%ld",&val[i]);
                    cin>>val[i];
                    sum=sum+val[i];
                    if(val[i]<0){
                       val2[counter]=-val[i];
                       pos[counter]=i;
                       wt[counter]=400;
                       counter++;
                    }
                    //val[i]=val[i]<0?-val[i]:-1;

              }
             // for(int i=0;i<=200005;i++){
              //       lazy[i]=tree[i]=201;
             //        narray[i]=0;
             // }
              // int x = (int)(ceil(log2(n))); //Height of segment tree
              //  int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
                //int *st = new int[max_size];
                real.clear();
               for(int i=0;i<m;i++){
                          int l,r,c;
                          scanf("%d%d%d",&l,&r,&c);
                  // cin>>l>>r>>c;
                   //  scanf("%lld %lld %lld",&l,&r,&c);
                    /// l=read_int();
                    // r=read_int();
                    // c=read_int();
                    // for(int j=l-1;j<r;j++){}
                          //  wt[j]=min(wt[j],c);
                     //update1(1,0,n,l,r,c);
                     real.push_back(make_pair(c,make_pair(l-1,r-1)));
                     //narray[l]=min(c,narray[l]);
                     //narray[r+1]=min(c,narray[r+1]);
                     //cout<<narray[l]<<" "<<narray[r+1]<<endl;


                            //cout<<m<<" ";
              }
              sort(real.begin(),real.end());
              //for(rt=real.begin();rt!=real.end();rt++){
                  //          cout<<(*rt).first<<" ";
              //}
              //cout<<endl;
              for(int i=0;i<counter;i++){
                     for(rt=real.begin();rt!=real.end();rt++){
                            if(pos[i]>=(*rt).second.first && pos[i]<=(*rt).second.second && wt[i]>(*rt).first){
                                   wt[i]=(*rt).first;
                                   break;
                            }
                     }
              }
              //for(int i=0;i<counter;i++){
              //       cout<<wt[i]<<" ";
              //}
             // for(int i=1;i<=n;i++){
              //              cout<<narray[i]<<" ";
             //       narray[i]=narray[i-1];
              //cout<<narray[i]<<" ";
             // }
             // for(int i=0;i<30;i++){
              //       cout<<tree[i]<<" ";
             // }
              //cout<<endl;
              //make_array(1,0,n);
             // for(int i=0;i<30;i++){
             //      cout<<narray[i]<<" ";
            //}
              //cout<<endl;
            //  for(int i=0;i<n;i++){
                   //cout<<val[i]<<" ";
                //   wt[i]=narray[i+1];
                //      if(val[i]!=-1&&wt[i]!=400)
                 //    tval.push_back(make_pair(wt[i],val[i]));
             // }
//
              /*
              cout<<endl;
              for(int i=0;i<n;i++){
                     cout<<wt[i]<<" ";
              }
              cout<<endl;

              //sort(tval.begin(),tval.end());

              //long int ans=-1000000000,curr=0;long int money=0;
              for(it=tval.begin();it!=tval.end();it++){
                    // cout<<(*it).first<<" "<<(*it).second<<endl;

                     if((*it).first+money>k)
                     {
                            curr=0;
                            money=0;
                           // if((*it).first+money>k)
                                 //  break;

                     }

                            money+=(*it).first;
                            curr+=(*it).second;

                 //cout<<"Ans :"<<ans<<" "<<curr<<endl;
                     if(ans<curr)
                            ans=curr;
              }
              /*
2
5 10 5
10 -2 -5 7 -10
1 1 5
2 4 10
4 4 12
3 4 10
1 5 15
5 10 5
10 -2 -5 7 -10
1 1 5
2 4 10
4 4 12
3 4 10
1 5 15

1
10 30 6
10 21 2 1 32 -12 -78 -12 2 3
1 6 16
2 3 4
5 7 15
9 10 8
1 10 20
1 10 20

              cout<<endl;
              for(int i=0;i<n;i++){
                     cout<<wt[i]<<" ";
              }
              */




              long long int ans=knapsack ( k , counter , wt , val2 )+sum;
              //ans=sum+ans;
             cout<<ans<<endl;
             // getchar();

    }
    return 0;
}
