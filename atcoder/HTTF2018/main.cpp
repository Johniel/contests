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
 
const int U = 0;
const int R = 1;
const int D = 2;
const int L = 3;
 
const int DIR[] = {U, R, D, L};
 
const int di[] = {-1, 0, +1, 0};
const int dj[] = {0, +1, 0, -1};
 
const int M = 29;
struct G {
  char g[M][M];
  G ()
  {
    fill(&g[0][0], &g[M - 1][M - 1], '.');
    for (int i = 0; i < M; ++i) {
      g[i][0] = g[0][i] = g[i][M - 1] = g[M - 1][i] = '#';
    }
  }
 
  bool inside(int i, int j) const
  {
    unless (0 <= i && i < M) return false;
    unless (0 <= j && j < M) return false;
    return true;
  }
 
  bool valid(int i, int j) const
  {
    return this->g[i][j] != '#' && this->inside(i, j);
  }
 
  char& at(int i, int j)
  {
    return g[i][j];
  }
 
  char& at(pair<int, int> p)
  {
    return this->at(p.first, p.second);
  }
 
  ostream& show(ostream& os) const
  {
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        os << g[i][j];
      }
      os << endl;
    }
    return os;
  }
 
  vector<pair<int, int>> run(string cmd)
  {
    int d = U;
    pair<int, int> p = make_pair(M / 2, M / 2);
    vector<pair<int, int>> path;
    each (c, cmd) {
      path.push_back(p);
      int x = 1;
      if (this->at(p) == 'D') x = 2;
      if (this->at(p) == 'T') x = 3;
      for (int k = 0; k < x; ++k) {
        if (c == 'S') {
          int ni = p.first + di[d];
          int nj = p.second + dj[d];
          if (this->valid(ni, nj)) {
            p = make_pair(ni, nj);
          }
        } else if (c == 'R' || this->at(p) == 'R') {
          d = (d + 1) % 4;
        } else if (c == 'L' || this->at(p) == 'L') {
          d = (d - 1 + 4) % 4;
        }
      }
    }
    path.push_back(p);
    return path;
  }
};
 
int calc_score(int x)
{
  if (x == 1) return 10;
  if (x == 2) return 3;
  if (x == 3) return 1;
  return 0;
}
 
int run(const vector<string>& cmds, G& g)
{
  assert(cmds.size());
 
  map<pair<int, int>, int> cnt;
  each (cmd, cmds) {
    vector<pair<int, int>> path = g.run(cmd);
    ++cnt[path.back()];
  }
 
  int score = 0;
  each (i, cnt) {
    score += calc_score(i.second);
  }
  return score;
}
 
int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n, m, _l;
  while (cin >> n >> m >> _l) {
    vector<string> cmds(n);
    cin >> cmds;
 
    vector<pair<int, int>> v;
    for (int i = 1; i < M - 1; ++i) {
      for (int j = 1; j < M - 1; ++j) {
        v.push_back(make_pair(i, j));
      }
    }
    G g;
  
    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < v.size() / 1; ++i) {
      g.at(v[i]) = 'R';
    }
    random_shuffle(v.begin(), v.end());
    
    int mx = run(cmds, g);
    each (p, v) {
      const char C = '#';
      const char tmp = g.at(p);
      g.at(p) = C;
      int x = run(cmds, g);
      if (mx < x) {
        mx = x;
      } else {
        g.at(p) = tmp;
      }
    }
    g.show(cout);
  }
 
  return 0;
}
