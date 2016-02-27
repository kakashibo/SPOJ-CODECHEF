#include <iostream>
#include <stdio.h>
using namespace std;
unsigned long long int ar[100010];
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        unsigned long long int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        unsigned long long int inc=0;
        unsigned long long int count=0;
        unsigned long long int pre=ar[0];
        for(int i=0;i<n;i++){
            if(pre<=ar[i]){
                inc++;
            }
            else{
                count+=((inc*(inc+1))/2);
                inc=1;
            }
            pre=ar[i];
        }
        unsigned long long int ans=count+(((inc*(inc+1))/2));
        printf("%llu\n",ans);

    }
    return 0;
}
