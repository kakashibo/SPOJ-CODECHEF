#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int no;int pre;int first;int f=0;
    cin>>no;
    int ar[no+1];
    for(int i=0;i<no;i++)
       cin>>ar[i];
    int counter=0;
    if(no%2==0){
              int temp=ar[no-1];
       while(temp!=no-1){
              temp--;
              counter++;
              if(temp==-1)
                temp=no-1;
       }
    }
    else{
       int temp=ar[no-1];
       while(temp!=no-1){
              temp++;
              counter++;
              temp=temp%no;
              //cout<<temp;
       }
    }
     //cout<<counter<<endl;
     for(int i=0;i<no-1;i++){
              int value;
       if(i%2==0)
       {
              value=ar[i];
              int t=counter;
           while(t--){
              value++;
              value=value%no;
           }
           //cout<<value<<" "<<i<<endl;
           if(value!=i){
              f=1;
              break;
           }

       }
       else{
           value=ar[i];
              int t=counter;
           while(t--){
              value--;
              if(value==-1)
                     value=no-1;
           }
           //cout<<value<<" "<<i<<endl;
           if(value!=i){
              f=1;
              break;
           }

       }
     }





    if(f==0)
       cout<<"YES"<<endl;
    else
       cout<<"NO"<<endl;
    return 0;
}
