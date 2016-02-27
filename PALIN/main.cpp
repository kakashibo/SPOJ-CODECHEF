#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

    cout << "Hello world!" << endl;
    int tc;
    cin>>tc;
    while(tc--)
    {
        char no[1000010];
        scanf("%s",no);
        int length=strlen(no);
        cout<<length;
        if(length%2==0)
        {
            int half=length-1/2;
            int pos=0;
             while(half!=pos)
            {
                if(no[half+pos]==no[half-pos])
                    continue;
                int first=no[half-pos]-48;
                int secound=no[half+pos]-48;
                no[half+pos]=no[half-pos]=first+1;
                pos++;
                cout<<no;
            }

        }
        else{

        }

    }

    return 0;
}
