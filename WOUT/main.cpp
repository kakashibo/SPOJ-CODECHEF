#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long int
#define LSOne(S) (S & (-S))
using namespace std;
#define nL cout<<endl;
int N;
ll ft[1000050];
// Point query: Returns the value at position b in the array
ll query(int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Point update: Adds v to the value at position k in the array
void update(int k, int v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j] in the array
void range_update(int i, int j, int v)	{
	update(i, v);
	update(j + 1, -v);
}

long long int ar[1000050];
int main()
{
    int tc;
    cin>>tc;
    while(tc--){

        long long int truck;long long int n;
        scanf("%lld%lld",&n,&truck);
        N=n+1;
        memset(ft, 0, (n+1) * sizeof(ll));

        for(int i=0;i<n;i++)ar[i]=0;
        for(int i=0;i<n;i++){
            long long int l,r;
            scanf("%lld %lld",&l,&r);

            range_update(l+1,r+1,1);

        }

        for(int i=0;i<n;i++){
            ar[i]=query(i+1);
        }
        long long int low=0,temp=0;
        for(int i=0;i<=truck-1;i++)
              temp=temp+ar[i];

        low=temp;
        for(int i=truck;i<=n-1;i++)
        {
              temp=temp+ar[i]-ar[i-truck];
              if(temp>=low)
                  low=temp;
        }
        printf("%lld\n",(n*truck)-low);



    }
    return 0;
}


