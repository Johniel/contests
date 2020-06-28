// atcoder/intro-heuristics
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

vec<lli> C;
int D;
const int CONTESTS = 26;
const int DAYS = 365;
lli SCORE[DAYS][CONTESTS];

using schedule = vec<int>;

void problem_B(void)
{
  schedule s(D);
  cin >> s;
  each (i, s) --i;

  static int last[CONTESTS];
  fill(last, last + CONTESTS, -1);

  lli x = 0;
  lli y = 0;
  for (int i = 0; i < D; ++i) {
    x += SCORE[i][s[i]];
    last[s[i]] = i;
    for (int j = 0; j < CONTESTS; ++j) {
      y += C[j] * (i - last[j]);
    }
    cout << x - y << endl;
  }

  return ;
}

void problem_C(void)
{
  return ;
}

lli calc_score(schedule s)
{
  assert(s.size() == D);

  static int last[CONTESTS];
  fill(last, last + CONTESTS, -1);

  lli x = 0;
  lli y = 0;
  for (int i = 0; i < D; ++i) {
    x += SCORE[i][s[i]];
    last[s[i]] = i;
    for (int j = 0; j < CONTESTS; ++j) {
      y += C[j] * (i - last[j]);
    }
  }

  return x - y;
}

void problem_A(void)
{
  int WIDTH = 11;

  vec<pair<lli, schedule>> v;
  schedule ini(D, -1);
  for (int i = 0; i < D; ++i) {
    lli idx = 0;
    for (int j = 0; j < CONTESTS; ++j) {
      if (SCORE[i][idx] < SCORE[i][j]) {
        idx = j;
      }
    }
    ini[i] = idx;
  }
  v.push_back({-calc_score(ini), ini});

  vec<pair<lli, int>> idx;
  for (int i = 0; i < D; ++i) {
    idx.push_back({SCORE[i][ini[i]], i});
  }
  sort(idx.begin(), idx.end());

  for (int _ = 0; _ < 365*3; ++_) {
    const int day = idx[_ % idx.size()].second;
    const lli size = min<int>(WIDTH, v.size());
    for (int i = 0; i < size; ++i) {
      schedule s = v[i].second;
      for (int alt = 0; alt < CONTESTS; ++alt) {
        schedule t = s;
        t[day] = alt;
        v.push_back({-calc_score(t), t});
      }
    }
    sort(v.begin(), v.end());
    while (WIDTH < v.size()) v.pop_back();
    if (_ == 365) {
      // random_shuffle(idx.begin(), idx.end());
      WIDTH = 6;
    }
  }

  each (i, v.back().second) {
    cout << i + 1 << endl;
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  C.resize(26);

  cin >> D >> C;
  for (int i = 0; i < D; ++i) {
    for (int j = 0; j < CONTESTS; ++j) {
      cin >> SCORE[i][j];
    }
  }

  // problem_B();
  // problem_C();
  problem_A();

  return 0;
}
