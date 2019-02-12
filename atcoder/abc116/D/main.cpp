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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end(), [] (auto a, auto b) { return a.second > b.second; });
    vector<int> u;
    set<int> vis;
    lli sum = 0;
    int cnt = 0;
    each (i, v) {
      if (vis.count(i.first)) {
        u.push_back(i.second);
      }
      sum += i.second;
      ++cnt;
      vis.insert(i.first);
      if (k < cnt) {
        sum -= u.back();
        --cnt;
        u.pop_back();
      }
    }
    cout << sum << endl;
  }

  return 0;
}
