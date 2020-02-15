// codeforces/620div2/B/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<string> v(n);
    cin >> v;
    int p[n];
    fill(p, p + n, -1);
    vector<int> u;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        unless (p[i] == -1 && p[j] == -1) continue;
        string s = v[j];
        reverse(s.begin(), s.end());
        if (v[i] == s) {
          p[i] = j;
          p[j] = i;
          u.push_back(i);
        }
      }
    }
    int k = -1;
    for (int i = 0; i < v.size(); ++i) {
      string s = v[i];
      reverse(s.begin(), s.end());
      if (p[i] == -1 && s == v[i]) {
        k = i;
        break;
      }
    }
    if (k != -1) u.push_back(k);
    for (int i = u.size() - 1; 0 <= i; --i) {
      if (p[u[i]] != -1) {
        u.push_back(p[u[i]]);
      }
    }
    cout << u.size() * m << endl;
    each (i, u) cout << v[i] << flush;
    cout << endl;
  }

  return 0;
}
