#include <stdio.h>
#include <iostream>
using namespace std;
//long long int poly[1000000];
#include <algorithm>
struct poly{
long long int *x;
long long int *y;
double area;
long int pos;
long int posasort;
};
bool sort_by_area(poly const& lhs, poly const& rhs) {
return lhs.area < rhs.area;
}

int compare (const void * a, const void * b)
{
double l = ((struct poly *)a)->area;
double r = ((struct poly *)b)->area;
//cout<<l<<" "<<r<<" ";
return l-r;
}
int mains() {
// your code goes here
int tc;
cin>>tc;
while(tc--)
{
int noPoly;
cin>>noPoly;
struct poly pol[noPoly];
for(int i=0;i<noPoly;i++)
{
int noVer;
cin>>noVer;
//noVer*=2;
pol[i].x=new long long int[noVer];
pol[i].y=new long long int[noVer];
pol[i].area=0;
pol[i].pos=i;
int j=0;
cin>>pol[i].x[0];
cin>>pol[i].y[0];
for(j=1;j<noVer;j++)
{
cin>>pol[i].x[j];
cin>>pol[i].y[j];
pol[i].area+=(pol[i].x[j-1]*pol[i].y[j])-(pol[i].x[j]*pol[i].y[j-1]);
}
pol[i].area+=(pol[i].x[j-1]*pol[i].y[0])-(pol[i].x[0]*pol[i].y[j-1]);
//cout<<pol[i].area<<" "<<pol[i].x[j-1]<<pol[i].y[j-1]<<" "<<pol[i].x[0]<<pol[i].y[0]<<endl;
pol[i].area*=.5;
if(pol[i].area<0)
pol[i].area*=-1;
}
//for(int i=0;i<noPoly;i++)
//cout<<pol[i].area<<" ";
//cout<<endl;
sort(pol,pol+noPoly,sort_by_area);
//for(int i=0;i<noPoly;i++)
//cout<<endl;
struct poly ppol[noPoly];
for(int i=0;i<noPoly;i++)
{
// ppol[pol[i].pos]=pol[i];
ppol[pol[i].pos].posasort=i;
}
//cout<<endl;
//for(int i=0;i<noPoly;i++)
//cout<<ppol[i].area<<" ";
//cout<<ppol[i].area<<" "<<ppol[i].pos<<" P: "<<ppol[i].posasort<<" ";
for(int i=0;i<noPoly;i++)
cout<<ppol[i].posasort<<" ";
cout<<endl;
/*
for(int i=0;i<noPoly;i++)
{
for(int j=0;j<noPoly;j++)
{
if(i==pol[j].pos)
printf("%d ",j);
/*
int f=0;
double first=pol[i].area;
for(int j=0;j<noPoly;j++)
{
if((pol[j].area<first))
f++;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct space{
       long int large_diff;
       long int least_diff;
       int pos;
       bool isfilled;
       int bridge_Used=-1;
};

bool compareleast(struct space& lhs, struct space& rhs) {
    return  lhs.least_diff<rhs.least_diff;

}
bool comparelarge(struct space& lhs, struct space& rhs) {
return  lhs.large_diff<rhs.large_diff;
}
//vector<pair<int,int>> dist;
int mains()
{
    int no_i;int no_b;
    cin>>no_i>>no_b;
    space var[no_i];
    int bridgeUsed[no_i];
    long long int x,y,x1,y1;
    bool isBridEmp[no_b];
    long int bridge[no_b];

    for(int i=0;i<no_i;i++){
       cin>>x>>y;

       if(i!=0){
       var[i-1].least_diff=x-y1;
       var[i-1].large_diff=y-x1;
       var[i-1].isfilled=false;
       var[i-1].pos=i;
       }
       x1=x;
       y1=y;
    }
    for(int i=0;i<no_b;i++){
       cin>>bridge[i];
       isBridEmp[i]=true;

    }
    sort(bridge,bridge+no_b);
    sort(var,var+no_i,compareleast);
    if(no_i-1<=no_b){
       cout<<"NO"<<endl;
       return 0;
    }
   int  index=0;
    for(int i=0;i<no_b;i++){
       if(var[index].isfilled==false && var[index].least_diff>=bridge[i]){
                     var[index].isfilled=true;


              isBridEmp[i]=false;
              var[index].bridge_Used=i+1;
              index++;
       }

    }
    sort(var,var+no_i,comparelarge);
    index=0;
    for(int i=0;i<no_b;i++){
               if(var[index].isfilled==false && var[index].least_diff>=bridge[i] && isBridEmp[i]==true){
                     var[index].isfilled=true;
                     isBridEmp[i]=false;
                     var[index].bridge_Used=i+1;
                     index++;
              }

    }
    for(int i=0;i<no_i-1;i++){
       if(!var[i].isfilled){
              cout<<"NO";
              return 0;
       }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<no_i-1;i++)
       cout<<var[i].bridge_Used<<" ";

    return 0;
}

printf("%d ",f);
}
}
cout<<endl;
*/
}
return 0;
}