#include <cstdio>
#include <cmath>
#include <iostream>
#include <math.h>
#include <string.h>
#define MOD 1000000007
using namespace std;
int const MAXN = 100050;
/// Implementaion https://mohamedmosamin.wordpress.com/2013/06/19/spoj-8002-horrible/
struct node {
    int st;
    int en;
    int mid;
    long long value;

};
long long int A[MAXN];
node tree[4 * MAXN];
long long int now=0;
long long lazy[4 * MAXN];
long long lazym[4 * MAXN];
long long lazyr[4*MAXN];
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
void printnap(int k[100][100],int n,int s){

              for ( int i = 0 ; i < n+1 ; i++ ) {
              for ( int j = 0 ; j < s+1 ; j++ ) {
                     printf("%d " , k[i][j]);
              }
              printf("\n");
              }

}
void build_tree(int node,int a,int b) {
  	if(a > b) return;

       tree[node].st = a, tree[node].en = b;
       tree[node].mid = (tree[node].st + tree[node].en) >> 1;

  	if(a == b) {
    		tree[node].value = A[a];
		return;
	}


	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
       lazym[node]=1;
       tree[node].value = lazy[node] =lazyr[node]= 0;
	tree[node].value = (tree[node*2].value+ tree[node*2+1].value)%MOD;
}

void updateeachnode(int stIndex, int lo, int hi, int index, long long int value, long long int diff) {
              if (lo == hi) {
                     tree[stIndex].value=value;
                     return;
              }

              int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
              if (index <= mid)
                     updateeachnode(left, lo, mid, index, value,diff);
              else
                     updateeachnode(right, mid+1, hi, index, value,diff);

              tree[stIndex].value=tree[stIndex].value-diff;
       }
void init_tree(int index, int left, int right) {

    tree[index].st = left, tree[index].en = right;
    tree[index].mid = (tree[index].st + tree[index].en) >> 1;

    if (tree[index].st != tree[index].en) {
        init_tree(2 * index, left, tree[index].mid);
        init_tree(2 * index + 1, tree[index].mid + 1, right);
    }

    tree[index].value = lazy[index] =lazym[index]= 0;
}

long long getValue(int index) {
    return (tree[index].value + (lazy[index] * (long long) (tree[index].en - tree[index].st + 1)%MOD)%MOD)%MOD;
}

void refresh(int index) {
    lazy[2 * index] =(lazy[2 * index]+ lazy[index])%MOD;
    lazy[2 * index + 1]= (lazy[2 * index + 1]+lazy[index])%MOD;
    lazy[index] = 0;
}

void printtree(){
       cout<<"Tree -";
      for(int i=0;i<15;i++){
              cout<<tree[i].value<<"->"<<lazy[i]<<"->"<<lazym[i]<<" ";
      }
       cout<<endl;
}
void resetrefresh(int index){
    lazyr[2 * index] =lazyr[index];
    lazyr[2 * index + 1]= lazyr[index];
    lazyr[index] = -1;


}
long long int typevalue(int index,int left,int right,long long int value){
     //  return (((tree[index].en-tree[index].st)*value)%MOD-query(1,left,right))%MOD;

}
void refresh_allnode(int index,int left, int right,int real){
       //cout<<real<<"->"<<index<<" ";
       if(left>right)
              return;
        if(left!=right){

             tree[index].value=getValue(index);
             refresh(index);
        }
        else{

              now=tree[index].value=(tree[index].value+lazy[index])%MOD;
              lazy[index] = 0;
              return;
        }
       // cout<<index<<" ";
       if (real <= tree[index].mid)
       refresh_allnode(2 * index, left, tree[index].mid,real);
       else
       refresh_allnode(2 * index + 1, tree[index].mid + 1, right,real);
}

void update(int index, int left, int right, long long int value,int type) {

    if (tree[index].st >= left && tree[index].en <= right) {


        if(type==2)
              lazym[index]=(lazym[index]*value)%MOD;
        else
              lazy[index] = (lazy[index]+value)%MOD;

        return;
    }
    if (tree[index].st > right || tree[index].en < left)
        return;
    if (tree[index].st < left || tree[index].en > right) {
        refresh(index);
        update(2 * index, left, right, value,type);
        update(2 * index + 1, left, right, value,type);
        tree[index].value = ((getValue(2 * index)*lazym[2*index])%MOD + (getValue(2 * index + 1)*lazym[2*index+1])%MOD)%MOD;
    }
}

long long query(int index, int left, int right,long long int mul) {
    if (tree[index].st >= left && tree[index].en <= right)
        return (getValue(index)*lazym[index])%MOD;
    if (tree[index].st > right || tree[index].en < left)
        return 0;
    long long result = 0;
    if (tree[index].st < left || tree[index].en > right) {
        refresh(index);
        result = query(2 * index, left, right,mul*lazym[index]) + query(2 * index + 1, left, right,mul*lazym[index]);
        tree[index].value = ((getValue(2 * index)*lazym[2*index])%MOD + (getValue(2 * index + 1)*lazym[2*index+1])%MOD)%MOD;
    }
    return result;
}


int main()
{
              long long int N,Q;
              //scanf("%ld %ld",&N,&Q);
              N=read_int();
              Q=read_int();
              for(int i=0;i<N;i++){
                    // scanf("%lld",&A[i]);
                    A[i]=read_int();
              }

              //init_tree(1, 0, N-1);
              build_tree(1,0,N-1);
              //memset(lazy,0,sizeof(lazy));
              //memset(lazy,0,sizeof(lazy));
              int choice;long long int p,q;
              long long int v;
              while(Q--){
                     scanf("%d",&choice);
                     if(choice ==1){
                                   p=read_int();
                                   q=read_int();
                                   v=read_int();
                                   //scanf("%d %d %lld", &p, &q, &v);
                                   printtree();
                                   update(1, p - 1, q - 1, v,1);
                                   printtree();
                                   //st.printstree();
                            }
                     else if(choice == 2){
                                   scanf("%d %d %lld", &p, &q, &v);
                                   printtree();
                                   update(1, p - 1, q - 1, v, 2);
                                   printtree();
                                   //st.updatemul(p-1, q-1, v);

                     }
                     else if (choice ==3 ){
                                   p=read_int();
                                   q=read_int();
                                   v=read_int();
                                  // scanf("%d %d %lld", &p, &q, &v);
                                  // printtree();
                                   for(int k=p-1;k<=q-1;k++){
                                          refresh_allnode(1,0,N-1,k);
                                         // printtree();
                                          long long int diff=now-v;
                                          //cout<<" NOW :"<<now<<" "<<k<<" " <<A[k]<<endl;
                                        //  updateeachnode(1,0,N-1,k,v,diff);
                                        //  printtree();
                                   }
                                       //updateeachnode(1,0,N-1,k,v);
                                     // printtree();
                            }
                     else if(choice ==4){
                            p=read_int();
                                   q=read_int();
                                  // v=read_int();
                                   //scanf("%d %d", &p, &q);
                                   printf("%lld\n", query(1, p - 1, q - 1,1));
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
2 2 4 2
4 1 4
*/