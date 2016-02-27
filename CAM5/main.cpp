#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
int node[100010];
int root(int i) {
	while (node[i] != i) i = node[i];
	return i;
}

int find_fun (int u, int v) {
	return (root(u) == root(v));
}

void union_fun (int u, int v) {
	node[root(u)] = root(v);
}
int main()
{
    int tc;set<int> ans;
    cin>>tc;
    while(tc--){
       int nodes;int a,b;
       cin>>nodes;int counts=0;
       int friends;
       cin>>friends;
       for (int i=0; i<=nodes; i++)
		node[i] = i;
       ans.clear();
       for(int i=0;i<friends;i++){
              cin>>a>>b;
            // cout<<"--------"<<endl;
             // cout<<root(a)<<" "<<root(b)<<endl;
              if(!find_fun(a,b)){
                     union_fun(a,b);
              }
             // cout<<root(a)<<" "<<root(b)<<endl;
              //cout<<"--------"<<endl;
       }
       for (int i=0; i<nodes; i++){
              ans.insert(root(i));
              //getchar();
              //cout<<i<<":"<<root(i)<<" ";

       }

       cout<<ans.size()<<endl;
       //getchar();
		//cout<<i<<":"<<root(i)<<" ";



    }
    return 0;
}
