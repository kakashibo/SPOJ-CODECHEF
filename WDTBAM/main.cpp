#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string s1;
        string s2;
        cin>>s1>>s2;
        int c=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==s2[i])c++;
        }
        long long int ans=0,temp,ans1;
        cin>>temp;
        ans1=temp;
        if(c!=0)
        {
            for(int i=1;i<=n;i++){
                cin>>temp;
                if(i<=c){
                    if(temp>ans)ans=temp;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++)
                cin>>temp;
        }
        if(c==n)
            cout<<temp<<endl;
        else if(ans>ans1)
            cout<<ans<<endl;
        else
            cout<<ans1<<endl;
    }
    return 0;
}
/*
3
5
ABCDE
EBCDA
0 10 20 30 40 50
4
CHEF
QUIZ
4 3 2 1 0
8
ABBABAAB
ABABABAB
100 100 100 100 100 100 100 100 100
*/
