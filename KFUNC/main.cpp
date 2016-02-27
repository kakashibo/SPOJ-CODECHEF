#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int arep[20];
long long int csum[20];
int k;
void run();
long long int F,D,L,R,divs,mod,ans,diff;
long long int sumdigits (long long int A);
unsigned long long int findR(long long int counter,long long int R,long long int last){
    double tt=(floor)(R/counter);
   return tt * last + csum[(R%counter)-1];
}
unsigned long long int findL(long long int counter,long long int L,long long int last){
    double tt=(floor)(L/counter);
   return tt * last + csum[(L%counter)-1];
}
long long int rep(){
    long long int FF=F;
    long long int counter=0;
    memset(arep,0,sizeof(arep));
    while(1){
         FF+=D;
         long long int temp=sumdigits(FF);
         //cout<<temp<<" :";
         if(!arep[temp]){
            arep[temp]=1;
            csum[counter++]=temp;

         }
         else{
            break;
         }
    }


    for(long long int i=1;i<counter;i++){
        // cout<<csum[i]<<" : ";
        csum[i]=csum[i-1]+csum[i];
       // cout<<csum[i]<<" | ";
    }


    unsigned long long int ans=findR(counter,R,csum[counter-1])-findL(counter,L-1,csum[counter-1]);
    //cout<<"R :"<<findR(counter,R,csum[counter-1]);
    //cout<<"L :"<<findL(counter,L-1,csum[counter-1]);
    return ans;

}
long long int sumdigits (long long int A) {
	if (A < 10) return A;
	long long int a = A;
	long long int s = 0;
	while (a > 0) {
		s = s + a % 10;
		a /= 10;
	}
	return sumdigits (s);
}

void run2(){
        ans=0;
        int i;
        for(i=0;i<k;i++)
        {
            ans+=(divs*csum[i]);
        }
        i=0;
        while(mod>0)
        {
           ans+=csum[i++];
           mod--;
        }
           cout<<ans<<"\n";

}
int main()
{
    long long int tc;
    cin>>tc;
    while (tc--) {
		cin>>F>>D>>L>>R;
		run();
		run2();
	}
    return 0;
}

void run(){
    long long int d=D;
    long long int l=L;
    long long int a=F;
    long long int x;
     int j;
     diff=R-L+1;
        d=((d-1)%9)+1;
        l=((l-1)%9)+1;
        a=((a-1)%9)+1;
        memset(arep,0,sizeof(arep));
        memset(csum,0,sizeof(csum));
        k=0;j=0;
        while(1)
        {
            x=((a+((l-1)*d)-1)%9)+1;
            j=x;
            if(arep[j]==1)
                break;
            else
               {
                  csum[k++]=x;
                  arep[x]=1;
               }
            l=(l%9)+1;

        }
        //cout<<k<<endl;
        divs=diff/k;
        mod=diff%k;

}
    /*2
1 1 1 3
14 7 2 4*/
/*
1
14 7 2 4
 x= 3 x= 1 x= 8 x= 6 x= 4 x= 2 x= 9 x= 7 x= 5 x= 3 k= 10 mi= 0 mo= 312
 */