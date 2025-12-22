#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    // Number of test cases

    while (t--) {
        int a;
        cin >> a;
        // Size of the permutation

        vector<int> inputs(a);
        // Stores the given permutation of size a

        for (int i = 0; i < a; i++) {
            cin >> inputs[i];
        }

        /*
        Idea:
        We need to generate a "twin permutation" such that:
        a1 + b1 <= a2 + b2 <= ... <= an + bn

        Instead of maintaining inequalities, we make all sums equal.
        Let:
            ai + bi = k  (constant for all i)

        For a permutation of size a, choosing:
            k = a + 1

        gives:
            bi = (a + 1) - ai

        This ensures all sums are equal and the result is also a valid permutation.
        */

        for (int i = 0; i < a; i++) {
            // Generate twin permutation in-place
            inputs[i] = (a + 1) - inputs[i];
        }

        for (int i = 0; i < a; i++) {
            cout << inputs[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity: O(t * a)
- For each test case, we traverse the permutation a constant number of times.

Space Complexity: O(a)
- A vector of size a is used to store the permutation.
*/
