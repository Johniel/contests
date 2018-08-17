# codeforces/310/A

## Codes
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    int a = 0;
    int b = 0;

    vector< vector<int> > v;
    for (int i = 0; i < k; ++i) {
      int m;
      cin >> m;
      vector<int> u(m);
      for (int j = 0; j < m; ++j) {
        cin >> u[j];
      }
      v.push_back(u);
    }


    for (int i = 0; i < v.size(); ++i) {
      if (v[i].front() == 1) {
        for (int j = 0; j < v[i].size(); ++j) {
          if (v[i][j] + 1 != v[i][j + 1]) {
            while (v[i].back() != v[i][j]) {
              v.push_back(vector<int>(1, v[i].back()));
              v[i].pop_back();
              ++a;
            }
            break;
          }
        }
      } else {
        for (int j = 0; j < v[i].size(); ++j) {
          if (v[i][j] + 1 != v[i][j + 1]) {
            while (1 < v[i].size()) {
              v.push_back(vector<int>(1, v[i].back()));
              v[i].pop_back();
              ++a;
            }
            break;
          }
        }
      }
    }

    // cout << endl;
    // each (i, v) {
    //   each (j, i) {
    //     cout << j << ' ';
    //   }
    //   cout << endl;
    // }

    b = v.size() - 1;
    cout << a + b << endl;
  }
  return 0;
}
```
