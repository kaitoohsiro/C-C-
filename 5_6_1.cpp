#include <iostream>

using namespace std;
#define MAX 1000000
typedef long long llong;

int n, k;

llong T[MAX];

int check(llong p) {
    int i = 0;
    for ( int j = 0; j < k; j++ ) {
        llong s = 0;
        while ( s + T[i] <= p ) {
            s += T[i];
            i++;
            if ( i == n ) return n;
        }
    }
    return i;
}

int solve() {
    llong left = 0;
    llong right = 10000 * 10000; // 荷物の個数 * 1個あたりの最大重量
    llong mid = 0;
    while ( right - left > 1 ) {
        mid = (left + right) / 2; //
        int v = check(mid);
        if ( v >= n ) right = mid;
        else left = mid;
    }
    return right;
}


int main() {
    cin >> n >> k;
    for ( int i = 0; i < n; i++) cin >> T[i];
    llong ans = solve();
    cout << ans << endl;
}