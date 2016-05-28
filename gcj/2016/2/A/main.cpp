#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

const int P = 0;
const int R = 1;
const int S = 2;

bool operator < (vector<int> a, vector<int> b)
{
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) return a[i] > b[i];
  }
  return false;
}

struct T {
  T* r = nullptr;
  T* l = nullptr;
  int v = -1;
  T (int _v) { v = _v; }
  T (T* _r, T* _l) { r = _r; l = _l; }
  ~T() {
    if (r) delete r;
    if (l) delete l;
  }
  vector<int> minify(void)
  {
    if (v != -1) return {v};
    vector<int> a = l->minify();
    vector<int> b = r->minify();
    if (a > b) {
      swap(r, l);
      swap(a, b);
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};

vector<int> f(int r, int p, int s, int winner)
{
  const int N = 13;
  const int M = 1 << N;
  int dp[N][M];
  fill(&dp[0][0], &dp[N - 1][M - 1] + 1, -1);

  const int n = log2(r + p + s);
  const int m = r + p + s;
  
  dp[0][0] = winner;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a, b;
      if (dp[i][j] == R) { a = R; b = S; }
      if (dp[i][j] == P) { a = P; b = R; }
      if (dp[i][j] == S) { a = P; b = S; }
      dp[i + 1][j * 2] = a;
      dp[i + 1][j * 2 + 1] = b;
    }
  }

  vector<T*> v;
  for (int i = 0; i < m; ++i) {
    if (dp[n][i] == R) { --r; v.push_back(new T(dp[n][i])); }
    if (dp[n][i] == P) { --p; v.push_back(new T(dp[n][i])); }
    if (dp[n][i] == S) { --s; v.push_back(new T(dp[n][i])); }
  }
  unless (r == 0 && p == 0 && s == 0) return vector<int>();

  while (v.size() != 1) {
    vector<T*> u;
    for (int i = 0; i < v.size(); i += 2) {
      u.push_back(new T(v[i], v[i + 1]));
    }
    v = u;
  }
  vector<int> ret = v[0]->minify();
  delete v[0];
  return ret;
}

int main(int argc, char *argv[])
{
  int tc, T = 0;
  cin >> tc;
  while (tc--) {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    vector<int> a = f(r, p, s, R);
    vector<int> b = f(r, p, s, P);
    vector<int> c = f(r, p, s, S);
    if (a.empty() && b.empty() && c.empty()) {
      cout << "Case #" << ++T << ": IMPOSSIBLE" << endl;
    } else {
      if (a.empty()) a.push_back(1 << 29);
      if (b.empty()) b.push_back(1 << 29);
      if (c.empty()) c.push_back(1 << 29);

      vector<int> mn = {1 << 29};
      mn = min(mn, a);
      mn = min(mn, b);
      mn = min(mn, c);

      cout << "Case #" << ++T << ": ";
      each (i, mn) {
        if (i == R) cout << 'R';
        if (i == P) cout << 'P';
        if (i == S) cout << 'S';
      }
      cout << endl;
    }
    
  }
  return 0;
}
