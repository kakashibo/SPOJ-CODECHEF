#include <iostream>
#include <vector>
using namespace std;
int ar[1000010];
int pos[1000010];
vector <pair<int,int> > v;

/*
7 0
4 2 6 3 2 5 1
*/
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
       cin>>ar[i];

       for(int i=0;i<n;i++){
              pos[i]=-1;
              for(int j=i;j>=0;j--){


                     if(i!=j)
                     if(ar[j]%ar[i]==k){
                            pos[i]=j;
                            cout<<i<<" : "<<j<<endl;
                            break;
                     }
              }
       }

       for(int i=0;i<n;i++){
              cout<<pos[i]<<" | ";
              if(i>0&&pos[i-1]>=pos[i]&&pos[i]!=-1&&pos[i-1]!=-1)
                     ar[i]=-1;

       }
       cout<<endl;
       for(int i=0;i<n;i++){
               if(ar[i]!=-1)
               {
                      v.push_back(make_pair(i,pos[i]));
               }
       }



       int sum=0;
       int end=v.size();
       for(int i=0;i<end;i++){

              sum+=i*(v[i+1].second-v[i].second);
              cout<<sum<<" ";

       }
       cout<<n*(n+1)/2-sum<<endl;
    return 0;
}
