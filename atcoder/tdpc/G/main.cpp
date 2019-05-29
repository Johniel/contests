// atcoder/tdpc/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int N = 1e6 + 5;
int g[N][30];
lli memo[N];
lli rec(int curr)
{
  lli& ret = memo[curr];
  if (ret != -1) return ret;

  lli sum = 1;
  for (char c = 'a'; c <= 'z'; ++c) {
    int next = g[curr][c - 'a'];
    unless (curr < next) continue;
    sum += rec(next);
    setmin(sum, 1000000000000000000LL+5);
  }
  return ret = sum;
}

vector<char> buff;
void build(int curr, lli x)
{
  if (x < 1) return ;
  for (char c = 'a'; c <= 'z'; ++c) {
    int next = g[curr][c - 'a'];
    unless (curr < next) continue;
    lli y = rec(next);
    if (x <= y) {
      buff.push_back(c);
      build(next, x-1);
      return ;
    }
    x -= y;
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  lli k;
  while (cin >> s >> k) {
    fill(&g[0][0], &g[N - 1][30 - 1] + 1, -1);
    fill(memo, memo + N, -1);

    s = "@" + s;
    for (int i = s.size() - 2; 0 <= i; --i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        g[i][c - 'a'] = g[i + 1][c - 'a'];
      }
      g[i][s[i + 1] - 'a'] = i + 1;
    }

    if (rec(0) < k+1) {
      cout << "Eel" << endl;
    } else {
      buff.clear();
      build(0, k);
      cout << string(buff.begin(), buff.end()) << endl;
    }
  }

  return 0;
}
