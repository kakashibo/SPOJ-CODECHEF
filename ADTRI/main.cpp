        #include <iostream>
        #include <map>
        #include <cmath>
        #include <vector>
        #include <stdio.h>
        #include <algorithm>
        #include <fstream>
        #include <string>
        #include <string>
        #include <stdlib.h>


        using namespace std;
        vector<int> prime;
        int ar[5000010]={0};
        int primea[50010];

        int total;
        int c=0;
        map<int,int> mp;
        int check;
        void primeFactors(int n);
        unsigned int isqrt(int number) {
          unsigned int n  = 1;
          unsigned int n1 = (n, number);

          while(abs(n1 - n) > 1) {
            n  = n1;
            n1 = (n, number);
          }
          while(n1*n1 > number)
            n1--;
          return n1;
        }



        //Implementation taken from https://comeoncodeon.wordpress.com/?s=prime+number
        void improved_sieve(int N)
        {
             int M=(N-1)/2;
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
                    //primea[2*i+1]=1;
                   // ar[2*i+1]=1;
                   // }
                 }


             //
        }
        void sieve(int N)
        {

                ofstream infiles("ans.txt");

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
                    if((((i)-1)%4)==0){
                        //printf("%d \n",(i));
                        //prime.push_back((i));
                        infiles<<i<<",";
                    }


        }
         long int tc;int flag=0;
        int main()
        {

            cin>>tc;

            improved_sieve(2250);






            while(tc--){
                int n;
                scanf("%d",&n);
                //cin>>n;
                //scan_integer(n);
                //cin>>n;
                check=0;

                //vector<long int> :: iterator it;
                //for(it=prime.begin();it<prime.end();it++){



                primeFactors(n);
                if(check==0){
                    printf("NO\n");
                }
            }

            return 0;
        }

        void primeFactors(int n)
        {
            while (n%4 == 0){
                n=n/4;
            }
            while (n%2 == 0)
            {
                n=n>>1;

            }
            if(n==1)
            {
              return;

            }
            int sr=sqrt(n);
            for (int i = 0; primea[i] <= sr; i++)
            {
                if(n%primea[i] == 0)
                {


                        if((((primea[i])-1)%4)==0){
                                printf("YES\n");
                                check=1;

                                return;
                        }
                        while(n%primea[i] == 0)
                            n=n/primea[i];
                }

            }

                if(n>2){
                    if(((n-1)%4)==0){
                                printf("YES\n");
                                check=1;

                                return;
                        }
                }

        }
