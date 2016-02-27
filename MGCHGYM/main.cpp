#include <iostream>
#include <stdio.h>
#include <cmath>
//Implementaion from http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
using namespace std;
void toArray(long int l,long int r,long int w);
bool isSubsetSum(int l,int r, int n, long int sum);
long int wt[100010];
void printar(int n){
    cout<<"Print : ";
    for(int i=1;i<=n;i++){
        cout<<wt[i]<<" ";
    }
    cout<<endl;
}
long int n,q;
int main()
{
    scanf("%ld%ld",&n,&q);

    for(int i=1;i<=n;i++){
        scanf("%ld",&wt[i]);
    }
    while(q--){
        int type;
        scanf("%d",&type);

        if(type==1){
            long int t1,t2;
            scanf("%ld%ld",&t1,&t2);
            wt[t1]=t2;
            //printar(n);
        }
        else if(type==2){
            long int t1,t2;
            scanf("%ld%ld",&t1,&t2);
            int c=0;
            int half=((t2-(t1-1))/2)+t1;
            for(int i=t1;i<half;i++){
                 wt[i]=wt[i]^wt[t2-c];
                 wt[t2-c]=wt[i]^wt[t2-c];
                 wt[i]=wt[i]^wt[t2-c];
                 c++;
                 //printar(n);

            }
        }
        else {
            long int r,l,w;
            scanf("%ld%ld%ld",&l,&r,&w);
            toArray(l,r,w);


        }
    }
    return 0;
}
void toArray(long int l,long int r,long int w){

    //printar(n);
    //long int ar[r-l+1];int j=0;
    //for(long int i=l;i<=r;i++){
    //    ar[j++]=wt[i];
    //}
    /*
    cout<<"Array build ";
    for(int i=0;i<r-l+1;i++){
        cout<<ar[i]<<" ";
    }
    */
    if(isSubsetSum(l,r,r-l+1,w))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
bool **subset;
bool isSubsetSum(int l,int r, int n, long int sum)
{
    /*
    cout<<"GOT ->";
    for(int i=0;i<n;i++){
        cout<<set[i]<<" ";
    }
    cout<<endl;
    */

    subset=new bool*[sum+1];
    //bool subset[sum+1][n+1];
    subset[0]=new bool[n+1];
     for (int i = 1; i <= sum; i++){
        subset[i]=new bool[n+1];
        subset[i][0] = false;
     }

    for (int i = 0; i <= n; i++)
      subset[0][i] = true;



     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= wt[j+l-1])
           subset[i][j] = subset[i][j] || subset[i - wt[j+l-1]][j-1];
       }
     }
     return subset[sum][n];
}
