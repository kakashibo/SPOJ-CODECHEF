#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int finds(int m,int arr[],int n,int cow)
{
    	int cowsplaced=1;
    	//cout<<m<<" ";
         long long int lastpos=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-lastpos>=m){
                cowsplaced++;
                //cout<<"|"<<cowsplaced<<"|";
                if(cowsplaced==cow)
                        return 1;
                lastpos=arr[i];
                }
            }
            //cout<<endl;
            //for(int i=0;i<n;i++)
            //cout<<"its zero";
            return 0;
}

int binarysearch(int stall[],int num,int cow)
{
    	int start=0,end=stall[num-1];
        while(start<end){

            int mid=(start+end)/2;
        //cout<<"mid"<<mid<<" ";
            if(finds(mid,stall,num,cow)==1)
                start=mid+1;
            else
                end=mid;
            }
            return start-1;

}

int main()
{
    //cout << "Hello world!" << endl;
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,cow;
        cin>>n>>cow;
        int stall[100010];

        for( int i =0;i <n;i++)
            scanf("%d",&stall[i]);

        sort(stall,stall+n);
        printf("%d\n",binarysearch(stall,n,cow));


    }
    return 0;
}
