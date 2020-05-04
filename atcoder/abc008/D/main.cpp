// atcoder/abc008/D/main.cpp
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

vec<pair<int, int>> v;

map<pair<int, int>, int> idx;
const int N = (30 + 2) * (30 + 2) * 2* 2;
int memo[N][N];

int rec(pair<int, int> a, pair<int, int> b)
{
  const int p = idx.count(a) ? idx[a] : idx.size();
  idx[a] = p;
  const int q = idx.count(b) ? idx[b] : idx.size();
  idx[b] = q;

  int& ret = memo[p][q];
  if (ret != -1) return ret;

  int mx = 0;
  each (i, v) {
    unless (a.first <= i.first && a.second <= i.second) continue;
    unless (i.first < b.first && i.second < b.second) continue;

    int sum = 0;

    sum += abs(a.first - b.first);
    sum += abs(a.second - b.second);
    --sum;

    sum += rec(a, i);
    sum += rec(make_pair(a.first, i.second + 1), make_pair(i.first, b.second));
    sum += rec(make_pair(i.first + 1, i.second + 1), b);
    sum += rec(make_pair(i.first + 1, a.second), make_pair(b.first, i.second));

    setmax(mx, sum);
  }

  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int w, h, n;
  while (cin >> w >> h >> n) {
    idx.clear();
    v.resize(n);

    cin >> v;
    each (i, v) {
      swap(i.first, i.second);
      --i.first;
      --i.second;
    }

    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(make_pair(0, 0), make_pair(h, w)) << endl;
  }

  return 0;
}
