// atcoder/abc023/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "("; each (i, s) os << i << ","; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "("; each (i, m) os << i << ","; os << ")"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int r, c, k, n;
  while (cin >> r >> c >> k >> n) {
    vector<pair<int, int>> v(n);
    cin >> v;

    map<int, lli> R, C;
    each (i, v) {
      ++R[i.first];
      ++C[i.second];
    }
    map<int, lli> rr, cc;
    each (i, R) ++rr[i.second];
    each (i, C) ++cc[i.second];
    rr[0] = r - R.size();
    cc[0] = c - C.size();

    lli cnt = 0;
    for (int i = 0; i <= k; ++i) {
      cnt += rr[i] * cc[k - i];
    }
    each (i, v) {
      cnt -= (R[i.first] + C[i.second] == k);
      cnt += (R[i.first] + C[i.second] == k + 1);
    }
    cout << cnt << endl;
  }

  return 0;
}
