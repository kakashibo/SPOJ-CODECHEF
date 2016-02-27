#include <iostream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
vector< pair<int,pair<string,int> > > intakes;
vector< pair<int,pair<string,int> > > yoe;
vector< pair<int,pair<string,int> > > :: iterator it;
vector< pair<int,pair<string,int> > > :: iterator its;
int main()
{
    ifstream infile("input.txt");
    ofstream ofile("output.txt");
    string line;

     int a=1;
     char tt[15];int i=0;
     string da;int db;int dc;
       while (getline(infile, line)||!infile.eof())
       {
              if(line=="")
                     continue;
              int b;
              if(line.find("DTE,MUMBAI")==-1){

                     int f=0;
                     itoa (a,tt,10);
                     if(line.find(tt)==0){
                            ofile<<line;
                            da=line;
                            cout<<da<<endl;f=1;
                            a++;
                     }
                     if(line.find("Year of Establishment")!=-1){
                            char tmp[line.size()];
                            string y=line.substr(23,28);
                            strcpy(tmp, y.c_str());
                            db=atoi(tmp);
                            ofile<<endl<<"                   "<<std::right<<line;
                            ofile<<endl;
                     }
                     char cpp[line.size()];
                     strcpy(cpp, line.c_str());
                     int intake=atoi(cpp);
                     if(intake>100&&intake<1600&&f==0){
                            dc=intake;
                            ofile<<"                       Intake : "<<intake;
                            ofile<<endl;
                            ofile<<"_____________________________________________________________________________________________________"<<endl;
                            intakes.push_back(make_pair(dc,make_pair(da,db)));
                            yoe.push_back(make_pair(db,make_pair(da,dc)));
                     }
                     i++;
              }
       }
       ofile.close();
       sort(intakes.rbegin(),intakes.rend());
       ofstream ofiles("output_intakes.txt");
       for(it=intakes.begin();it!=intakes.end();it++){
              ofiles<<"College:"<<(*it).second.first<<endl;
              ofiles<<"Year   :"<<(*it).second.second<<endl;
              ofiles<<"Intake :"<<(*it).first<<endl;
              ofiles<<"_____________________________________________________________________________________________________"<<endl;
       }
       sort(yoe.begin(),yoe.end());
       ofstream ofiless("output_yoe.txt");
       for(it=yoe.begin();it!=yoe.end();it++){
              ofiless<<"College:"<<(*it).second.first<<endl;
              ofiless<<"Year   :"<<(*it).first<<endl;
              ofiless<<"Intake :"<<(*it).second.second<<endl;
              ofiless<<"_____________________________________________________________________________________________________"<<endl;
       }

       cout<<"Complete";
    return 0;
}
