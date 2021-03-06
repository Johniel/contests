// atcoder/abc163/E/main.cpp
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

const int N = 2000 + 5;
lli memo[N][N];
vec<pair<lli, int>> v;
int n;
lli rec(int i, int j)
{
  lli& ret = memo[i][j];
  if (ret != -1) return ret;
  unless (i <= j) return 0;

  const int k = i + (v.size() - j - 1);

  lli a = rec(i + 1, j) + v[k].first * abs(v[k].second - i);
  lli b = rec(i, j - 1) + v[k].first * abs(v[k].second - j);

  return ret = max(a, b);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    v.clear();
    for (int i = 0; i < a.size(); ++i) {
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, a.size() - 1) << endl;
  }

  return 0;
}
