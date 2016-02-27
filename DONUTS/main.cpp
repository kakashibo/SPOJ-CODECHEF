#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int ar[20010];
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        long int n,m;
        cin>>n>>m;
        int needed=m-1;
        int cut=0;
        for(int i=0;i<m;i++)
            scanf("%ld",&ar[i]);
        sort(ar,ar+m);
        int c=0;
        if(ar[0]>=m-1)
		  {
		  	 cout<<m-1<<"\n";
		  	 continue;
		  }
        while(cut<needed-1){
            cut+=ar[c++];
            needed=m-c;

        }
        if(cut==(needed-1))cout<<cut<<endl;
        else
            cout<<m-c<<endl;


    }
    return 0;
}
