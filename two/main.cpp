#include<bits/stdc++.h>
using namespace std;
    long int a[200020];

int main()
{
    long long n,w;
    cin>>n;
    cin>>w;
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    double min1=a[0],max1=a[0];
    for(int i=1;i<2*n;i++)
    {
        if(a[i]>max1)
        {
            max1=a[i];
        }
        if(a[i]<min1)
        {
            min1=a[i];
        }
    }
    double sum=0;
    double e=max1;
    double f=max1/2;
    double g=n;
    sum=(e+f)*g;

    if(f>min1)
    {
        sum=min1*3*n;
        if(sum>w)
        {

                   cout<<w<<endl;
        }
        else
        {

            cout<<sum<<endl;
        }
   }
    else if(sum>w)
    {
       cout<<w<<endl;

    }
    else
    {
        cout<<sum<<endl;
    }
}


int mains() {

    long int x,n,i,w;
    cin>>n>>w;
    long long int ar[200020];

    for(i=0;i<2*n;i++)
    {
       cin>>ar[i];
    }
    sort(ar,ar+(2*n));
    long long int g=ar[n];
    //cout<<g<<" ";

    double div=g/2.0;
    //cout<<div<<" ";
    double total=(div*n)+(g*n);
    while(total>w){
       total=w;
    }
    cout<<total<<endl;
}