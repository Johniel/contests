// codeforces/e110/D/main.cpp
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

const int N = 1 << 19;
int x[N];
char s[N];
map<pair<int, int>, int> rev;
pair<int, int> m[N];
int rec(int nth, const int i, const int k, const pair<int, int> target, char c)
{
  if (k - i == 1) return x[nth] = 1;
  pair<int, int> curr = make_pair(i, k);
  const int L = nth * 2;
  const int R = nth * 2 + 1;
  if (curr == target) {
    // cout << nth << ' ' << curr << ' ' << c << ' ' << x[L] << ' ' << x[R] << endl;
    if (c == '?') return x[nth] = x[L] + x[R];
    if (c == '0') return x[nth] = x[L];
    if (c == '1') return x[nth] = x[R];
  } else {
    const int j = i + (k - i) / 2;
    if (target.second <= j) {
      rec(L, i, j, target, c);
    } else {
      rec(R, j, k, target, c);
    }
    // cout << curr << endl;
    // assert(rev.count(curr));
    // cout << nth << ' ' << curr << ' ' << s[rev[curr]] << ' ' << x[L] << ' ' << x[R] << endl;
    if (s[rev[curr]] == '?') return x[nth] = x[L] + x[R];
    if (s[rev[curr]] == '0') return x[nth] = x[L];
    if (s[rev[curr]] == '1') return x[nth] = x[R];
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int k, y;
  // while (cin >> k >> s >> y) {
  while (scanf("%d%s%d", &k, s, &y) == 3) {
    x[0] = 0;
    x[1] = (1 << k);
    for (int i = 1; i < (1 << k); ++i) {
      x[i * 2 + 0] = x[i] / 2;
      x[i * 2 + 1] = x[i] / 2;
    }
    queue<pair<int, int>> q;
    // map<int, pair<int, int>> m;
    int cnt = 0;
    for (int i = 0; i < (1 << k); ++i) {
      q.push(make_pair(i, i + 1));
    }
    while (1 < q.size()) {
      pair<int, int> a = q.front(); q.pop();
      pair<int, int> b = q.front(); q.pop();
      pair<int, int> c = make_pair(a.first, b.second);
      m[cnt++] = c;
      q.push(c);
    }
    rev.clear();
    for (int i = 0; i < (1 << k); ++i) {
      rev[m[i]] = i;
    }
    // cout << m << endl;
    // cout << rev << endl;
    for (int i = 0; i < (1 << k); ++i) {
      // cout << "?" << m[i] << endl;
      rec(1, 0, (1 << k), m[i], s[i]);
    }

    while (y--) {
      int idx;
      char c;
      // cin >> idx >> c;
      scanf("%d %c\n", &idx, &c);
      --idx;
      // cout << rec(1, 0, (1 << k), m[idx], c) << endl;
      int z = rec(1, 0, (1 << k), m[idx], c);
      printf("%d\n", z);
      s[idx] = c;
    }
  }


  return 0;
}
