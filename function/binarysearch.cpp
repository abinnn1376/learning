#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll longlong
#define int long long
bool bsearch(int tar,int arr[],int n)
{
    int l = 0;
    int r = n;
    
        while (l <= r)
        {
            int mid = (l+r)/2;
            if(arr[mid] == tar)
                return true;
            else if(arr[mid] > tar)
                r = mid - 1;
            else
                l = mid + 1;       
        }  
    
}




signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;
    bool end = bsearch(target,a,n);
    if(end)
        cout << "YES";
    else
        cout << "NO";
    
    
    return 0;

}