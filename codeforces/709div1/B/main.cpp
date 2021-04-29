// codeforces/709div1/B/main.cpp
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

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    queue<pair<int, int>> q;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 1) % a.size();
      if (__gcd(a[i], a[j]) == 1) q.push(make_pair(i, j));
    }

    const int N = 1e5 + 5;
    static int next[N];
    static int prev[N];
    for (int i = 0; i < a.size(); ++i) {
      next[i] = (i + 1) % a.size();
      prev[i] = (i - 1 + a.size()) % a.size();
    }

    set<int> vis;
    vec<int> v;
    while (q.size()) {
      pair<int, int> p = q.front();
      q.pop();
      if (vis.count(p.first) || vis.count(p.second)) continue;
      int idx = p.second;
      v.push_back(idx);
      vis.insert(idx);

      int i = prev[idx];
      int j = next[idx];
      prev[j] = i;
      next[i] = j;
      if (__gcd(a[i], a[j]) == 1) {
        q.push(make_pair(i, j));
      }
    }

    cout << v.size();
    each (i, v) cout << ' ' << i + 1;
    cout << endl;
  }

  return 0;
}
