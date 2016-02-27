#include <iostream>
#include<cmath>
using namespace std;
int gcd(int a, int b)
{
       if(b==0)
       return a;
       else
       return gcd(b, a%b);
}
int track1(int a, int b)
{
       int k=gcd(a,b);
       return (a+b)/k;
}
int track2(int a, int b)
{
       int k=gcd(a,b);
       if(a>b)
              return (a-b)/k;
       else
              return (b-a)/k;
}
int main()
{
    //cout << "Hello world!" << endl;
    int tc;
    cin>>tc;
    while(tc--){

       int a,b;
       cin>>a>>b;

       if(a<0&&b>0)
        cout<<track1(abs(a),b)<<endl;
       else if(a>0&&b<0)
        cout<<track1(abs(b),a)<<endl;
        else if(a<0&&b<0)
              cout<<track2(abs(a),abs(b))<<endl;
        else
             cout<<track2(a,b)<<endl;
    }
    return 0;
}
