#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;int k;
        cin>>n>>k;
        for ( i = 0; i < n; ++i ) {
        long long int sum=0,a;
        for(int i=0;i<n;i++){
            cin>>a;
            sum+=a;
        }
        if(sum%2==0)
        {
            if(k==1)
            cout<<"odd"<<endl;
            else
                cout<<"even"<<endl;
        }
        else
            cout<<"even"<<endl;


    }
    return 0;
}
