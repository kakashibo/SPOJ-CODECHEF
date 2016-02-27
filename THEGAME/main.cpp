#include <iostream>
#include <stdio.h>
#define RED 1
using namespace std;
int r,cc;
char **input;
int **flag;
int no_sector;
float ss[10000];
double mul;
double expec(double ans,double no,int  t){
    ans+=((no/mul)*(t));
    return ans;
}
long int play(int i,int j,int count){


        //if(i>=cc||j>=r)
            //return count;
        if(flag[i][j]==RED)
            return count;
        flag[i][j]=RED;
        //cout<<"--"<<i<<" | "<<j<<" : "<<count<<endl;
        count++;
        if(i+1<r)
        if(input[i+1][j]=='o')
            count=play(i+1,j,count);
        if(i-1>=0)
        if(input[i-1][j]=='o')
            count=play(i-1,j,count);
        if(j+1<cc)
        if(input[i][j+1]=='o')
            count=play(i,j+1,count);
        if(j-1>=0)
        if(input[i][j-1]=='o')
            count=play(i,j-1,count);

        return count;

}
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        double ans=0;no_sector=0;
        mul=0;
        cin>>r>>cc;
        input=new char*[r+10];
        flag=new int*[r+10];
        for(int i=0;i<r;i++){
            input[i]=new char[cc+10];
            flag[i]=new int[cc+10];
            for(int j=0;j<cc;j++){

                cin>>input[i][j];
                flag[i][j]=0;
                if(input[i][j]=='o')mul++;
            }
        }
        /*
        for(int i=0;i<r;i++){
                for(int j=0;j<cc;j++){
                    cout<<input[i][j]<<" ";
                }
                cout<<endl;
        }
        */
        int t=1;double no;int flag_traget=0;int target=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<cc;j++){
                if(flag[i][j]!=RED && input[i][j]!='#'){
                    ss[no_sector]=play(i,j,0);
                   // cout<<ss[no_sector]<<" || <<"<<i<<" "<<j<<endl;
                    if(flag_traget!=0){
                        if(flag[0][0]==RED&&flag[r-1][cc-1]==RED){
                            target=no_sector;
                            flag_traget=1;
                        }
                    }
                    no_sector++;
                    //cout<<i<<" "<<j<<"->"<<no<<endl;
                    //ans=expec(ans,no,t++);

                }
            }
        }
        //cout<<"Traget :"<<target<<endl;
        //cout<<no_sector<<endl;

        for(int i=0;i<no_sector;i++){
            if(target!=i)
                ans+=(ss[i])/(ss[i]+ss[target]);
           // else
               // ans+=(1*sector_strength[i])/(sector_strength[i]+no_sector-1);
                //printf("%.9lf\n",ans);
                //cout<<"->"<<ans<<" "<<sector_strength[i]<<endl;
                //cout<<(1*(sector_strength[i]))/(sector_strength[i]+no_sector-1);
               // ans+=(2*sector_strength[i])/mul;
            ///Do your thing
        }
        //ans+=(1*sector_strength[target])/mul;

        printf("%.9lf\n",ans+1);
        continue;
        //continue;
        //ans=0;
        /*
        int p=2;
        int i,j;
        for(i=0;i<no_sector;i++){
                if(i!=target){
                    double not_happ=1;
                    for(j=0;j<=i;j++){
                        if(i!=j){
                            not_happ*=1-(ss[j]/mul);
                        }
                        cout<<"NP :"<<not_happ<<" j "<<j<<endl;
                    }
                    cout<<" i "<<i<<" j: "<<j<<"Asn : befor : "<<ans<<endl;
                    ans+=(not_happ*p++);
                    cout<<ans<<endl;
                }
        }
        ans+=ss[target]/mul;
        cout<<"Ans :"<<ans<<endl;
        ans=0;
        */
        //cout<<no_sector<<endl;

        double tt=ss[0];
        ss[0]=ss[target];
        ss[target]=tt;
        double a=ss[0];
        double b=ss[1];
        double c=ss[2];
        double d=ss[3];
        if(no_sector==3){
            ans=(a/(a+b+c))+(2*((b*a)/((a+b+c)*(a+c)))+((c*a)/((a+b+c)*(a+b))))+3*(((b*c*a)/(((a+b+c)*(a+c))*a))+((c*b*a)/((a+b+c)*(a+b)*a)));
        }

        else if(no_sector==2){
            ans=(a/(a+b))+(2*((b*a)/((a+b)*a)));
        }
        else if(no_sector==1){
            ans=a/(a);

        }
        else if(no_sector==4){

        }
        else if(no_sector==5){

        }
        else if(no_sector==6){

        }
        else if(no_sector==7){

        }
        else{
            while(1){}
        }


        printf("%.9lf\n",ans);
    }
    return 0;
}
/*
2
3 3
o#o
oo#
#oo
2 2
oo
oo
1
10 10
ooooo#####
###oo###o#
##oo######
##o#oooo##
##o##ooooo
##o#######
#ooooo####
#####ooooo
#####o####
#####ooooo
*/
