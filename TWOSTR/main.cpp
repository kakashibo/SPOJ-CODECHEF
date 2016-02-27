#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
       string x,y;
       cin>>x>>y;
       int f=0;
       for(int i=0;i<x.length();i++){
              if(x[i]=='?'||y[i]=='?')
                     continue;
              if(x[i]=='?'&&y[i]=='?')
                     continue;
              if(x[i]==y[i])
                     continue;
              f=1;
       }
       if(f)
              cout<<"No"<<endl;
       else
              cout<<"Yes"<<endl;
    }
    return 0;
}
