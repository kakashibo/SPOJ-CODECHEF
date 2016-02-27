#include <iostream>
#include <cstdio>
#define MAX 1e9
#include <vector>
using namespace std;
vector< pair<int,int> > link;


int till;
int ar[110][110];int n;
int penetrate(int k,int depth,int sum)
{
    sum+=ar[depth][k];
    cout<<" "<<sum<<" ";
    link.push_back(make_pair(depth,k));
    if(sum>till)
        return till;
    //cout<<depth<<"|"<<k<<" -> ";

    if(depth==n-1){
         if(till>sum)
            till=sum;
            cout<<endl;
            vector< pair<int,int> >::iterator it = link.begin();
            for(it = link.begin();it<=link.end();it++)
            {
                cout<<"["<<it->first<<","<<it->second<<"]";
            }
            link.clear();
            cout<<" Sum"<<sum;
            cout<<endl;
            getchar();
        return sum;
    }


    int dir=k;int r=0,l=0,c=0;

    if(dir>=0){
        cout<<"(Current)";

        c=penetrate(dir,depth+1,sum);

    }
    if(dir-1>=0){
        cout<<"(Left)";

        l=penetrate(dir-1,depth+1,sum);

    }
    if(dir+1>n-1){
        cout<<"(Right)";

        r=penetrate(dir+1,depth+1,sum);
    }


    return(min(l,min(r,c)));
}

int main()
{
    int m,i,j;
    cin>>n>>m;
    till=0;
    for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        cin>>ar[i][j];


    }
    till+=ar[i][0];
    }
    int res=10000000;
    for(i=0;i<m;i++)
    {
        res=penetrate(i,0,0);
        cout<<endl<<"res   --> "<<res<<endl;

    }


    return 0;
}
