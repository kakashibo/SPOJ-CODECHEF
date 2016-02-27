#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int sum,t;int given_time;
int no_toll;int ttime=0;
int msum=1000000000;
int reach[55];
int f=1;
int toll_m[51][51];int time_m[51][51];
void dfs(int curr,int pre)
{
       int i;
       if(curr==no_toll-1)
       {
            if(t<given_time)
             if(msum>=sum){
                  msum=sum;
                  //if(ttime>t)
                  ttime=t;
                  //cout<<ttime<<" ";
             }
           //  cout<<endl<<"-->Reached "<<sum<<"  time "<<t<<" MAX "<<msum;
             sum-=toll_m[pre][curr];
             t-=time_m[pre][curr];
             return;
       }
      // cout<<endl;
      // for(i=0;i<no_toll;i++)
            //  cout<<i<<" "<<reach[i]<<"|";


       //cout<<"new dfs";
              //if(gt<t||msum<sum)
              //  return;
       reach[curr]=1;
       for(i=1;i<no_toll;i++){
              if(curr==0)t=sum=0;
              if(time_m[curr][i] && !reach[i] )
              {
                      //printf("\n %d->%d  t :%d  sum : %d",curr,i,t,sum);
                      //cout<<"I"<<i;
                     // getchar();
                     if(t+time_m[curr][i]<given_time)
                            //cout<<"Tdfdf:"<<t;
                        if(msum>=sum+toll_m[curr][i]){
                            sum+=toll_m[curr][i];
                            t+=time_m[curr][i];
                            //cout<<"Time after :"<<t;
                            dfs(i,curr);

                        }

              }
       }
      // cout<<endl<<"Curr:"<<curr<<" Pre :"<<pre<<" Sum"<<sum<<"time : "<<t;
       reach[curr]=0;
       sum-=toll_m[pre][curr];
       t-=time_m[pre][curr];
       return;

       //cout<<endl<<sum<<" "<<t<<" "<<msum<<" "<<totalt<<endl;

  //cout<<endl;
}

int main()
{

    int i,j,k,l;

    while(cin>>no_toll>>given_time&&no_toll!=0&&given_time!=0)
    {

        for(i=0;i<no_toll;i++)
            for(j=0;j<no_toll;j++)
            scanf("%d",&time_m[i][j]);



        for(i=0;i<no_toll;i++)
            for(j=0;j<no_toll;j++)
            scanf("%d",&toll_m[i][j]);

        ttime=0;
        sum=0,t=0;
        msum=1000000000;
        dfs(0,0);

        cout<<msum<<" "<<ttime;



    }

    return 0;
}
