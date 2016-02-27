#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define Lar 10000
struct process{
       int time;
       int index;

};
struct process pro[10000];
bool compare(struct process *a,struct process *b){
      if(a->time>b->time)
       return false;
      else
       return true;
}
int maxVal;
int bit[10000];
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx <= maxVal){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    for(int i=0;i<Lar;i++){
       update(i,1);
    }
    int noPro;
    cin>>noPro;
    for(int i=0;i<noPro;i++){
       scanf("%d%d",&pro[i].index,&pro[i].time);
    }
    sort(pro,pro+noPro,compare(process *a,process *b));
    int total_time=0;
    int current_time=0;
    for(int i=1;i<noPro;i++){
       //cout<<pro[i].time<<" ";
       current_time=(pro[i].time-pro[i-1].time)*(noPro-i+1);
       current_time+=read(pro[i].index);
       update(pro[i].index,-1);
       total_time=current_time;
       current_time+=(noPro-i)*read(pro[i].index);
    }
    cout<<total_time<<endl;
    return 0;
}
