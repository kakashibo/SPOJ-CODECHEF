#include <iostream>

using namespace std;

int main()
{

    long int n;
    cin>>n;
    long int ar[n+1];
    long int e=0,o=0;
    for(long int i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]%2==0)
            e++;
        else
            o++;
    }
    if(e>o){
        cout<<"READY FOR BATTLE"<<endl;
    }
    else
        cout<<"NOT READY"<<endl;
    return 0;
}
