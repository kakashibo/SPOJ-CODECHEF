#include <iostream>
#include <string.h>
using namespace std;
int road[1430];
int main()
{
    //cout << "Hello world!" << endl;
    int no;
    while(cin>>no&&no!=0)
    {
           int a;
           memset(road,0,sizeof(road));
           for(int i=0;i<no;i++){
              cin>>a;
              road[a]=1;
           }
           int f=0;
              int count;
           for(int i=0;i<=1422;i++)
           {

                  //count=0;
                  if(road[i]==1)
                     {
                            count=0;
                     }
                     else
                          count++;
                     if(count>200)
                     {
                            f=1;
                            break;

                     }
                    // cout<<road[i]<<"|"<<i<<endl;


           }
           if(f==1){
              cout<<"IMPOSSIBLE"<<endl;
              continue;
           }
           f=0;
           for(int i=1422;i>=0;i--)
           {

                  //count=0;
                  if(road[i]==1)
                     {
                            count=0;
                     }
                     else
                          count++;
                     if(count>200)
                     {
                            f=1;
                            break;

                     }
                    // cout<<road[i]<<"|"<<i<<endl;


           }
           if(f==1)
              cout<<"IMPOSSIBLE"<<endl;
           else
              cout<<"POSSIBLE"<<endl;

    }
    return 0;
}
