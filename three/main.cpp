#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+7;

struct data
{
    int l,d;
};

bool cmp(data a, data b)
{
    return (a.l<b.l) || (a.l==b.l && a.d<b.d);
}

long long l[maxn],d[maxn],restmp,res=1000000000;
int n,m,r;
data a[maxn];

int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i)
    {
        int k;
        scanf("%d",&k);
        m=max(m,k);
        r=min(r,k);
        a[i].l=k;
        l[k]++;
    }
    for (int i=1; i<=n; ++i)
    {
        int k;
        scanf("%d",&k);
        a[i].d=k;
        d[k]++;
    }
    sort(a+1,a+n+1,cmp);
    int i=m;
    while (i>=r)
    {
        if (l[i]>0)
        {
        	int luu=restmp;
        	int sumz=0;
            for (int j=n; j>n-l[i]; --j)
            {
                d[a[j].d]--;
                sumz+=a[j].d;
            }
            int tmp=0;
            int sct;
            if (l[i]>n/2) sct=0;
            else sct=n-l[i]-(l[i]-1);
            for (int j=200; j>=1; --j)
            {
            	if (d[j]!=0)
                if (d[j]+tmp<=sct) restmp+=d[j]*j;
                else restmp+=(sct-tmp)*j;
            }
            res=min(res, restmp);
            restmp=luu+sumz;
            n-=l[i];
        }
        i--;
    }
    cout << res;
}





