#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
       string a[6];
       for(int i=0;i<6;i++){
              cin>>a[i];

       }
       bool ans=false;
       for(int i=0; i<2; i++) {
              for(int j=2; j<4 ; j++) {
                     for(int k=4; k<6; k++) {
                                   if(a[i]==a[j]&&a[i]==a[k])
                                     ans=true;
                     }
              }
       }
       if(ans)
              cout<<"YES"<<endl;
       else
              cout<<"NO"<<endl;
       continue;
       //getchar();
       if(a[0]==a[2]||a[0]==a[3]){
              if(a[0]==a[4]||a[0]==a[5])
              cout<<"YES"<<endl;
       }
       else if(a[1]==a[2]||a[1]==a[3]){
              if(a[1]==a[4]||a[1]==a[5])
              cout<<"YES"<<endl;
       }
       else
              cout<<"NO"<<endl;
    }
    //getchar();
    return 0;
}
