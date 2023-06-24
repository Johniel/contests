// github.com/Johniel/contests
// atcoder/abc307/C/main.cpp

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
  int ha, wa;
  int hb, wb;
  int hx, wx;
  while (cin >> ha >> wa) {
    const int H = 10 + 1;
    const int W = 10 + 1;
    char a[H][W];
    for (int i = 0; i < ha; ++i) {
      for (int j = 0; j < wa; ++j) {
        cin >> a[i][j];
      }
    }
    char b[H][W];
    cin >> hb >> wb;
    for (int i = 0; i < hb; ++i) {
      for (int j = 0; j < wb; ++j) {
        cin >> b[i][j];
      }
    }
    char x[H][W];
    cin >> hx >> wx;
    for (int i = 0; i < hx; ++i) {
      for (int j = 0; j < wx; ++j) {
        cin >> x[i][j];
      }
    }

    vec<pair<int, int>> va;
    for (int i = 0; i < ha; ++i) {
      for (int j = 0; j < wa; ++j) {
        if (a[i][j] == '#') va.push_back(make_pair(i, j));
      }
    }
    vec<pair<int, int>> vb;
    for (int i = 0; i < hb; ++i) {
      for (int j = 0; j < wb; ++j) {
        if (b[i][j] == '#') vb.push_back(make_pair(i, j));
      }
    }
    vec<pair<int, int>> vx;
    for (int i = 0; i < hx; ++i) {
      for (int j = 0; j < wx; ++j) {
        if (x[i][j] == '#') vx.push_back(make_pair(i, j));
      }
    }
    sort(vx.begin(), vx.end());

    bool f = false;
    for (int i = 0; i < vx.size(); ++i) {
      for (int j = 0; j < vx.size(); ++j) {
        vec<pair<int, int>> v;
        const pair<int, int> originA = vx[i];
        const pair<int, int> originB = vx[j];
        for (int k = 0; k < va.size(); ++k) {
          int s = va[k].first + (originA.first - va.front().first);
          int t = va[k].second + (originA.second - va.front().second);
          v.push_back(make_pair(s, t));
        }
        for (int k = 0; k < vb.size(); ++k) {
          int s = vb[k].first + (originB.first - vb.front().first);
          int t = vb[k].second + (originB.second - vb.front().second);
          v.push_back(make_pair(s, t));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (vx == v) {
          f = true;
          i = j = (1 << 29);
        }
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  return 0;
}
