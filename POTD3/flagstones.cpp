#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a;
    cin >> n >> m >> a;
    // Taking inputs, n=length, m=width, a=side of the flagstone
    long long len = ((n+a-1)/a);
    // how many tiles will be used to cover up the length of the rectangle
    long long wid = ((m+a-1)/a);
    // how many tiles will be used to cover up the width of the rectangle
    cout << len * wid;

    return 0;
}

// Time Complexity: O(1)
// We perform a constant number of arithmetic operations, independent of input size.
// Space Complexity: O(1)
// We only use a few fixed-size variables; no extra space grows with the input.