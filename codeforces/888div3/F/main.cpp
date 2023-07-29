// github.com/Johniel/contests
// codeforces/888div3/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

pair<int, int> fn(int x, int y, int w)
{
  int val = 0;
  int z = 0;
  for (int i = w - 1; 0 <= i; --i) {
    int m = (1 << i);
    int a = x & m;
    int b = y & m;
    if (a == b) {
      val += m;
      if (!a) z += m;
    }
  }
  return {val, z};
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n, m;
  while (cin >> n >> m) {
    vec<int> a(n);
    cin >> a;

    vec<pair<int, int>> v;
    for (int i = 0; i < a.size(); ++i) {
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());

    int mx = -1;
    pair<int, int> p;
    int x;
    for (int i = 0; i + 1 < v.size(); ++i) {
      int j = i + 1;
      auto [val, y] = fn(v[i].first, v[j].first, m);
      if (mx < val) {
        mx = val;
        x = y;
        p = make_pair(v[i].second, v[j].second);
      }
    }
    cout << p.first + 1 << ' ' << p.second + 1 << ' ' << x << endl;
  }
  return 0;
}
