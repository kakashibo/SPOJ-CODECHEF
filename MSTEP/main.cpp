#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,pair<int,int> > >ar;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n;long int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                int val;
                cin>>val;
                ar.push_back(make_pair(val,make_pair(i,j)));
        }
        sort(ar.begin(),ar.end());
        for(int i=0;i<ar.size()-1;i++){
            //cout<<ar[i].first<<" | "<<ar[i].second.first<<" | "<<ar[i].second.second<<endl;
            ans+=abs(ar[i+1].second.first-ar[i].second.first);
            ans+=abs(ar[i+1].second.second-ar[i].second.second);
        }
        //cout<<"Ans :"<<ans<<endl;
        cout<<ans<<endl;
        ar.clear();


    }
    return 0;
}
