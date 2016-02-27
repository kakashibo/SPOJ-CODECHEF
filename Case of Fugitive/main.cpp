#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct space{
       long long int large_diff;
       long long int least_diff;
       int pos;
       bool isfilled;
       int bridge_Used=-1;
};

bool compareleast(space const& lhs, space const& rhs) {
    return  lhs.least_diff<rhs.least_diff;

}
bool comparelarge(space const& lhs, space const& rhs) {
return  lhs.large_diff<rhs.large_diff;
}
//vector<pair<int,int>> dist;
int main()
{
    int no_i;int no_b;
    cin>>no_i>>no_b;
    struct space var[no_i];
    int bridgeUsed[no_i];
    long long int x,y,x1,y1;
    bool bridgepoint[no_b];
    pair<long long int,int> bridge[no_b];
    int ans[no_i+1];
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
    //for(int i=0;i<no_i-1;i++){
    //   cout<<var[i].least_diff<<" "<<var[i].pos<<endl;
    //}
    long long int bg;
    for(int i=0;i<no_b;i++){
       cin>>bg;
       bridge[i]=make_pair(bg,i);
       bridgepoint[i]=true;


    }
    sort(bridge,bridge+no_b);
    sort(var,var+no_i-1,comparelarge);
    if(!(no_i-1<=no_b)){
       cout<<"No"<<endl;
       return 0;
    }
    //for(int i=0;i<no_i-1;i++){
    //   cout<<var[i].least_diff<<" "<<var[i].pos<<endl;
    //}
   int  index=0;
    for(int i=0;i<no_b;i++){
      // cout<<"->"<<var[index].least_diff<<" "<<var[index].large_diff<<" | "<<bridge[i].first<<endl;
       if(var[index].isfilled==false && var[index].least_diff<=bridge[i].first&& var[index].large_diff >=bridge[i].first){
                     var[index].isfilled=true;


              bridgepoint[bridge[i].second]=false;
              var[index].bridge_Used=bridge[i].second+1;
             // cout<<"B"<<var[index].bridge_Used<<endl;
              index++;
       }
       if(index>no_i-2)
                     break;

    }
    //cout<<"Broidge ";
    //for(int i=0;i<no_b;i++){

    //   cout<<isBridEmp[i]<<" "<<i<<endl;

    //}
    //sort(var,var+no_i-1,comparelarge);
    //index=1;
    /*
    for(int i=0;i<no_b;i++){
               if(var[index].isfilled==false && var[index].least_diff>=bridge[i] && isBridEmp[i]==true){
                     var[index].isfilled=true;
                     isBridEmp[i]=false;
                     var[index].bridge_Used=i+1;
                     index++;
              }
              if(index>no_i-1)
                     break;

    }
    */
    for(int i=0;i<no_i-1;i++){
              //cout<<var[i].bridge_Used<<" ";
              ans[var[i].pos]=var[i].bridge_Used;
       if(!var[i].isfilled){
              cout<<"No";
              return 0;
       }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<no_i;i++)
       cout<<ans[i]<<" ";

    return 0;
}