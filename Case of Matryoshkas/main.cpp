#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int nom;
    int nest;
    cin>>nom>>nest;
    int count=2*(nom-1)-nest+1;
    //cout<<count;
    for(int i=0;i<nest;i++){
       int curr,pre;
       int nochain;int first;int temp=2;
       cin>>nochain;
       cin>>pre;
       first=pre;
       //cout<<"NO"<<nochain;
       //cout<<"Pre"<<pre;
       nochain=nochain-1;
       while(nochain--){
              cin>>curr;


                if(curr==temp&&first==1)
                    count=count-2;
              temp++;

       }

        //cout<<"Count "<<count<<endl;
    }
    cout<<count<<endl;
    return 0;
}
