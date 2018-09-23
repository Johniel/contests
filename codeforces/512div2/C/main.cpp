#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    vector<int> v;
    each (c, s)
      v.push_back(c - '0');

    const int y = accumulate(v.begin(), v.end(), 0);

    bool f = false;

    for (int x = 0; x <= 9 * 100; ++x) {
      if (x == y) continue;
      int sum = 0;
      for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        if (x == sum) {
          // if (n == 3 && x == 2) cout << ">> " << sum << endl;
          sum = 0;
        }
      }
      if (sum == 0) {
        // cout << make_pair(x, sum) << endl;
        f = true;
      }
    }

    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
