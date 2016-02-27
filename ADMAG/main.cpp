#include <iostream>

using namespace std;

long long int table[100];
void pre_compute(){
       table[1]=1;
       table[2]=2;
       for(int i=3;i<90;i++){
              table[i]=table[i-1]+table[i-2];
       }

}

int main()
{
       pre_compute();
       int tc;
       cin>>tc;
       while(tc--){

                     long long int n;
                     cin>>n;
                     for(int i=1;i<=90;i++){
                            if(n==table[i]){
                                   cout<<i<<endl;
                                   break;
                            }
                            if(n<table[i]){
                                   cout<<i-1<<endl;
                                   break;
                            }
                     }

       }
       return 0;
}
