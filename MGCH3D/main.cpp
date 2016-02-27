#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#define EPSILON 0.0000001

double squareroot(double val) {

        double low = 0;

        double high = 10000000; // a sufficiently big number

        double mid = 0;


        while (high - low > EPSILON) {

                mid = low + (high - low) / 2;

                if (mid*mid > val) {

                        high = mid;

                } else {

                        low = mid;

                }

        }

        return mid;

}
using namespace std;
int X[1000000];
int Y[1000000];
int Z[1000000];
double ind[1000000];
int main()
{
    long int n;int q;
    cin>>n;
    cin>>q;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&X[i],&Y[i],&Z[i]);
    }
    long int count=1;
    for(long int i=1;i<=n;i++){
            for(long int j=i+1;j<=n;j++){
                //if( i == j ) continue;
                int x,y,z;
                x = X[i]-X[j];y = Y[i]-Y[j];z = Z[i]-Z[j];
                //cout<<pow(x,4)<<endl;
                //xx[i][j]=x;yy[i][j]=y;zz[i][j]=z;
                double deno = n*(n-1)*squareroot(pow(x,4)+pow(y,4)+pow(z,4));
                //cout<<deno<<endl;
                ind[count++]=deno;
            }
    }
    //cout<<"c"<<count<<endl;


    while(q--){
        int a,b,c,d;double ans=0;long int i,j;long int l=1;
        scanf("%d%d%d%d",&a,&b,&c,&d);

               for(i=1;i<=n;i++){
                    for(j=i+1;j<=n;j++){
                    //if( i == j ) continue;
                    int x,y,z;
                    x = X[i]-X[j];y = Y[i]-Y[j];z = Z[i]-Z[j];
                    int x1,y1,z1;
                    x1 = X[j]-X[i];y1 = Y[j]-Y[i];z1 = Z[j]-Z[i];
                    double num = fabs(a*x+b*y+c*z+d);
                    double num2 = fabs(a*x1+b*y1+c*z1+d);
                    //double deno = sqrt(pow(x,4)+pow(y,4)+pow(z,4));
                    //double num = fabs(a*xx[i][j]+b*yy[i][j]+c*zz[i][j]+d);
                //cout<<num<<endl;
                //cout<<deno<<endl;

                    num= (num+num2)/(ind[l++]);
                    ans += num;


                //cout<<ans<<endl;
                }


               }
               printf("%.15lf\n",ans);
               //printf("%Lf\n",ans);
        }
        //cout<<ans<<endl;




    return 0;
}
