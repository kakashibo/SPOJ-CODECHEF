#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
#include<string.h>
#include<math.h>

#define N 20
#define MAX 100010
#define inf 0x7fffffff
///Implementation from https://gist.github.com/shobhit6993/7088061
long long int arr[MAX];
long long int tree[MAX];
long long int lazy[MAX];
long long int lazym[MAX];

/**
 * Build and init tree
 */
void build_tree(int node,int a,int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = (tree[node*2]+ tree[node*2+1]); // Init root value
}
/** Reset Vales of Lazy Propagation
*/
void reset(int stIndex, int start, int end, UpdateType value) {
       if(start > end )
              return;
       if(start == end) { // Leaf node
              nodes[stIndex].total = ((nodes[stIndex].total)+value)+nodes[stIndex].pendingUpdate;
              //cout<<"jaja";
              nodes[stIndex].pendingUpdate=0;

              return;
       }
       //cout<<"jajaasd"<<start<<" "<<end<<" "<<nodes[stIndex].pendingUpdate<<" ";
       int mid = (start+end)/2;
			//cout<<mid<<" ";
			int leftChildIndex = 2 * stIndex;
			int rightChildIndex = leftChildIndex + 1;
              reset(leftChildIndex, start, mid, nodes[stIndex].pendingUpdate+value);
              reset(rightChildIndex, mid+1, end, nodes[stIndex].pendingUpdate+value);
              nodes[stIndex].pendingUpdate=0;

       }
/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(ll node,ll a, ll b, ll i, ll j, ll value) {

  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node];
    			lazym[node*2+1] // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = max(q1, q2); // Return final result

	return res;
}

int main()
{
    //int tc;
    //scanf("%d",&tc);
    //while(tc--){
              int N,Q;
              scanf("%d %d",&N,&Q);

              for(int i=0;i<N;i++){
                     scanf("%lld",&arr[i]);
              }

              //for(int i = 0; i < N; i++) arr[i] = 1;

              build_tree(1, 0, N-1);

              memset(lazy, 0, sizeof lazy);

              //printf("%lld\n", st.query(1, 3));
              int choice;int p,q;
              long long int v;
              while(Q--){
              scanf("%d",&choice);

              switch(choice){
                     case 1: scanf("%d %d %lld", &p, &q, &v);
                                   //st.printstree();
                                   update_tree(1, 0, N-1,p-1, q-1, v);
                                   //printf("%lld\n", st.query(p-1, q-1));
                                   //st.printstree();
                                   break;
                     case 2: scanf("%d %d %lld", &p, &q, &v);
                                   //st.updatemul(p-1, q-1, v);
                                   break;
                     case 3:scanf("%d %d %lld", &p, &q, &v);
                                   st.reset();
                                   //cout<<endl;
                                   // st.printstree();
                                   for(int k=p-1;k<=q-1;k++)
                                        st.updateeach(k,v);
                                   //st.printstree();
                                          //st.buildTree()
                                   break;
                     case 4 :scanf("%d %d", &p, &q);
                                   printf("%lld\n",query_tree(1, 0, N-1,p-1, q-1));
                                   break;
                     }
              }
   // }
   return 0;
}
/*
4 4
1 2 3 4
4 1 4
1 1 3 10
3 2 4 2
4 1 4
*/