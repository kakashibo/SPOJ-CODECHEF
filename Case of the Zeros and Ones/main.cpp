#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int no;int t;int one=0,zero=0;
    cin>>no;
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){

       if(a[i]=='1')
              one++;
       else
              zero++;
    }
    //cout<<one<<" "<<zero;
    cout<<abs(one-zero)<<endl;

    return 0;
}
