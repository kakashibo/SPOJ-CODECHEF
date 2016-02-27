#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct Node
{
    long long value;
    int p1;
    int p2;
    Node()
    {

    }
    Node(long long value,int p1,int p2)
    {
        this->value = value;
        this->p1 = p1;
        this->p2 = p2;
    }
};

bool comp(Node n1,Node n2)
{
    return n1.value > n2.value;
}

int main()
{
    int n;
    scanf("%d",&n);

    long long size = (2*n*n) - n;
    Node nodes[size];


    long long val;
    int index = 0;
    long long players = 2*n;
    for(int i=2; i<=players; i++)
    {
        for(int j=1; j<i; j++)
        {
            cin>>val;
            nodes[index++] = Node(val,i,j);
        }
    }

    //cout<<"%";
    sort(nodes,nodes+size,comp);

    bool paired[801] = {false};
    int ans[801];

    for(int i=0; i<index; i++)
    {
        int p1 = nodes[i].p1;
        int p2 = nodes[i].p2;
        if(paired[p1] == false && paired[p2] == false)
        {
            ans[p1] = p2;
            ans[p2] = p1;
            paired[p1] = paired[p2] = true;
        }
    }

    for(int i=1; i<=(2*n); i++)
        cout<<ans[i]<<" ";




    return 0;
}
