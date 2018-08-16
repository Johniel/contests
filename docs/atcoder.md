# AtCoder

[profile](https://atcoder.jp/user/Johniel)

[AtCoder Problems](https://kenkoooo.com/atcoder/?user=Johniel&rivals=&kind=category)

## Codes
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  while (cin >> a >> b >> c) {
    map<int, int> cnt;
    ++cnt[a];
    ++cnt[b];
    ++cnt[c];
    each (i, cnt) if (i.second == 1) cout << i.first << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    
    int di[] = {-1, -1, -1,  0,  0, +1, +1, +1};
    int dj[] = {-1,  0, +1, -1, +1, -1,  0, +1};
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == '#') {
          cout << '#' << flush;
        } else {
          int cnt = 0;
          for (int dir = 0; dir < 8; ++dir) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            unless (0 <= i && i < h) continue;
            unless (0 <= j && j < w) continue;
            cnt += (g[ni][nj] == '#');
          }
          cout << cnt << flush;
        }
      }
      cout << endl;
    }
  }
  
  return 0;
}
```
```cpp
// uva 796
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

static const int FAIL = -1;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void traverse(const Graph &G, int n, int d[], int p[], int l[], int &time)
{  
  d[n] = l[n] = ++time;
  FOR(e, G[n]){
    if(!d[e->dst]){
      p[e->dst] = e->src;
      traverse(G, e->dst, d, p, l, time); 
      l[e->src] = min(l[e->src], l[e->dst]); 
    }
    else if(p[e->src] != e->dst)
      l[e->src] = min(l[e->src], d[e->dst]); 
  }
  return ;
}

Edges findBridge(const Graph &G)
{// G is not allowed parallel edge
  const int size = G.size();
  int d[size], p[size], l[size], time = 0;
  Edges B;
  fill(d, d + size, false);
  fill(p, p + size, FAIL);
  REP(i, size){
    if(d[i])continue;
    traverse(G, i, d, p, l, time);
  }
  REP(i, size){
    if(p[i] != FAIL && d[i] == l[i])
      B.push_back(Edge(p[i], i));
  }
  return B;
}

bool cmp(const Edge &a, const Edge &b)
{
  if(a.src != b.src)return a.src < b.src;
  return a.src > b.dst;
}

#include <set>
#include <utility>
int main(void)
{
  int n, m;

  while (cin >> n >> m) {
    Graph g(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(Edge(a ,b));
      g[b].push_back(Edge(b, a));
    }
    cout << findBridge(g).size() << endl;
    
  }
  
  // while(cin >> node){
  //   int src, edge, dst, cnt = 0;
  //   char c;
  //   set< pair<int, int> > S, T;
  //   Graph G(node);
  //   REP(i, node){
  //     cin >> src >> c >> edge >> c;
  //     REP(j, edge){
  //       cin >> dst;
  //       if(S.count(make_pair(src, dst))){
  //         T.insert(make_pair(src, dst));
  //       }
  //       else{
  //         G[src].push_back(Edge(src, dst));		  
  //         G[dst].push_back(Edge(dst, src));
  //       }
  //     }
  //   }
  //   Edges B = findBridge(G), R;
  //   FOR(e, B){
  //     //if(T.count(make_pair(e->src, e->dst)))continue;
  //     R.push_back(Edge(min(e->src, e->dst), max(e->src, e->dst)));
  //   }
  //   sort(ALL(R), cmp);
  //   cout << R.size() << " critical links" << endl;
  //   FOR(e, R)
  //     cout << e->src << " - " << e->dst << endl;
  //   cout << endl;
  // }
  return 0;
}
```
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<lli> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<point> v;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      v.push_back(point(x, y));
    }

    sort(v.begin(), v.end(), [] (point a, point b) { return a.imag() < b.imag(); });
    // cout << endl; each (i, v) cout << i << endl; 

    // +--d---+
    // |      |
    // a      b
    // |      |
    // +----c-+
    ull mn = 1ULL << 63;
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        if (a == b) continue;
        for (int c = 0; c < n; ++c) {
          unless (v[a].real() <= v[c].real() && v[c].real() <= v[b].real()) continue;
          unless (min(v[a].imag(), v[b].imag()) >= v[c].imag()) continue;
          int cnt = 0;
          for (int d = c; d < n; ++d) {
            unless (v[a].real() <= v[d].real() && v[d].real() <= v[b].real()) continue;
            ++cnt;
            if (k <= cnt) {
              ull s = labs(v[a].real() - v[b].real());
              ull t = labs(v[c].imag() - v[d].imag());
              // cout << v[a] << " - " << v[b] << endl;
              // cout << v[c] << " - " << v[d] << endl;
              // cout << s * t << endl;
              mn = min(mn, s * t);
            }
          }
        }
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int r, g;
  while (cin >> r >> g) {
    cout << 2 * g - r << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    int x = 1;
    while (n--) {
      x = min(x * 2, x + k);
    }
    cout << x << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const string X = "UNRESTORABLE";
  string s, t;
  while (cin >> s >> t) {
    string x = "~";
    for (int i = 0; i < s.size(); ++i) {
      int matched = 0;
      string u = s;
      replace(u.begin(), u.end(), '?', 'a');
      for (int j = 0; j < t.size() && i + j < s.size(); ++j) {
        matched += (s[i + j] == '?' || s[i + j] == t[j]);
        u[i + j] = t[j];
      }
      if (matched == t.size()) {
        x = min(x, u);
      }
    }
    cout << (x == "~" ? X : x) << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    int t[n];
    int v[n];
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    vector<pair<int, int>> range;
    int acc = 0;
    for (int i = 0; i < n; ++i) {
      range.push_back(make_pair(acc, acc + t[i]));
      acc += t[i];
    }
    
    const int N = (200 * 100 + 5) * 2;
    const double inf = 1e100;
    double x[N];
    fill(x, x + N, inf);
    for (int i = 0; i < n; ++i) {
      for (int j = range[i].first * 2; j <= range[i].second * 2; ++j) {
        x[j] = min<double>(x[j], v[i]);
      }
    }
    const int k = range.back().second * 2 + 1;
    assert(k < N);
    x[0] = 0;
    x[k - 1] = 0;
      
    for (int i = 0; i + 1 < N; ++i) {
      if (x[i] == N) {
        if (x[i - 1] == x[i + 1]) x[i] = x[i + 1];
        else x[i] = min(x[i - 1] + 0.5, x[i + 1] + 0.5);
      }
    }
    
    for (int i = 1; i - 1 < k; ++i) {
      x[i] = min({x[i - 1] + 0.5, x[i], x[i + 1] + 0.5});
    }
    for (int i = k - 2; 0 < i; --i) {
      x[i] = min({x[i - 1] + 0.5, x[i], x[i + 1] + 0.5});
    }
   
    double sum = 0;
    for (int i = 1; i < k; ++i) {
      if (x[i - 1] == x[i]) {
        sum += x[i - 1] * 0.5;
      } else {
        if (x[i - 1] < x[i]) {
          sum += (x[i - 1] * 0.5) + (0.5 * 0.5 * 0.5);
        } else {
          sum += (x[i - 1] * 0.5) - (0.5 * 0.5 * 0.5);
        }
      }
    }
    printf("%.10lf\n", sum);
  }

  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli a, b, n;
  while (cin >> n >> a >> b) {
    cout << min(b, a * n) << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    lli n = stoll(s);
    lli sum = 0;
    each (c, s) {
      sum += c - '0';
    }
    cout << (n % sum == 0 ? "Yes" : "No") << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    int f[n][5][2];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 2; ++k) {
          cin >> f[i][j][k];
        }
      }
    }
    int p[n][10];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 10; ++j) {
        cin >> p[i][j];
      }
    }
    
    lli mx = -(1LL << 60);
    for (int bit = 1; bit < (1 << 10); ++bit) {
      lli sum = 0;
      for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 10; ++j) {
          cnt += (bool)((bit & (1 << j)) && f[i][j / 2][j % 2]);
        }
        sum += p[i][cnt];
      }
      mx = max(mx, sum);
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
```cpp
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

struct edge {
  int to, cap, rev;
};

const int N = 1e5 * 2 + 10;
vector<int> g[N];

void add_edge(int src, int dst)
{
  g[src].push_back(dst);
  g[dst].push_back(src);
  return ;
}

int match[N];
int vis[N], x;
bool rec(int curr)
{
  vis[curr] = x;
  each (next, g[curr]) {
    int w = match[next];
    if (w < 0 || (vis[w] != x && rec(w))) {
      match[curr] = next;
      match[next] = curr;
      return true;
    }
  }
  return false;
}

int matching(int n = N)
{
  int res = 0;
  fill(match, match + N, -1);
  x = 1;
  fill(vis, vis + N, 0);
  for (int i = 0; i < n; ++i) {
    if (match[i] < 0) {
      res += rec(i);
      ++x;
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int c;
  while (cin >> n >> c) {
    fill(g, g + N, vector<int>());
    vector<pair<int, int>> v[c];
    map<tuple<int, int, int>, int> name;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int s, t, c;
      cin >> s >> t >> c;
      --c;
      v[c].push_back(make_pair(s, t));
      name[make_tuple(c, s, t)] = cnt++;
    }
    for (int i = 0; i < c; ++i) {
      sort(v[i].begin(), v[i].end()); 
    }

    for (int i = 0; i < c; ++i) {
      for (int j = 0; j + 1 < v[i].size(); ++j) {
        tuple<int, int, int> a = make_tuple(i, v[i][j].first, v[i][j].second);
        tuple<int, int, int> b = make_tuple(i, v[i][j + 1].first, v[i][j + 1].second);
        add_edge(name[a], name[b] + name.size());
      }
    }
    for (int i = 0; i < c; ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        const pair<int, int>& p = v[i][j];
        auto a = make_tuple(i, v[i][j].first, v[i][j].second);
        for (int k = 0; k < c; ++k) {
          if (i == k) continue;
          auto itr = lower_bound(v[k].begin(), v[k].end(), make_pair(p.second + 1, 0));
          if (itr != v[k].end()) {
            auto b = make_tuple(k, itr->first, itr->second);
            add_edge(name[a], name[b] + name.size());
          }
        }
      }
    }

    cout << n - matching() << endl;
  }
  
  return 0;
}
```
```cpp
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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "{";
  each (i, v) os << i << ", ";
  os << "}";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    if (n < 1200) {
      cout << "ABC" << endl;
      continue;
    }
    if (n < 2800) {
      cout << "ARC" << endl;
      continue;
    }
    cout << "AGC" << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    bool f = true;
    f = f && (s[0] == 'A');

    int cnt = 0;
    for (int i = 2; i < int(s.size())- 1; ++i) {
      cnt += (s[i] == 'C');
    }
    f = f && (cnt == 1);

    each (c, s) {
      if (c == 'A' || c == 'C') continue;
      f = f && ('a' <= c && c <= 'z');
    }
    
    cout << (f ? "AC" : "WA") << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli d, g;
  while (cin >> d >> g) {
    g /= 100;

    vector<pair<int, lli>> v(d);
    each (i, v) {
      cin >> i.first >> i.second;
      i.second /= 100;
    }

    const int D = 10 + 5;
    const int N = 10 * 100 * 3;
    const lli inf = 1LL << 60;
    static lli dp[D][N];
    fill(&dp[0][0], &dp[D - 1][N - 1] + 1, -inf);
    dp[0][0] = 0;

    for (int i = 0; i < v.size(); ++i) {
      for (int solved = 0; solved <= 10*100; ++solved) {
        for (int added = 0; added <= v[i].first; ++added) {
          int x = added * (i + 1);
          int y = v[i].second * (added == v[i].first);
          dp[i + 1][solved + added] = max(dp[i + 1][solved + added], dp[i][solved] + x + y);
        }
      }
    }

    int mn = 1 << 29;
    for (int i = 0; i < N; ++i) {
      if (g <= dp[d][i]) mn = min(mn, i);
    }
    cout << mn << endl;
  }

  return 0;
}
```
```cpp
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

struct acc {
  vector<lli> sum;
  acc(vector<lli> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const lli mod = 1e9 + 7;
  const string t = "ABC_";
  string s;
  while (cin >> s) {
    vector<lli> a(s.size(), 0);
    vector<lli> c(s.size(), 0);
    vector<lli> h(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
      a[i] += (s[i] == 'A');
      c[i] += (s[i] == 'C');
      h[i] += (s[i] == '?');
    }

    map<int, lli> p3;
    lli prev = 1;
    for (int i = 0; i < 1e5; ++i) {
      p3[i] = prev;
      (prev *= 3) %= mod;
    }
    p3[-1] = 0;
    
    acc acc_a(a);
    acc acc_c(c);
    acc acc_h(h);

    lli sum = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'B' || s[i] == '?') {
        lli A = acc_a.query(0, i);
        lli AH = acc_h.query(0, i);

        lli C = acc_c.query(i + 1, s.size());
        lli CH = acc_h.query(i + 1, s.size());
        
        // ?B?
        {
          lli x = AH * CH;
          lli y = p3[AH - 1] * p3[CH - 1];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
        // AB?
        {
          lli x = A * CH;
          lli y = p3[AH] * p3[CH - 1];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
        // ?BC
        {
          lli x = AH * C;
          lli y = p3[AH - 1] * p3[CH];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
        // ABC
        {
          lli x = A * C;
          lli y = p3[AH] * p3[CH];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ", ";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    cout << bool(n % k) << endl;
  }
  
  return 0;
}
```
```cpp
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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ", ";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    bool f = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f = f || (i * 4 + j * 7) == n;
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  
  return 0;
}
```
```cpp
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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ", ";
  os << ")";
  return os;
}

void fn(lli n, int x) {
    vector<int> v(60, 0);
    for (int i = 0; i < v.size(); ++i) {
      if (n & (1LL << i)) v[i] = 1;
    }

    for (int i = 0; i < v.size(); ++i) {
      if (1 < v[i]) {
        v[i + 1] += v[i] / 2;
        v[i] %= 2;
      }
      if (i % 2 == x && v[i]) {
        v[i + 1] += v[i];
      }
    }

    while (1 < v.size() && v.back() == 0) v.pop_back();
    reverse(v.begin(), v.end());
    each (i, v) cout << i; cout << endl;

    return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    if (0 <= n) fn(n, 1);
    else fn(abs(n), 0);    
  }
  
  return 0;
}
```
```cpp
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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    map<lli, lli> cnt;
    lli x = 0;
    each (i, a) {
      x += i;
      x %= m;
      ++cnt[x];
    }
    lli sum = cnt[0];
    each (i, cnt) {
      sum += i.second * (i.second - 1) / 2;
    }
    cout << sum << endl;
  }

  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vector<int> v;
    for (int i = 0; i < 2 * n; ++i) {
      int m;
      cin >> m;
      v.push_back(m);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size(); i += 2) {
      sum += v[i];
    }
    cout << sum << endl;
  }
  return 0;
}
```
```cpp
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

lli f(lli n, lli x)
{
  lli sum = 0;
  sum += 3 * x * ((n - x) / x);
  lli y = ((n - x) % x);
  if (y) sum += f(x + y, y);
  return sum;
}

int main(int argc, char *argv[])
{
  lli n, x;
  while (cin >> n >> x) {
    cout << f(n, x) << endl;
  }
  return 0;
}
```
```cpp
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

const int N = 2000 + 10;
vector<int> g[N];

int diameter(const int root = 0)
{
  function<int(int)> bfs = [&] (int src) {
    queue<int> q;
    map<int, int> cost;
    cost[root] = 0;
    for (q.push(root); q.size(); q.pop()) {
      int curr = q.front();
      each (next, g[curr]) {
        if (!cost.count(next)) {
          cost[next] = cost[curr] + 1;
          q.push(next);
        }
      }
    }
    pair<int, int> x = *max_element(
      cost.begin(),
      cost.end(),
      [] (pair<int, int> a, pair<int, int> b) { return a.second < b.second; })
    ;
    return x.first;
  };
  return bfs(bfs(root));
}

set<int> reachable(int src, int k, int p = -1)
{
  set<int> vis;
  if (p != -1) vis.insert(p);
  function<void(int, int)> rec = [&] (int curr, int depth) {
    vis.insert(curr);
    each (next, g[curr]) {
      if (!vis.count(next) && depth) rec(next, depth - 1);
    }
    return ;
  };
  rec(src, k);
  return vis;
}

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    fill(g, g + N, vector<int>());
    vector<pair<int, int>> es;
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
      es.push_back(make_pair(a, b));
    }
    int mn = 1 << 29;
    if (k % 2) {
      each (e, es) {
        set<int> a = reachable(e.first, k / 2, e.second);
        set<int> b = reachable(e.second, k / 2, e.first);
        int m = n;
        for (int i = 0; i < n; ++i) {
          m -= a.count(i) | b.count(i);
        }
        mn = min<int>(mn, m);
      }
    } else {
      for (int i = 0; i < n; ++i) {
        set<int> x = reachable(i, k / 2);
        mn = min<int>(mn, n - x.size());
      }
    }
    cout << mn << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int a, b;
  while (cin >> a >> b) {
    if (0 < a) {
      cout << "Positive" << endl;
    } else if (a <= 0 && 0 <= b) {
      cout << "Zero" << endl;
    } else {
      if (a < 0 && (b - a) % 2 == 0) {
        cout << "Negative" << endl;
      } else {
        cout << "Positive" << endl;
      }
    }
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }

    const int N = 100000 + 10;
    bool  p[N];
    double q[N];
    fill(p, p + N, 0);
    fill(q, q + N, 1);
    p[1] = 1;

    each (i, v) {
      const int x = i.first;
      const int y = i.second;

      if (q[x] == 1) {
        p[y] |= p[x];
        p[x] = 0;
      } else {
        p[y] |= p[x];
      }
      --q[x];
      ++q[y];
    }

    // for (int i = 0; i <= n; ++i) {
    //   cout << i << ":" << p[i] << endl;
    // }
    
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (p[i]) ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n, l;
  while (cin >> n >> l) {
    vector<int> v;;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    int idx = -1;
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (l <= v[i] + v[i + 1]) {
        idx = i;
        break;
      }
    }

    if (idx == -1) {
      cout << "Impossible" << endl;
      continue;
    }

    cout << "Possible" << endl;
    for (int i = 0; i < idx; ++i) {
      cout << i + 1 << endl;
    }
    for (int i = n - 2; idx <= i; --i) {
      cout << i + 1 << endl;
    }
  }
  return 0;
}
```
```cpp
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
 
template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ',';
  os << ")";
  return os;
}
 
struct UnionFind {
  vector<int> r, p, s;
  UnionFind(int n)
  {
    r.resize(n, 1);
    s.resize(n, 1);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }
  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    int c = link(a, b);
    if (a != b) s[c] = (s[a] + s[b]);
  }
  int find(int a)
  {
    return (a == p[a]) ? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b)
  {
    return find(a) == find(b);
  }
  int link (int a, int b)
  {
    int c;
    if (r[a] > r[b]) {
      c = (p[b] = a);
    } else {
      c = (p[a] = b);
      if(r[a] == r[b]) r[b]++;
    }
    return c;
  }
  int size(int a)
  {
    return s[find(a)];
  }
};
 
int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      v.push_back(make_pair(a, b));
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int>> qs;
    for (int i = 0; i < q; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      --z;
      qs.push_back(make_tuple(x, y, z));
    }
 
    vector<int> small(q, 0);
    vector<int> large(q, m + 1);
    map<int, vector<int>> mid;
    for (int i = 0; i < q; ++i) {
      mid[(small[i] + large[i]) / 2].push_back(i);
    }
 
    auto f = [&] (void) {
      for (int i = 0; i < q; ++i) {
        if (small[i] + 1 < large[i]) return true;
      }
      return false;
    };
    
    while (f()) {
      UnionFind uf(n);
      map<int, vector<int>> next;
      for (int i = 0; i < m; ++i) {
        uf.unite(v[i].first, v[i].second);
        unless (mid.count(i + 1)) continue;
        each (q_idx, mid[i + 1]) {
          int x, y, z;
          tie(x, y, z) = qs[q_idx];
          const int size = uf.isSameSet(x, y) ? uf.size(x) : uf.size(x) + uf.size(y);
          if (size > z) {
            large[q_idx] = i + 1;
          } else {
            small[q_idx] = i + 1;
          }
          next[(small[q_idx] + large[q_idx]) / 2].push_back(q_idx);
        }
      }
      mid = move(next);
    }
 
    for (int i = 0; i < q; ++i) {
      cout << large[i] << endl;
    }
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  string s;
  while (cin >> s) {
    int n = 0;
    n += (bool)count(s.begin(), s.end(), 'N');
    n -= (bool)count(s.begin(), s.end(), 'S');
    int m = 0;
    m += (bool)count(s.begin(), s.end(), 'E');
    m -= (bool)count(s.begin(), s.end(), 'W');
    cout << (n == 0 && m == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
```
```cpp
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

lli g(vector<lli> v)
{
  lli cnt = 0;
  for (int i = 0; i + 1 < v.size(); ++i) {
    cnt += v[i] / 2;
    v[i] %= 2;
    int j = i + 1;
    int mn = min(v[i], v[j]);
    v[i] -= mn;
    v[j] -= mn;
    cnt += mn;
  }
  each (i, v) cnt += i / 2;
  return cnt;
}

lli f(vector<lli> v)
{
  vector<lli> u = v;
  reverse(u.begin(), u.end());
  return max(g(v), g(u));
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    lli sum = 0;
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 0 && v.size()) {
        sum += f(v);
        v.clear();
      } else {
        v.push_back(a);
      }
    }
    if (v.size()) sum += f(v);
    cout << sum << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    map<int, int> no;
    for (int i = 0; i < n; ++i) {
      no[b[i]] = i;
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(no[a[i]]);
    }

    int odd = 0;
    int even = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (i % 2 != v[i] % 2) {
        int& o = odd;
        int& e = even;
        (i % 2 ? o : e) += 1;
      }
    }
    assert(odd == even);
    cout << odd << endl;
  }
  return 0;
}
```
```cpp
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

lli f(lli a, lli b, lli c)
{
  lli n = a / 2;

  lli x = n * b * c;
  lli y = (a - n) * b * c;
  return labs(x - y);
}

int main(int argc, char *argv[])
{
  lli a, b, c;
  while (cin >> a >> b >> c) {
    lli mn = 1LL << 60;
    vector<lli> v = {a, b, c};
    sort(v.begin(), v.end());
    do {
      mn = min(mn, f(v[0], v[1], v[2]));
    } while (next_permutation(v.begin(), v.end()));
    cout << mn << endl;
  }
  return 0;
}
```
```cpp
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

const int N = 2000 + 10;
const lli inf = 1LL << 50;

int main(int argc, char *argv[])
{
  int n, x;
  while (cin >> n >> x) {
    lli a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    lli dp[n];
    for (int i = 0; i < n; ++i) {
      dp[i] = a[i];
    }

    lli mn = inf;
    for (lli ench = 0; ench <= 2 * n; ++ench) {
      for (int slime = 0; slime < n; ++slime) {
        const int i = (slime - ench + n * 10) % n;
        dp[slime] = min(dp[slime], a[i]);
      }
      mn = min(mn, accumulate(dp, dp + n, 0LL) + ench * x);
    }
    
    cout << mn << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lli n;
  while (cin >> n) {
    lli a[n];
    lli b[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    reverse(a, a + n);
    reverse(b, b + n);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      a[i] += sum;
      lli y = (a[i] / b[i]) + (bool)(a[i] % b[i]);
      lli x = y * b[i] - a[i];
      sum += x;
      a[i] += x;
      // cout << "x: " << x << endl;
    }
    // for (int i = 0; i < n; ++i) cout << a[i] << ' ' ; cout << endl;
    // for (int i = 0; i < n; ++i) cout << b[i] << ' ' ; cout << endl;
    cout << sum << endl;
  }
  return 0;
}
```
```cpp
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

const int N = 100000 + 10;
int a[N];
vector<int> g[N];

int rec(int curr)
{
  vector<int> v;
  each (next, g[curr]) {
    // cout << curr+1 << " -> " << next+1 << endl;
    v.push_back(rec(next) + 1);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int mx = -1;
  for (int i = 0; i < v.size(); ++i) {
    mx = max(mx, v[i] + i);
  }
  // cout << curr+1 << ": " ; each (i, v) cout << i+1 << ' '; cout << endl;
  return v.size() ? mx : 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 1; i < n; ++i) {
      int a;
      cin >> a;
      // cout << make_pair(a - 1 + 1, i + 1) << endl;
      g[a - 1].push_back(i);
    }
    cout << rec(0) << endl;
    // cout << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    int o = 0;
    int e = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a % 2 == 0) ++e;
      else ++o;
    }
    cout <<  ((o % 2 == 0) ? "YES" : "NO") << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  lli n;
  while (cin >> n) {
    lli a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    lli b[n];
    for (int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      b[i] = a[j] - a[i];
    }
    lli sum = accumulate(a, a + n, 0LL);
    lli m = (n + 1) * n / 2;
    bool f = true;
    f = f && (sum % m == 0);
    lli k = sum / m;
    for (int i = 0; i < n; ++i) {
      b[i] -= k;
    }
    for (int i = 0; i < n; ++i) {
      f = f && (b[i] <= 0) && (b[i] % n == 0);
    }
    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  while (cin >> m) {
    int n = m * 3;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    deque<int> q;
    for (int i = 0; i < n; ++i) {
      q.push_back(a[i]);
    }
    lli sum = 0;
    while (q.size()) {
      q.pop_back();
      sum += q.back();
      q.pop_back();
      q.pop_front();
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a % 2 || b % 2 || c % 2) {
      cout << 0 << endl;
      continue;
    }
    set<tuple<int, int, int>> vis;
    int cnt = 0;
    while (true) {
      tuple<int, int, int> t = make_tuple(a, b, c);
      // cout << a << ' ' << b << ' ' << c << endl;
      if (vis.count(t)) {
        cnt = -1;
        break;
      }
      vis.insert(t);
      int A = (b / 2) + (c / 2);
      int B = (a / 2) + (c / 2);
      int C = (a / 2) + (b / 2);
      a = A;
      b = B;
      c = C;
      ++cnt;
      if (a % 2 || b % 2 || c % 2) break;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    map<int, int> cnt;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      ++cnt[a];
      ++cnt[b];
    }
    bool f = true;
    each (i, cnt) f = f && (i.second % 2 == 0);
    cout << (f ? "YES" : "NO") << endl;
  }
  
  return 0;
}

```
```cpp
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

const int H = 800 + 10;
const int W = 800 + 10;

char g[H][W];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w, k;
  while (cin >> h >> w >> k) {
    pair<int, int> ini;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') ini = make_pair(i, j);
      }
    }

    const int inf = 1 << 29;
    static int cost[H][W];
    fill(&cost[0][0], &cost[H - 1][W - 1] + 1, inf);
    cost[ini.first][ini.second] = 0;
    queue<pair<int, int>> q;
    for (q.push(ini); q.size(); q.pop()) {
      const int i = q.front().first;
      const int j = q.front().second;
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      for (int d = 0; d < 4; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (cost[ni][nj] != inf) continue;
        if (g[ni][nj] == '#') continue;
        cost[ni][nj] = cost[i][j] + 1;
        q.push(make_pair(ni, nj));
      }
    }

    int mn = inf;
    
    for (int i = 0; i < h; ++i) {
      if (cost[i][0] < k || cost[i][w - 1] < k) mn = 1;
    }
    for (int j = 0; j < w; ++j) {
      if (cost[0][j] < k || cost[h - 1][j] < k) mn = 1;
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (cost[i][j] <= k) {
          int a = (h - i - 1 + k - 1) / k + 1;
          int b = (i + k - 1) / k + 1;
          int c = (j + k - 1) / k + 1;
          int d = (w - j - 1 + k - 1) / k + 1;
          mn = min({mn, a, b, c, d});
        }
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
```cpp
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

int f(string s, char c)
{
  if (count(s.begin(), s.end(), c) == 0)  return 1 << 29;
  int cnt = 0;
  while (count(s.begin(), s.end(), c) != s.size()) {
    string t(s.size() - 1, '@');
    for (int i = 0; i < t.size(); ++i) {
      t[i] = s[i];
      if (s[i + 1] == c) t[i] = c;
    }
    s = t;
    ++cnt;
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int mn = 1 << 29;
    for (char c = 'a'; c <= 'z'; ++c) {
      mn = min(mn, f(s, c));
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, p;
  while (cin >> n >> p) {
    vector<int> a(n);
    each (i, a) cin >> i;

    const int N = n + 1;
    lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, 0);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
      dp[i + 1][(0 + a[i]) % 2] += dp[i][0];
      dp[i + 1][(1 + a[i]) % 2] += dp[i][1];

      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
    }

    cout << dp[n][p] << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, a, b, c, d;
  while (cin >> n >> a >> b >> c >> d) {

    bool f = false;

    for (int i = 0; i < n - 1; ++i) {
      const lli s = a - i * c;
      const lli t = a - i * d;

      const lli p = b - (n - 1 - i) * c;
      const lli q = b - (n - 1 - i) * d;

      if (min(p, q) <= min(s, t) && min(s, t) <= max(p, q)) {
        f = true;
        break;
      }
      if (min(p, q) <= max(s, t) && max(s, t) <= max(p, q)) {
        f = true;
        break;
      }
    }

    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli q, h, s, d, n;
  while (cin >> q >> h >> s >> d >> n) {
    // q 0.25
    // h 0.5
    // s 1
    // d 2

    // q 1
    // h 2
    // s 4
    // d 8

    const lli inf = 1LL << 60;
    const int N = 10;
    lli dp[N];
    fill(dp, dp + N, inf);
    dp[0] = 0;

    vector<pair<int, int>> v;
    v.push_back(make_pair(1, q));
    v.push_back(make_pair(2, h));
    v.push_back(make_pair(4, s));
    v.push_back(make_pair(8, d));
    for (int i = 0; i < N; ++i) {
      each (j, v) {
        if (i + j.first < N) {
          dp[i + j.first] = min(dp[i + j.first], dp[i] + j.second);
        }
      }
    }

    lli sum = (n / 2) * dp[8];
    if (n % 2) sum += dp[4];
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
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

const int N = 2 * 100000 + 5;
int rad[N * 2];

int longest_palindrome(const char *text, int n)
{
  int i, j, k;
  for (i = 0, j = 0; i < 2*n; i += k, j = max(j-k, 0)) {
    while (i-j >= 0 && i+j+1 < 2*n && text[(i-j)/2] == text[(i+j+1)/2]) ++j;
    rad[i] = j;
    for (k = 1; i-k >= 0 && rad[i]-k >= 0 && rad[i-k] != rad[i]-k; ++k)
      rad[i+k] = min(rad[i-k], rad[i]-k);
  }
  return *max_element(rad, rad+2*n); // ret. centre of the longest palindrome
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    map<char, lli> cnt;
    each (c, s) ++cnt[c];
    const lli n = s.size();
    lli sum = n * (n - 1) / 2 + 1;
    each (i, cnt) sum -= i.second * (i.second - 1) / 2;
    cout << sum << endl;
  }
  
  return 0;
}


// (length "abracadabra") ; 11
// (/ (* 11 (- 11 1)) 2) ; 55
```
```cpp
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

int fn(string s)
{
  int sum = 0;
  each (c, s) sum += c - '0';
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int mx = fn(s);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') continue;
      string t = s;
      t[i] = t[i] - 1;
      fill(t.begin() + i + 1, t.end(), '9');
      mx = max(mx, fn(t));
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());

    map<pair<string, string>, lli> cnt1, cnt2;
    for (int bit = 0; bit < (1 << n); ++bit) {
      {
        string a, b;
        for (int i = 0; i < n; ++i) {
          if (bit & (1 << i)) {
            a += s[i];
          } else {
            b += s[i];
          }
        }
        reverse(b.begin(), b.end());
        ++cnt1[make_pair(a, b)];
      }
      {
        string a, b;
        for (int i = 0; i < n; ++i) {
          if (bit & (1 << i)) {
            a += s[n + i];
          } else {
            b += s[n + i];
          }
        }
        reverse(a.begin(), a.end());
        ++cnt2[make_pair(a, b)];
      }
    }
    lli sum = 0;
    each (i, cnt1) {
      sum += i.second * cnt2[i.first];
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{

  int x1, y1;
  int x2, x3;
  int y2, y3;
  int r;
  while (cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3) {
    bool blue = true;
    bool red = true;

    {
      vector<pair<int, int>> v;
      v.push_back(make_pair(x2, y2));
      v.push_back(make_pair(x2, y3));
      v.push_back(make_pair(x3, y2));
      v.push_back(make_pair(x3, y3));

      each (p, v) {
        double X = x1 - p.first;
        double Y = y1 - p.second;
        double dist = sqrt(X * X + Y * Y);
        blue = blue && dist <= r;
      }
    }
    {
      vector<pair<int, int>> v;
      v.push_back(make_pair(x1, y1 - r));
      v.push_back(make_pair(x1, y1 + r));
      v.push_back(make_pair(x1 - r, y1));
      v.push_back(make_pair(x1 + r, y1));
      each (p, v) {
        red = red && (x2 <= p.first) && (p.first <= x3) && (y2 <= p.second) && (p.second <= y3);
      }
    }

    cout << (!red ? "YES" : "NO") << endl;
    cout << (!blue ? "YES" : "NO") << endl;
  }
  return 0;
}
```
```cpp
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

int counter;
int gcd(int a, int b) {
  if (b == 0) return a;
  counter++;
  return gcd(b, a%b);
}
void f(int a, int b)
{
  counter = 0;
  gcd(a, b);
  printf("%d\n", counter);
  return ;
}

int main(int argc, char *argv[])
{
  int k;
  while (cin >> k) {
    if (k == 0) cout << "0 1" << endl;
    else {
      pair<int, int> p = make_pair(2, 1);
      while (--k) {
        p = make_pair(p.first + p.second, p.first);
      }
      cout << p.first << ' ' << p.second << endl;
    }
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    lli mn = 1LL << 60;
    for (int target = -100; target <= 100; ++target) {
      lli sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += (target - a[i]) * (target - a[i]);
      }
      mn = min(mn, sum);
    }
    cout << mn << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  string s;
  while (cin >> s) {
    pair<int, int> p = make_pair(-1, -1);
    if (s.size() == 2) {
      if (s[0] == s[1]) cout << 1 << ' ' << 2 << endl;
      else cout << -1 << ' ' << -1 << endl;
      continue;
    }
    for (int i = 0; i + 2 < s.size(); ++i) {
      set<char> t;
      t.insert(s[i]);
      t.insert(s[i + 1]);
      t.insert(s[i + 2]);
      if (t.size() <= 2) {
        p = make_pair(i + 1, i + 3);
      }
    }
    cout << p.first << ' ' << p.second << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n, a;
  while (cin >> n >> a) {
    int x[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }

    const int N = 53;
    const int SUM = N * 51;
    static lli dp[N][N][SUM];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][SUM - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < SUM; ++k) {
          unless (dp[i][j][k]) continue;
          // choose
          dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
          // ignore
          dp[i + 1][j][k] += dp[i][j][k];
        }
      }
    }
    
    lli s = 0;
    for (int card = 1; card < N; ++card) {
      for (int sum = 0; sum < SUM; ++sum) {
        if (sum % card == 0 && sum / card == a) {
          s += dp[n][card][sum];
        }
      }
    }

    cout << s << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  string s;
  while (cin >> s) {
    lli sum = 0;
    for (int bit = 0; bit < (1 << (s.size() - 1)); ++bit) {
      vector<string> v;
      string t;
      for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        if (bit & (1 << i)) {
          v.push_back(t);
          t = "";
        }
      }
      v.push_back(t);
      // each (s, v) cout << s << ","; cout << endl;
      each (s, v) sum += atol(s.c_str());
    }
    cout << sum << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  lli h, w, n;
  while (cin >> h >> w >> n) {
    map<int, lli> cnt;
    set<pair<int, int>> s;
    s.clear();
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      s.insert(make_pair(a - 1, b - 1));
    }

    vector<pair<int, int>> v;
    each (p, s) {
      for (int i = -2; i < 3; ++i) {
        for (int j = -2; j < 3; ++j) {
          int I = p.first + i;
          int J = p.second + j;
          unless (0 <= I && I + 2 < h) continue;
          unless (0 <= J && J + 2 < w) continue;
          v.push_back(make_pair(I, J));
        }
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
   
    each (p, v) {
      int x = 0;
      for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
          x += s.count(make_pair(p.first + i, p.second + j));
        }
      }
      ++cnt[x];
    }


    lli sum = 0;
    for (int i = 1; i <= 9; ++i) {
      sum += cnt[i];
    }

    cnt[0] = (h - 2LL) * (w - 2LL) - sum;
    for (int i = 0; i <= 9; ++i) {
      cout << cnt[i] << endl;
    }
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  string s;
  while (cin >> s) {
    int cnt = 0;
    for (int i = 0; i + 1 < s.size(); ++i) {
      cnt += (s[i] != s[i + 1]);
    }
    cout << cnt << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n, t;
  while (cin >> n >> t) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int mx[n];
    mx[n - 1] = a[n - 1];
    for (int i = n - 2; 0 <= i; --i) {
      mx[i] = max(mx[i + 1], a[i]);
    }

    // for (int i = 0; i < n; ++i) cout << mx[i] << ' ';cout << endl;
    
    int cnt = 0;
    int m = 0;
    for (int i = 0; i + 1 < n; ++i) {
      int x = mx[i + 1] - a[i];
      if (m < x) {
        cnt = 0;
        m = x;
      }
      if (m == x) {
        ++cnt;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
```
```cpp
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

int solve(int n)
{
  const lli mod = 1000000000 + 7;
  lli m = 1;
  for (int i = 0; i < n / 2; ++i) {
    m *= 2;
    m %= mod;
  }
  return m;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i]];
    }
    bool f = true;
    if (n % 2) {
      int x = 2;
      for (int i = 0; i < n / 2; ++i) {
        f = (cnt[x] == 2);
        x += 2;
      }
      f = (cnt[0] == 1);
    } else {
      int x = 1;
      for (int i = 0; i < n / 2; ++i) {
        f = (cnt[x] == 2);
        x += 2;
      }      
    }
    printf("%d\n", f ? solve(n) : 0);
  }
  
  return 0;
}
```
```cpp
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

lli f(int a[], const int N, int mod)
{
  lli sum = 0;
  lli cost = 0;

  for (int i = 0; i < N; ++i) {
    sum += a[i];
    if (i % 2 == mod) {
      if (sum < 1) {
        cost += abs(sum) + 1;
        sum = 1;
      }
    } else {
      if (-1 < sum) {
        cost += abs(sum) + 1;
        sum = -1;
      }
    }
  }
  
  return cost;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << min(f(a, n, 0), f(a, n, 1)) << endl;
  }
  return 0;
}
```
```cpp
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

void trial(void)
{
  const int LOSE = 0;
  const int WIN = 1;
  const int YET = 2;
  
  const int N = 40;
  int memo[N][N];
  function<int(int, int)> rec = [&] (int x, int y)
  {
    int& ret = memo[x][y];
    if (ret != YET) return ret;
    int best = LOSE;
    for (int i = 1; 2 * i <= x; ++i) {
      best = max(best, rec(x - 2 * i, y + i) ^ 1);
    }
    for (int i = 1; 2 * i <= y; ++i) {
      best = max(best, rec(x + i, y - 2 * i) ^ 1);
    }
    return ret = best;
  };

  for (int x = 0; x < N / 2; ++x) {
    for (int y = 0; y < N / 2; ++y) {
      fill(&memo[0][0], &memo[N - 1][N - 1] + 1, YET);
      // cout << make_pair(x, y) << ", " << rec(x, y) << endl;
      cout << rec(x, y) << " ";
    }
    cout << endl;
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // trial(); return 0;
  
  lli x, y;
  while (cin >> x >> y) {
    cout << (abs(x - y) <= 1 ? "Brown" : "Alice") << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v) cin >> i;

    const int N = 100 * 100 + 1;
    bool dp[N];
    fill(dp, dp + N, false);
    dp[0] = true;

    each (i, v) {
      for (int j = N - 1; 0 <= j; --j) {
        if (dp[j]) {
          dp[j + i] = true;
        }
      }
    }
    
    lli mx = 0;
    for (int i = 0; i < N; ++i) {
      if (i % 10 && dp[i]) mx = i;
    }
    cout << mx << endl;
  }
  
  return 0;
}
```
```cpp
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

bool f(vector<lli> v, lli a, lli b, lli x)
{
  each (i, v) i = max<lli>(0, i - b * x);
  const lli c = a - b;
  each (i, v) x -= (i / c) + (bool)(i % c);
  return 0 <= x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, a, b;
  while (cin >> n >> a >> b) {
    vector<lli> v(n);
    each (i, v) cin >> i;

    auto g = [&] (lli x) { return f(v, a, b, x); };
    
    lli small = 0;
    lli large = 1e9 + 100;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (g(mid)) large = mid;
      else small = mid;
    }
    cout << (g(small) ? small : large) << endl;
  }
  
  return 0;
}
```
```cpp
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

template<typename V>
class BIT {
public:
  vector<V> bit;
  int n;
  BIT (int n_)
  {
    n = n_;
    bit.resize(n + 1);
  }
  V sum(int i)
  {
    ++i; // 1-origin
    V s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, V x)
  {
    ++i; // 1-origin
    while (i <= n)
    {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
  void set(int i, V x)
  {
    return add(i, x - bit[i]);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    each (i, a) i-= k;

    vector<lli> acc(n);
    acc[0] = a[0];
    for (int i = 1; i < n; ++i) {
      acc[i] = acc[i - 1] + a[i];
    }

    vector<pair<lli, int>> v;
    v.push_back(make_pair(0, 0));
    each (i, acc) {
      v.push_back(make_pair(i, v.size()));
    }
    stable_sort(v.begin(), v.end());

    lli sum = 0;
    BIT<lli> bit(v.size());
    each (i, v) {
      sum += bit.sum(i.second);
      bit.add(i.second, 1);
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
#include <algorithm>
#include <list>
#include <iostream>
#include <vector>
 
#define unless(cond) if (!(cond))
 
using namespace std;
 
typedef long long int lli;
typedef unsigned long long ull;
 
int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    list<int> x;
    for (int i = 0; i < n; ++i) {
      if (x.size() % 2) x.push_front(a[i]);
      else x.push_back(a[i]);
    }
    if (n % 2) reverse(x.begin(), x.end());
    bool f = false;
    for (auto i = x.begin(); i != x.end(); ++i) {
      if (f) cout << ' ';
      f = true;
      cout << *i;
    }
    cout << endl;
  }
  
  return 0;
}
```
```cpp
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

lli extgcd(lli a, lli b, lli& x, lli& y)
{
  lli g = a;
  x = 1;
  y = 0;
  if (b != 0) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return g;
}

lli mod_inverse(lli a, lli m)
{
  lli x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

constexpr lli mod = 1e9 + 7;
constexpr int N = min<lli>(mod, 100000 + 5);
lli fact[N]; // P.263

template<typename T, typename U>
T mod_fact(T n, U p, U &e)
{
  e = 0;
  if (n == 0) return 1;

  T res = mod_fact(n / p, p, e);
  e += n / p;
  if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
  return res * fact[n % p] % p;
}

// nCk mod P O(n log p )
lli mod_comb(lli n, lli k, lli p = mod)
{
  if (n < 0 || k < 0 || n < k) {
    return 0;
  }
  lli e1, e2, e3;
  lli a1 = mod_fact(n, p, e1);
  lli a2 = mod_fact(k, p, e2);
  lli a3 = mod_fact(n - k, p, e3);
  if (e1 > e2 + e3) {
    return 0;
  }
  return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }

  lli n;
  while (cin >> n) {
    ++n;
    vector<int> a(n);
    each (i, a) cin >> i;
    int mn = 0;
    int mx = 0;
    {
      map<int, int> idx;
      for (int i = 0; i < a.size(); ++i) {
        if (idx.count(a[i])) {
          mn = idx[a[i]];
          mx = i;
          break;
        }
        idx[a[i]] = i;
      }
    }

    const int x = mn;
    const int y = mx - mn - 1;
    const int z = n - 2 - x - y;

    cout << n - 1 << endl;
    for (int i = 2; i <= n; ++i) {
      lli m = mod_comb(n, i);
      if (0 < x + z && i - 1 <= x + z) {
        m = (m - mod_comb(x + z, i - 1) + mod) % mod;
      }
      cout << m << endl;
    }
    cout << endl;
  }

  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n, m;
  while (cin >> n >> m) {
    set<int> x, y;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      if (a == 1) x.insert(b);
      if (b == n) y.insert(a);
    }
    bool f = false;
    for (int i = 1; i <= n; ++i) {
      f = f || (x.count(i) && y.count(i));
    }
    cout << (f ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;
    lli sum = 0;
    while (true) {
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());
      lli x = a[0] / a.size();
      if (x == 0) break;
      sum += x;
      a[0] %= a.size();
      for (int i = 1; i < a.size(); ++i) {
        a[i] += x;
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    double p = 1.0;
    for (int i = 0; i < m; ++i) {
      p /= 2.0;
    }
    const double q = p;
    double x = 0;
    const double a = (n - m) * 100.0;
    const double b = m * 1900.0;
    for (int i = 1; i <= 10000; ++i) {
      x += i * p * (a + b);
      p = p * (1.0 - q);
    }
    printf("%.0lf\n", x);
  }
  
  return 0;
}
```
```cpp
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

const int N = 2000 + 10;
int n;

vector<lli> a1;
lli memo1[N];

lli rec2(int other) ;

lli rec1(int other)
{
  if (other == a1.size() - 1) {
    return +(1LL << 60);
  }

  lli& ret = memo1[other];
  if (ret != -1) return ret;

  lli best = labs(a1[other] - a1.back());
  for (int i = other + 1; i < a1.size(); ++i) {
    best = max(best, rec2(i));
  }

  return ret = best;
}

vector<lli> a2;
lli memo2[N];

lli rec2(int other)
{
  if (other == a2.size() - 1) {
    return -(1LL << 60);
  }

  lli& ret = memo2[other];
  if (ret != -1) return ret;

  lli best = labs(a2[other] - a2.back());
  for (int i = other + 1; i < a1.size(); ++i) {
    best = min(best, rec1(i));
  }

  return ret = best;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli z, w;
  while (cin >> n >> z >> w) {
    fill(memo1, memo1 + N, -1);
    fill(memo2, memo2 + N, -1);
    a1.resize(n + 1);
    a2.resize(n + 1);
    a1[0] = w;
    a2[0] = z;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      a1[i + 1] = a2[i + 1] = a;
    }
    cout << rec1(0) << endl;
  }

  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++cnt[x];
    }
    vector<pair<int, int>> v;
    each (i, cnt) v.push_back(make_pair(i.second, i.first));
    sort(v.begin(), v.end());
    lli sum = 0;
    for (int i = 0; i + k < v.size(); ++i) {
      sum += v[i].first;
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;


    int idx = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (abs(a[idx]) < abs(a[i])) {
        idx = i;
      }
    }

    vector<pair<int, int>> v;
    if (0 == a[idx]) {
    } else if (0 < a[idx]) {
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] < 0) {
          a[i] += a[idx];
          v.push_back(make_pair(idx, i));
        }
      }
      for (int i = 0; i + 1 < a.size(); ++i) {
        v.push_back(make_pair(i, i + 1));
      }
    } else {
      for (int i = 0; i < a.size(); ++i) {
        if (0 < a[i]) {
          a[i] += a[idx];
          v.push_back(make_pair(idx, i));
        }
      }
      for (int i = a.size() - 1; 0 <= i - 1; --i) {
        v.push_back(make_pair(i, i - 1));
      }      
    }

    cout << v.size() << endl;
    each (i, v) cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }
  
  return 0;
}
```
```cpp
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

struct edge {
  int to, cap, rev;
};

const int N = 200 + 10;
vector<int> g[N];

void add_edge(int src, int dst)
{
  g[src].push_back(dst);
  g[dst].push_back(src);
  return ;
}

int match[N];
int vis[N], x;
bool rec(int curr)
{
  vis[curr] = x;
  each (next, g[curr]) {
    int w = match[next];
    if (w < 0 || (vis[w] != x && rec(w))) {
      match[curr] = next;
      match[next] = curr;
      return true;
    }
  }
  return false;
}

int matching(int n = N)
{
  int res = 0;
  fill(match, match + N, -1);
  x = 1;
  fill(vis, vis + N, 0);
  for (int i = 0; i < n; ++i) {
    if (match[i] < 0) {
      res += rec(i);
      ++x;
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());

    pair<int, int> b[n];
    pair<int, int> r[n];
    for (int i = 0; i < n; ++i) {
      cin >> r[i].first >> r[i].second;
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i].first >> b[i].second;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (r[i].first < b[j].first && r[i].second < b[j].second) {
          add_edge(i, j + n);
        }
      }
    }
    cout << matching() << endl;
  }

  return 0;
}
```
```cpp
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

struct Acc {
  vector<int> sum;
  Acc(vector<int> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  int query(int begin, int end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  while (cin >> n >> s) {
    vector<int> ve;
    vector<int> vw;
    each (c, s) {
      ve.push_back(c == 'E');
      vw.push_back(c == 'W');
    }
    
    Acc e(ve);
    Acc w(vw);

    int mn = 1 << 29;
    for (int i = 0; i < s.size(); ++i) {
      mn = min(mn, w.query(0, i) + e.query(i + 1, s.size()));
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;

    int bit = 0;

    int begin = 0;
    int end = 0;

    lli sum = 0;
    while (begin <= end) {
      while (end < n) {
        if (bit & a[end]) break;
        bit |= a[end];
        ++end;
      }

      sum += end - begin;
      bit ^= a[begin];
      ++begin;
    }

    cout << sum << endl;
  }

  return 0;
}
```
```cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    each (i, a) cin >> i;

    int sum = 0;
    sum += (n - 1) / (k - 1);
    if ((n - 1) % (k - 1)) ++sum;
    cout << sum << endl;
   }
  
  return 0;
}
```
```cpp
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

lli fn(vector<lli> a, lli b)
{
  lli sum = 0;
  for (int i = 0; i < a.size(); ++i) {
    sum += abs(a[i] - (b + i));
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    each (i, a) cin >> i;


    lli large = 1e9 + 10;
    lli small = -large;
    lli right, left;
    for (int loop = 1000; loop--; ) {
      left = (large - small) / 3.0 + small;
      right = (large - small) * 2.0 / 3.0 + small;
      
      lli dl = fn(a, left);
      lli dr = fn(a, right);
      
      if (dr < dl) small = left;
      else large = right;      
    }

    lli x = fn(a, small);
    lli y = fn(a, small + 1);
    lli z = fn(a, large);
    cout << min({x, y, z}) << endl;
  }
  
  return 0;
}
```
```cpp
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

template<typename T>
struct Acc {
  vector<T> v;
  Acc() {
    v.push_back(0);
  }
  // returns sum of (begin, end]
  T query(int begin, int end) {
    return v[end] - v[begin];
  }
  void append(T x) {
    v.push_back(v.back() + x);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    each (i, v) cin >> i;

    Acc<lli> a;
    each (i, v) a.append(i);

    const lli inf = 1LL << 60;
    auto fn = [&] (int i, int j, int k) {
      unless (i < j) return inf;
      unless (j < k) return inf;
      lli x = max({a.query(0, i), a.query(i, j), a.query(j, k), a.query(k, n)});
      lli y = min({a.query(0, i), a.query(i, j), a.query(j, k), a.query(k, n)});
      return x - y;
    };

    lli mn = inf;
    int i = 1;
    int k = 3;
    for (int j = 2; j < n - 1; ++j) {
      while (i + 1 < j) {
        lli x = abs(a.query(0, i + 0) - a.query(i + 0, j));
        lli y = abs(a.query(0, i + 1) - a.query(i + 1, j));
        if (x > y) ++i;
        else break;
      }
      k = max(k, j + 1);
      while (k + 1 < n) {
        lli x = abs(a.query(j, k + 0) - a.query(k + 0, n));
        lli y = abs(a.query(j, k + 1) - a.query(k + 1, n));
        if (x > y) ++k;
        else break;
      }
      mn = min(mn, fn(i, j, k));
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
```cpp
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

class PersistentUnionFind {
public:
  PersistentUnionFind(int n)
  {
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent.push_back(make_pair(i, 1 << 29));
    }
  }
  inline int find(int n)
  {
    return find(n, version);
  }
  inline int find(int n, int t)
  {
    if (parent[n].second <= t) {
      return find(parent[n].first, t);
    } else {
      return n;
    }
  }
  inline void unite(int a, int b)
  {
    a = find(a, version);
    b = find(b, version);
    ++version;
    if (a == b) return ;
    if (rank[a] > rank[b]) {
      parent[b] = make_pair(a, version);
    } else {
      parent[a] = make_pair(b, version);
      rank[b] += (rank[a] == rank[b]);
    }
  }
  inline bool isSameSet(int a, int b)
  {
      return isSameSet(a, b, version);
  }
  inline bool isSameSet(int a, int b, int t)
  {
      return find(a, t) == find(b, t);
  }
  int version = 0;
  vector<int> rank;
  vector<pair<int, int>> parent;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while (cin >> n >> m && n) {
    PersistentUnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      uf.unite(a, b);
    }

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      if (!uf.isSameSet(a, b)) {
        cout << -1 << endl;
        continue;
      }
      int small = 0;
      int large = uf.version + 1;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (uf.isSameSet(a, b, mid)) large = mid;
        else small = mid;
      }
      cout << large << endl;
    }
  }
  
  return 0;
}
```
