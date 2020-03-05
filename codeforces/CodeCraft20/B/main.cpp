// codeforces/CodeCraft20/B/main.cpp
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

  int _;
  cin >> _;

  int n;
  str s;
  while (cin >> n >> s) {
    pair<str, int> mn = make_pair(s, 1);
    reverse(s.begin(), s.end());
    setmin(mn, make_pair(s, (int)s.size()));
    reverse(s.begin(), s.end());

    for (int k = 0; k < s.size(); ++k) {
      str t, u;
      for (int i = 0; i < s.size(); ++i) {
        if (i < k) t += s[i];
        else u += s[i];
      }
      // cout << t << ' ' << u << ", " << k << endl;
      if ((s.size() - k) % 2 == 1) {
        reverse(t.begin(), t.end());
        setmin(mn, make_pair(u + t, k + 1));
      } else {
        setmin(mn, make_pair(u + t, k + 1));
      }
    }

    cout << mn.first << endl;
    cout << mn.second << endl;
  }

  return 0;
}
