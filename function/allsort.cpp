#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define longlong ll

// 全排列
void exc(int arry[], int sta, int end) {
    int temp = arry[end];
    for (int i = end; i >= sta + 1; i--) {
        arry[i] = arry[i - 1];
    }
    arry[sta] = temp;
}

void exc_back(int arry[], int sta, int end) {
    int temp = arry[sta];
    for (int i = sta; i <= end - 1; i++) {
        arry[i] = arry[i + 1];
    }
    arry[end] = temp;
}

void ins(int arry[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arry[i] << " ";
    }
    cout << endl;
}

void asort(int arry[], int sta, int end) {
    if (sta == end) {
        ins(arry, end + 1);
    } else {
        for (int i = sta; i <= end; i++) {
            exc(arry, sta, i);
            asort(arry, sta + 1, end);
            exc_back(arry, sta, i);
        }
    }
}

int main() {
    int n, x, sta, end;
    cin >> n;
    sta = 0;
    end = n - 1;
    int arry[n];
    for (int i = 0; i < n; i++) {
        cin >> x;
        arry[i] = x;
    }
    asort(arry, sta, end);

    return 0;
}