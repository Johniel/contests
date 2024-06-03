#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;

        string required = "ABCDEFG";

        map<char, int> problem_count;
        for (char c : a) {
            problem_count[c]++;
        }

        int needed_problems = 0;
        for (char c : required) {
            if (problem_count[c] < m) {
                needed_problems += (m - problem_count[c]);
            }
        }

        cout << needed_problems << endl;
    }

    return 0;
}
