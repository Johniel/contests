// codeforces/e108/D/main.cpp
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

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
};

const int N = 5000 + 4;
lli memo[N][N];
vec<lli> a, b;

lli rec(int i, int j)
{
  unless (i <= j) return 0;
  if (i == j) return a[i] * b[i];
  lli& ret = memo[i][j];
  if (ret != -1) return ret;
  return ret = rec(i + 1, j - 1) + a[i] * b[j] + a[j] * b[i];
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    a.resize(n);
    b.resize(n);
    cin >> a >> b;
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);

    vec<lli> v;
    lli mx = 0;
    for (int i = 0; i < a.size(); ++i) {
      mx += a[i] * b[i];
      v.push_back(a[i] * b[i]);
    }
    PrefixSum<lli> s(v);

    for (int i = 0; i < a.size(); ++i) {
      for (int j = i; j < a.size(); ++j) {
        lli z = 0;
        z += s(0, i);
        z += rec(i, j);
        z += s(j+1, n);
        // cout << make_pair(i, j) << ' ' << z << ' ' << s(0, i) << "+" << rec(i, j) << "+" << s(j+1, n) << endl;
        setmax(mx, z);
      }
    }

    cout << mx << endl;
    // break;
  }

  return 0;
}
