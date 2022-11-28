// github.com/Johniel/contests
// atcoder/abc206/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 100 + 3;
int memo[N][N];
vec<pair<int, int>> v;
int rec(int begin, int end)
{
  if (end <= begin) return 0;
  int& ret = memo[begin][end]; // mex
  if (ret != -1) return ret;

  vec<int> u;
  each (i, v) {
    if (end <= i.first) break;
    if (begin <= i.first && i.second <= end) {
      int x = rec(begin, i.first);
      int y = rec(i.second, end);
      u.push_back(x ^ y);
    }
  }

  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  ret = u.size();
  for (int i = 0; i < u.size(); ++i) {
    if (u[i] != i) {
      return ret = i;
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    v.resize(n);
    cin >> v;
    sort(v.begin(), v.end());
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << (rec(0, 100) ? "Alice" : "Bob") << endl;
  }
  return 0;
}
