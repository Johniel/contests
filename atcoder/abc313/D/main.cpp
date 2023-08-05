// github.com/Johniel/contests
// atcoder/abc313/D/main.cpp

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

int main(int argc, char *argv[])
{
  int n, k;
  cin >> n >> k;

  if (k == 1) {
    vec<int> a;
    for (int i = 0; i < n; ++i) {
      cout << "? " << i + 1 << endl;
      int x;
      cin >> x;
      a.push_back(x);
    }
    cout << "! ";
    each (i, a) cout << i << ' ';
    cout << endl;
    return 0;
  }

  cout << "?"; for (int i = 0; i < k; ++i) cout << ' ' << i + 1; cout << endl;
  int x0;
  cin >> x0;

  vec<int> v(k, -1);
  v[0] = -2;
  for (int t = k; t < n; ++t) {
    cout << "?";
    for (int i = 1; i < k; ++i) {
      cout << ' ' << i + 1;
    }
    cout << ' ' << t+1 << endl;
    int x;
    cin >> x;
    v.push_back(x == x0);
  }

  for (int t = 1; t < k; ++t) {
    cout << "?";
    for (int i = 0; i < k; ++i) {
      if (i == t) continue;
      cout << ' ' << i + 1;
    }
    cout << ' ' << n << endl;
    int x;
    cin >> x;
    if (v.back()) v[t] = (x == x0);
    else v[t] = !(x == x0);
  }

  int same = count(v.begin(), v.begin() + k, 1);
  int diff = count(v.begin(), v.begin() + k, 0);
  // cout << make_pair(same, diff) << endl;
  vec<int> a(n, -3);
  if (diff == same) {
    a[0] = !x0;
  } else {
    same %= 2;
    diff %= 2;
    if (!diff) a[0] = x0;
    else a[0] = !x0;
  }
  for (int i = 1; i < a.size(); ++i) {
    a[i] = (a[0] == v[i]);
  }
  // cout << x0 << ' ' << v << endl;
  cout << "!";
  each (i, a) cout << ' ' << i;
  cout << endl;

  return 0;
}
