#include <iostream>

using namespace std;
int ar[1000];
long long int total[1000]={0};
int main()
{


        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            //total[i]=0;
            for(int j=0;j<n;j++){
                cin>>ar[j];
                //total[j]+=ar[i][j];
               // cout<<total[j]<<" ";
            }
            int max=ar[0];int w=0;
            for(int j=1;j<n;j++){

                if(max<ar[j]){
                        max=ar[j];
                        w=j;
                }
            }
            //cout<<w<<"-";
            total[w]++;

        }
        int ans=0;long int max=-1;
        for(int i=0;i<n;i++){
           //cout<<total[i]<<endl;
            if(max<total[i]){
                max=total[i];
                ans=i+1;
            }
        }
        cout<<ans<<endl;



    //cout << "Hello world!" << endl;
    return 0;
}
