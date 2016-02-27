#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long int temp;
long int answer;
int main()
{
    long int n,k,i,q;
    long int co=0;
    scanf("%ld",&n);
    long int a[n+2];
    long int b[n+2];
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
		if(i==0)
            b[i]=a[i];
		else
            b[i]=b[i-1]+a[i];

	}
    scanf("%ld",&q);
    for(long int i=0;i<q;i++){

		scanf("%ld",&temp);
		if((n%(1+temp))==0){
			answer=n/(1+temp);
		}
		else
            answer=(n/(1+temp))+1;
		 cout<<b[answer-1]<<endl;
	}
    return 0;
}
/*
4 3 2 1 4 2 0 2
*/
