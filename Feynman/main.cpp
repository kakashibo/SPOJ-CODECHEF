#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n!=0){


        int square=0;
        for(int i=1;i<=n;i++)
        square+= pow((n-i)+1,2);

        cout<<square<<endl;

    }
    return 0;
}
