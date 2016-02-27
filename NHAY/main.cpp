#include <iostream>
#include <stdio.h>
#define M 1000010
using namespace std;
long int n,m;

long int pow[1000010];
int B=10037;
void powfun()
{
       pow[0]=1;
       for (int i = 1; i <= 1000010; ++i)
              pow[i] = (pow[i-1] * B) % M;
}


long int int_mod(long int a, long int b)
{
       return (a % b + b) % b;
}
int Rabin_Karp(string text,string pattern) {

       if(n < m) return 0; // no match is possible
       int f=0;
       long int hp = 0;
       for(long int i = 0; i < m; i++)
              hp = int_mod(hp * B +pattern[i], M);
  //cout<<endl;
 // cout<<"Hash Pattern "<<hp<<endl;


  long int ht=0;
  for(long int i = 0; i < m; i++)
    ht = int_mod(ht * B + text[i], M);
   if(hp == ht){
          f=1;
           cout<<"0"<<endl;
   }

  long int E=pow[m-1];
 long int hy=0;
  for(long int i = m; i <= n; i++)
  {

      //ht = int_mod(ht*B - int_mod(text[i - m] * E,M) + text[i],M);
      ht = int_mod(ht - int_mod(text[i - m] * E, M), M);
      ht = int_mod(ht * B, M);
      ht = int_mod(ht + text[i], M);
      //cout<<"Hash Test "<<ht<<" "<<text.substr(i-m+1,m)<<endl;
      hy=0;
      //for(long int j = i-m+1; j < i+1; j++)
       //  hy = int_mod(hy * B + text[j], M);
       //  cout<<"cal :"<<hy<<" "<<i-m+1<<" "<<i+1<<endl;
    if(hp == ht&&text.substr(i-m+1,m)==pattern){
            f=1;
           cout<<i-m+1<<endl;
    }

  }
  if(f==1)
    return 1;
  else
    return 0;

}
int main()
{

    powfun();
    while (cin>>m){

        string needle;string s;
        //cout<<"Enter Needle";
        cin>>needle;
        //cout<<"Enter String";
        cin>>s;
        n=s.length();
        //cout<<needle<<" "<<s;
        int a=Rabin_Karp(s,needle);
        if(a==0)
            cout<<endl;


    }
    return 0;
}
