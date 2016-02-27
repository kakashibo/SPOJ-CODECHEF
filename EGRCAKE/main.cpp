#include <iostream>
using namespace std;
int index(int n,int m,int i){
    i=i+m;
    if(i>n)i=i-n;
    return i;
}
int gcd(int n,int m)
{
	if(n%m==0)
        return m;
	else
        return gcd(m,n%m);
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;int hcf,ans;
        cin>>n>>m;
        if(m==0){
                ans=1;
        }
        else{
            hcf=gcd(n,m);
			ans=n/hcf;
        }
        if(ans==n){
            cout<<"Yes"<<endl;

        }
        else{
            cout<<"No "<<ans<<endl;

        }
        continue;
        if(m==1){
              cout<<"Yes"<<endl;
              continue;
        }
        else if(m==(n-1)){
            cout<<"Yes"<<endl;
            continue;
        }


        //if(m>n/2)m=m-(m-n/2)+1;
        //cout<<m;
        int t=1,f=0;int next;
        int pre=index(n,m,1);
        while(1){
            next=index(n,m,pre);
            //cout<<pre<<" : "<<next<<endl;
            t++;
            if(next==1){

                f=1;
                break;
            }
            /*
            if(pre<next){

            }
            else{
                f=1;break;
            }

            */
            pre=next;
        }
        if(f==1){
            if(t==n)cout<<"Yes"<<endl;
            else
            cout<<"No "<<t<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
        /*
        if(f==1){
            if(next==1)
                cout<<"No "<<t<<endl;
            else
                cout<<"Yes"<<endl;
        }
        */

    }
    return 0;
}
