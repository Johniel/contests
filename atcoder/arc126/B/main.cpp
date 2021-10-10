// atcoder/arc126/B/main.cpp
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

#define REP(i, n) for(int i=0; i<(int)n; i++)
static const int INF = INT_MAX;
static const int N = 2 * 1e5 + 3;
int num[N];
int LIS(const int num[], const int size)
{
  int t[size];
  int ind[size];
  int len = INT_MIN;
  fill(t, t + size, INF);
  REP(i, size){
    ind[i] = lower_bound(t, t + size, num[i]) - t;
    t[ind[i]] = num[i];
  }
  len = *max_element(ind, ind + size);
  int tmp = len;
  int result[len+1];
  REP(i, size)if(ind[size-1-i] == len)result[len--] = num[size-1-i];
  // REP(i, tmp+1)printf("%d\n", result[i]);
  return tmp+1;
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    sort(v.begin(), v.end(), [] (auto p, auto q) {
      if (p.first != q.first) return p < q;
      else return p.second > q.second;
    });

    for (int i = 0; i < v.size(); ++i) {
      num[i] = v[i].second;
    }
    int a = LIS(num, v.size());
    cout << a << endl;
  }

  return 0;
}
