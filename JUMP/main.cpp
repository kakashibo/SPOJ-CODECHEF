#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <vector>
#include <set>
#define INF 1000000;
#include <cstdio>
#include <queue>
using namespace std;
int ar[10][10];
int p[300010];
int a[300010],h[300010];
int ans=INT_MAX;
struct edge {
	int u;
	int w;
};

bool operator <( edge a, edge b ) {
	return a.w < b.w;
}
int function(int energy,int curr,int next,int n,int h[],int a[]){

    if(next==n)return pow(h[n]-h[curr],2)+a[n];
    //if(next>n)return INT_MAX;
    //int temp=INT_MAX;
    for(int i=next;i<=n;i++){
            if(p[curr]<p[i]){
                    int temp;
                    if(ar[curr][i]==0){
                        //temp=function(0,curr,i,n);
                        ar[curr][i]=temp;
                    }
                    else
                        temp=ar[curr][i];
                    temp+=energy+pow(h[i]-h[curr],2)+a[i];
                    cout<<temp<<" : "<<i<<" : "<<curr<<endl;
                    ans=min(temp,ans);


            }

    }
    return ans;

}


void dijkstra( vector< edge > graph[], int dist[], int N, int s ) {
	dist[ s ] = 0;
	priority_queue< edge > q;
	q.push( ( edge ) { s, 0 } );

	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();
		for ( int i = 0; i < graph[ p.u ].size(); ++i ) {
			int u = p.u;
			int v = graph[ p.u ][ i ].u;
			if ( dist[ u ] + graph[ p.u ][ i ].w < dist[ v ] ) {
				dist[ v ] = dist[ u ] + graph[ p.u ][ i ].w;
				q.push( graph[ p.u ][ i ] );
			}
		}
	}
}
int main()
{
    int n;
    cin>>n;
    //scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    vector< edge > graph[ n + 1 ];
    int dist[n+1];
    for ( int i = 0; i <= n; ++i ) {
			dist[i] = INF;
    }
    for (int i = 2; i <=n; ++i ) {
        graph[p[1]].push_back( ( edge ) { p[i],pow(h[i]-h[1],2)+a[1]+a[i] } );
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(p[i]<p[j])
            graph[p[i]].push_back(( edge ){p[j],pow(h[i]-h[j],2)+a[j]});
        }
    }
    dijkstra( graph, dist, n, 1 );
    cout<<dist[n];


    return 0;
}
/*
5
1 4 3 2 5
0 1 3 0 0
1 2 3 4 5
*/
