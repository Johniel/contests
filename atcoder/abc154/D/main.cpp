// atcoder/abc154/D/main.cpp
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

  const int N = 1000 + 5;
  double e[N];
  fill(e, e + N, 0);
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      e[i] += j * (1.0 / i);
    }
  }

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    cin >> a;
    vector<double> b;
    each (i, a) b.push_back(e[i]);
    // cout << b << endl;

    double mx = 0;

    queue<double> q;
    double sum = 0;
    each (i, b) {
      sum += i;
      q.push(i);
      if (k < q.size()) {
        sum -= q.front();
        q.pop();
      }
      if (q.size() == k) {
        setmax(mx, sum);
      }
    }

    printf("%.10lf\n", mx);
  }


  return 0;
}
