#include<bits/stdc++.h>
#define pc(x) putchar_unlocked(x);
#define pc(x) putchar_unlocked(x);
using namespace std;
typedef long long int ll;
int prime[1000010]={0};
void run(long long int n);
int primea[1000010];
long long int ans[10000001];
int phii[1000001]={0};
long long int phi(long long int n);
/*
inline void fastRead_int(int &x) {
	    register int c = getchar_unlocked();
	    x = 0;
	    int neg = 0;
	    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	    if(c=='-'){
	    	neg = 1;
	        c = getchar_unlocked();}
	    for(; c>47 && c<58 ; c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
	    if(neg){ x = -x;}}

    inline void writeInt (long long int n)
    {
        long long int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
    }
*/
void improved_sieve(int N)
        {
             int M=(N-1)/2;
             int c=1;
             int x=(floor(sqrt(N))-1)/2,i,j;
             vector<bool> S(M+1,0);
             for (i=1;i<=x;i++)
                 if (!S[i])
                    for (j=2*i*(i+1);j<=M;j+=(2*i+1))
                        S[j]=1;



             for (i=1;i<=M;i++)
                 if (!S[i]){
                    //if((((2*i+1)-1)%4)==0){
                    //printf("%ld \n",(2*i+1));
                    primea[c++]=2*i+1;
                    prime[2*i+1]=1;
                    //if(arr[i] != i)	sum[i] = sum[arr[i]]*sum[i/arr[i]];
 		            //else sum[i] = (c[i]*i*i + 1LL)/(c[i]+1LL);
                    //cout<<2*i+1<<" ";
                    //primea[2*i+1]=1;
                   // ar[2*i+1]=1;
                   // }
                 }
            primea[0]=2;
            prime[2]=1;


             //
        }
void sieve(int N)
{
    int x=sqrt(N),i,j;
    vector<bool> S(N+1,0);
    for (i=4;i<=N;i+=2)
        S[i]=1;
    for (i=3;i<=x;i+=2)
        if (!S[i])
          for (j=i*i;j<=N;j+=2*i)
             S[j]=1;

    long long s=0;
        for (i=2;i<=N;i++)
            if (!S[i])
              prime[i]=1;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void ansfind()
{
    memset(ans,0,sizeof ans);
    long long int i,j;
    for(i=2;i<=1000000;i++){
        if(prime[i]!=1)
        for(j=i;j<=1000000;j+=i)
            ans[j]+=i*phii[i];
    }

}
void runner(){

   for(int i=2;i<=1000000;i++){
       phii[i]=phi(i);
   }
}
long long int ans1;
int main()
{
   ll n,sum=0;
   //sieve(100000);
   improved_sieve(1000000);
   runner();
   ansfind();
   int tc;
   cin>>tc;
   //n=1;
   while(tc--){
        int a;
        fastRead_int(a);
        n=a;
        if(a<1000000){
            if(prime[a]==1){
                 writeInt(((n-1)*n)+1);
                 continue;
            }
        }
            if(a<1000000){
                writeInt(ans[n]+1);
            }
            else{
                run(n);
            }




   }
   return 0;
}

long long int phi(long long int n)
{
    long long int result = n;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    int sr=sqrt(n);
    for (int i = 0; primea[i] <= sr; i++)
    {
        // Check if i is a prime factor.
        if(n%primea[i] == 0)
        {
            // If yes, then update n and result
            while (n % primea[i] == 0)
                n /= primea[i];
            result -= result / primea[i];
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}
int arr[10000001];
ll sum[10000001];
ll c[10000001];
void Sieve(int n)
{
	arr[1]=1;
	sum[1]=1;
	c[1]=1;
 	int a,b;
    for (ll i=2;i<=n; ++i)
    {
       if ( arr[i] == 0 )
       {
        	arr[i] = i;
        	c[i] = i;
            ll num=i*i;
		    while ( (num) <= n )
		    {
		    	if(arr[num]==0)
		    	{
		    	    c[num] = i;
		    	    if((num/i)%i ==0)
		        	{
		        	    arr[num] = i*arr[num/i];

		        	}
		        	else
		        	{
		        	    arr[num] = i;

		        	}
		    	}
                num +=i;
		    }
       }
 		if(arr[i] != i)	sum[i] = sum[arr[i]]*sum[i/arr[i]];
 		else sum[i] = (c[i]*i*i + 1LL)/(c[i]+1LL);
   }
}
void run(long long int n){

      long long int counter=n-1;
      long long int sum=1;
      for(int i=1;i<n;i++){
           if(n%i==0){
               long long int temp;
               /*
                if((n/i)<100000){
                    if(phii[n/i]!=0)
                        temp=phii[n/i];
                    else{
                         temp=phi(n/i);
                         phii[n/i]=temp;
                    }
                 }
                 else{
                    temp=phi(n/i);
                     phii[n/i]=temp;
                 }
                 */
                temp=phi(n/i);
                sum+=(temp*n/i);
                counter=counter-temp;

           }
           if(counter<=0)break;
      }
      //ans1=sum;
      //cout<<sum<<endl;
      printf("%lld\n",sum);
      //writeInt(sum);
      //46349 Wronged at46349 | -2146783843 2148183453
}







/*
using namespace std;
long int gcd[10000]={1};
int main()
{


    int tc;
    while(tc--){
        int[] gcd = new int[x + 1];
        for (int i = 1; i <= x; i++) gcd[i] = 1;
        for (int i = 0; i < p.Length; i++)
                for (int j = 0, h = p[i]; j < c[i]; j++, h *= p[i])
            f       for (long k = h; k <= x; k += h)
                        gcd[k] *= p[i];

    long sum = 0;
    for (int i = 1; i <= x; i++) sum += gcd[i];
    }
    return 0;
}
sum=sum*2;
                 sum+=2;
                 1
1/gcd(1,1)= 1
1
2
2/gcd(1,2)= 2
2/gcd(2,2)= 1
3
3
3/gcd(1,3)= 3
3/gcd(2,3)= 3
3/gcd(3,3)= 1
7
4
4/gcd(1,4)= 4
4/gcd(2,4)= 2
4/gcd(3,4)= 4
4/gcd(4,4)= 1
11
5
5/gcd(1,5)= 5
5/gcd(2,5)= 5
5/gcd(3,5)= 5
5/gcd(4,5)= 5
5/gcd(5,5)= 1
21
6
6/gcd(1,6)= 6
6/gcd(2,6)= 3
6/gcd(3,6)= 2
6/gcd(4,6)= 3
6/gcd(5,6)= 6
6/gcd(6,6)= 1
21
7
7/gcd(1,7)= 7
7/gcd(2,7)= 7
7/gcd(3,7)= 7
7/gcd(4,7)= 7
7/gcd(5,7)= 7
7/gcd(6,7)= 7
7/gcd(7,7)= 1
43
8
8/gcd(1,8)= 8
8/gcd(2,8)= 4
8/gcd(3,8)= 8
8/gcd(4,8)= 2
8/gcd(5,8)= 8
8/gcd(6,8)= 4
8/gcd(7,8)= 8
8/gcd(8,8)= 1
43
9
9/gcd(1,9)= 9
9/gcd(2,9)= 9
9/gcd(3,9)= 3
9/gcd(4,9)= 9
9/gcd(5,9)= 9
9/gcd(6,9)= 3
9/gcd(7,9)= 9
9/gcd(8,9)= 9
9/gcd(9,9)= 1
61
10
10/gcd(1,10)= 10
10/gcd(2,10)= 5
10/gcd(3,10)= 10
10/gcd(4,10)= 5
10/gcd(5,10)= 2
10/gcd(6,10)= 5
10/gcd(7,10)= 10
10/gcd(8,10)= 5
10/gcd(9,10)= 10
10/gcd(10,10)= 1
63
11
11/gcd(1,11)= 11
11/gcd(2,11)= 11
11/gcd(3,11)= 11
11/gcd(4,11)= 11
11/gcd(5,11)= 11
11/gcd(6,11)= 11
11/gcd(7,11)= 11
11/gcd(8,11)= 11
11/gcd(9,11)= 11
11/gcd(10,11)= 11
11/gcd(11,11)= 1
111
12
12/gcd(1,12)= 12
12/gcd(2,12)= 6
12/gcd(3,12)= 4
12/gcd(4,12)= 3
12/gcd(5,12)= 12
12/gcd(6,12)= 2
12/gcd(7,12)= 12
12/gcd(8,12)= 3
12/gcd(9,12)= 4
12/gcd(10,12)= 6
12/gcd(11,12)= 12
12/gcd(12,12)= 1
77
13
13/gcd(1,13)= 13
13/gcd(2,13)= 13
13/gcd(3,13)= 13
13/gcd(4,13)= 13
13/gcd(5,13)= 13
13/gcd(6,13)= 13
13/gcd(7,13)= 13
13/gcd(8,13)= 13
13/gcd(9,13)= 13
13/gcd(10,13)= 13
13/gcd(11,13)= 13
13/gcd(12,13)= 13
13/gcd(13,13)= 1
157
14
14/gcd(1,14)= 14
14/gcd(2,14)= 7
14/gcd(3,14)= 14
14/gcd(4,14)= 7
14/gcd(5,14)= 14
14/gcd(6,14)= 7
14/gcd(7,14)= 2
14/gcd(8,14)= 7
14/gcd(9,14)= 14
14/gcd(10,14)= 7
14/gcd(11,14)= 14
14/gcd(12,14)= 7
14/gcd(13,14)= 14
14/gcd(14,14)= 1
129
15
15/gcd(1,15)= 15
15/gcd(2,15)= 15
15/gcd(3,15)= 5
15/gcd(4,15)= 15
15/gcd(5,15)= 3
15/gcd(6,15)= 5
15/gcd(7,15)= 15
15/gcd(8,15)= 15
15/gcd(9,15)= 5
15/gcd(10,15)= 3
15/gcd(11,15)= 15
15/gcd(12,15)= 5
15/gcd(13,15)= 15
15/gcd(14,15)= 15
15/gcd(15,15)= 1
147
16
16/gcd(1,16)= 16
16/gcd(2,16)= 8
16/gcd(3,16)= 16
16/gcd(4,16)= 4
16/gcd(5,16)= 16
16/gcd(6,16)= 8
16/gcd(7,16)= 16
16/gcd(8,16)= 2
16/gcd(9,16)= 16
16/gcd(10,16)= 8
16/gcd(11,16)= 16
16/gcd(12,16)= 4
16/gcd(13,16)= 16
16/gcd(14,16)= 8
16/gcd(15,16)= 16
16/gcd(16,16)= 1
171
17
17/gcd(1,17)= 17
17/gcd(2,17)= 17
17/gcd(3,17)= 17
17/gcd(4,17)= 17
17/gcd(5,17)= 17
17/gcd(6,17)= 17
17/gcd(7,17)= 17
17/gcd(8,17)= 17
17/gcd(9,17)= 17
17/gcd(10,17)= 17
17/gcd(11,17)= 17
17/gcd(12,17)= 17
17/gcd(13,17)= 17
17/gcd(14,17)= 17
17/gcd(15,17)= 17
17/gcd(16,17)= 17
17/gcd(17,17)= 1
273
18
18/gcd(1,18)= 18
18/gcd(2,18)= 9
18/gcd(3,18)= 6
18/gcd(4,18)= 9
18/gcd(5,18)= 18
18/gcd(6,18)= 3
18/gcd(7,18)= 18
18/gcd(8,18)= 9
18/gcd(9,18)= 2
18/gcd(10,18)= 9
18/gcd(11,18)= 18
18/gcd(12,18)= 3
18/gcd(13,18)= 18
18/gcd(14,18)= 9
18/gcd(15,18)= 6
18/gcd(16,18)= 9
18/gcd(17,18)= 18
18/gcd(18,18)= 1
183
19
19/gcd(1,19)= 19
19/gcd(2,19)= 19
19/gcd(3,19)= 19
19/gcd(4,19)= 19
19/gcd(5,19)= 19
19/gcd(6,19)= 19
19/gcd(7,19)= 19
19/gcd(8,19)= 19
19/gcd(9,19)= 19
19/gcd(10,19)= 19
19/gcd(11,19)= 19
19/gcd(12,19)= 19
19/gcd(13,19)= 19
19/gcd(14,19)= 19
19/gcd(15,19)= 19
19/gcd(16,19)= 19
19/gcd(17,19)= 19
19/gcd(18,19)= 19
19/gcd(19,19)= 1
343
20
20/gcd(1,20)= 20
20/gcd(2,20)= 10
20/gcd(3,20)= 20
20/gcd(4,20)= 5
20/gcd(5,20)= 4
20/gcd(6,20)= 10
20/gcd(7,20)= 20
20/gcd(8,20)= 5
20/gcd(9,20)= 20
20/gcd(10,20)= 2
20/gcd(11,20)= 20
20/gcd(12,20)= 5
20/gcd(13,20)= 20
20/gcd(14,20)= 10
20/gcd(15,20)= 4
20/gcd(16,20)= 5
20/gcd(17,20)= 20
20/gcd(18,20)= 10
20/gcd(19,20)= 20
20/gcd(20,20)= 1
231
*/
