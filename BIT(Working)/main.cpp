#include <iostream>

using namespace std;

int main()
{
    int i=5;
    while(i<15){
       cout<<i<<" ";
       i=i+(i&-i);
    }
    return 0;
}
