// codeforces/731div3/C/main.cpp
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

  int _;
  cin >> _;

  int k, n, m;
  while (cin >> k >> n >> m) {
    vec<int> a(n), b(m);
    cin >> a >> b;

    vec<int> v;
    for (int i = 0, j = 0, z = k; i < a.size() || j < b.size(); ) {
      if (i < a.size() && a[i] == 0) {
        v.push_back(a[i++]);
      } else if (j < b.size() && b[j] == 0) {
        v.push_back(b[j++]);
      } else if (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) v.push_back(a[i++]);
        else             v.push_back(b[j++]);
      } else {
        if (i == a.size()) v.push_back(b[j++]);
        else               v.push_back(a[i++]);
      }

      z += (v.back() == 0);
      if (v.back() != 0 && z + 1 <= v.back()) {
        v.clear();
        break;
      }
    }

    if (v.empty()) cout << -1 << endl;
    else {
      each (i, v) cout << i << ' '; cout << endl;
    }
  }

  return 0;
}
