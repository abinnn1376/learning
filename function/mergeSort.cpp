#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll longlong


int n;
vector<int> tem;
vector<int> arr;


void merge(int l,int r,int m)
{
    int a = l;
    int b = m + 1;
    int i = l;
    while(a <= m && b <= r )
    {
        tem[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m)
    {
        tem[i++] = arr[a++];
    }
    while(b <= r)
    {
        tem[i++] = arr[b++];
    }
    for(i=l;i<=r;i++)
    {
        arr[i] = tem[i];
    }
    
}


void mergeSort1(int l,int r)
{
    if(l == r)
        return; 
    int m = (l+r)/2;
    mergeSort1(l,m);
    mergeSort1(m+1,r);
    merge(l,r,m);
}

void mergeSort2()
{
    for(int l,m,r,step=1;step < n;step <<= 1)
    {
         l = 0;
        while (l < n)
        {
            m = l + step - 1;
            if(m >= n - 1)
                break;
            
            r = min((l + (step << 1) - 1),n - 1);
            merge(l,r,m);
            l = r + 1;
            
        }
        
    }
}

  


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    tem.resize(n);
    arr.resize(n);

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    mergeSort1(0,n-1);
    mergeSort2();

    for(int i=0;i<n;i++)
    {
       cout <<  arr[i] ;
    }
    
    
    return 0;

}