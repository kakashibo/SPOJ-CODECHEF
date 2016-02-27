#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <cmath>
#include <sstream>
using namespace std;
map<double,vector<string> > mp;
map<double,vector<string> >:: iterator it;
void pre_run(){
    for(int i=0;i<12;i++){
        for(int j=0;j<60;j++){

           double hour_angle = 0.5 * (i*60 + j);
           double minute_angle = 6*j;
           double angle = abs(hour_angle - minute_angle);
           angle = min(360-angle, angle);
           int h=i,m=j;ostringstream oss;
           if(h<10)oss<<"0"<<h<<":";
           else oss<<h<<":";
           if(m<10)oss<<"0"<<m;
           else oss<<m;
           string temp=oss.str();
           //cout<<temp<<endl;
           mp[angle].push_back(temp);

        }
    }

}
int main()
{

    //pre_run();
    /*
    for (it=mp.begin(); it!=mp.end(); ++it){
        cout << it->first << " => ";
        vector<string> a=it->second;
        vector<string>:: iterator j;
        for(j=a.begin();j<a.end();j++){
            cout<<*(j)<<" ";
        }
        cout<<endl;
    }
    */
    int tc;
    cin>>tc;
    while(tc--){
        vector<string> a;
        double t;
        scanf("%lf",&t);

        for(int i=0;i<12;i++){
        for(int j=0;j<60;j++){

           double hour_angle = 0.5 * (i*60 + j);
           double minute_angle = 6*j;
           double angle = abs(hour_angle - minute_angle);
           angle = min(360-angle, angle);
           if(abs(t-angle)<(double)(1.0/120.0)){
          // if(t==angle){

            int h=i,m=j;ostringstream oss;
            if(h<10)oss<<"0"<<h<<":";
            else oss<<h<<":";
            if(m<10)oss<<"0"<<m;
            else oss<<m;
            string temp=oss.str();
           //cout<<temp<<endl;
            cout<<temp<<endl;
           //}
           }

           //mp[angle].push_back(temp);

        }
    }
    }
    return 0;

/*

        if ( mp.find(t) == mp.end() ) {
            //cout<<abs(t)<<endl;
            //continue;
            double frac=t-(long)t;
            //cout<<frac<<endl;
            if(frac>.75){
                a=mp.find(ceil(t))->second;
            }
            else if(frac<.25){
                a=mp.find(floor(t))->second;
            }
            else{
                double temp=((long)t)+.5;
                //cout<<temp<<endl;
                a=mp.find(temp)->second;
            }
        }
        else
        {
            a=mp.find(t)->second;
        }
        vector<string>:: iterator j;
        //sort((itlow->second).begin(),(itlow->second).end());
        for(j=a.begin();j<a.end();j++){
            cout<<*(j)<<endl;
        }


    }



    return 0;
    */
}