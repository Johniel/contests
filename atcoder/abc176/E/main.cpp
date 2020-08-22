// atcoder/abc176/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, m;
  while (cin >> h >> w >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first, --i.second;
    sort(v.begin(), v.end());

    map<int, int> a, b;
    int mx_a = 0;
    int mx_b = 0;
    each (i, v) {
      setmax(mx_a, ++a[i.first]);
      setmax(mx_b, ++b[i.second]);
    }

    int mx = 0;
    each (i, v) {
      setmax(mx, a[i.first] + b[i.second] - 1);
    }

    vec<int> p, q;
    each (i, a) {
      if (mx_a == i.second) {
        p.push_back(i.first);
      }
    }
    each (i, b) {
      if (mx_b == i.second) {
        q.push_back(i.first);
      }
    }

    each (i, p) {
      each (j, q) {
        if (!binary_search(v.begin(), v.end(), make_pair(i, j))) {
          mx = a[i] + b[j];
          break;
        }
      }
    }

    cout << mx << endl;
  }

  return 0;
}
