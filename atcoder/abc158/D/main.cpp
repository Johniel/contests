// atcoder/abc158/D/main.cpp
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

int di[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dj[] = {1, 0, 0, -1, 1, -1, -1, 1};
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  str s;
  int q;
  while (cin >> s >> q) {
    deque<char> d;
    each (c, s) d.push_back(c);

    bool rev = false;
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        rev = rev ^ 1;
      }
      if (t == 2) {
        int f;
        char c;
        cin >> f >> c;
        if (rev) f = (f == 1 ? 2 : 1);
        if (f == 1) d.push_front(c);
        if (f == 2) d.push_back(c);
        // cout << rev << ": "; for (int i = 0; i < d.size(); ++i) cout << d[i]; cout << endl;
      }
    }

    str t;
    while (!d.empty()) {
      if (rev) {
        t += d.back();
        d.pop_back();
      } else {
        t += d.front();
        d.pop_front();
      }
    }
    cout << t << endl;
  }

  return 0;
}
