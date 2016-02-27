#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int no_intial;
    cin>>no_intial;
    int no_box;
    cin>>no_box;
    int t,left;
    cin>>t>>left;
    int count_left=no_intial;
    int total_number=no_intial;
    while(count_left!=left){
       cout<<count_left<<" ";
       count_left+=no_box-1;
       total_number+=no_box;

    }
    cout<<"Ans"<<total_number;
    return 0;
}
