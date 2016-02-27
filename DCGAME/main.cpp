#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include<string.h>
#include<math.h>
#define N 1000010
#include <map>
#include <vector>
#define MAX (1+(1<<6))
#define inf 0x7fffffff
using namespace std;

int arr[1000010];
int tree[1000010];
map<int,int>mymap;
map<int,int>::iterator it;
vector<pair<int,int> >vec;
/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a == b) { // Leaf node
    		tree[node] += value;
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

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}
int bin_search(int st,int en,int K){

	if(en-st==0){
		return st;
	}

	int mid=(st+(en-st)/2);
	pair<int,int>pr=vec[mid];
	if(pr.first>K)
              return bin_search(st,mid,K);
	else if(pr.first<K)
              return bin_search(mid+1,en,K);
	else return mid;
}
char rev(char curr){
	if(curr=='D')
	return 'C';
	else
	return 'D';
}
char check(int num,char start){
	if(num==0){
         return rev(start);
	}
	else if(num%2!=0){
		return start;
	}
	else{
		return rev(start);
	}

}

	//cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
//}
int main()
{
       long int m,n;char choice;long int operand;char start;
       scanf("%ld %ld",&n,&m);

       for(int i=0;i<n;i++){
              scanf("%lld",&arr[i]);
       }
       build_tree(1, 0, n-1);
       //int fre[n]={1};

       long int max;
       for(int i=0;i<n;i++){
              int temp=0;
              //mymap[arr[i]]=1;
              //if((n-1)-i>temp)
              for(int j=i;j<=i+temp;j++){
                     max=query_tree(1, 0, n-1, i, j);
                     cout<<i<<" "<<j<<" : "<<max<<endl;
                     mymap[max]++;
                     temp++;
                     if(temp+i>n-1)
                            break;
              }


       }
       int fre_sum=0;
        for(it=mymap.begin();it!=mymap.end();++it){
              cout<<it->first<<" : "<<it->second<<endl;
              fre_sum+=it->second+1;

              it->second=fre_sum;
              //cout<<it->first<<" : "<<it->second<<endl;
              vec.push_back(make_pair(it->first,it->second));
        }
        getchar();
       while(m--){
              //cin>>choice>>operand>>start;
              choice=getchar();getchar();
              scanf("%ld",&operand);
              getchar();start=getchar();getchar();
              //cout<<"->"<<choice;

              int limit=vec.size()-1;
              int index=0;
              if(vec[limit].first<operand)
                     index=limit+1;
              else if(vec[0].first>operand){
                     cout<<check(vec[limit].second,start)<<endl;
                     continue;
              }
              else {
                     index=bin_search(0,limit,operand);
                     if(vec[index].first!=operand){
                            if(vec[index].first<operand)
                                   if(choice=='>')
                                          index++;
                                   else
                                          index--;
                            else
                                   if(choice=='<')
                                          index++;
                                   else
                                          index--;
                     }
              }

              //cout<<"index :"<<index<<" "<<limit<<" "<<vec[index].second<<endl;
              if(choice=='>')
                    cout<<check(vec[limit].second-vec[index].second,start)<<endl;
              else if(choice=='<')
                    cout<<check(vec[index-1].second,start)<<endl;
              else if(choice=='=')
                     cout<<check(vec[index].second-vec[index-1].second,start)<<endl;

       }
//       }
       //scanf("%c %ld %c",&choice,&operand,&start);

       //cout<<choice<<" "<<operand<<start;
       return 0;
}
