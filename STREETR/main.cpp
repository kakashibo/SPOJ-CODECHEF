#include <iostream>
#include <numeric>
#include <stdio.h>
using namespace std;


int gcd(int a,int b){
//cout<<a<<" "<<b<<endl;
if(a>b){
return gcd(b,a);
}else{
int c=b%a;
if(c==0) return a;
else return(gcd(b%a,a));
}
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}


int main()
{
       int N , n1, n2,X[100000],g,s=0;
cin>>N;
cin>>n1;
for(int i=0;i<N-1;i++){
cin>>n2;
X[i]=n2-n1;
n1=n2;
}
g=gcd(X[0],X[1]);
for(int i=2;i<N-1;i++){
g=gcd(g,X[i]);
}
for(int i=0;i<N-1;i++){
s+=((X[i]/g)-1);
}
cout<<s<<endl;
return 0;
	int no;long int curr,pre=0,first,second,far,diff;
	long int ar[100010];long int gcd_val=0;
	cin>>no;
	cin>>first>>second;
	far=second-first;pre=second;
	gcd_val=gcd(far,1);
	ar[1]=far;
	for(int i=2;i<no;i++)
	{
		scanf("%ld",&curr);
		//cout<<curr<<" ";

		diff=curr-pre;
	       gcd_val=gcd(gcd_val,diff);
	       ar[i]=diff;
	       pre=curr;

	}
	//cout<<"Far :"<<gcd_val<<endl;
	int counts=0;
        int index=0;



	int dcount=0;
	for(int i=1;i<no;i++)
       {

             dcount+=((ar[i]/gcd_val)-1);

       }
       //cout<<dcount<<endl;
	cout<<dcount<<endl;

	//cout<<counts<<endl;
	return 0;
}
/*
4
1
3
7
13
4
2
6
12
18
*/
