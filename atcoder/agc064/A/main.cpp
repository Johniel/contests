// github.com/Johniel/contests
// atcoder/agc064/A/main.cpp

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

bool fn(vec<int> v)
{
  map<int, int> m;
  for (int i = 0; i < v.size(); ++i) {
    int j = (i + 1) % v.size();
    int d = abs(v[i] - v[j]);
    unless (1 <= d && d <= 2) return false;
  }
  each (i, v) ++m[i];
  each (i, m) if (i.second != i.first) return false;
  return true;
}

int main(int argc, char *argv[])
{
  if (0) {
    vec<int> v;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j <= i; ++j) {
        v.push_back(i + 1);
      }
    }
    v.erase(v.begin());
    do {
      v.insert(v.begin(), 1);
      bool f = true;
      for (int i = 0; i < v.size(); ++i) {
        int j = (i + 1) % v.size();
        int d = abs(v[i] - v[j]);
        f = f && (1 <= d && d <= 2);
      }
      if (f) cout << v << endl;
      v.erase(v.begin());
    } while (next_permutation(v.begin(), v.end()));
  }

  int n;
  while (cin >> n) {
    vec<int> v;

    for (int i = 1; i <= n-2; ++i) v.push_back(i);
    v.push_back(n);
    v.push_back(n-1);
    for (int i = 0; i < n-2; ++i) {
      v.push_back(n);
      v.push_back(n - 1);
    }
    v.push_back(n);

    for (int i = n - 2; 3 < i; i -= 2) {
      for (int j = 0; j < i-2; ++j) {
        v.push_back(i);
        v.push_back(i - 1);
      }
      v.push_back(i);
    }
    if (n % 2) {
      v.push_back(3);
      v.push_back(2);
      v.push_back(3);
    } else {
      v.push_back(2);
    }

    if (n == 3) {
      cout << "1 3 2 3 2 3" << endl;
      continue;
    }
    if (n == 4) {
      cout << "1 3 4 2 4 3 4 2 4 3" << endl;
      continue;
    }
    each (i, v) cout << i << ' '; cout << endl;
    unless (fn(v)) assert(false);
  }
  return 0;
}
