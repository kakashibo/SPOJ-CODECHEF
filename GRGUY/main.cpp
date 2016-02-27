#include <iostream>
#include <stdio.h>
using namespace std;

char l1[1000001],l2[1000001];
int solve(int i,int pre){
       int c=0;
       int count=0;
       for(int j=0;j<i;j++){
              if(l1[j+1]=='#'&&l2[j+1]=='#')
                     return -1;
              if(pre==1){
                     if(l1[j+1]=='.')
                            continue;
                     else{
                            pre=2;
                            count++;
                     }
              }
              if(pre==2){
                     if(l2[j+1]=='.')
                            continue;
                     else{
                            pre=1;
                            count++;
                     }
              }
       }
       return count;
}
int main()
{
    int tc;
    cin>>tc;
    getchar();
    while(tc--){
              char temp;int i=0;int z=0;int count=0;
              temp=getchar();int f=0;
              while(temp!='\n'){
                     l1[i++]=temp;
                     temp=getchar();

              }

              temp=getchar();
              while(temp!='\n'){
                     l2[z++]=temp;
                     temp=getchar();
              }
              i--;z--;
              int c=0;
              int flag1=l1[0]=='.'?1:0;
              int flag2=l2[0]=='.'?1:0;
              int pre=-1;
              /*
              for(int j=0;j<i;){
                     if(l1[j]=='#'&&l2[j]=='#'){
                            cout<<"No"<<endl;
                            f=1;
                            break;
                     }
                      else if(l1[j]=='#' && l2[j]=='.')
                     {
                            if(pre==1)
                                   count++;
                            pre=2;
                            j++;
                     }
                     else if(l1[j]=='.' && l2[j]=='#')
                     {
                            if(pre==2)
                                   count++;
                            pre=1;
                            j++;
                     }
                      else
                     {
                            while(l1[j]=='.' && l2[j]=='.')
                            j++;
                     }

              }
              if(f==0)
                     cout<<"Yes\n"<<count<<endl;
              continue;
              */

              int count2=0,count3=0;
              //cout<<flag1<<" "<<flag2<<endl;
              if(flag1==0&&flag2==0){
                     cout<<"No"<<endl;
                     continue;
              }
              if(flag1-flag2!=0){

                     pre=flag1>flag2?1:2;
                     count=solve(i,pre);
                     if(count!=-1)
                            f=1;

              }
              else{
                     pre=1;
                     count=solve(i,pre);
                     pre=2;
                     count2=solve(i,pre);
                     if(count+count2==-2)
                            f=0;
                     else if(count==-1&&count2!=-1){
                            count=count2;
                            f=1;
                     }
                     else if(count!=-1&&count2==-1){
                            f=1;
                     }
                     else {
                            if(count>count2){
                                   count=count2;
                            }
                            f=1;
                     }



              }
              if(f==1)
                     cout<<"Yes\n"<<count<<endl;
              else
                     cout<<"No\n"<<endl;




    }
    return 0;
}
