#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  
    // Number of test cases

    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        // Given values:
        // x = max(a, b), y = max(b, c), z = max(a, c)

        int maxi = max({x, y, z});
        // Find the maximum among x, y, and z

        int cnt = (x == maxi) + (y == maxi) + (z == maxi);
        // Count how many times the maximum value appears

        /*
        For valid values of a, b, c:
        - The maximum element among (a, b, c) must appear
          in at least two of x, y, z.
        - This is because each of x, y, z represents the max
          of a different pair.
        */

        if (cnt < 2) {
            cout << "No\n";
            // If the maximum appears less than twice,
            // such a triplet (a, b, c) cannot exist
        } else {
            cout << "Yes\n";

            int mini = min({x, y, z});
            // The remaining value must be the minimum

            /*
            Construction logic:
            - Let the maximum value appear once in (a, b, c)
            - Let the minimum value appear twice
            This ensures the maximum appears exactly twice
            in the pairwise maximums (x, y, z)
            */

            cout << maxi << " " << mini << " " << mini << "\n";
        }
    }

    return 0;
}

/*
Time Complexity: O(n)
- Each test case is processed

Space Complexity: O(1)
- Only a fixed number of variables are used.
*/
