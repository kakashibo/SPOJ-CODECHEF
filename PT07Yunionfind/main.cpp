#include <iostream>

using namespace std;
int node[10010];
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
    int nodes;int edges;int x,y;
    cin>>nodes>>edges;
    if(nodes-1!=edges){
       cout<<"NO"<<endl;
       return 0;
    }
    for (int i=0; i<nodes; i++)
		node[i] = i;

    for (int i=0; i<edges; i++) {
	cin>>x>>y;
	x--;
	y--;
       if(!find_fun(x,y)){
              union_fun(x,y);
       }
       else{
            cout<<"NO"<<endl;
            return 0;
       }
    }
    cout<<"YES"<<endl;
    return 0;
}
