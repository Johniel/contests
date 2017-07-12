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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    // cout << endl;
    if (n == k + 1) {
      cout << 2 << endl;
      for (int i = 0; i < k; ++i) {
        cout << 1 << ' ' << 2 + i << endl;
      }
      continue;
    }
    if (k + 2 == n) {
      cout << 3 << endl;
      int cnt = 2;
      for (int i = 0; i < k; ++i) {
        cout << 1 << ' ' << cnt++ << endl;
      }
      int a = cnt++ - 1;
      int b = cnt++ - 1;
      cout << a << ' ' << b << endl;
      continue;
    }
    if ((n - 1 - k) <= k) {
      cout << 4 << endl;
      vector<int> v(k, 1);
      int cnt = 2;
      for (int i = 0; i < n - 1 - k; ++i) {
        cout << 1 << ' ' << (v[i] = cnt++) << endl;
      }
      for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ' << cnt++ << endl;
      }
      continue;
    }

    int x = 0;
    int cost = 1 << 29;
    for (int i = 2; i <= k; ++i) {
      int c = 0;
      const int s = (n - 1 - k) / i;
      const int t = (n - 1 - k) % i;
      c += s * 2 + (1 <= t) + (2 <= t) + 2;

      if (cost > c) {
        x = i;
        cost = c;
      }
    }

    const int s = (n - 1 - k) / x;
    const int t = (n - 1 - k) % x;
    cout << cost << endl;
    int cnt = 2;
    vector<int> v;
    for (int i = 0; i < x; ++i) {
      int prev = 1;
      for (int j = 0; j < s + (i < t); ++j) {
        cout << prev << ' ' << cnt << endl;
        prev = cnt++;
      }
      v.push_back(prev);
    }
    for (int i = 0; i < min<int>(v.size(), k); ++i) {
      cout << v[i] << ' ' << cnt++ << endl;
    }
    for (int i = 0; i < k - v.size(); ++i) {
      cout << v.back() << ' ' << cnt++ << endl;
    }
  }
  
  return 0;
}
