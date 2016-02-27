#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
void printArray(int arr[], int size);
void rvereseArray(int arr[], int start, int end);

// Report parity of permutation.
/*
1
6 4
1 5 4 6 3 2
6 5 1 3 2 4
1
6 4
2 1 3 5 6 4
1 4 3 5 6 2
---------
8
5 2
1 2 4 5 3
2 3 4 1 5
5 3
2 3 1 4 5
1 3 5 4 2
5 4
3 2 4 1 5
1 5 3 2 4
5 5
1 2 3 4 5
4 5 1 2 3
5 3
5 1 3 2 4
3 2 4 1 5
6 4
1 5 4 6 3 2
6 5 1 3 2 4
6 4
2 1 3 5 6 4
1 4 3 5 6 2
5 5
1 2 3 4 5
5 4 1 2 3
------------
3 1 5 2 4
3 2 5 1 4
3 2 4 1 5
*/
void printArray(int arr[], int size);

/*Fuction to get gcd of a and b*/
int gcd(int a,int b);
int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}
/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); i++)
  {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}

void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("%\n ");
}
void rvereseArray(int arr[], int start, int end)
{
  int i;
  int temp;
  while(start < end)
  {
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
int fact(int n)
{
    return (n <= 1)? 1 :n * fact(n-1);
}
void populateAndIncreaseCount (int* count, char* str)
{
    int i;

    for( i = 0; str[i]; ++i )
        ++count[ str[i] ];

    for( i = 1; i < 256; ++i )
        count[i] += count[i-1];
}


void printpemu(int tm[],int n,int b[]){
    int counter=1;
    do {
            int c=1;
            for(int i=0;i<n;i++){
                    ///cout<<tm[i]<<" "<<b[i]<<endl;
                if(!(b[i]==tm[i]))c=0;
                //cout<<tm[i]<<" ";

            }//cout<<endl;
            if(c==1){
                cout<<counter<<endl;
                return;
            }
            counter++;
       } while ( std::next_permutation(tm,tm+n) );
}
int tp(int n, int D[])
   {int p = 1;
    int v[n];
    int P[n];
    for(int j=0; j<n; ++j) {
            v[j] = j+1;
            P[j]=D[j];
    }
    for(int j=0; j<n; ++j){
         if(!(v[j]==P[j]))
         {

             //int x = j;
             int x;
            do {    ++p;
                    x = P[j];
                    int t=P[x-1];
                    P[x-1] = P[j];
                    P[j]= t;
                    //printArray(P,n);
              } while (P[j]!=v[j]);
        }
    }
        //cout<<"p"<<p<<endl;
       if(p%2==0)return 1;
    else
        return 0;
}
int parity(int n,int P[]){
    int total=0;
    for(int i=0;i<n;i++){
            int c=0;
        for(int j=i;j<n;j++)
        {
            if(P[i]>P[j])c++;
        }
        total+=c;
    }
    if(total%2==0)return 1;
    else
        return 0;


}

int tm[100000];
int a1[100000];
int main(){

   int tc;
   cin>>tc;
   while(tc--){
   int n,k;
   cin>>n>>k;
   int a[100000+1];
   int b[100000+1];
   for(int i=0;i<n;i++){
    cin>>a[i];
     a1[i]=tm[i]=a[i];
   }
   for(int i=0;i<n;i++){
    cin>>b[i];
   }
   sort(tm,tm+n);

   if(n==k){
        int f=0;
        for(int j=0;j<n;j++){
            int c=1;
            for(int i=0;i<n;i++)
                if(!(a1[i]==b[i]))c=0;

            if(c==0)
            leftRotate(a1, 1, n);
            else{
                f=1;
                break;
            }
            //printArray(a1,n);
        }
        if(f==1)printpemu(tm,n,b);
        else cout<<"-1"<<endl;


      }

   else if((n%2==0)&&(k<n)){
    ///print the lexo
      printpemu(tm,n,b);
   }
   else if(k%2!=0){
     int p1=tp(n,a);
     int p2=tp(n,b);
      //cout<<p1<<" "<<p2;
      //printpemu(tm,n,b);
      if(p1==p2){
        printpemu(tm,n,b);
      }
      else
        cout<<"-1"<<endl;
   }
   else {
      cout<<"-1"<<endl;
   }

   }
   return 0;
}

