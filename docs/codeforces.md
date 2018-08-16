# Codeforces

## Codes
```gitignore
a.out
*~
input
output
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
    int m[n];
    for (int i = 0; i < n; ++i) {
      cin >> m[i];
    }
    for (int i = 0; i < n; ++i) {
      int cnt = 1;
      for (int j = 0; j < n; ++j) {
        cnt += (m[i] < m[j]);
      }
      if (i) cout << ' ';
      cout << cnt;
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
  string a, b, c;
  while (cin >> a >> b >> c) {
    map<char, int> A, B, C;
    for (char d = 'a'; d <= 'z'; ++d) {
      A[d] = count(a.begin(), a.end(), d);
      B[d] = count(b.begin(), b.end(), d);
      C[d] = count(c.begin(), c.end(), d);
    }
    const map<char, int> A_ = A;
    const map<char, int> B_ = B;
    const map<char, int> C_ = C;
    int mx = 0;
    pair<int, int> p;
    for (int i = 0; b.size() * i <= a.size(); ++i) {
      A = A_;
      B = B_;
      C = C_;
      const int inf = 1 << 28;
      int j = inf;
      for (char d = 'a'; d <= 'z'; ++d) {
        A[d] -= B[d] * i;
        if (A[d] < 0) { j = -1; break; }        
        if (C[d]) j = min(j, A[d] / C[d]);
      }
      if (j < 0) continue;
      if (j == inf) j = 0;
      if (i + j > mx) {
        mx = i + j;
        p = make_pair(i, j);
      }
    }
    A = A_;
    B = B_;
    C = C_;

    if (mx) {
      for (int i = 0; i < p.first; ++i) {
        cout << b;
      }
      for (int i = 0; i < p.second; ++i) {
        cout << c;
      }
      for (char d = 'a'; d <= 'z'; ++d) {
        A[d] -= (B[d] * p.first) + (C[d] * p.second);
        cout << string(A[d], d);
      }
      cout << endl;
    } else {
      cout << a << endl;
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

const int N = 100000 + 100;
lli p[N];
lli q[N];

bool f(lli turn)
{
  
}

int main(int argc, char *argv[])
{
  lli n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    lli small = 1;
    lli large = 1LL << 60;
    while (small < large) {
      lli mid = (small + large) / 2;
      if (f(mid)) small = mid;
      else large = mid;
    }
    cout << (f(large) ? large : small) << endl;
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
  int n, k;
  while (cin >> n >> k) {
    int a = 0;
    int b = 0;

    vector< vector<int> > v;
    for (int i = 0; i < k; ++i) {
      int m;
      cin >> m;
      vector<int> u(m);
      for (int j = 0; j < m; ++j) {
        cin >> u[j];
      }
      v.push_back(u);
    }


    for (int i = 0; i < v.size(); ++i) {
      if (v[i].front() == 1) {
        for (int j = 0; j < v[i].size(); ++j) {
          if (v[i][j] + 1 != v[i][j + 1]) {
            while (v[i].back() != v[i][j]) {
              v.push_back(vector<int>(1, v[i].back()));
              v[i].pop_back();
              ++a;
            }
            break;
          }
        }
      } else {
        for (int j = 0; j < v[i].size(); ++j) {
          if (v[i][j] + 1 != v[i][j + 1]) {
            while (1 < v[i].size()) {
              v.push_back(vector<int>(1, v[i].back()));
              v[i].pop_back();
              ++a;
            }
            break;
          }
        }
      }
    }

    // cout << endl;
    // each (i, v) {
    //   each (j, i) {
    //     cout << j << ' ';
    //   }
    //   cout << endl;
    // }

    b = v.size() - 1;
    cout << a + b << endl;
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
    vector<pair<lli, lli>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first >> v[i].second;
    }
    priority_queue<tuple<lli, lli, int>,
                   vector<tuple<lli, lli, int>>,
                   greater<tuple<lli, lli, int>>> p;
    for (int i = 0; i + 1 < n; ++i) {
      p.push(make_tuple(v[i + 1].first - v[i].second,
                        v[i + 1].second - v[i].first,
                        i + 1));
    }
    priority_queue<pair<lli, int>,
                   vector<pair<lli, int>>,
                   greater<pair<lli, int>>> q;
    for (int i = 0; i < m; ++i) {
      lli n;
      cin >> n;
      q.push(make_pair(n, i + 1));
    }
    int match[n + 1];
    while (p.size()) {
      cout << q.top() << endl;
      cout << "(" << get<0>(p.top()) << ' ' << get<1>(p.top())  << ' ' << get<2>(p.top()) << ")" << endl;
      cout << endl;
      if (get<0>(p.top()) <= q.top().first && q.top().first <= get<1>(p.top())) {
        match[get<2>(p.top())] = q.top().second;
        p.pop();
        q.pop();
      } else {
        break;
      }
    }
    cout << (p.empty() ? "Yes" : "No") << endl;
    if (p.empty()) {
      for (int i = 1; i < n; ++i) {
        if (i - 1) cout << ' ';
        cout << match[i] ;
      }
      cout << endl;
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
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      if (x > 0) a.push_back(make_pair(x, y));
      else b.push_back(make_pair(x, y));
    }
    const int mn = min(a.size(), b.size());
    a.push_back(make_pair(1 << 29, 0));
    b.push_back(make_pair(-(1 << 29), 0));
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(), b.end());
    int sum = 0;
    for (int i = 0; i < mn; ++i) {
      //      cout << a[i] << ' ' << b[i] << endl;
      sum += a[i].second + b[i].second;
    }
    sum += max(a[mn].second, b[mn].second);
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
    const int N = 1000000 + 10;
    static int cnt[N];
    static int mn[N];
    static int mx[N];
    const int inf = 1 << 29;
    fill(cnt, cnt + N, 0);
    fill(mn, mn + N, inf);
    fill(mx, mx + N, -inf);
    int best = -1;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      mn[m] = min(mn[m], i);
      mx[m] = max(mx[m], i);
      ++cnt[m];
      if (i == 0) best = m;
    }
    for (int i = 0; i < N; ++i) {
      if (cnt[i] == 0) continue;
      if (cnt[best] < cnt[i])  {
        best = i;
      }
      if (cnt[best] == cnt[i] && (mx[best] - mn[best]) > (mx[i] - mn[i])) {
        best = i;
      }
    }
    cout << mn[best] + 1 << ' ' << mx[best] + 1 << endl;
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

string common_prefix(string a, string b)
{
  string c;
  for (int i = 0; i < min(a.size(), b.size()); ++i) {
    if (a[i] == b[i]) c += a[i];
  }
  return c;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vector<string> v;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      string s;
      while (m) {
        s += '0' + (m % 2);
        m /= 2;
      }
      reverse(s.begin(), s.end());
      v.push_back(s);
    }
    string s = v[0];
    for (int i = 1; i < v.size(); ++i) {
      s = common_prefix(s, v[i]);
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
    vector<pair<int, int>> p;
    for (int i = 0; i < n * n; ++i) {
      pair<int, int> a;
      // cin >> a.first >> a.second;
      scanf("%d %d", &a.first, &a.second);
      --a.first;
      --a.second;
      p.push_back(a);
    }
    set<int> vis_h;
    set<int> vis_w;
    vector<int> v;
    for (int k = 0; k < n * n; ++k) {
      for (int d = 0; d < 4; ++d) {
        const int i = p[k].first;
        const int j = p[k].second;
        if (vis_h.count(i) == 0 && vis_w.count(j) == 0) {
          vis_h.insert(i);
          vis_w.insert(j);
          v.push_back(k + 1);
        }
      }
    }
    for (int i = 0; i < v.size(); ++i) {
      if (i) printf(" ");
      printf("%d", v[i]);
    }
    puts("");
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
  while(scanf("%d", &n) == 1) {
    int a[n];
    bool vis[n];
    for (int i = 0; i < n; ++i) {
      vis[i] = false;
      scanf("%d", a + i);
    }

    int cnt = -1;
    int collected = 0;
    while (collected < n) {
      ++cnt;
      if (cnt % 2) {
        for (int i = n - 1; 0 <= i; --i) {
          if (vis[i]) continue;
          if (a[i] <= collected) {
            vis[i] = true;
            ++collected;
          }
        }
      } else {
        for (int i = 0; i < n; ++i) {
          if (vis[i]) continue;
          if (a[i] <= collected) {
            vis[i] = true;
            ++collected;
          }
        }
      }
    }
    printf("%d\n", cnt);
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
    const int m = n * n;
    multiset<int, greater<int>> s;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      s.insert(x);
    }

    vector<int> v;
    while (s.size()) {
      const int x = *s.begin();
      s.erase(s.begin());
      each (y, v) {
        auto itr1 = s.find(__gcd(x, y));
        if (itr1 == s.end()) continue;
        auto itr2 = itr1;
        advance(itr2, 1);
        s.erase(itr2);
        s.erase(itr1);
      }
      v.push_back(x);
    }

    for (int i = 0; i < v.size(); ++i) {
      if (i) cout << ' ';
      cout << v[i];
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

  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (count(a, a + n, 0) == n) {
      cout << 0 << endl;
      continue;
    }
    int h = 0;
    while (a[n-1] == 0) --n;
    {
      int i;
      for (i = 0; i < n; ++i) {
        if (a[i]) break;
      }
      for (; i < n; ++i) {
        if (i + 1 < n && a[i] == 0 && a[i + 1] == 0) ;
        else if (i && a[i] == 0 && a[i - 1] == 0) ;
        else ++h;
      }
    }
    cout << h << endl;

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
    int a1[n];
    int a2[n];
    int b[n];
    for (int i = 0; i < n - 1; ++i) {
      cin >> a1[i];
    }
    for (int i = 0; i < n - 1; ++i) {
      cin >> a2[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }


    int acc1[n];
    int acc2[n];

    fill(acc1, acc1 + n, 0);
    fill(acc2, acc2 + n, 0);

    for (int i = 1; i < n; ++i) {
      acc1[i] += acc1[i - 1] + a1[i - 1];
    }


    for (int i = n - 2; 0 <= i; --i) {
      acc2[i] += acc2[i + 1] + a2[i];
    }

    // for (int i = 0; i < n; ++i) cout << acc1[i] << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << acc2[i] << ' '; cout << endl;

    int mn = 1 << 29;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        const int x = acc1[i] + b[i] + acc2[i];
        const int y = acc1[j] + b[j] + acc2[j];
        const int cost = x + y;
        mn = min(mn, cost);
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
  int n;
  while (cin >> n) {
    lli sum = 0;
    lli best = 1 << 29;
    for (int i = 0; i < n; ++i) {
      lli a, p;
      cin >> a >> p;
      best = min(best, p);
      sum += best * a;
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
  const int P = 1000010;
  bool p[P];
  fill(p, p + P, true);
  p[0] = p[1] = false;
  for (int i = 2; i * i < P; ++i) {
    for (int j = 2; i * j <  P; ++j) {
      p[i * j] = false;
    }
  }

  vector<int> v;
  for (int i = 0; i < P; ++i) {
    if (p[i]) v.push_back(i);
  }

  lli n;
  while (cin >> n) {
    map<lli, int> cnt;
    lli m = n;
    each (i, v) {
      if (m % i == 0) {
        while (m % i == 0) {
          ++cnt[i];
          m /= i;
        }
      }
    }
    if (m != 1) ++cnt[m];
    lli x = 1;
    each (i, cnt) {
      x *= i.first;
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
  const int N = 50000000 + 10;
  int w[N];
  int n;
  while (scanf("%d", &n) == 1 && n) {
    fill(w, w + N, 0);
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      ++w[m];
    }
    int carry = 0;
    for (int i = 0; i < N; ++i) {
      w[i] += carry;
      carry = w[i] / 2;
      w[i] %= 2;
    }
    printf("%d\n", accumulate(w, w + N, 0));
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

vector<>

int main(int argc, char *argv[])
{
  
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
vector<int> c[N];

namespace LCA {
  const int NODE = 100000 + 10;
  const int DEPTH = 18;

  int doubling[NODE][DEPTH], parent[NODE], level[NODE];

  int addLevel(int node)
  {
    return (level[node] != -1) ? level[node] : (level[node] = addLevel(parent[node]) + 1);
  }

  vector<int> C[NODE][DEPTH];
  
  void fn(vector<int>& a, vector<int>& b)
  {
    // cout << "("; each (i, a) cout << i << ", "; cout << ")"; cout << "  +  ";
    // cout << "("; each (i, b) cout << i << ", "; cout << ")"; cout << " = ";
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    while (10 < a.size()) a.pop_back();
    // cout << "("; each (i, a) cout << i << ", "; cout << ")"; cout << endl;
    return ;
  }  

  void build(const int &node, const int root = 0)
  {
    fill(&C[0][0], &C[NODE - 1][DEPTH - 1] + 1, vector<int>());
    
    fill(level, level + node, -1);
    level[root] = 0;
    for (int i = 0; i < node; ++i) {
      level[i] = addLevel(i);
    }

    fill(&doubling[0][0], &doubling[NODE - 1][DEPTH], -1);
    for (int i = 0; i < node; ++i) {
      doubling[i][0] = parent[i];
      // fn(C[i][0], c[parent[i]]);
      fn(C[i][0], c[i]);
    }
    for(int j = 1; (1 << j) < node; ++j){
      for (int i = 0; i < node; ++i) {
        const int p = doubling[i][j - 1];
        if (p != -1) {
          doubling[i][j] = doubling[p][j - 1];
          fn(C[i][j], C[p][j - 1]);
          fn(C[i][j], C[i][j - 1]);
        }
      }
    }
    

    // for(int j = 0; (1 << j) < node; ++j){
    //   for (int i = 0; i < node; ++i) {
    //     if (C[i][j].empty()) continue;
    //     cout << i+1 << "-th, 2^" << j << endl;
    //     each (k, C[i][j]) cout << k << ' ';
    //     cout << endl;
    //   }
    // }
   

    return ;
  }
  
  vector<int> query(int a, int b)
  {
    // cout << string(50, '#') << endl;
    
    vector<int> v;
    if (level[a] < level[b]) swap(a, b);

    int lg = 1;
    while ((1 << lg) <= level[a]) ++lg;
    --lg;
    
    fn(v, c[a]);
    fn(v, c[b]);
    
    // cout << ">> " << a+1 << ' ' << b+1 << endl;
    
    for (int i = lg; 0 <= i; --i) {
      if (level[a] - (1 << i) >= level[b]) {
        fn(v, C[a][i]);
        a = doubling[a][i];
      }
    }
    
    // cout << ">> " << a+1 << ' ' << b+1 << endl;
    // cout << "ini : " ;each (i, v) cout << i << ' ' ; cout << endl;
    
    if (a == b) return v;
    for (int i = lg; 0 <= i; --i) {
      if (doubling[a][i] != -1 && doubling[a][i] != doubling[b][i]) {
        a = doubling[a][i];
        b = doubling[b][i];
        fn(v, C[a][i]);
        fn(v, C[b][i]);
      }
    }
    fn(v, c[parent[a]]);
    // return parent[a];
    return v;
  }
};

int main(int argc, char *argv[])
{
  int n, m, q;
  while (scanf("%d%d%d", &n, &m, &q) == 3) {
    vector<int> g[N];
    fill(c, c + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    fill(c, c + N, vector<int>());
    for (int i = 0; i < m; ++i) {
      int a;
      scanf("%d", &a);
      c[a - 1].push_back(i + 1);
    }
    
    for (int i = 0; i < N; ++i) {
      sort(c[i].begin(), c[i].end());
      while (10 < c[i].size()) c[i].pop_back();
    }

    // for (int i = 0; i < n; ++i) {
    //   cout << i+1 << ": ";
    //   each (j, c[i]) cout << j << ' ' ;
    //   cout << endl;
    // }

    function<void(int, int)> fn = [&] (int curr, int prev) {
      LCA::parent[curr] = prev;
      each (next, g[curr]) {
        if (next != prev) fn(next, curr);
      }
      return ;
    };
    const int root = 0;
    fn(root, root);
    
    LCA::build(n);
    
    while (q--) {
      int x, y, a;
      scanf("%d%d%d", &x, &y, &a);
      --x;
      --y;
      vector<int> v = LCA::query(x, y);
      const int z = min<int>(a, v.size());
      while (z < v.size()) v.pop_back();
      printf("%d", z);
      each (i, v) printf(" %d", i);
      puts("");
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
  int l;
  while (scanf("%d", &l) == 1) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.10lf\n", a / (a + b) * l);
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
  const int C = 'z' + 1;
  char conv[C];
  while (scanf("%d %d\n", &n, &m) == 2) {
    for (char c = 'a'; c <= 'z'; ++c) {
      conv[c] = c;
    }
    const int L = 200000 + 10;
    static char str[L];
    scanf("%s\n", str);
    while (m--) {
      char a, b;
      scanf("%c %c\n", &a, &b);
      int x, y;
      for (char c = 'a'; c <= 'z'; ++c) {
        if (conv[c] == a) x = c;
        if (conv[c] == b) y = c;
      }
      swap(conv[x], conv[y]);
    }
    for (int i = 0; i < n; ++i) {
      printf("%c", conv[(int)str[i]]);
    }
    puts("");
  }
  return 0;
}
```
```php
<?php
for ($a = 0; $a <= 1; ++$a) {
    for ($b = 0; $b <= 1; ++$b) {
        for ($c = 0; $c <= 1; ++$c) {
            echo 3 . "\n";
            echo $a . " " . $b . " " . $c . "\n";
        }
    }   
}```
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

// int main(int argc, char *argv[])
void test(void)
{
  const int N = 10;
  int a[N];
  int b[N];
  
  srand(time(NULL));
  for (int i = 0; i < N; ++i) {
    a[i] = rand() % 2;
  }

  while (true) {
    for (int i = 0; i < N; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
    b[0] = a[0];
    b[N - 1] = a[N - 1];
    for (int i = 1; i + 1 < N; ++i) {
      b[i] = ((a[i - 1] + a[i] + a[i + 1]) >= 2);
    }
    bool f = true;
    for (int i = 0; i < N; ++i) {
      f = f && (a[i] == b[i]);
    }
    if (f) break;
    copy(b, b + N, a);
  }
  return ;
}

void _00(int n, int a[])
{
  int b[n];
  copy(a, a + n, b);
  int mx = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 0) {
      int j = i;
      int len = 0;
      while (j < n && a[j] == 0 && a[j + 1] == 1 && a[j + 2] == 0) {
        ++len;
        j += 2;
      }
      mx = max(mx, len);
      i = j;
    }      
  }

  int x = 0;
  int y = 0;
  
  b[0] = a[0];
  for (int i = 1; i + 1 < n; ++i) {
    b[i] = (a[i - 1] && a[i]) || (a[i] && a[i + 1]);    
  }
  b[n - 1] = a[n - 1];
  
  if (b[0]) for (int i = 0; i < n; i += 2) {
    if (a[i] == 1 && a[i + 1] == 0) {
      b[i] = b[i + 1] = 1;
      ++x;
    } else break;
  }
  if (b[n - 1]) for (int i = n - 1; 0 < i; i -= 2) {
    if (a[i - 1] == 0 && a[i] == 1) {
      b[i - 1] = b[i] = 1;
      ++y;
    } else break;
  }

  mx = max({mx, x, y});
  
  printf("%d\n", mx);
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", b[i]);
  }
  puts("");
  return ;
}

pair<int, vector<int>> f(vector<int> v)
{
  // cout << ">> "; each (i, v)  cout << i << ' '; cout << endl;
  if (v.size() == 1) return make_pair(0, v);
  const int z = count(v.begin(), v.end(), 0);  
  const int o = count(v.begin(), v.end(), 1);
  
  if (v.front() == 0 && v.back() == 0) {
    replace(v.begin(), v.end(), 1, 0);
    return make_pair(o, v);
  }
  
  if (v.front() == 1 && v.back() == 1) {
    replace(v.begin(), v.end(), 0, 1);
    return make_pair(z, v);
  }
  
  if (v.front() == 0 && v.back() == 1) {
    vector<int> u;
    for (int i = 0; i < z; ++i) u.push_back(0);
    for (int i = 0; i < o; ++i) u.push_back(1);
    return make_pair(o - 1, u);
  }
  
  if (v.front() == 1 && v.back() == 0) {
    vector<int> u;
    for (int i = 0; i < o; ++i) u.push_back(1);
    for (int i = 0; i < z; ++i) u.push_back(0);
    return make_pair(o - 1, u);
  }
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
      int n;
      scanf("%d", &n);
      a.push_back(n);
    }

    int mx = 0;
    each (i, a) {      
      if (b.size() && b.back() == i) {
        pair<int, vector<int>> tmp = f(b);
        each (j, tmp.second) c.push_back(j);
        mx = max(mx, tmp.first);
        b.clear();        
      }
      b.push_back(i);
    }
    
    if (b.size()) {
      pair<int, vector<int>> tmp = f(b);
      each (j, tmp.second) c.push_back(j);
      mx = max(mx, tmp.first);      
    }
    printf("%d\n", mx);
    for (int i = 0; i < c.size(); ++i) {
      if (i) printf(" ");
      printf("%d", c[i]);
    }
    puts("");
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
  while (scanf("%d\n", &n) == 1) {
    const int L = 1000 + 10;
    char buff[L];
    map<char, int> cnt[n];
    int len[n];
    for (int i = 0; i < n; ++i) {
      scanf("%s\n", buff);
      // puts(buff);
      len[i] = strlen(buff);      
      for (int j = 0; j < len[i]; ++j) {
        ++cnt[i][buff[j]];
      }
    }
    int mx = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (cnt[i][c] == len[i]) {
          sum += len[i];
        }
      }
      mx = max(mx, sum);
    }
    
    for (char c = 'a'; c <= 'z'; ++c) {
      for (char d = 'a'; d <= 'z'; ++d) {
        if (c == d) continue;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
          if (cnt[i][c] + cnt[i][d] == len[i]) {
            sum += len[i];
          }
        }
        mx = max(mx, sum);
      }
    }

    printf("%d\n", mx);
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

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    lli x1, x2;
    scanf("%lld%lld", &x1, &x2);
    static lli k[N], b[N];    
    
    vector<pair<lli, lli>> v;
    for (int i = 0; i < n; ++i) {
      scanf("%lld%lld", k + i, b + i);
      v.push_back(make_pair(k[i], b[i]));
    }
    
    auto fn1 = [&] (pair<lli, lli> p) { return p.first * x1 + p.second; };
    auto fn2 = [&] (pair<lli, lli> p) { return p.first * x2 + p.second; };    

    sort(v.begin(),
         v.end(),
         [&] (pair<lli, lli> s, pair<lli, lli> t)
         {
           if (fn1(s) != fn1(t)) return fn1(s) < fn1(t);
           return fn2(s) > fn2(t);
         });

    
    int next[N];
    next[n - 1] = n - 1;
    for (int i = n - 2; 0 <= i; --i) {
      if (fn1(v[i]) != fn1(v[i + 1])) {
        next[i] = i + 1;
      } else {
        next[i] = next[i + 1];
      }
    }
    
    lli mn[N];
    for (int i = 0; i < v.size(); ++i) {
      mn[i] = fn2(v[i]);
    }
    for (int i = n - 2; 0 <= i; --i) {
      mn[i] = min(mn[i], mn[i + 1]);
    }

    // each (i, v) cout << i << endl;
    // for (int i = 0; i < n; ++i) cout << next[i] << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << mn[i] << ' '; cout << endl;
    
    bool f = false;
    for (int i = 0; i < n; ++i) {
      if (mn[next[i]] < fn2(v[i]) && fn1(v[i]) != fn1(v[next[i]])) f = true;
    }
    puts(f ? "YES" : "NO");
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
  lli a, b, c;
  while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
    const lli inf = 1LL << 60;
    lli g[3][3];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        g[i][j] = inf;
      }
    }
    g[0][1] = g[1][0] = a;
    g[0][2] = g[2][0] = b;
    g[1][2] = g[2][1] = c;
    for (int k = 0; k < 3; ++k) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    printf("%lld\n", g[0][1] + g[1][2] + g[2][0]);
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
  int size_b;
  int size_f;
  while (scanf("%d%d", &size_f, &size_b) == 2) {
    int f[size_f];
    int b[size_b];
    for (int i = 0; i < size_f; ++i) scanf("%d", f + i);
    for (int i = 0; i < size_b; ++i) scanf("%d", b + i);

    map<int, int> cnt_f;
    map<int, int> cnt_b;
    for (int i = 0; i < size_f; ++i) ++cnt_f[f[i]];
    for (int i = 0; i < size_b; ++i) ++cnt_b[b[i]];

    bool pos = true;
    bool one = true;
    for (int i = 0; i < size_b; ++i) {
      pos = pos && cnt_f.count(b[i]);
      one = one && (cnt_f[b[i]] == 1);
    }
    
    if (!pos) { puts("Impossible"); continue; }
    if (!one) { puts("Ambiguity");  continue; }
    
    map<int, int> fi;
    for (int i = 0; i < size_f; ++i) {
      fi[f[i] - 1] = i;
    }
    puts("Possible");
    for (int i = 0; i < size_b; ++i) {
      if (i) printf(" ");
      printf("%d", fi[b[i] - 1] + 1);
    }
    puts("");
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
  while (scanf("%d", &n) == 1) {
    int h[n];
    for (int i = 0; i < n; ++i) scanf("%d", h + i);

    int g[n];
    copy(h, h + n, g);
    sort(g, g + n);
    map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i) {
      idx[g[i]].push_back(i);
    }

    auto fn = [] (pair<int, int> a, pair<int, int> b) {
      if (a.second < b.first) return false;
      if (b.second < a.first) return false;
      return true;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for (int i = 0; i < n; ++i) {
      const int mn = min(i, idx[h[i]].front());
      const int mx = max(i, idx[h[i]].front());
      pair<int, int> p = make_pair(mn, mx);
      q.push(p);
      idx[g[i]].erase(idx[g[i]].begin());
    }

    int cnt = 1;
    while (1 < q.size()) {
      pair<int, int> a = q.top();
      q.pop();
      pair<int, int> b = q.top();
      q.pop();
      if (fn(a, b)) {
        q.push(make_pair(min(a.first, b.first), max(a.second, b.second)));
      } else {
        q.push(b);
        ++cnt;
      }
    }
    printf("%d\n", cnt);
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
  int n, s;
  while (scanf("%d%d", &n, &s) == 2) {
    int f, t;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &f, &t);
      if (abs(s - f) <= t) {
        mx = max(mx, f + t);
      } else {
        mx = max(mx, f + abs(s - f));
      }
    }
    printf("%d\n", mx);
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
  const int M = 200000 + 100;
  char buff_a[M];
  char buff_b[M];
  while (scanf("%s%s", buff_a, buff_b) == 2) {
    string a(buff_a);
    string b(buff_b);
    lli sum = 0;
    int o = 0;
    int z = 0;
    int j = 0;
    for (int i = 0; i < b.size(); ++i) {
      if (i < a.size()) {
        z += (a[i] == '0');
        o += (a[i] == '1');
      }
      if (b.size() - i < a.size()) {
        z -= (a[j] == '0');
        o -= (a[j] == '1');
        // cout << "j : " << j << endl;
        ++j;
      }
      sum += (b[i] == '1') ? z : o;
      // cout << z << ' ' << o << " : " << sum << endl;
    }
    printf("%lld\n", sum);
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

const int M = 1000000 + 10;
int p[M];
int l[M];
int edge[M];

int memo[M];
int rec(int curr)
{
  int &ret = memo[curr];
  if (ret != -1) return ret;
  if (edge[curr] == -1) return ret = 1;
  else return ret = 1 + rec(edge[curr]);
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    fill(p, p + M, 0);
    fill(edge, edge + M, -1);
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      p[a] = b;
    }
    l[0] = -1;
    for (int i = 1; i < M; ++i) {
      if (0 < p[i - 1]) l[i] = i - 1;
      else l[i] = l[i - 1];
    }
    for (int i = 0; i < M; ++i) {
      if (p[i]) {
        edge[i] = l[max(0, i - p[i])];
      }
    }
    // for (int i = 0; i < M; ++i) if (0 < p[i]) cout << i << ' ' << edge[i] << endl;
    fill(memo, memo + M, -1);
    int mn = n;
    for (int i = 0; i < M; ++i) {
      if (p[i]) mn = min(mn, n - rec(i));
    }
    printf("%d\n", mn);
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

const int N = 500 + 10;
int m[N];

int memo[N][N];
int rec(int begin, int end)
{
  unless (begin < end) return 1 << 28;
  int& ret = memo[begin][end];
  if (ret != -1) return ret;
  if (begin + 1 == end) return 1;
  if (begin + 2 == end) return 1 + (m[begin] != m[begin + 1]);

  int mn = end - begin;
  if (m[begin]  == m[end - 1]) {
    mn = min(mn, rec(begin + 1, end - 1));
  }

  for (int i = begin + 1; i < end; ++i) {
    mn = min(mn, rec(begin, i) + rec(i, end));
  }
  return ret = mn;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", m + i);
    }
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    printf("%d\n", rec(0, n));
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
  while (scanf("%d%d", &n, &m) == 2) {
    set<int> v;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      for (int j = 0; j < a; ++j) {
        int b;
        scanf("%d", &b);
        v.insert(b);
      }
    }
    puts(v.size() == m ? "YES" : "NO");
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
vector<int> g[N];
vector<int> h[N];

int memo1[N];
int rec1(int curr)
{
  int& ret = memo1[curr];
  if (ret != -1) return ret;
  int mx = 1;
  each (next, g[curr]) mx = max(mx, rec1(next) + 1);
  return ret = mx;
}

int memo2[N];
int rec2(int curr)
{
  int& ret = memo2[curr];
  if (ret != -1) return ret;
  int mx = 1;
  each (next, h[curr]) mx = max(mx, rec2(next) + 1);
  return ret = mx;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    fill(g, g + N, vector<int>());
    fill(h, h + N, vector<int>());
    map<int, lli> deg;
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      ++deg[a];
      ++deg[b];
      if (a < b) {
        g[a].push_back(b);
        h[b].push_back(a);
      } else {
        g[b].push_back(a);
        h[a].push_back(b);
      }
    }
    fill(memo1, memo1 + N, -1);
    fill(memo2, memo2 + N, -1);
    // for (int i = 1; i <= n; ++i) cout << "deg: " << i << " := " << deg[i] << ", " << rec1(i) << endl;
    lli mx = 0;
    for (int i = 1; i <= n; ++i) {      
      // mx = max(mx, rec1(i) * deg[i]);
      mx = max(mx, rec2(i) * deg[i]); 
    }
    printf("%lld\n", mx);
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

const int N = 2100 + 10;

bool is_possible(string s, string t)
{
  set<char> C(s.begin(), s.end());
  each (c, t) if (C.count(c) == 0) return false;
  return true;
}

int main(int argc, char *argv[])
{
  char buff_s[N];
  char buff_t[N];
  while (scanf("%s\n%s\n", buff_s, buff_t) == 2) {
    string s(buff_s);
    string t(buff_t);
    if (!is_possible(s, t)) {
      puts("-1");
      continue;
    }
    string r = s;
    reverse(r.begin(), r.end());

    static int lcp1[N][N];
    fill(&lcp1[0][0], &lcp1[N - 1][N - 1] + 1, 0);
    static int lcp2[N][N];
    fill(&lcp2[0][0], &lcp2[N - 1][N - 1] + 1, 0);

    for (int t_idx = t.size() - 1; 0 <= t_idx; --t_idx) {
      for (int s_idx = s.size() - 1; 0 <= s_idx; --s_idx) {
        if (s[s_idx] == t[t_idx]) {
          lcp1[t_idx][s_idx] = lcp1[t_idx + 1][s_idx + 1] + 1;
        }
      }
      for (int r_idx = r.size() - 1; 0 <= r_idx; --r_idx) {
        if (r[r_idx] == t[t_idx]) {
          lcp2[t_idx][r_idx] = lcp2[t_idx + 1][r_idx + 1] + 1;
        }
      }
    }

    vector<pair<int, int>> v;
    for (int idx = 0; idx < t.size(); ) {
      int* a = max_element(lcp1[idx], lcp1[idx] + N);
      int* b = max_element(lcp2[idx], lcp2[idx] + N);
      if (*a < *b) {
        int i = (b - lcp2[idx]);
        int j = i + *b - 1;
        v.push_back(make_pair(r.size() - i, r.size() - j));
      } else {
        int i = (a - lcp1[idx]) + 1;
        int j = i + *a - 1;
        v.push_back(make_pair(i, j));
      }
      idx += max(*a, *b);
    }

    printf("%d\n", v.size());
    each (p, v) printf("%d %d\n", p.first, p.second);
  }
  return 0;
}
```
```rb
MOD = 1000000000 + 7

def f(n, p)
  if p == 0 then
    return 1
  end
  m = f(n, p / 2)
  if p % 2 == 1 then
    return m * m * n % MOD
  else
    return m * m % MOD
  end
end

while s = $stdin.gets() do
  s = $stdin.gets()
  ps = s.split(" ")
  cnt = {}
  ps.each do |p|
    key = p.to_i()
    if cnt[key] then
      cnt[key] = cnt[key] + 1
    else
      cnt[key] = 1
    end
  end
  
  d = 1
  cnt.each do |key, val|
    d *= val + 1
  end

  ret = 1
  cnt.each do |key, val|
    x = f(key, (val * (val + 1) / 2) % (MOD - 1))
    y = f(x, (d / (val + 1)) % (MOD - 1))
    ret = ret * y % MOD
  end
  puts(ret)
end
```
```rb
require 'scanf'

while s = $stdin.gets() do
  l, r, k = s.scanf("%d %d %d")
  n = 1
  f = false
  while n <= r do
    if l <= n && n <= r then
      if f then
        print(" ")  
      end
      f = true
      print(n)
    end
    n *= k;
  end
  if f then
    puts("");
  else
    puts("-1");
  end
end
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

bool beautiful(string s)
{
  return s[0] == '1' && (count(s.begin(), s.end(), '0') + 1 == s.size());
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    char buff[100000 + 10];
    string no_b;
    int z = 0;
    bool f = true;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      string s(buff);
      f = f && s != "0";
      if (beautiful(s)) {
        z += (int)s.size() - 1;
      } else {
        no_b = s;
      }
    }
    if (f) {
      if (no_b.empty()) no_b = "1";
      printf("%s", no_b.c_str());
      for (int i = 0; i < z; ++i) {
        printf("0");  
      }
      puts("");
    } else {
      puts("0");
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

point normal(point v)
{
  return v * point(0, -1);
}

double dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

namespace CCW{
  enum{ RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if( cross(b, c) < 0 )return CCW::RIGHT;
  if( cross(b, c) > 0 )return CCW::LEFT;
  if( dot(b, c) < 0 )return CCW::BACK;
  if( norm(b) < norm(c) )return CCW::FRONT;
  return CCW::OTHER;
}

bool inside(vector<point> v, point p)
{
  bool r = true;
  bool l = true;
  for (int i = 0; i < v.size() + 2; ++i) {
    int a = i % v.size();
    int b = (i + 1) % v.size();
    r = r && (ccw(v[a], v[b], p) == CCW::RIGHT);
    l = l && (ccw(v[a], v[b], p) == CCW::LEFT);
  }
  return r || l;
}

double dist_pp(point a, point b)
{
  double s = a.real() - b.real();
  double t = a.imag() - b.imag();
  s *= s;
  t *= t;
  return sqrt(s + t);
}


double D(point a, point b)
{
  double s = a.real() - b.real();
  double t = a.imag() - b.imag();
  s *= s;
  t *= t;
  return s + t;
}

double area(double r)
{
  return r * r * 3.14159265358979323846264338327950288;
}

const double EPS = 1e-8;

double distance_lp(point a1, point a2, point b)
{
  if(dot(a2-a1, b-a1) < EPS)return abs(b-a1);
  if(dot(a1-a2, b-a2) < EPS)return abs(b-a2);
  return abs(cross(a2-a1, b-a1)) / abs(a2-a1);
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    point p(a, b);

    vector<point> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      v.push_back(point(a, b));
    }
    point f = v[0];
    each (q, v) {
      if (D(p, f) < D(p, q)) {
        f = q;
      }
    }
    double mn = 1e128;
    for (int i = 0; i < v.size() + 10; ++i) {
      mn = min(mn, distance_lp(v[i % v.size()], v[(i + 1) % v.size()], p));
    }
    printf("%.10lf\n", area(dist_pp(p, f)) - area(mn));
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
  while (scanf("%d", &n) == 1) {
    printf("%d\n", (n / 5) + (bool)(n % 5));
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
  while (scanf("%d", &n) == 1) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      v.push_back(m);
    }
    if (count(v.begin(), v.end(), 0) == v.size()) {
      puts("0");
      continue;
    }
    vector<int> u;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == 1) u.push_back(i);
    }
    ull m = 1;
    for (int i = 0; i + 1 < u.size(); ++i) {
      m *= (ull)(u[i + 1] - u[i]);
    }
    printf("%llu\n", m);
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

double dist_pp(point a, point b)
{
  double x = a.real() - b.real();
  double y = a.imag() - b.imag();
  x *= x;
  y *= y;
  return sqrt(x + y);
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    point a(x, y);
    scanf("%lf%lf", &x, &y);
    point b(x, y);
    vector<point> v;
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf", &x, &y);
      v.push_back(point(x, y));
    }
    sort(v.begin(), v.end(), [&] (point s, point t) { return dist_pp(a, s) < dist_pp(a, t); });
    
    double mn = 0;
    {
      double mn1 = 0;
      double mn2 = 0;
      each (p, v) mn1 = max(mn1, dist_pp(p, a));
      each (p, v) mn2 = max(mn2, dist_pp(p, b));
      mn = min(mn1, mn2) * min(mn1, mn2);
    }

    for (int i = 0; i < v.size(); ++i) {
      double A = dist_pp(v[i], a);
      double B = 0;
      for (int j = i + 1; j < v.size(); ++j) {
        double db = dist_pp(b, v[j]);
        B = max(B, db);
      }
      mn = min(mn, A * A + B * B);
    }
    printf("%.0lf\n", mn);
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
  pair<int, int> a, b, c;
  while (scanf("%d%d%d%d%d%d", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second) == 6) {

    if (a.first == b.first && a.first == c.first) {
      puts("1");
    } else if (a.second == b.second && a.second == c.second) {
      puts("1");
    } else {
      vector<pair<int,int>> v = {a, b ,c};
      sort(v.begin(), v.end());
      bool f = false;
      do {
        f = f || ((v[0].first  == v[1].first)  && !(min(v[0].second,  v[1].second)  < v[2].second && v[2].second   < max(v[0].second, v[1].second)));
        f = f || ((v[0].second == v[1].second) && !(min(v[0].first, v[1].first) < v[2].first && v[2].first < max(v[0].first,v[1].first)));
      } while (next_permutation(v.begin(), v.end()));
      puts(f ? "2" : "3");
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

double g(pair<int, int> a, int p)
{
  return (a.second / p - (a.first - 1) / p) / (double)(a.second - a.first + 1);
}

double f(pair<int, int> a, pair<int, int> b, int p)
{
  return 1.0 - (1.0 - g(a, p)) * (1.0 - g(b, p));
}

int main(int argc, char *argv[])
{
  int n, p;
  while (scanf("%d%d", &n, &p) == 2) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      v.push_back(make_pair(a, b));
    }

    double e = 0.0;
    for (int i = 0; i < v.size(); ++i) {
      int j = (i + 1) % v.size();
      e += f(v[i], v[j], p) * 2000.0;
    }
    printf("%.10lf\n", e);
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

lli a, b, c;

lli g(lli m)
{
  lli ret = max(0LL, m - b) / (b - c);
  m -= ret * (b - c);
  while (b <= m) {
    ++ret;
    m -= b;
    m += c;
  }
  return ret + (m / a);
}

lli f(lli m)
{
  return (m / a) + g(m % a);
}

int main(int argc, char *argv[])
{
  lli n;
  while (scanf("%lld%lld%lld%lld", &n, &a, &b, &c) == 4) {
    printf("%lld\n", max(g(n), f(n)));
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
  const int N = 100000 + 5;
  const int M = 30 + 5;
  char g[N];
  char a[M];
  while (scanf("%s%s", g, a) == 2) {
    int cnt = 0;
    const int n = strlen(g);
    const int m = strlen(a);
    for (int i = 0; i < n; ++i) {
      int f = 0;
      for (int j = 0; i + j < n && j < m; ++j) {
        f += (g[i + j] == a[j]);
      }
      if (f == m) {
        ++cnt;
        i += f - 1;
      }
    }
    printf("%d\n", cnt);
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
  const int N = 500 + 5;
  lli g[N][N];
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    lli cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k - 1; ++j) {
        g[i][j] = ++cnt;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = k - 1; j < n; ++j) {
        g[i][j] = ++cnt;
      }
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += g[i][k - 1];
    }

    printf("%lld\n", sum);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j) printf(" ");
        printf("%lld", g[i][j]);
      }
      puts("");
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
  while (scanf("%d", &n) == 1) {
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
    }
    int mx = 0;
    int or_a = 0;
    int or_b = 0;
    for (int l = 0; l < n; ++l) {
      or_a |= a[l];
      or_b |= b[l];
      int x = or_a;
      int y = or_b;
      for (int r = l; r < n; ++r) {
        x |= a[r];
        y |= b[l];
        mx = max(mx, x + y);
      }
    }
    printf("%d\n", mx);
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
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    pair<int, int> r[n];
    pair<int, int> c[m];
    fill(r, r + n, make_pair(0, 0));
    fill(c, c + m, make_pair(0, 0));
    for (int i = 0; i < k; ++i) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      if (x == 1) r[y - 1] = make_pair(i, z);
      else        c[y - 1] = make_pair(i, z);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j) printf(" ");
        printf("%d", max(r[i], c[j]).second);
      }
      puts("");
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
  while (scanf("%d%d", &n, &m) == 2) {
    int a[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++i) {
      int t, r;
      scanf("%d%d", &t, &r);
      while (v.size() && v.back().second < r) v.pop_back();
      v.push_back(make_pair(t, r));
    }
    int r = 0;
    each (i, v) r = max(r, i.second);
    sort(a, a + r);
    deque<int> q;
    for (int i = 0; i < r; ++i) {
      q.push_back(a[i]);
    }

    for (size_t i = 0; i + 1 < v.size(); ++i) {
      for (int loop = v[i].second - v[i + 1].second; loop--; ) {
        if (v[i].first == 2) {
          a[--r] = q.front();
          q.pop_front();
        } else {
          a[--r] = q.back();
          q.pop_back();
        }
      }
    }
    while (q.size()) {
      if (v.back().first == 2) {
        a[--r] = q.front();
        q.pop_front();
      } else {
        a[--r] = q.back();
        q.pop_back();
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i) printf(" ");
      printf("%d", a[i]);
    }
    puts("");
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

int* buildFail(pair<lli, char> p[], const int m)
{
  int *fail = new int[m+1];
  int j = fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    while (j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
  return fail;
}

pair<lli, char> H;
pair<lli, char> T;

lli match(pair<lli, char> t[], pair<lli, char> p[], const int n, const int m)
{
  int* fail = buildFail(p, m);
  lli count = 0;
  for (int i = 0, k = 0; i < n; ++i) {
    while (k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      // match at t[i-m+1 .. i]
      if (0 <= i-m+1-1 && i + 1 < n) {
        pair<lli, char> x = t[i-m+1-1];
        pair<lli, char> y = t[i + 1];
        count += (x.first >= H.first) * (x.second == H.second) * (y.first >= T.first) * (y.second == T.second);
      }
      k = fail[k];
    }
  }
  return count;
}

pair<lli, char> s[200000];
pair<lli, char> t[200000];

int main(int argc, char *argv[])
{
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      lli l;
      char c;
      scanf("%lld-%c", &l, &c);
      if (i && s[i - 1].second == c) {
        --n;
        --i;
        s[i].first += l;
      } else {
        s[i] = make_pair(l, c);
      }
    }
    for (int i = 0; i < m; ++i) {
      lli l;
      char c;
      scanf("%lld-%c", &l, &c);
      if (i && t[i - 1].second == c) {
        --m;
        --i;
        t[i].first += l;
      } else {
        t[i] = make_pair(l, c);
      }
    }
    if (m == 1) {
      lli cnt = 0;
      for (int i = 0; i < n; ++i) {
        lli c = s[i].first - (t[0].first - 1);
        cnt += (s[i].first >= t[0].first) * (s[i].second == t[0].second) * c;
      }
      printf("%lld\n", cnt);
    } else if (m == 2) {
      lli cnt = 0;
      for (int i = 0; i + 1 < n; ++i) {
        cnt +=
          (s[i + 0].first >= t[0].first) * (s[i + 0].second == t[0].second) *
          (s[i + 1].first >= t[1].first) * (s[i + 1].second == t[1].second);
      }
      printf("%lld\n", cnt);
    } else {
      H = t[0];
      T = t[m - 1];
      printf("%lld\n", match(s, t + 1, n, m - 2));
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
  int d, h, v, e;
  while (scanf("%d%d%d%d", &d, &h, &v, &e) == 4) {
    const double pi =  3.141592653589793238462643383279;
    auto fn = [&] (double t) {
      const double a = pi * (d / 2.0) * (d / 2.0);
      return (a * h) + (a * e * t) < (v * t) + 1e-10;
    };
    double small = 0, large = 100000;
    for (int loop = 100; loop--; ) {
      double mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(large)) {
      puts("YES");
      printf("%.10lf\n", large);
    } else {
      puts("NO");
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
  while (scanf("%d", &n) == 1) {
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    const lli sum = accumulate(v.begin(), v.end(), 0);
    const lli mx = *max_element(v.begin(), v.end());
    printf("%lld\n", labs((sum - mx) - mx) + 1LL);
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
  const int N = 10000 + 100;
  char buff[N];
  while (scanf("%s\n", buff) == 1) {
    const int n = strlen(buff);
    bool dp[N];
    fill(dp, dp + N, false);
    dp[n] = true;
    for (int i = N - 1; 3 <= i; --i) {
      dp[i - 2] |= dp[i];
      dp[i - 3] |= dp[i];
    }
    fill(dp, dp + 5, false);
    set<string> suff;
    for (int i = 0; i < n; ++i) {
      if (dp[i] && dp[i + 2]) suff.insert(string("") + buff[i] + buff[i + 1]);
      if (dp[i] && dp[i + 3]) suff.insert(string("") + buff[i] + buff[i + 1] + buff[i + 2]);
    }
    printf("%d\n", (int)suff.size());
    cout << n << endl;
    // each (i, suff) puts(i.c_str());
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
  while (scanf("%d", &n) == 1) {
    int mn = n * 2, mx = 0;

    for (int base = 0; base < 7; ++base) {
      int cnt = 0;
      for (int d = 0; d < n; ++d) {
        cnt += (5 <= (base + d) % 7);
      }
      mn = min(mn, cnt);
      mx = max(mx, cnt);
    }
    printf("%d %d\n", mn, mx);
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
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      v.push_back(m);
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      lli s = sum + i + 1;
      if (k <= s) {
        printf("%d\n", v[k - sum - 1]);
        break;
      }
      sum = s;
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
  while (scanf("%d", &n) == 1) {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      ++cnt[m];
    }

    vector<pair<int, int>> v;
    int m;
    scanf("%d", &m);
    v.resize(m);
    
    for (int i = 0; i < m; ++i) {
      int a;
      scanf("%d", &a);
      v[i].first = a;
    }
    
    for (int i = 0; i < m; ++i) {
      int a;
      scanf("%d", &a);
      v[i].second = a;
    }    
    
    int j = 0;
    for (int i = 0; i < m; ++i) {
      if (cnt[v[j].first] < cnt[v[i].first]) j = i;
      if (cnt[v[j].first] == cnt[v[i].first] && cnt[v[j].second] < cnt[v[i].second]) j = i;
    }
    printf("%d\n", j + 1);
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

const int N = 1000 + 10;
int dp[N][N];



int main(int argc, char *argv[])
{
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int b[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
    }

    int c = 0;

    while (true) {
      for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
          k -= abs(b[i] - a[i]);
          b[i] = a[i];
        }
      }
      if (k < 0) break;
      ++c;
      for (int i = 0; i < n; ++i) {
        b[i] -= a[i];
      }
    }
    
    printf("%d\n", c);
  }
  return 0;
}
```
```ml
open Printf
open Scanf

let read_int  () = bscanf Scanning.stdib " %d "  (fun x -> x);;
let read_long () = bscanf Scanning.stdib " %Ld " (fun x -> x);;

let ( ** ) a b = Int64.mul a b
let ( ++ ) a b = Int64.add a b
let ( -- ) a b = Int64.sub a b
let ( // ) a b = Int64.div a b
let ( %% ) a b = Int64.rem a b
let ( ^^ ) a b = Int64.shift_left a b
let rec sum (i : int) (j : int) f (ac : int64) =
  if i > j then
    ac
  else
    sum (i + 1) j f (ac ++ (f i));;

let () =
  try
    while true do
      let n = read_int () in
      let k = read_long () in
      let a = Array.init n (fun _ -> read_long()) in
      let b = Array.init n (fun _ -> read_long()) in

      let possible m =
        let x = sum 0 (n - 1) (fun i -> min 4000000000L (max 0L ((m ** a.(i)) -- b.(i)))) 0L in
        x <= k
      in

      let rec binary_search small large =
        if (small ++ 1L) < large then
          let (mid : int64) = (small ++ large) // 2L in
          if possible mid then binary_search mid large else binary_search small mid
        else
          small
      in
      
      printf "%Ld\n" (binary_search 0L 2000000001L)
    done
  with End_of_file -> ()
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
  int n, m, p;
  while (scanf("%d %d %d\n", &n, &m, &p) == 3) {
    const int N = 500000 + 10;
    int match[N];
    int R[N];
    int L[N];
    fill(R, R + N, -1);
    fill(L, L + N, -1);

    char cbs[N];
    for (int i = 0; i < n; ++i) {
      scanf("%c", cbs + i);
    }
    scanf("\n");

    for (int i = 0; i <= n; ++i) R[i] = i + 1;
    for (int i = 0; i <= n; ++i) L[i] = i - 1;
    
    {
      stack<int> s;
      for (int i = 0; i < n; ++i) {
        if (cbs[i] == '(') s.push(i);
        else {
          int j = s.top();
          s.pop();
          match[j + 1] = i + 1;
          match[i + 1] = j + 1;
        }
      }
    }
    auto output = [&] (void) {
      int idx = R[0];
      while (idx <= n) {
        printf("%c", cbs[idx - 1]);
        idx = R[idx];
      }
      puts("");      
      return ;
    };
    
    auto del = [&] (int i, int j) {
      const int a = min(L[i], L[j]);
      const int b = max(R[i], R[j]);
      R[a] = b;
      L[b] = a;
      if (R[b] == -1) return p = L[R[a]];
      return p = b;
    };
    
    for (char c; m--; ) {
      scanf("%c", &c);
      if (c == 'L') p = L[p];
      if (c == 'R') p = R[p];
      if (c == 'D') p = del(p, match[p]);
    }    
    scanf("\n");
    output();
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
  lli a, b, c;
  while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
    if (c) {
      puts(((b - a) % c == 0) && ((b - a) / c >= 0) ? "YES" : "NO");
    } else {
      puts(b == a? "YES" : "NO");
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
  int n, a, b, c, d;
  while (scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) == 5) {
    lli cnt = 0;

    const lli mn = min({(a+b), (a+c), (b+d), (c+d)}) + 2;
    const lli mx = max({(a+b), (a+c), (b+d), (c+d)}) + n + n;
      
    for (lli x1 = 1; x1 <= n; ++x1) {
      const lli x5 = (x1 + a + b) - (c + d);
      const lli x2 = (x1 + a + b) - (a + c);
      const lli x4 = (x1 + a + b) - (b + d);

      unless (1 <= x2 && x2 <= n) continue;
      unless (1 <= x4 && x4 <= n) continue;
      unless (1 <= x5 && x5 <= n) continue;
      cnt += n;
    }
    
    printf("%lld\n", cnt);
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
  while (scanf("%d", &n) == 1) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(a[i], a[j]);
        int x, y;
        for (int k = 0; k < n; ++k) {
          if (a[k] == 1) x = k;
          if (a[k] == n) y = k;
        }
        mx = max(mx, abs(x - y));
        swap(a[i], a[j]);
      }
    }
    printf("%d\n", mx);
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
  while (scanf("%d%d", &n, &t) == 2) {
    const int N = 15;
    double dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    dp[0][0] = t;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (1 < dp[i][j]) {
          double f = dp[i][j] - 1.0;
          dp[i][j] = 1.0;
          dp[i + 1][j] += f / 2;
          dp[i + 1][j + 1] += f / 2;
        }
      }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt += (dp[i][j] == 1.0);
      }
    }
    printf("%d\n", cnt);
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

int f(string s, char c, int k)
{
  if (k == 0) {
    int cnt = 1;
    int mx = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) ++cnt;
      else {
        mx = max(mx, cnt);
        cnt = 1;
      }
    }
    return max(cnt, mx);
  }
  
  map<char, map<int, int>> acc;
  for (int i = 0; i < s.size(); ++i) {
    acc['a'][i + 1] = acc['a'][i] + (s[i] == 'a');
    acc['b'][i + 1] = acc['b'][i] + (s[i] == 'b');
  }

  const int n = s.size();
  const char d = (c == 'a' ? 'b' : 'a');

  auto g = [&] (size_t i, size_t j) {
    return i < s.size() && j <= s.size() && acc[d][j] - acc[d][i] <= k;
  };

  int i = 0;
  int j = 0;
  int mx = 0;
  
  while (i <= j) {
    while (g(i, j + 1)) ++j;
    if (g(i, j)) mx = max(mx, j - i);
    ++i;
  }
  return mx;
}

int main(int argc, char *argv[])
{
  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    cout << max(f(s, 'a', k), f(s, 'b', k)) << endl;
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


const int N = 1000 + 10;
char g[N][N];
int h, w;
int ti, tj;
int mi, mj;

const int U = 0;
const int R = 1;
const int D = 2;
const int L = 3;

char rot(char c)
{
  if (c == '+') return '+';

  if (c == '-') return '|';
  if (c == '|') return '-';

  if (c == '<') return '^';
  if (c == '>') return 'v';
  if (c == 'v') return '<';
  if (c == '^') return '>';

  if (c == 'L') return 'U';
  if (c == 'U') return 'R';
  if (c == 'R') return 'D';
  if (c == 'D') return 'L';

  if (c == '*') return '*';
}

bool valid(char c, int dir)
{
  if (c == '+') return true;

  if (c == '-' && (dir == R || dir == L)) return true;
  if (c == '|' && (dir == D || dir == U)) return true;

  if (c == '<' && dir == L) return true;
  if (c == '>' && dir == R) return true;
  if (c == 'v' && dir == D) return true;
  if (c == '^' && dir == U) return true;

  if (c == 'L' && dir != L) return true;
  if (c == 'R' && dir != R) return true;
  if (c == 'U' && dir != U) return true;
  if (c == 'D' && dir != D) return true;

  if (c == '*') return false;
  return false;
}

char rn(int i, int j, int r)
{
  char c = g[i][j];
  while (r--) c = rot(c);
  return c;
}

int opp(int dir)
{
  if (dir == R) return L;
  if (dir == L) return R;
  if (dir == U) return D;
  if (dir == D) return U;
}

struct S { int r, i, j; };

int cost[4][N][N];

int f(void)
{
  const int di[] = {-1, 0, +1, 0};
  const int dj[] = {0, +1, 0, -1};
  const int inf = 1 << 29;

  fill(&cost[0][0][0], &cost[4 - 1][N - 1][N - 1] + 1, inf);
  cost[0][ti][tj] = 0;  

  queue<S> q;
  for (q.push((S){0, ti, tj}); q.size(); q.pop()) {
    S curr = q.front();
    
    for (int d = 0; d < 4; ++d) {
      int ni = curr.i + di[d];
      int nj = curr.j + dj[d];
      int nr = curr.r;
      unless (0 <= ni && ni < h) continue;
      unless (0 <= nj && nj < w) continue;
      if (cost[nr][ni][nj] != inf) continue;
      if (0 &&curr.i == 0 && curr.j == 0 && curr.r == 3) {
        cout << "--" << endl;
        cout << rn(curr.i, curr.j, curr.r) << endl;
        cout << rn(ni, nj, curr.r) << endl;
        cout << opp(d) << endl;
        cout << "##" << endl;
      }
      if (valid(rn(curr.i, curr.j, curr.r), d) &&
          valid(rn(ni, nj, curr.r), opp(d))) {
        cost[nr][ni][nj] = cost[curr.r][curr.i][curr.j] + 1;
        q.push((S){nr, ni, nj});
      }
    }
    int nr = (curr.r + 1) % 4;
    if (cost[nr][curr.i][curr.j] == inf) {
      cost[nr][curr.i][curr.j] = cost[curr.r][curr.i][curr.j] + 1;
      q.push((S){nr, curr.i, curr.j});
    }
  }

  int mn = inf;
  for (int i = 0; i < 4; ++i) {
    mn = min(mn, cost[i][mi][mj]);
  }
  return mn == inf ? -1 : mn;
}

int main(int argc, char *argv[])
{
  while (scanf("%d %d\n", &h, &w) == 2) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        scanf("%c", &(g[i][j]));
      }
      scanf("\n");
    }

    // cout << h << ' ' << w << endl;
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << g[i][j];
    //   }
    //   cout << endl;
    // }

    scanf("%d %d\n", &ti, &tj);
    scanf("%d %d\n", &mi, &mj);
    --ti;
    --tj;
    --mi;
    --mj;
    printf("%d\n", f());
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
  int n, h;
  while (scanf("%d%d", &n, &h) == 2) {
    int sum = n;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      sum += h < m;
    }
    printf("%d\n", sum);
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

int char2int(char c)
{
  if ('0' <= c && c <= '9') return c - '0';
  if ('A' <= c && c <= 'Z') return c - 'A' + 10;
  if ('a' <= c && c <= 'z') return c - 'a' + 36;
  if (c == '-') return 62;
  return 63;
}

string int2bit(int n)
{
  string s;
  while (s.size() < 6) {
    s += '0' + (n & 1);
    n /= 2;
  }
  return s;
}

int main(int argc, char *argv[])
{
  const int N = 100000 + 10;
  char buff[N];
  while (scanf("%s", buff) == 1) {
    string s(buff);
    string t;
    each (c, s) t += int2bit(char2int(c));
    const int z = count(t.begin(), t.end(), '0');
    // cout << t << endl;
    const lli mod = 1000000000 + 7;
    lli n = 1;
    for (int i = 0; i < z; ++i) {
      n = n * 3 % mod;
    }
    // n = (n * 2  - 1 + mod) % mod;
    printf("%lld\n", n);
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
  while (scanf("%d", &n) == 1) {
    char buff[100];
    bool f = false;
    for (int i = 0; i < n; ++i) {
      int b, a;
      scanf("%s%d%d", buff, &b, &a);
      if (2400 <= b && b < a) f = true;
    }
    puts(f ? "YES" : "NO");
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
  const lli A = 1234567;
  const lli B = 123456;
  const lli C = 1234;
  lli n;
  while (scanf("%lld", &n) == 1) {
    bool f = false;
    for (int a = 0; (a * A) <= n; ++a) {
      for (int b = 0; (a * A) + (b * B) <= n; ++b) {
        lli m = n - (a * A) - (b * B);
        if (m % C == 0) {
          f = true;
        }
      }
    }
    puts(f ? "YES" : "NO");
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

void dump(priority_queue<int, vector<int>, less<int>> q)
{
  while (q.size()) {
    printf("%d, ", q.top());
    q.pop();
  }
  puts("");
  return;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    char buff[100];
    int m;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<pair<char, int>> v;

    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      if (buff[0] == 'i') {
        scanf("%d", &m);
        q.push(m);
        v.push_back(make_pair('i', m));
      }
      if (buff[0] == 'r') {
        if (q.size()) q.pop();
        else v.push_back(make_pair('i', -1000000000));
        v.push_back(make_pair('r', -1));
      }
      if (buff[0] == 'g') {
        scanf("%d", &m);
        while (q.size() && m > q.top()) {
          q.pop();
          v.push_back(make_pair('r', -1));
        }
        if (q.empty() || q.top() != m) {
          q.push(m);
          v.push_back(make_pair('i', m));
        }
        v.push_back(make_pair('g', m));
      }
    }

    printf("%d\n", (int)v.size());
    each (i, v) {
      if (i.first == 'i') printf("insert %d\n", i.second);
      if (i.first == 'r') printf("removeMin\n");
      if (i.first == 'g') printf("getMin %d\n", i.second);
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
  lli n, m;
  while (scanf("%lld%lld", &n, &m) == 2) {
    lli sum = 0;
    for (int i = 1; i <= n; ++i) {
      lli a = i + 1;
      lli b = i + m;
      sum += b/5 - max<lli>(0, a - 1)/5;
    }
    printf("%lld\n", sum);
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
  while (scanf("%d", &n) == 1) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      q.push(a);
    }
    int target = 1;
    while (true) {
      while (q.size() && q.top() < target) q.pop();
      if (q.empty()) break;
      ++target;
      q.pop();
    }
    printf("%d\n", target);
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
lli a[N];
vector<pair<int, lli>> g[N];

int rec(int curr, lli cost = 0)
{
  if (a[curr] < cost) return 0;
  int sum = 1;
  each (e, g[curr]) {
    sum += rec(e.first, max(cost + e.second, e.second));
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
    }

    for (int i = 0; i < n - 1; ++i) {
      int p;
      lli w;
      scanf("%d%lld", &p, &w);
      g[p-1].push_back(make_pair(i+1, w));
    }
    
    printf("%d\n", n - rec(0));
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

int a, b, c;

string s, t;

const int N = 1000 + 2;
const int K = 11;
int memo[N][2][N][2][K];
const int inf = (1 << 28);

int rec(int i, int I, int j, int J, int k)
{
  if (k == c) {
    return 0;
  }

  if (i == s.size()) return -inf;
  if (j == t.size()) return -inf;

  int& ret = memo[i][I][j][J][k];
  if (ret != -1) return ret;
  
  int mx = -inf;

  if (I && J) {
    if (s[i] == t[j]) {
      mx = max(mx, rec(i + 1, true, j + 1, true, k) + 1);
      mx = max(mx, rec(i + 1, false, j + 1, false, k + 1) + 1);
    }
  } else if (I) {
    mx = max(mx, rec(i, true, j + 1, false, k));
  } else if (J) {
    mx = max(mx, rec(i + 1, false, j, true, k));
  } else {
    mx = max(mx, rec(i, true, j, true, k));
    mx = max(mx, rec(i + 1, false, j, false, k));
    mx = max(mx, rec(i, false, j + 1, false, k));    
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  while (scanf("%d%d%d", &a, &b, &c) == 3) {
    char buff[1000 + 10];

    scanf("%s", buff);
    s = string(buff);

    scanf("%s", buff);
    t = string(buff);

    fill(&memo[0][0][0][0][0], &memo[N - 1][2 - 1][N - 1][2 - 1][K - 1] + 1, -1);
    printf("%d\n", rec(0, false, 0, false, 0));

    // break;
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
  int n, d;
  while (scanf("%d%d", &n, &d) == 2) {
    char buff[110];
    vector<int> v;
    for (int i = 0; i < d; ++i) {
      scanf("%s", buff);
      string s(buff);
      if (count(s.begin(), s.end(), '1') != s.size()) {
        v.push_back(i);
      }
    }
    int cnt = (bool)v.size();
    int mx = cnt;
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (v[i] + 1 == v[i + 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }
      mx = max(mx, cnt);
    }
    mx = max(mx, cnt);
    printf("%d\n", mx);
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
  char buff[100000 + 10];
  while (scanf("%s", buff) == 1) {
    string s(buff);
    string t(buff);
    reverse(t.begin(), t.end());
    printf("%s%s\n", s.c_str(), t.c_str());
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
int color[N];

vector<int> g[N];

const int A = 0;
const int B = 1;
const int C = 2;

bool rec(int curr, int c)
{
  color[curr] = c;
  each (next, g[curr]) {
    if (color[next] == c) throw "";
    if (color[next] == C) rec(next, c ^ 1);
  }
  return true;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    fill(color, color + N, C);
    try {
      for (int i = 0; i < n; ++i) {
        if (color[i] == C) rec(i, i % 2);
      }
    } catch(const char* e) {
      puts("-1");
      continue;
    }
    vector<int> a, b;
    for (int i = 0; i < N; ++i) {
      if (color[i] == A) a.push_back(i + 1);
      if (color[i] == B) b.push_back(i + 1);
    }

    

    printf("%d\n", (int)a.size());
    for (int i = 0; i < a.size(); ++i) {
      if (i) printf(" ");
      printf("%d", a[i]);
    }
    puts("");
    printf("%d\n", (int)b.size());
    for (int i = 0; i < b.size(); ++i) {
      if (i) printf(" ");
      printf("%d", b[i]);
    }
    puts("");
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
  while (scanf("%d%d", &a, &b) == 2) {
    int n;
    scanf("%d", &n);
    double x[n];
    double y[n];
    double v[n];
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf", x + i, y + i, v + i);
    }

    double mn = 1e128;
    auto d = [&] (int i) {
      double s = (a - x[i]);
      double t = (b - y[i]);
      double u = sqrt(s * s + t * t);
      return u / v[i];
    };
    for (int i = 0; i < n; ++i) {
      mn = min(mn, d(i));
    }
    printf("%.10lf\n", mn);
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
  while (scanf("%d", &n) == 1) {
    int x[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", x + i);
    }
    sort(x, x + n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int m;
      scanf("%d", &m);
      printf("%d\n", (int)(upper_bound(x, x + n, m) - x));
    }
  }
  return 0;
}
```
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define MIN(A,B) (A=std::min(A,B))

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
  while (scanf("%d", &n) == 1) {
    int c[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", c + i);
    }

    string s[n];
    string t[n];
    char buff[100000 + 10];
    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      t[i] = s[i] = string(buff);
      reverse(t[i].begin(), t[i].end());
    }

    const lli inf = (1LL << 60);
    const int N = 100000 + 10;

    lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, inf);
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i = 0; i + 1 < n; ++i) {
      const int j = i + 1;
      auto f = [&] (bool i_reversed, bool j_reversed) {
        string a = i_reversed ? t[i] : s[i];
        string b = j_reversed ? t[j] : s[j];
        if (a <= b) {
          MIN(dp[j][j_reversed], dp[i][i_reversed] + j_reversed * c[j]);
        }
        return ;
      };
      f(0, 0);
      f(0, 1);
      f(1, 0);
      f(1, 1);
    }

    lli mn = min(dp[n - 1][0], dp[n - 1][1]);
    printf("%lld\n", (mn < inf) ? mn : -1);
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


string f(lli n)
{
  if (n == 0) return "0";
  string s;
  while (n) {
    s += '0' + (n & 1);
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}


int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d\n", &n) == 1) {
    map<lli, int> cnt;
    cnt[0] = 1;
    while (n--) {
      char c;
      lli x;
      scanf("%c %lld\n", &c, &x);
      if (c == '+') {
        ++cnt[x];
      }
      if (c == '-') {
        --cnt[x];
        if (cnt[x] == 0) cnt.erase(x);
      }
      if (c == '?') {
        auto fn = [&] (lli bit, lli mask) {
          auto itr = cnt.lower_bound(bit);
          return itr != cnt.end() && (itr->first & mask) == bit;
        };

        lli mask = 0;
        lli y = 0;
        for (int i = 40; i >= 0; --i) {
          const lli b = (1LL << i);
          mask |= b;
          const lli z = y | b;          
          if (fn(y, mask) && fn(z, mask)) {
            y = (x ^ y) < (x ^ z) ? z : y;
          } else if (fn(z, mask)) {
            y = z;
          } else {
          }
        }
        printf("%lld\n", max(x ^ y, x));
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
  int n;
  while (scanf("%d", &n) == 1) {
    lli a[n];
    for (lli i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<lli> v;
    for (lli i = 0; i + 1 < n; ++i) {
      v.push_back(a[i] + a[i + 1]);
    }
    each (i, v) cout << i << ' ';
    cout << a[n - 1] << endl;
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
    if (s.size() % 2) {
      cout << -1 << endl;
      continue;
    }
    int U = count(s.begin(), s.end(), 'U');
    int D = count(s.begin(), s.end(), 'D');
    int R = count(s.begin(), s.end(), 'R');
    int L = count(s.begin(), s.end(), 'L');

    int x = abs(U - D);
    int y = abs(L - R);

    cout << min(x, y) + (max(x, y) - min(x, y)) / 2 << endl;
    
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
  int x, y;
  while (scanf("%d%d", &x, &y) == 2) {
    vector<int> v = {y, y, y};
    int cnt = 0;

    while (v != vector<int>({x, x, x})) {
      // cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
      int z = (v[1] + v[2]) - 1;
      v[0] = min(x, z);
      sort(v.begin(), v.end());
      ++cnt;
    }
    
    printf("%d\n", cnt);
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
  lli a, b, c, d, k;
  while (cin >> a >> b >> c >> d >> k) {
    lli x = max(a, c);
    lli y = min(b, d);
    lli z = y - x + 1;
    if (x <= k && k <= y) --z;
    cout << max(z, 0LL) << endl;
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
  lli n;
  while (scanf("%lld", &n) == 1) {
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      lli a;
      scanf("%lld", &a);
      v.push_back(a);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    if (v.size() == 1) puts("YES");
    else if (v.size() == 2) puts("YES");
    else if (v.size() == 3 && v[1] - v[0] == v[2] - v[1]) puts("YES");
    else puts("NO");
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

inline void add(map<string, int>& cnt, char buff[])
{
  string s(buff);
  reverse(s.begin(), s.end());
  while (s.size() < 18) s += "0";
  string t;
  for (int i = 0; i < s.size(); ++i) {
    t += (s[i] - '0') % 2 + '0';
  }
  ++cnt[t];
  return ;
}

inline void sub(map<string, int>& cnt, char buff[])
{
  string s(buff);
  reverse(s.begin(), s.end());
  while (s.size() < 18) s += "0";
  string t;
  for (int i = 0; i < s.size(); ++i) {
    t += (s[i] - '0') % 2 + '0';
  }
  --cnt[t];
  return ;
}

inline void query(map<string, int>& cnt, char buff[])
{
  string s(buff);
  reverse(s.begin(), s.end());
  while (s.size() < 18) s += '0';
  if (cnt.count(s)) printf("%d\n", cnt[s]);
  else puts("0");
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d\n", &n) == 1) {
    char c;
    char s[20];
    map<string, int> cnt;
    while (n--) {
      scanf("%c %s\n", &c, s);
      if (c == '+') add(cnt, s);
      if (c == '-') sub(cnt, s);
      if (c == '?') query(cnt, s);
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
  int n, c;
  while (scanf("%d%d", &n, &c) == 2) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (v.empty()) v.push_back(x);
      else {
        if (abs(v.back() - x) > c) {
          v.clear();
        }
        v.push_back(x);
      }
    }
    printf("%d\n", (int)v.size());
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
  const int M = 50000 + 10;
  char s[M];
  while (scanf("%s", s) == 1) {
    const int N = strlen(s);
    map<char, int> cnt;

    auto fn = [&] () {
      int sum = 0;
      for (char c = 'A'; c <= 'Z'; ++c) {
        if (cnt[c] >= 2) return false;
        sum += cnt[c];
      }
      // cout << sum << ' ' << cnt['?']  << endl;
      return sum + cnt['?'] == 26;
    };
    
    bool f = false;
    int i = 0;
    int j = 0;
    for (; i < N; ++i) {
      ++cnt[s[i]];
      if (j + 25 == i) {
        // cout << make_pair(j, i) << endl;
        // each (p, cnt) cout << p << endl;
        if (fn()) { f = true; break; }
        --cnt[s[j]];
        ++j;
      }
    }

    if (f) {
      set<char> x;
      for (char c = 'A'; c <= 'Z'; ++c) x.insert(c);
      for (int k = j; k <= i; ++k) {
        x.erase(s[k]);
      }
      vector<char> v(x.begin(), x.end());
      for (int k = 0; k < N; ++k) {
        if (s[k] == '?') {
          if (j <= k && k <= i) {
            s[k] = v.back();
            v.pop_back();
          } else {
            s[k] = 'A';
          }
        }
      }
      puts(s);
    }
    else puts("-1");
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

bool sq(lli x)
{
  static lli i = 1;
  for (; i * i <= x; ++i) {
    if (i * i == x) return true;
  }
  return false;
}

void validate(lli curr, lli x, lli add)
{
  lli next = curr + 1;
  assert(x % curr == 0);
  lli y = x + add * curr;
  assert(0 < y);
  assert(y % next == 0);
  assert(sq(y));
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    lli level = 1;
    lli x = 2;
    while (level <= n) {
      const lli y = (level + 1) * level;
      assert(y % level == 0);
      assert(x % level == 0);
      lli add = y * (y / level) - (x / level);
      printf("%lld\n", add);
      // validate(level, x, add);
      x = y;
      ++level;
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
  std::ios::sync_with_stdio(false);
  int k, r;
  while (cin >> k >> r) {
    for (int i = 1; i < 1000; ++i) {
      int mod = (k * i) % 10;
      if (mod == r || mod == 0) {
        cout << i << endl;
        break;
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

const int N = 500 + 10;
int a[N];

const int inf = 1 << 29;
int b[N];

int f(int x, const int n, const int k)
{
  copy(a, a + N, b);
  b[0] += x;
  for (int i = 1; i < n; ++i) {
    const int diff = k - (b[i] + b[i - 1]);
    b[i] += max(diff, 0);
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += abs(a[i] - b[i]);
  }
  return sum;
}

int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);
  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int c[N];
    int mn = inf;
    for (int i = 0; i <= 500; ++i) {
      int x = f(i, n, k);
      if (x < mn) {
        mn = x;
        copy(b, b + N, c);
      }
    }
    cout << mn << endl;
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ' ;
      cout << c[i];
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

const lli inf = 1LL << 63;


int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);
  lli a, b, c;
  while (cin >> a >> b >> c) {
    const lli mx = max({a, b, c});
    lli mn = 1LL << 62;

    for (int bit = 0; bit < (1 << 4) - 1; ++bit) {
      lli A = mx - (bool)(bit & (1 << 0));
      lli B = mx - (bool)(bit & (1 << 1));
      lli C = mx - (bool)(bit & (1 << 2));
      
      if (A < a) continue;
      if (B < b) continue;
      if (C < c) continue;
      
      lli diff = (A - a) + (B - b) + (C - c);
      // cout << (A - a) << ' ' << (B - b) << ' ' <<  (C - c) << endl;
      // cout << diff << endl;
      mn = min(mn, diff);
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

const int N = 100000 + 10;
const int M = N;
int a[N];
int day[M];

bool f(int limit, const int n, const int m)
{
  // cout << "============================== " << limit << endl;
  map<int, int> last;
  for (int i = 0; i < limit; ++i) {
    if (day[i]) last[day[i]] = i;
  }

  vector<pair<int, int>> v;
  each (i, last) v.push_back(make_pair(i.second, i.first));
  sort(v.begin(), v.end());
  queue<int> q;
  each (i, v) q.push(i.second);

  set<int> passed;
  int pre[n];
  fill(pre, pre + n, 0);
  for (int i = 0; i < limit; ++i) {
    const int j = day[i];
    if (j && last[j] == i) {
      if (pre[j] == a[j]) {
        passed.insert(j);
      }
      else return false;
    } else {
      while (q.size() && pre[q.front()] >= a[q.front()]) q.pop();
      if (q.size()) {
        ++pre[q.front()];
      }
    }
  }
  
  return passed.size() == m;
}

int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> day[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> a[i + 1];
    }
    int small = 0;
    int large = n;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (f(mid, n, m)) large = mid;
      else small = mid;
    }
    if (f(small, n, m)) cout << small << endl;
    else if (f(large, n, m)) cout << large << endl;
    else cout << -1 << endl;
    // break;
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
  int n, k;
  while (scanf("%d %d\n", &n, &k) == 2) {
    char s[n];
    scanf("%s\n", s);
    int g = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'G') g = i;
      if (s[i] == 'T') t = i;
    }
    queue<int> q;
    for (q.push(g); q.size(); q.pop()) {
      int a = q.front() - k;
      int b = q.front() + k;
      vector<int> v = {a, b};
      each (i, v) {
        if (0 <= i && i < n && s[i] != '#') {
          s[i] = '#';
          q.push(i);
        }
      }
    }
    puts(s[t] == 'T' ? "NO" : "YES");
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
  int n, n1, n2;
  while (scanf("%d%d%d", &n, &n1, &n2) == 3) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (n1 > n2) swap(n1, n2);
    double x = 0;
    double y = 0;
    for (int i = 0; i < n1; ++i) {
      x += v[i];
    }
    for (int i = n1; i < n1 + n2; ++i) {
      y += v[i];
    }
    // cout << x << ' ' << y << endl;
    printf("%.10lf\n", x / n1 + y / n2);
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
  lli n;
  while (scanf("%lld", &n) == 1) {
    const int N = 100;
    lli a[N];
    a[0] = a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for (int i = 4; i < N; ++i) {
      a[i] = a[i - 1] + a[i - 2];
    }
    for (int i = 0; i < 10; ++i) {
      // cout << a[i] << endl;
    }
    int j;
    for (int i = 0; i < N; ++i) {
      if (1000000000000000000 < a[i]) break;
      if (a[i] <= n) {
        j = i;
      }
    }
    printf("%d\n", j - 2);
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
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int mx = *max_element(a, a + n);
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += mx - a[i];
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

  string s;
  while (cin >> s) {
    string t = "RBYG";
    sort(t.begin(), t.end());
    do {
      bool f = true;
      map<char, int> cnt;
      for (int i = 0, j = 0; i < s.size(); ++i, ++j) {
        int k = j % t.size();
        f = f && (s[i] == '!' || s[i] == t[k]);
        if (s[i] == '!') ++cnt[t[k]];
      }
      if (f) {
        cout << cnt['R'] << ' ' << cnt['B'] << ' ' << cnt['Y'] << ' ' << cnt['G'] << endl;
        break;
      }
    } while (next_permutation(t.begin(), t.end()));
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

  int h, w, x, y;
  lli k;
  while (cin >> h >> w >> k >> x >> y) {
    vector<pair<int, int>> v;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        v.push_back(make_pair(i, j));
      }
    }
    for (int i = h - 2; 0 < i; --i) {
      for (int j = 0; j < w; ++j) {
        v.push_back(make_pair(i, j));
      }
    }

    lli cnt[h][w];
    fill(&cnt[0][0], &cnt[h - 1][w - 1] + 1, k / v.size());
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (i == 0 || i == h - 1) continue;
        cnt[i][j] *= 2;
      }
    }
    
    for (int i = 0; i < k % (lli)v.size(); ++i) {
      int j = i % v.size();
      ++cnt[v[j].first][v[j].second];
    }
    lli mn = *min_element(&cnt[0][0], &cnt[h - 1][w - 1] + 1);
    lli mx = *max_element(&cnt[0][0], &cnt[h - 1][w - 1] + 1);
    cout << mx << ' ' << mn << ' ' << cnt[x - 1][y - 1] << endl;
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

#define MX(a, b) (a) = max((a), (b))
#define MN(a, b) (a) = min((a), (b))

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ull n;
  string s;
  while (cin >> n >> s) {
    const int N = s.size() + 1;
    ull dp[N];
    const ull inf = ULLONG_MAX;
    fill(dp, dp + N, inf);
    dp[0] = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      unless (dp[i] < inf) continue;
      ull x = 0;
      for (size_t j = i; j < s.size(); ++j) {
        x = (x * 10LL) + (s[j] - '0');
        if (n <= x) break;
        MN(dp[j + 1], dp[i] * n + x);
        if (s[i] == '0') break;
      }
    }
    cout << dp[s.size()] << endl;
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
  int n, m, z;
  while (cin >> n >> m >> z) {
    map<int, int> cnt;
    for (int i = 1; i * n <= z; ++i) {
      ++cnt[i * n];
    }
    for (int i = 1; i * m <= z; ++i) {
      ++cnt[i * m];
    }
    int x = 0;
    each (i, cnt) {
      x += (i.second == 2);
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

  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int i = 0;
    int j = n - 1;
    while (i < j) {
      swap(a[i], a[j]);
      i += 2;
      j -= 2;
    }
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << a[i];
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

const int inf = 1 << 28;

class UnionFind {
public:
  vector<int> rank, p;
  UnionFind(int size)
  {
    rank.resize(size, -inf);
    p.resize(size, -inf);
  }
  void make(int a)
  {
    rank[a] = 0;
    p[a] = a;
  }
  void unite(int a, int b)
  {
    link(find(a), find(b));
  }
  int find(int a)
  {
    return (a == p[a]) ? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b)
  {
    return find(a) == find(b);
  }
  void link (int a, int b)
  {
    if (rank[a] > rank[b]) {
      p[b] = a;
    } else {
      p[a] = b;
      if(rank[a] == rank[b]) rank[b]++;
    }
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<int, int>> es;
    int c[n];
    vector<int> g[n];
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      es.push_back(make_pair(a, b));
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
      uf.make(i);
    }
    each (e, es) {
      if (c[e.first] == c[e.second]) {
        uf.unite(e.first, e.second);
      }
    }
    for (int i = 0; i < n; ++i) {
      uf.find(i);
    }
    set<int> r;
    for (int i = 0; i < n; ++i) {
      r.insert(uf.find(i));
    }
    int z = -1;
    for (int i = 0; i < n; ++i) {
      set<int> x;
      x.insert(uf.find(i));
      each (j, g[i]) {
        x.insert(uf.find(j));
      }
      if (r == x) {
        z = i;
        break;
      }
    }
    if (z == -1) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << z + 1 << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<string, int> m;
  m["Tetrahedron"] = 4;
  m["Cube"] = 6;
  m["Octahedron"] = 8;
  m["Dodecahedron"] = 12;
  m["Icosahedron"] = 20;

  int n;
  while (cin >> n) {
    lli sum = 0;
    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      sum += m[s];
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

  int n, m;
  while (cin >> n) {
    vector<pair<int, int>> a(n);
    each (i, a) cin >> i.first >> i.second;
    cin >> m;
    vector<pair<int, int>> b(m);
    each (i, b) cin >> i.first >> i.second;

    auto end = [] (pair<int, int> x, pair<int, int> y) {
      return x.first < y.first;
    };
    auto begin = [] (pair<int, int> x, pair<int, int> y) {
      return x.second < y.second;
    };
    sort(a.begin(), a.end(), begin);
    sort(b.begin(), b.end(), end);
    int y = b.back().first - a.front().second;

    // cout << "a: " << endl;
    // each (i, a) cout << i << endl;
    // cout << "b: "  << endl;
    // each (i, b) cout << i << endl;
    
    sort(a.begin(), a.end(), end);
    sort(b.begin(), b.end(), begin);
    int x = a.back().first - b.front().second;

    cout << max({0, x, y}) << endl;
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

lli f(const lli n, const lli m)
{
  auto fn = [&] (lli mid) {
    return (mid * (mid + 1) / 2) - ((mid - 1) * m) + (mid * m);
  };
  lli small = 0;
  lli large = 1LL << 31;
  while (small + 1 < large) {
    lli mid = (small + large) / 2;
    if (n <= fn(mid)) large = mid;
    else small = mid;
  }
  return large + m;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  while (cin >> n >> m) {
    cout << (n <= m ? n : f(n, m)) << endl;
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

  int a, b;
  while (cin >> a >> b) {
    for (int i = 0; ; ++i) {
      a *= 3;
      b *= 2;
      if (a > b) {
        cout << i+1 << endl;
        break;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while (cin >> n >> m) {
    vector<int> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    bool f = true;
    set<int> vis;
    for (int src = 0; src < n; ++src) {
      if (vis.count(src)) continue;
      vis.insert(src);
      queue<int> q;
      lli e = 0;
      lli v = 0;
      for (q.push(src); q.size(); q.pop()) {
        ++v;
        each (next, g[q.front()]) {
          ++e;
          if (vis.count(next) == 0) {
            vis.insert(next);
            q.push(next);
          }
        }
      }
      e /= 2;
      f = f && (v * (v - 1) / 2 == e);
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

  vector<string> names;
  for (char c = 'A'; c <= 'Z'; ++c) {
    for (char d = 'a'; d <= 'z'; ++d) {
      names.push_back(string("") + c + d);
    }
  }
  reverse(names.begin(), names.end());

  int n, k;
  while (cin >> n >> k) {
    const int m = n - k + 1;

    string a[n];
    
    string b[n];
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    int idx = -1;
    for (int i = 0; i < m; ++i) {
      if (b[i] == "YES") {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      for (int i = 0; i < n; ++i) {
        if (i) cout << ' ' ;
        cout << "Xx" ;
      }
      cout << endl;
      continue;
    }
    for (int i = 0; i < k; ++i) {
      a[idx + i] = names.back();
      names.pop_back();
    }
    for (int i = idx + 1, j = idx + k; i < m; ++i, ++j) {
      if (b[i] == "YES") {
        a[j] = names.back();
        names.pop_back();
      } else {
        a[j] = a[i];
      }
    }
    for (int i = idx - 1; 0 <= i; --i) {
      if (b[i] == "YES") {
        a[i] = names.back();
        names.pop_back();
      } else {
        a[i] = a[i + k - 1];
      }
    }
    
    for (int i = 0; i < n; ++i) {
      if (a[i].empty()) a[i] = '-';
      if (i) cout << ' ';
      cout << a[i];
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

  lli a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    lli x = b;
    lli y = d;
    for (int i = 0; i < 100000000; ++i) {
      if (x == y) break;
      if (x < y) x += a;
      else y += c;
    }
    cout << (x == y ? x : -1) << endl;
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

    vector<int> v[m];
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      v[i].resize(k);
      each (j, v[i]) cin >> j;
    }

    for (int i = 0; i < m; ++i) {
      sort(v[i].begin(), v[i].end());
      v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }

    bool f = false;
    for (int i = 0; i < m; ++i) {
      map<int, int> cnt;
      int mx = 0;
      each (j, v[i]) mx = max(mx, ++cnt[abs(j)]);
      f = f || (mx == 1);
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

  lli a, b;
  while (cin >> a >> b) {
    if (a == b) cout << a << endl;
    else cout << 2 << endl;
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
    string s = "aabb";
    for (int i = 0; i < n; ++i) {
      cout << s[i % s.size()];
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

  int n;
  while (cin >> n) {
    cout << (n - 1) / 2 << endl;
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

  const lli mod = 1e9 + 7;
  
  const int N = 1000000 + 10;
  lli x[N];
  x[0] = 0;
  x[1] = 1;
  for (int i = 2; i < N; ++i) {
    x[i] = (x[i - 1] << 1) + 1;
    x[i] %= mod;
  }

  string s;
  while (cin >> s) {
    int cnt = 0;
    lli sum = 0;
    each (c, s) {
      if (c == 'a') ++cnt;
      if (c == 'b') (sum += x[cnt]) %= mod;
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

  int n, m;
  while (cin >> n >> m) {
    vector<int> ice[n];
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      for (int j = 0; j < x; ++j) {
        int y;
        cin >> y;
        ice[i].push_back(y);
      }
    }
    vector<int> g[n];
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    map<int, int> color;
    set<int> used;
    function<void(int, int)> rec = [&] (int curr, int prev) {

      used.clear();
      each (i, ice[curr]) {
        if (color.count(i)) used.insert(color[i]);
      }
      int cnt = 1;
      each (i, ice[curr]) {
        if (color.count(i)) continue;
        while (used.count(cnt)) ++cnt;
        color[i] = cnt++;
      }

      each (next, g[curr]) {
        if (next != prev) rec(next, curr);
      }
      return ;
    };

    rec(0, -1);
    for (int i = 1; i <= m; ++i) {
      color[i] = max(color[i], 1);
    }

    int mx = 0;
    each (c, color) mx = max(mx, c.second);
    cout << mx << endl;
    each (c, color) cout << c.second << ' '; cout << endl;
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
  lli a, b;
  while (cin >> a >> b) {
    int turn = 0;
    int c = 1;
    while (c <= a) {
      ++turn;
      a -= c++;
      swap(a, b);
    }
    cout << (turn % 2 ? "Valera" : "Vladik") << endl;
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
    vector<int> p(n);
    each (i, p) cin >> i;
    while (m--) {
      int begin, end, x;
      cin >> begin >> end >> x;
      --begin;
      --end;
      --x;
      int cnt = 0;
      for (int i = begin; i <= end; ++i) {
        if (p[i] < p[x]) ++cnt;
      }
      // cout << begin << ' ' << end << ' ' << x << ' ' << cnt << endl;
      cout << (begin + cnt == x ? "Yes" : "No") << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;

    map<int, int> cnt;
    each (i, a) cnt[i] = count(a.begin(), a.end(), i);
    
    const int N = 5000 + 3;

    int mx[N];
    fill(mx, mx + N, 0);
    for (int i = 0; i < n; ++i) {
      mx[a[i]] = i;
    }
    int mn[N];
    fill(mn, mn + N, 1 << 29);
    for (int i = 0; i < n; ++i) {
      mn[a[i]] = min(mn[a[i]], i);
    }
    
    static int dp[N];
    fill(dp, dp + N, 0);

    for (int i = 0; i < n; ++i) {
      dp[i + 1] = max(dp[i + 1], dp[i]);
      int x = 0;
      if (mn[a[i]] == i) {
        bool vis[N];
        fill(vis, vis + N, false);
        int end = 0;
        for (int j = i; j < n; ++j) {
          if (!vis[a[j]]) {
            if (mn[a[j]] != j) break;
            end = max(end, mx[a[j]]);
            vis[a[j]] = true;
            x ^= a[j];
          }
          int& y = dp[j + 1];
          end = max(end, mx[a[j]]);
          if (end == j) y = max(y, dp[i] + x);
        }
      }
    }

    cout << *max_element(dp, dp + N) << endl;
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

  int l[4], s[4], r[4], p[4];
  while (cin
         >> l[0] >> s[0] >> r[0] >> p[0]
         >> l[1] >> s[1] >> r[1] >> p[1]
         >> l[2] >> s[2] >> r[2] >> p[2]
         >> l[3] >> s[3] >> r[3] >> p[3]
    ) {

    bool f = false;

    // s
    for (int i = 0; i < 4; ++i) {
      int j = (i + 2) % 4;
      if (s[i] && p[j]) f = true;
      if (s[i] && p[i]) f = true;
    }

    // l
    for (int i = 0; i < 4; ++i) {
      int j = (i + 3) % 4;
      if (l[i] && p[j]) f = true;
      if (l[i] && p[i]) f = true;
    }

    // r
    for (int i = 0; i < 4; ++i) {
      int j = (i + 1) % 4;
      if (r[i] && p[j]) f = true;
      if (r[i] && p[i]) f = true;
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

  int h, w;
  while (cin >> h >> w) {
    const int H = h;
    const int W = w + 2;
    bool g[H][W];
    for (int i = h - 1; 0 <= i; --i) {
      for (int j = 0; j < W; ++j) {
        char c;
        cin >> c;
        g[i][j] = c - '0';
      }
    }

    const int N = H + 1;
    const int inf = 1 << 28;
    pair<int, int> dp[N];
    fill(dp, dp + N, make_pair(inf, inf));
    dp[0].first = 0;

    vector<int> u[H];
    for (int i = 0; i < h; ++i) {
      { // >^
        int& x = dp[i + 1].second;
        x = min(x, dp[i].first + W);
      }
      { // <^
        int& x = dp[i + 1].first;
        x = min(x, dp[i].second + W);
      }
      vector<int> v;
      for (int j = 0; j < W; ++j) {
        if (g[i][j]) v.push_back(j);
      }
      if (v.size()) {
        // ><^
        int& x = dp[i + 1].first;
        x = min(x, dp[i].first + (v.back()) * 2 + 1);
        // <>^
        int& y = dp[i + 1].second;
        y = min(y, dp[i].second + (W - 1 - v.front()) * 2 + 1);
      } else {
        dp[i + 1].first  = dp[i].first + 1;
        dp[i + 1].second = dp[i].second + 1;
      }
      u[i] = v;
    }

    int mn = inf;
    for (int i = 0; i < h; ++i) {
      if (u[i].size()) {
        mn = inf;
        mn = min(mn, dp[i].first + u[i].back());
        mn = min(mn, dp[i].second + (W - 1 - u[i].front()));
      }
    }

    cout << (mn == inf ? 0 : mn) << endl;
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

lli f(vector<lli> a, lli k, lli S)
{
  if (a.size() < k) return 0;
  vector<lli> b;
  for (int i = 0; i < a.size(); ++i) {
    b.push_back(a[i] + (i + 1) * k);
  }

  sort(b.begin(), b.end());
  lli sum = accumulate(b.begin(), b.begin() + k, 0LL);
  
  if (S < sum) return 0;
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, S;
  while (cin >> n >> S) {
    vector<lli> a(n);
    each (i, a) cin >> i;

    lli small = 0;
    lli large = 1 << 28;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (f(a, mid, S)) small = mid;
      else large = mid;
    }

    if (0) {
    } else if (f(a, large, S)) {
      cout << large << ' ' << f(a, large, S) << endl;
    } else if (f(a, small, S)) {
      cout << small << ' ' << f(a, small, S) << endl;
    } else {
      cout << 0 << ' ' << 0 << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> x(n);
    vector<int> y(m);
    each (i, x) cin >> i;
    each (i, y) cin >> i;

    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());

    for (int i = 0, j = 0; i < x.size(); ++i) {
      if (x[i] == 0) {
        x[i] = y[j++];
      }
    }
    vector<int> z = x;
    sort(z.begin(), z.end());
    cout << (x != z ? "Yes" : "No") << endl;
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

bool valid(vector<int> a, vector<int> b, vector<int> c)
{
  int x = 0;
  int y = 0;
  for (int i = 0; i < c.size(); ++i) {
    x += (a[i] != c[i]);
    y += (b[i] != c[i]);
  }
  return x == 1 && y == 1 && set<int>(c.begin(), c.end()).size() == c.size();
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    vector<int> b(n);
    each (i, a) cin >> i;
    each (i, b) cin >> i;

    vector<int> c = a;

    map<int, int> cnt_a;
    map<int, int> cnt_b;

    each (i, a) ++cnt_a[i];
    each (i, b) ++cnt_b[i];

    for (int i = 0; i < n; ++i) {
      if (cnt_a[a[i]] == 2) {
        for (int j = 1; j <= n; ++j) {
          c[i] = j;
          if (valid(a, b, c)) {
            i = 1 << 28;
            break;
          }
          c[i] = a[i];
        }
      }
    }

    each (i, c) cout << i << ' ' ; cout << endl;
    assert(valid(a, b, c));
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
  string s;
  int q;
  while (cin >> n >> s >> q) {
    map<pair<int, char>, int> memo;
    while (q--) {
      int x;
      char c;
      cin >> x >> c;
      pair<int, char> key = make_pair(x, c);
      if (memo.count(key)) {
        cout << memo[key] << endl;
        continue;
      }
      int mx = 0;
      int begin = 0;
      int end = 0;
      int y = x;
      while (begin < s.size()) {
        while (end < s.size()) {
          if (s[end] != c && y == 0) break;
          y -= (s[end] != c);
          ++end;
        }
        mx = max(mx, end - begin);
        y += (s[begin++] != c);
      }
      cout << (memo[key] = mx) << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, m;
  char c;
  while (cin >> h >> c >> m) {
    int cnt = 0;
    while (true) {
      char buff[100];
      sprintf(buff, "%02d:%02d", h, m);
      string s(buff);
      string t = s;
      reverse(t.begin(), t.end());
      if (s == t) break;
      ++m;
      h = (h + m / 60) % 24;
      m %= 60;
      ++cnt;
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

  int n, k, q;
  while (cin >> n >> k >> q) {
    const int N = 200000 + 10;
    lli x[N];
    fill(x, x + N, 0);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      ++x[a];
      --x[b + 1];
    }
    for (int i = 1; i < N; ++i) {
      x[i] += x[i - 1];
    }
    lli y[N];
    for (int i = 0; i < N; ++i) {
      y[i] = (k <= x[i]);
    }
    for (int i = 1; i < N; ++i) {
      y[i] += y[i - 1];
    }
    while (q--) {
      int a, b;
      cin >> a >> b;
      cout << y[b] - y[a - 1] << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const int M = 100 + 5;
  static int g[M][M];
  
  int h, w;
  while (cin >> h >> w) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int s, t, u;
    s = t = -1;
    int best = 1 << 29;
    
    auto show = [&] () {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << g[i][j] << ' ';
        }
        cout << endl;
      }
      return ;
    };
    
    static int x[M][M];
    copy(&g[0][0], &g[M - 1][M - 1] + 1, &x[0][0]);
    const int A = g[0][0];
    for (int _a = 0; _a <= A; ++_a) {
      copy(&x[0][0], &x[M - 1][M - 1] + 1, &g[0][0]);
      const int a = _a;
      const int b = max(g[0][0] - a, a - g[0][0]);
      u = g[0][0];
      
      for (int i = 0; i < h; ++i) g[i][0] -= a;
      for (int j = 0; j < w; ++j) g[0][j] -= b;

      for (int i = 0; i < h; ++i) {
        const int sub = abs(g[i][0]);
        for (int j = 0; j < w; ++j) g[i][j] -= sub;
        u += sub;
      }

      for (int j = 0; j < w; ++j) {
        const int sub = abs(g[0][j]);
        for (int i = 0; i < h; ++i) g[i][j] -= sub;
        u += sub;
      }

      int cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cnt += (g[i][j] == 0);
        }
      }
      if (cnt == h * w && best > u) {
        s = a;
        t = b;
        best = u;
      }
    }

    if (s == -1 && t == -1) cout << -1 << endl;
    else {
      cout << best << endl;
      copy(&x[0][0], &x[M - 1][M - 1] + 1, &g[0][0]);
      const int a = s;
      const int b = t;

      for (int i = 0; i < h; ++i) g[i][0] -= a;
      for (int k = 0; k < a; ++k) cout << "col " << 1 << endl;
      for (int j = 0; j < w; ++j) g[0][j] -= b;
      for (int k = 0; k < b; ++k) cout << "row " << 1 << endl;

      for (int i = 0; i < h; ++i) {
        const int sub = g[i][0];
        for (int j = 0; j < w; ++j) g[i][j] -= sub;
        for (int j = 0; j < sub; ++j) cout << "row " << i + 1 << endl;
      }

      for (int j = 0; j < w; ++j) {
        const int sub = g[0][j];
        for (int i = 0; i < h; ++i) g[i][j] -= sub;
        for (int i = 0; i < sub; ++i) cout << "col " << j + 1 << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli a, b;
  while (cin >> a >> b) {
    lli n = 1;
    for (lli i = 2; i <= min(a, b); ++i) {
      n *= i;
    }
    cout << n << endl;
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

  int x, y;
  string s, t;
  while (cin >> x >> y >> s >> t) {
    vector<int> v(t.size() + 1);

    for (int i = 0; i + s.size() <= t.size(); ++i) {
      vector<int> u;
      for (int j = 0; j < s.size(); ++j) {
        if (t[i + j] != s[j]) {
          u.push_back(j);
        }
      }
      if (u.size() < v.size()) {
        v = u;
      }
    }
    cout << v.size() << endl;
    each (i, v) cout << i + 1 << ' '; cout << endl;
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

struct S {
  int begin, end;
  lli cost;
  S(int b, int e, lli c) : begin(b), end(e), cost(c) {}
  lli operator () (){
    return end - begin + 1;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  while (cin >> n >> x) {
    vector<S> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      v.push_back(S(a, b, c));
    }
    const int X = 2 * 100000 + 1;
    static vector<pair<int, lli>> u[X];
    fill(u, u + X, vector<pair<int, lli>>());
    each (i, v) {
      u[i()].push_back(make_pair(i.begin, i.cost));
    }
    for (int i = 0; i < X; ++i) {
      sort(u[i].begin(), u[i].end());
    }

    static vector<lli> acc[X];
    fill(acc, acc + X, vector<lli>());
    for (int i = 0; i < X; ++i) {
      if (u[i].empty()) continue;
      vector<lli> v(u[i].size(), u[i].back().second);
      for (int j = v.size() - 2; 0 <= j; --j) {
        v[j] = min(v[j + 1], u[i][j].second);
      }
      acc[i] = v;
    }
    
    const lli inf = 1LL << 60;
    lli mn = inf;
    each (i, v) {
      const int j = x - i();
      unless (0 <= j) continue;
      auto itr = lower_bound(u[j].begin(), u[j].end(), make_pair(i.end + 1, 0LL));
      if (itr == u[j].end()) continue;
      const int k = distance(u[j].begin(), itr);
      mn = min(mn, i.cost + acc[j][k]);
      // cout << i.begin << ' ' << i.end << ' ' << i.cost << ": " << *itr << endl;
    }
    cout << (mn == inf ? -1 : mn) << endl;
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

  const lli mod = 1e9 + 7;
  const int N = 5 * 1000000 + 4;

  static lli fact[N];
  for (int i = 0; i < N; ++i) {
    fact[i] = i;
  }
  for (int i = 2; i < N; ++i) {
    if (fact[i] == i) {
      for (int j = 2; i * j < N; ++j) {
        fact[i * j] = min<lli>({i, fact[i * j]});
      }
    }
  }
  
  static lli z[N];
  for (lli i = 1; i < N; ++i) {
    z[i] = i * (i - 1) / 2LL;
  }
  for (lli i = 2; i < N; ++i) {
    for (lli j = i; 1 < j; j /= fact[j]) {
      z[i] = min(z[i], z[i / fact[j]] + (i * (fact[j] - 1LL) / 2LL));
    }
  }

  lli t, small, large;
  while (cin >> t >> small >> large) {
    lli x = 0;
    lli y = 1;
    for (int i = small; i <= large; ++i) {
      (x += z[i] % mod * y) %= mod;
      (y *= t) %= mod;
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

  lli n, a, b;
  while (cin >> n >> a >> b) {
    lli c = 0;
    lli cnt = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x == 1) {
        if (a) --a;
        else if (b) { --b; ++c; }
        else if(c) --c;
        else cnt += 1;
      }
      if (x == 2) {
        if (b) --b;
        else cnt += 2;
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

    int mn_h = 1 << 29;
    int mn_w = 1 << 29;
    int mx_h = -1;
    int mx_w = -1;
    int cnt = 0;
    
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'B') {
          ++cnt;
          mn_h = min(mn_h, i);
          mn_w = min(mn_w, j);
          mx_h = max(mx_h, i);
          mx_w = max(mx_w, j);
        }
      }
    }

    const int inf = 1 << 29;
    int mn = inf;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; i + k < h && j + k < w; ++k) {
          pair<int, int> a = make_pair(i, j);
          pair<int, int> b = make_pair(i + k, j + k);
          if (a.first <= mn_h && a.second <= mn_w && mx_h <= b.first && mx_w <= b.second) {
            mn = min(mn, (k + 1) * (k + 1) - cnt);
          }
        }
      }
    }

    if (cnt == 0) mn = 1;
    cout << (mn == inf ? -1 : mn) << endl;
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

struct S {
  pair<int, int> p;
  int i;
};

bool operator < (const S& a, const S& b)
{
  return a.p < b.p;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<S> v;
    string t[n];
    int len = 0;
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        v.push_back((S){make_pair(x - 1, x - 1 + t[i].size()), i});
        len = max<int>(len, x + t[i].size() - 1);
      }
    }
    sort(v.begin(), v.end());

    // each (i, v) cout << i.p << ' ' << t[i.i] << endl;
    
    string s(len, '@');

    int idx = 0;
    each (i, v) {
      idx = max(idx, i.p.first);
      for (int j = idx; j < i.p.second; ++j) {
        s[j] = t[i.i][j - i.p.first];
        ++idx;
      }
    }
    
    replace(s.begin(), s.end(), '@', 'a');
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    // cout << endl;
    if (n == k + 1) {
      cout << 2 << endl;
      for (int i = 0; i < k; ++i) {
        cout << 1 << ' ' << 2 + i << endl;
      }
      continue;
    }
    if (k + 2 == n) {
      cout << 3 << endl;
      int cnt = 2;
      for (int i = 0; i < k; ++i) {
        cout << 1 << ' ' << cnt++ << endl;
      }
      int a = cnt++ - 1;
      int b = cnt++ - 1;
      cout << a << ' ' << b << endl;
      continue;
    }
    if ((n - 1 - k) <= k) {
      cout << 4 << endl;
      vector<int> v(k, 1);
      int cnt = 2;
      for (int i = 0; i < n - 1 - k; ++i) {
        cout << 1 << ' ' << (v[i] = cnt++) << endl;
      }
      for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ' << cnt++ << endl;
      }
      continue;
    }

    int x = 0;
    int cost = 1 << 29;
    for (int i = 2; i <= k; ++i) {
      int c = 0;
      const int s = (n - 1 - k) / i;
      const int t = (n - 1 - k) % i;
      c += s * 2 + (1 <= t) + (2 <= t) + 2;

      if (cost > c) {
        x = i;
        cost = c;
      }
    }

    const int s = (n - 1 - k) / x;
    const int t = (n - 1 - k) % x;
    cout << cost << endl;
    int cnt = 2;
    vector<int> v;
    for (int i = 0; i < x; ++i) {
      int prev = 1;
      for (int j = 0; j < s + (i < t); ++j) {
        cout << prev << ' ' << cnt << endl;
        prev = cnt++;
      }
      v.push_back(prev);
    }
    for (int i = 0; i < min<int>(v.size(), k); ++i) {
      cout << v[i] << ' ' << cnt++ << endl;
    }
    for (int i = 0; i < k - v.size(); ++i) {
      cout << v.back() << ' ' << cnt++ << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    lli turn = (n / k); // + (bool)(n % k);
    cout << (turn % 2 ? "YES" : "NO") << endl;
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

  string s, t;
  while (cin >> s >> t) {
    set<int> good(s.begin(), s.end());
    const bool f = count(t.begin(), t.end(), '*');
    int q;
    cin >> q;
    while (q--) {
      cin >> s;
      if (!f) {
        bool f = (s.size() == t.size());
        for (int i = 0; f && i < t.size(); ++i) {
          if (t[i] == '?') f = f && good.count(s[i]);
          else f = f && (s[i] == t[i]);
        }
        cout << (f ? "YES" : "NO") << endl;
      } else {
        bool f = true;
        for (int i = 0; i < s.size() && t[i] != '*'; ++i) {
          if (t[i] == '?') f = f && good.count(s[i]);
          else f = f && (s[i] == t[i]);
          s[i] = '@';
        }
        const int s_size = s.size();
        const int t_size = t.size();
        for (int i = 0; 0 <= min<int>(t_size, s_size) - i && t[t_size - i] != '*'; ++i) {
          if (t[t_size - i] == '?') f = f && good.count(s[s_size - i]);
          else f = f && (s[s_size - i] == t[t_size - i]);
          s[s_size - i] = '@';
        }

        f = f && (t_size == count(s.begin(), s.end(), '@') + 1);
        each (c, s) f = f && (good.count(c) == 0);
        cout << (f ? "YES" : "NO") << endl;
      }
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

constexpr int NODE = 100000 + 5;
constexpr int DEPTH = log2(NODE) + 1;

int T[NODE][DEPTH], P[NODE], L[NODE];

int addLevel(int node)
{
  if (L[node] != -1) return L[node];
  else return L[node] = addLevel(P[node]) + 1;
}

// ! keep P[root] = root
void LCA(const int &node)
{
  const int root = 0;
  fill(L, L + node, -1);
  L[root] = 0;
  for (int i = 0; i < node; ++i) {
    L[i] = addLevel(i);
  }

  fill(&T[0][0], &T[NODE - 1][DEPTH], -1);
  for (int i = 0; i < node; ++i) {
    T[i][0] = P[i];
  }
  for(int j = 1; (1 << j) < node; ++j){
    for (int i = 0; i < node; ++i) {
      if (T[i][j - 1] != -1) {
        T[i][j] = T[T[i][j - 1]][j - 1];
      }
    }
  }

  return ;
}

int query(int a, int b)
{
  if (L[a] < L[b]) swap(a, b);

  int lg = 1;
  while ((1 << lg) <= L[a]) ++lg;
  --lg;

  for (int i = lg; 0 <= i; --i) {
    if (L[a] - (1 << i) >= L[b]) {
      a = T[a][i];
    }
  }

  if (a == b) return a;
  for (int i = lg; 0 <= i; --i) {
    if (T[a][i] != -1 && T[a][i] != T[b][i]) {
      a = T[a][i];
      b = T[b][i];
    }
  }

  return P[a];
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    vector<int> e[n];
    for (int i = 0; i < n - 1; ++i) {
      int j;
      cin >> j;
      e[i + 1].push_back(j - 1);
      e[j - 1].push_back(i + 1);
    }
    int depth[n];
    function<void(int, int)> rec = [&] (int curr, int prev) {
      each (next, e[curr]) {
        if (next != prev) {
          P[next] = curr;
          depth[next] = depth[curr] + 1;
          rec(next, curr);
        }
      }
      return ;
    };

    const int root = 0;
    depth[root] = 0;
    rec(root, -1);
    P[root] = root;
    LCA(n);

    while (q--) {
      vector<int> v(3);
      each (i, v) { cin >> i; --i; }
      int mx = 0;
      sort(v.begin(), v.end());
      do {
        int x = query(v[0], v[1]);
        int y = query(v[0], v[2]);
        int z = query(v[1], v[2]);

        if (depth[z] > max(depth[x], depth[y])) {
          int w = query(v[0], z);
          mx = max(mx, depth[z] - depth[w] + depth[v[0]] - depth[w] + 1);
        } else {
          mx = max(mx, depth[v[0]] - max(depth[x], depth[y]) + 1);
        }
      } while (next_permutation(v.begin(), v.end()));
      cout << mx << endl;
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

  int n, k;
  while (cin >> n >> k) {
    string s;
    cin >> s;
    map<char, int> m;
    int mx = 0;
    each (c, s) mx = max(mx, ++m[c]);
    cout << (mx <= k ? "YES" : "NO") << endl;
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
    each (i, a) i %= 2;
    
    cout << (count(a.begin(), a.end(), 0) == a.size() ? "Second" : "First") << endl;
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
    vector<pair<int, int>> a;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      a.push_back(make_pair(x, i));
    }

    vector<pair<int, int>> b;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      b.push_back(make_pair(x, i));
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    
    // each (i, a) cout << i << endl;
    // cout << endl;
    // each (i, b) cout << i << endl;
    // cout << endl;

    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
      c[b[i].second] = a[i].first;
    }
    each (i, c) cout << i << ' ' ; cout << endl;
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
    const int N = 100 + 5;
    const int ODD = 0;
    const int EVEN = ODD ^ 1;
    bool dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, false);
    if (a[0] % 2) {
      dp[0][EVEN] = true;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (dp[i][j]) {
          int len = 0;
          for (int k = i; k < n; ++k) {
            ++len;
            if (len % 2 && a[k] % 2) {
              dp[k + 1][j ^ 1] = true;
            }
          }
        }
      }
    }
    cout << (dp[n][ODD] ? "Yes" : "No") << endl;
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

point normal(point v)
{
  return v * point(0, -1);
}

double dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

namespace CCW{
  enum{ RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if( cross(b, c) < 0 )return CCW::RIGHT;
  if( cross(b, c) > 0 )return CCW::LEFT;
  if( dot(b, c) < 0 )return CCW::BACK;
  if( norm(b) < norm(c) )return CCW::FRONT;
  return CCW::OTHER;
}

double angle(point a, point b)
{
  double r = a.real() - b.real();
  double i = a.imag() - b.imag();
  return i / r;
}

bool intersect_ll(point a1, point a2, point b1, point b2)
{
  return angle(a1, a2) != angle(b1, b2);
}

bool fn1(vector<point> v)
{
  vector<int> idx1;
  vector<int> idx2;
  idx1.push_back(0);
  idx1.push_back(1);

  const int N = v.size();
  for (int i = 2; i < N; ++i) {
    int dir = ccw(v[0], v[1], v[i]);
    if (dir == CCW::FRONT || dir == CCW::BACK || dir == 0) {
      idx1.push_back(i);
    } else {
      idx2.push_back(i);
    }
  }

  for (int i = 0; i + 2 < idx2.size(); ++i) {
    int a = idx2[i + 0];
    int b = idx2[i + 1];
    int c = idx2[i + 2];
    int dir = ccw(v[a], v[b], v[c]);
    if (dir == CCW::FRONT || dir == CCW::BACK || dir == 0) {
    } else {
      return false;
    }
  }

  if (2 <= idx1.size() && 2 <= idx2.size()) {
    if (intersect_ll(v[idx1[0]], v[idx1[1]],
                     v[idx2[0]], v[idx2[1]]))
    {
      return false;
    }
  }

  if (idx1.empty()) return false;
  if (idx2.empty()) return false;

  // cout << "A: " ; each (i, idx1) cout << v[i] << ' '; cout << endl;
  // cout << "B: " ; each (i, idx2) cout << v[i] << ' '; cout << endl;

  return true;
}

bool fn2(vector<point> v)
{
  swap(v[1], v[2]);
  return fn1(v);
}

bool fn3(vector<point> v)
{
  swap(v[0], v[2]);
  return fn1(v);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<point> v;
    for (int i = 0; i < n; ++i) {
      double y;
      cin >> y;
      v.push_back(point(i + 1, y));
    }

    cout << (fn1(v) || fn2(v) || fn3(v) ? "Yes" : "No") << endl;
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

  const int N = 1000000;
  lli x[N];
  for (lli i = 0; i < N; ++i) {
    x[i] = (i - 1) * i / 2;
  }

  lli n;
  while (cin >> n) {
    char c = 'a';
    if (n == 0) cout << 'a' << endl;
    while (n) {
      int i = lower_bound(x, x + N, n) - x;
      if (n < x[i]) --i;
      n -= x[i];
      cout << string(i, c++);
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
  
  lli n;
  int k;
  while (cin >> n >> k) {
    lli x = n;
    
    int cnt2 = 0;
    while (x && cnt2 < k && x % 2 == 0) {
      ++cnt2;
      x /= 2;
    }
    int cnt5 = 0;
    while (x && cnt5 < k && x % 5 == 0) {
      ++cnt5;
      x /= 5;
    }

    cout << x << string(k, '0') << endl;
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
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int k, f;
      cin >> k >> f;
      v.push_back(make_pair(k, f));
    }
    set<int> vis;
    for (int flats = 1; flats <= 200; ++flats) {
      auto fn = [&] (lli floor) {
        return make_pair<lli, lli>(floor * flats - flats + 1, floor * flats);
      };
      bool f = true;
      each (i, v) {
        pair<int, int> p = fn(i.second);
        f = f && p.first <= i.first && i.first <= p.second;
      }
      if (f) {
        int x = (n / flats) + (bool)(n % flats);
        vis.insert(x);
      }
    }
    if (vis.size() == 1) cout << *vis.begin() << endl;
    else cout << -1 << endl;
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

  int n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    // Rabbit's and Owl's houses is a meters
    // Rabbit's and Eeyore's house is b meters
    // Owl's and Eeyore's house is c meters.

    const int N = 3;
    int g[N][N];
    g[0][1] = g[1][0] = a;
    g[0][2] = g[2][0] = b;
    g[1][2] = g[2][1] = c;

    lli sum = 0;
    int i = 0;
    --n;
    while (n--) {
      int j = (i + 1) % N;
      int k = (i - 1 + N) % N;
      if (g[i][j] < g[i][k]) {
        sum += g[i][j];
        i = j;
      } else {
        sum += g[i][k];
        i = k;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k, m;
  while (cin >> n >> k >> m) {
    vector<int> v(n);
    each (i, v) cin >> i;
    map<int, int> cnt;
    each (i, v) ++cnt[i % m];

    int x = -1;
    each (i, cnt) {
      if (k <= i.second) x = i.first;
    }

    if (x == -1) cout << "No" << endl;
    else {
      cout << "Yes" << endl;
      for (int i = 0; i < v.size() && k; ++i) {
        if (v[i] % m == x) {
          cout << v[i] << ' ';
          --k;
        }
      }
      cout << endl;
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

lli fn(lli x)
{
  if (x < 0) return x;
  lli sum = x;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    vector<lli> v;
    for (int i = 0; i <= 10000; ++i) {
      if (fn(n - i) == n) {
        v.push_back(n - i);
      }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    each (i, v) cout << i << endl;
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
    set<int> idx;
    vector<string> v = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    for (int i = 0; i < s.size(); ++i) {
      string t = s.substr(i);
      each (j, v) {
        auto x = t.find(j);
        if (x != string::npos) idx.insert(x + i);
      }
    }
    cout << (idx.size() == 1 ? "YES" : "NO") << endl;
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
    const int N = 5000 + 10;
    const int inf = 1 << 29;
    int dp[N][3];
    fill(&dp[0][0], &dp[N - 1][3 - 1] + 1, 0);

    for (int i = 0; i < s.size(); ++i) {
      { // Aba
        int& x = dp[i + 1][0];
        int& y = dp[i + 1][1];
        x = max(x, dp[i][0] + (s[i] == 'a'));
        y = max(y, dp[i][0] + (s[i] == 'b'));
      }
      { // aBa
        int& x = dp[i + 1][1];
        int& y = dp[i + 1][2];
        x = max(x, dp[i][1] + (s[i] == 'b'));
        y = max(y, dp[i][1] + (s[i] == 'a'));
      }
      { // abA
        int& x = dp[i + 1][2];
        x = max(x, dp[i][2] + (s[i] == 'a'));
      }
    }
    
    int mx = 0;
    for (int i = 0; i < N; ++i) {
      mx = max(mx, dp[i][0]);
      mx = max(mx, dp[i][1]);
      mx = max(mx, dp[i][2]);
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
    vector<int> v;
    for (int i = 1; i < n; i += 2) {
      v.push_back(i);
    }
    for (int i = 0; i < n; i += 2) {
      v.push_back(i);
    }
    for (int i = 1; i < n; i += 2) {
      v.push_back(i);
    }
    cout << v.size() << endl;
    each (i, v) cout << i+1 << ' ' ; cout << endl;
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

  int h, w, k;
  while (cin >> h >> w >> k) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;
    queue<pair<int, int>> q;
    int cost[h][w];
    const int inf = 1 << 29;
    fill(&cost[0][0], &cost[h - 1][w - 1] + 1, inf);
    cost[a][b] = 0;
    for (q.push(make_pair(a, b)); q.size() && cost[c][d] == inf; q.pop()) {
      pair<int, int> p = q.front();
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      for (int d = 0; d < 4; ++d) {
        for (int x = 1; x <= k; ++x) {
          int ni = p.first + di[d] * x;
          int nj = p.second + dj[d] * x;
          unless (0 <= ni && ni < h) break;
          unless (0 <= nj && nj < w) break;
          if (g[ni][nj] == '#') break;
          if (cost[ni][nj] == inf) {
            cost[ni][nj] = cost[p.first][p.second] + 1;
            q.push(make_pair(ni, nj));
          }
        }
      }
    }
    cout << (cost[c][d] == inf ? -1 : cost[c][d]) << endl;
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
    lli x = 0;
    for (int i = 0; i < n; ++i) {
      if (i) ++x;
      lli s, d;
      cin >> s >> d;
      if (x <= s) {
        x = s;
      } else {
        lli m = ((x - s) / d) + (bool)((x - s) % d);
        x = s + m * d;
      }
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

  int n;
  lli k;
  while (cin >> n >> k) {
    deque<int> q;

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      q.push_back(a);
    }

    int x = n;
    while (true) {
      int a = q.front();
      q.pop_front();
      int b = q.front();
      q.pop_front();
      int cnt = 1;
      int c = max(a, b);
      q.push_back(min(a, b));
      while (cnt < min<lli>(n, k)) {
        if (c < q.front()) {
          break;
        }
        ++cnt;
        q.push_back(q.front());
        q.pop_front();
      }
      if (min<lli>(n, k) == cnt) {
        x = c;
        break;
      }
      q.push_front(c);
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

  int n;
  while (cin >> n) {
    vector<pair<char, int>> v(n);
    each (i, v) cin >> i.first >> i.second;

    const int N = 10;
    int x[N];
    const int _0 = 0;
    const int _1 = 1;
    const int K = 2;
    const int R = 3;
    fill(x, x + N, K);

    each (i, v) {
      if (i.first == '|') {
        for (int j = 0; j < N; ++j) {
          if (i.second & (1 << j)) {
            x[j] = _1;
          }
        }
      }
      if (i.first == '&') {
        for (int j = 0; j < N; ++j) {
          unless (i.second & (1 << j)) {
            x[j] = _0;
          }
        }
      }
      if (i.first == '^') {
        for (int j = 0; (1 << j) <= i.second; ++j) {
          if (i.second & (1 << j)) {
            if (0) ;
            else if (x[j] == K) x[j] = R;
            else if (x[j] == R) x[j] = K;
            else if (x[j] == _0) x[j] = _1;
            else if (x[j] == _1) x[j] = _0;
          }
        }
      }
    }

    // for (int i = 0; i < N; ++i) {
    //   if (x[i] == _0) cout << 0 ;
    //   if (x[i] == _1) cout << 1 ;
    //   if (x[i] == K) cout << 'K' ;
    //   if (x[i] == R) cout << 'R' ;
    // }
    // cout << endl;
    
    vector<pair<char, int>> u;
    { // and
      int a = 1024 - 1;
      for (int i = 0; i < N; ++i) {
        if (x[i] == _0) {
          a -= (1 << i);
        }
      }
      u.push_back(make_pair('&', a));
    }
    { // or
      int a = 0;
      for (int i = 0; i < N; ++i) {
        if (x[i] == _1) {
          a |= (1 << i);
        }
      }
      u.push_back(make_pair('|', a));
    }
    { // reverse
      int a = 0;
      for (int i = 0; i < N; ++i) {
        if (x[i] == R) {
          a |= (1 << i);
        }
      }
      u.push_back(make_pair('^', a));
    }

    cout << u.size() << endl;
    each (i, u) cout << i.first << ' ' << i.second << endl;
    
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
    reverse(s.begin(), s.end());
    bool f = false;
    int z = 0;
    each (c, s) {
      z += (c == '0');
      f = f || (6 <= z && c == '1');
    }
    cout << (f ? "yes" : "no") << endl;
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

set<int> s[3];

int fn(int n)
{
    int x = 0;
    for (int i = 1; i < 10; ++i) {
      bool ok = false;
      for (int j = 0; j < 3; ++j) {
        ok = ok || s[j].count(i);
      }
      if (!ok) return x;
      x = i;
    }

    for (int i = 10; i < 100; ++i) {
      bool ok = false;
      int p = i / 10;
      int q = i % 10;
      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
          ok = ok || (a != b && s[a].count(p) && s[b].count(q));
        }
      }
      if (!ok) return x;
      x = i;
    }

    for (int i = 100; i < 1000; ++i) {
      bool ok = false;

      char buff[10];
      sprintf(buff, "%d", i);
      int p = buff[0] - '0';
      int q = buff[1] - '0';
      int r = buff[2] - '0';

      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
          for (int c = 0; c < 3; ++c) {
            if (a == b) continue;
            if (b == c) continue;
            if (a == c) continue;
            ok = ok || (s[a].count(p) && s[b].count(q) && s[c].count(r));
          }
        }
      }
      if (!ok) return x;
      x = i;
    }

    return 999;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    s[0].clear();
    s[1].clear();
    s[2].clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 6; ++j) {
        int a;
        cin >> a;
        s[i].insert(a);
      }
    }
    cout << fn(n) << endl;
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

bool fn(vector<int> v)
{
  v.insert(v.begin(), -1);
  {
    vector<int> a;
    a.push_back(v[1]);
    a.push_back(v[3]);
    a.push_back(v[5]);
    a.push_back(v[7]);
    a.push_back(v[9]);
    a.push_back(v[11]);
    a.push_back(v[24]);
    a.push_back(v[22]);
    vector<int> b;
    b.push_back(v[2]);
    b.push_back(v[4]);
    b.push_back(v[6]);
    b.push_back(v[8]);
    b.push_back(v[10]);
    b.push_back(v[12]);
    b.push_back(v[23]);
    b.push_back(v[21]);
    assert(a.size() == b.size());
    bool x = true;
    bool y = true;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 2) % a.size();
      int k = (i - 2 + a.size()) % a.size();
      x = x && (a[i] == b[j]);
      y = y && (a[i] == b[k]);
    }
    bool z = true;
    z = z && (v[13] == v[14] && v[14] == v[15] && v[15] == v[16]);
    z = z && (v[17] == v[18] && v[18] == v[19] && v[19] == v[20]);
    if (z && (x || y)) return true;
  }

  {
    vector<int> a;
    a.push_back(v[13]);
    a.push_back(v[14]);
    a.push_back(v[5]);
    a.push_back(v[6]);
    a.push_back(v[17]);
    a.push_back(v[18]);
    a.push_back(v[21]);
    a.push_back(v[22]);
    vector<int> b;
    b.push_back(v[15]);
    b.push_back(v[16]);
    b.push_back(v[7]);
    b.push_back(v[8]);
    b.push_back(v[19]);
    b.push_back(v[20]);
    b.push_back(v[23]);
    b.push_back(v[24]);
    assert(a.size() == b.size());
    bool x = true;
    bool y = true;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 2) % a.size();
      int k = (i - 2 + a.size()) % a.size();
      x = x && (a[i] == b[j]);
      y = y && (a[i] == b[k]);
    }
    bool z = true;
    z = z && (v[1] == v[2] && v[2] == v[3] && v[3] == v[4]);
    z = z && (v[9] == v[10] && v[10] == v[11] && v[11] == v[12]);
    if (z && (x || y)) return true;    
  }
  

  {
    vector<int> a;
    a.push_back(v[1]);
    a.push_back(v[2]);
    a.push_back(v[18]);
    a.push_back(v[20]);
    a.push_back(v[12]);
    a.push_back(v[11]);
    a.push_back(v[15]);
    a.push_back(v[13]);
    vector<int> b;
    b.push_back(v[3]);
    b.push_back(v[4]);
    b.push_back(v[17]);
    b.push_back(v[19]);
    b.push_back(v[10]);
    b.push_back(v[9]);
    b.push_back(v[16]);
    b.push_back(v[14]);
    assert(a.size() == b.size());
    bool x = true;
    bool y = true;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 2) % a.size();
      int k = (i - 2 + a.size()) % a.size();
      x = x && (a[i] == b[j]);
      y = y && (a[i] == b[k]);
    }
    bool z = true;
    z = z && (v[5] == v[6] && v[6] == v[7] && v[7] == v[8]);
    z = z && (v[21] == v[22] && v[22] == v[23] && v[23] == v[24]);
    if (z && (x || y)) return true;    
  }

  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    vector<int> v(24);
    each (i, v) unless (cin >> i) return 0;
    cout << (fn(v) ? "YES" : "NO") << endl;
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

  while (true) {
    vector<int> v;
    for (int i = 0; i < 6; ++i) {
      int x;
      if (cin >> x) {
        v.push_back(x);
      }
    }

    if (v.size() != 6) break;

    bool f = false;
    sort(v.begin(), v.end());
    do {
      int a = 0;
      int b = 0;
      a += v[0];
      a += v[1];
      a += v[2]; 
      b += v[3];
      b += v[4];
      b += v[5];
      f = f || (a == b);
    } while (next_permutation(v.begin(), v.end()));
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

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v) cin >> i;

    const int c = set<int>(v.begin(), v.end()).size();
    reverse(v.begin(), v.end());

    int x = 0;
    set<int> vis;
    each (i, v) {
      vis.insert(i);
      if (vis.size() == c) {
        x = i;
        break;
      }
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

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v) cin >> i;
    
    int mx = 0;
    int cnt = 0;
    map<int, int> m;
    int time = 0;

    auto show = [&] () {
      cout << "(";
      each (i, m) cout << i << " ";
      cout << ")" << endl;
      return ;
    };
    
    each (i, v) {
      if (m.count(i)) {
        if (--m[i] == 0) {
          m.erase(i);
        }
      } else {
        ++cnt;
      }
      ++time;
      ++m[time];
      // show();
      mx = max<int>(mx, cnt);
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
    const int N = 'z' - 'a' + 1;
    set<int> g[N];
    set<int> used;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j + 1 < s.size(); ++j) {
        int src = s[j] - 'a';
        int dst = s[j + 1] - 'a';
        g[src].insert(dst);
      }
      each (c, s) used.insert(c - 'a');
    }

    bool f = false;
    for (int i = 0; i < N; ++i) {
      if (1 < g[i].size()) {
        f = true;
      }
    }
    if (f) {
      cout << "NO" << endl;
      continue;
    }

    int deg[N];
    fill(deg, deg + N, 0);
    for (int i = 0; i < N; ++i) {
      if (g[i].size()) ++deg[*g[i].begin()];
    }

    set<int> vis;
    string s;
    function<void(int)> rec = [&] (int curr) {
      vis.insert(curr);
      s += 'a' + curr;
      each (next, g[curr]) {
        if (vis.count(next)) throw "";
        rec(next);
      }
      return true;
    };

    each (i, used) {
      if (deg[i] == 0) {
        try {
          rec(i);
        } catch (const char* e) {
          s = "NO";
          break;
        }
      }
    }
    cout << (s.size() != used.size() ? "NO" : s) << endl;
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
    vector<lli> b(n);
    each (i, a) cin >> i;
    each (i, b) cin >> i;

    lli sum = accumulate(a.begin(), a.end(), 0LL);
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    cout << (b[0] + b[1] < sum ? "NO" : "YES") << endl;
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

    reverse(v.begin(), v.end());
    int cnt = 0;
    int x = 0;
    each (i, v) {
      if (x == 0) ++cnt;
      x = max<int>({0, x - 1, i});
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

lli gcd(lli a, lli b)
{
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    each (i, v) cin >> i;


    {
      lli x = v[0];
      each (i, v) x = gcd(x, i);
      if (x != 1) {
        cout << -1 << endl;
        continue;
      }
    }

    const lli one = count(v.begin(), v.end(), 1);
    const lli inf = 1LL << 60;
    lli x = one ? n - one : inf;

    for (int i = 0; i < n; ++i) {
      lli z = v[i];
      int cnt = 0;
      for (int j = i + 1; j < n; ++j) {
        z = gcd(z, v[j]);
        ++cnt;
        if (z == 1) {
          x = min<lli>(x, cnt + n - 1);
          break;
        }
      }
    }
    cout << (x == inf ? -1 : x) << endl;
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

    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> next;
    for (int i = 0; i < b.size(); ++i) {
      next[b[i]] = b[(i + 1) % b.size()];
    }

    each (i, a) cout << next[i] << ' '; cout << endl; 
  }
  
  return 0;
}

// (setq c-electric-flag nil)
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
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        for (int k = j + 1; k < s.size(); ++k) {
          cnt += (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q');
        }
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
    
const lli mod = 1000000007;

lli fn(lli x, lli p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  lli y = fn(x, p / 2);
  y = (y * y) % mod;
  if (p % 2) {
    y = (y * x) % mod;
  }
  return y;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  int k;
  while (cin >> n >> m >> k) {
    lli y = fn(fn(2, n - 1), m - 1);
    if (k == 1) {
      cout << y << endl;
    } else {
      cout << ((n + m) % 2 ? 0 : y) << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v) cin >> i;
    int mn = 360;
    for (int i = 0; i < v.size(); ++i) {
      int sum = 0;
      for (int j = 0; j < v.size(); ++j) {
        int k = (i + j) % v.size();
        sum += v[k];
        int a = sum;
        int b = 360 - sum;
        mn = min(mn, abs(a - b));
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

  int n, m;
  string s;
  while (cin >> n >> m >> s) {
    while (m--) {
      int a, b;
      char c, d;
      cin >> a >> b >> c >> d;
      for (int i = a; i <= b; ++i) {
        if (s[i - 1] == c) {
          s[i - 1] = d;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  char buff[100];
  vector<lli> v;
  for (int i = 1; ; ++i) {
    sprintf(buff, "%d", i);
    string s(buff);
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    if (s.size() % 2) continue;
    v.push_back(stoll(s));
    if (v.size() == 1e5) break;
  }
  sort(v.begin(), v.end());

  lli k, mod;
  while (cin >> k >> mod) {
    lli sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += v[i];
      sum %= mod;
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

  int n, m;
  while (cin >> n >> m) {
    const int N = 100 + 5;
    static bool g[N][N];
    fill(&g[0][0], &g[N - 1][N - 1] + 1, false);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      for (int j = a; j <= b; ++j) {
        g[a][j] = true;
      }
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          g[i][j] |= (g[i][k] && g[k][j]);
        }
      }
    }
    cout << (g[0][m] ? "YES" : "NO") << endl;
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

const int N = 1e4 + 10;
vector<int> g[N];

int req[N];
int curr[N];
const int UNDEFINED = -1;

int rec(int curr, int color)
{
  int sum = (color != req[curr]);
  each (next, g[curr]) {
    sum += rec(next, req[curr]);
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
      cin >> req[i];
    }
    fill(curr, curr + N, UNDEFINED);
    int cost = rec(0, -2);
    cout << cost << endl;
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

  string a, b;
  while (cin >> a >> b) {
    string s;
    s += a[0];
    for (int i = 1; i < a.size(); ++i) {
      if (a[i] < b[0]) {
        s += a[i];
      } else {
        break;
      }
    }
    s += b[0];
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    if (n == 1) cout << 1 << endl;
    else {
      lli sum = 0;
      for (int i = n; 1 <= i; i -= 2) {
        sum += i;
      }
      cout << sum << endl;
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

const int N = 5000 + 10;
char types[N];

const lli mod = 1e9 + 7;

lli memo[N][N];
lli rec(int nth, int indent)
{
  if (!types[nth]) return 1;
  lli& ret = memo[nth][indent];
  if (ret != -1) return ret;
  lli sum = 0;

  if (types[nth] == 'f') {
    sum += rec(nth + 1, indent + 1);
    sum %= mod;
  }
  if (types[nth] == 's') {
    sum += rec(nth + 1, indent);
    sum %= mod;
  }
  if (indent && nth && types[nth - 1] == 's') {
    sum += rec(nth, indent - 1);
    sum %= mod;
  }

  return ret = sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> types[i];
    }
    types[n] = '\0';
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, 0) << endl;
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
    vector<pair<char, int>> v;
    each (c, s) {
      if (v.empty()) {
        v.push_back(make_pair(c, 1));
      } else {
        if (v.back().first == c) ++v.back().second;
        else v.push_back(make_pair(c, 1));
      }
    }

    int cnt = 0;
    while (1 < v.size()) {
      const vector<pair<char, int>> V = v;
      vector<pair<char, int>> u;
      for (int i = 0; i < v.size(); ++i) {
        if (i) --v[i].second;
        if (i + 1 < v.size()) --v[i].second;
      }
      each (i, v) {
        if (i.second <= 0) continue;
        if (u.empty()) u.push_back(i);
        else {
          if (u.back().first == i.first) u.back().second += i.second;
          else u.push_back(i);
        }
      }
      if (u == V) break;
      ++cnt;
      v = u;
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

const int N = 1e5 + 5;
map<int, char> p;
vector<int> g[N];

int memo[N];

int rec(int curr) {
  int& ret = memo[curr];
  if (ret != -1) return ret;
  int mx = 0;
  each (next, g[curr]) {
    mx = max(mx, rec(next) + (p[curr] == 0 && p[next] == 1));
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vector<int>());
    p.clear();
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      p[i] = x;
    }

    int deg[N];
    fill(deg, deg + N, 0);

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      ++deg[b];
    }

    fill(memo, memo + N, -1);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 0) {
        mx = max(mx, rec(i) + p[i]);
      }
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

  lli a, b;
  while (cin >> a >> b) {
    lli x, y, z;
    cin >> x >> y >> z;

    a -= x * 2;

    a -= y;
    b -= y;

    b -= z * 3;

    cout << abs(min<lli>(0, a) + min<lli>(0, b)) << endl;
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

  lli n, k;
  while (cin >> n >> k) {
    if (k == 1) {
      cout << n << endl;
    } else {
      lli x = n;
      for (lli i = 1; i <= n; i *= 2) {
        if ((n & i) == 0) {
          x |= i;
        }
      }
      cout << x << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, h, m;
  while (cin >> x >> h >> m) {
    int cnt = 0;
    auto fn = [&] () {
      return (h % 10 == 7) || (m % 10 == 7);
    };
    // printf("%02d:%02d\n", h, m);
    while (!fn()) {
      ++cnt;
      m -= x;
      if (m < 0) --h;
      m = (m + 60) % 60;
      h = (h + 24) % 24;
      // printf("%02d:%02d\n", h, m);
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

  lli n, k;
  while (cin >> n >> k) {
    const int N = 70;
    map<int, int> cnt;
    for (int i = 0; i < 60; ++i) {
      cnt[i] = 0;
      if (n & (1LL << i)) {
        cnt[i] = 1;
      }
    }
    int sum = 0;
    each (i, cnt) sum += i.second;
    for (int i = N - 1; -N < i; --i) {
      if (k < sum + cnt[i]) break;
      sum += cnt[i];
      cnt[i - 1] += cnt[i] + cnt[i];
      cnt[i] = 0;
    }
    vector<int> v;
    for (int i = -N; i < N; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        v.push_back(i);
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    while (v.size() < k) {
      int x = v.back();
      v.pop_back();
      v.push_back(x - 1);
      v.push_back(x - 1);
    }
    if (v.size() == k) {
      cout << "Yes" << endl;
      each (i, v) cout << i << ' ';
      cout << endl;
    } else {
      cout << "No" << endl;
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

bool is_prime(int x)
{
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, m;
  while (cin >> n >> m) {
    const int P = 524287;
    if (n == 2) {
      cout << P << ' ' << P << endl;
      cout << 1 << ' ' << 2 << ' ' << P << endl;
      continue;
    }
    
    map<pair<int, int>, int> vis;

    vis[make_pair(n-1, n)] = P - (n - 2);
    for (int i = 1; i + 1 < n; ++i) {
      vis[make_pair(i, i + 1)] = 1;
    }

    cout << P << ' ' << P << endl;
    each (e, vis) {
      cout << e.first.first << ' ' << e.first.second << ' ' << e.second << endl;
    }
    m -= vis.size();
    
    for (int i = 1; i <= n && m; ++i) {
      for (int j = i + 2; j <= n && m; ++j) {
        cout << i << ' ' << j << ' ' << 1000000000 << endl;
        --m;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    unless (a < b) swap(a, b);

    const int N = 1000 + 10;
    lli sum[N];
    sum[0] = 0;
    for (int i = 1; i < N; ++i) {
      sum[i] = sum[i - 1] + i;
    }

    lli mn = 1LL << 62;
    for (int i = a; i <= b; ++i) {
      int x = abs(a - i);
      int y = abs(b - i);
      mn = min(mn, sum[x] + sum[y]);
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

  int n, a, b;
  while (cin >> n >> a >> b) {
    unless (a < b) swap(a, b);
    
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i + 1);
    }
    int x = 0;
    bool flg = true;
    while (flg) {
      // each (i, v) cout << i << ' ' ; cout << endl;
      
      ++x;
      vector<int> u;
      for (int i = 0; i < v.size(); i += 2) {
        if (v[i] == a && v[i + 1] == b) {
          flg = false;
        }
        if (0) ;
        else if (v[i] == a || v[i + 1] == a) u.push_back(a);
        else if (v[i] == b || v[i + 1] == b) u.push_back(b);
        else u.push_back(v[i]);
      }
      v = u;
    }
    if (v.size() < 2) cout << "Final!" << endl;
    else cout << x << endl;
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
    vector<lli> x(n);
    each (i, x) cin >> i;

    sort(x.begin(), x.end());
    
    const lli mn = *min_element(x.begin(), x.end());
    const lli mx = *max_element(x.begin(), x.end());

    if (mn == mx) {
      cout << n << endl;
      each (i, x) cout << i << ' ';
      cout << endl;
    }
    if (mn + 1 == mx) {
      cout << n << endl;
      each (i, x) cout << i << ' ';
      cout << endl;      
    }
    if (mn + 2 == mx) {
      const lli mid = mn + 1;
      int a = count(x.begin(), x.end(), mn);
      int b = count(x.begin(), x.end(), mid);
      int c = count(x.begin(), x.end(), mx);
      const int A = a;
      const int B = b;
      const int C = c;
      
      int p = a;
      int q = b;
      int r = c;

      lli best = n;
      while (2 <= b) {
        b -= 2;
        ++a;
        ++c;
        lli score = min(A, a) + min(B, b) + min(C, c);
        if (best > score) {
          best = score;
          p = a;
          q = b;
          r = c;
        }
      }
      while (a && c) {
        --a;
        --c;
        b += 2;
        lli score = min(A, a) + min(B, b) + min(C, c);
        if (best > score) {
          best = score;
          p = a;
          q = b;
          r = c;
        }
      }      

      cout << best << endl;
      for (int i = 0; i < p; ++i) cout << mn << ' ';
      for (int i = 0; i < q; ++i) cout << mid << ' ';
      for (int i = 0; i < r; ++i) cout << mx << ' ';
      cout << endl;
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

const int N = 100000 + 10;
vector<int> g[N];
map<int, int> cnt;

void rec(int curr, int depth)
{
  ++cnt[depth];
  each (next, g[curr]) {
    rec(next, depth + 1);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());

    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      g[x].push_back(i);
    }

    cnt.clear();
    rec(0, 0);
    int sum = 0;
    each (i, cnt) sum += i.second % 2;
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

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    replace(&g[0][0], &g[h - 1][w - 1] + 1, '.', 'D');

    bool f = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] != 'S') continue;
        int di[] = {0, 0, -1, +1};
        int dj[] = {-1, +1, 0, 0};
        for (int d = 0; d < 4; ++d) {
          const int ni = i + di[d];
          const int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          if (g[ni][nj] == 'W') {
            f = false;
          }
        }
      }
    }
    if (f) {
      cout << "Yes" << endl;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cout << g[i][j];
        }
        cout << endl;
      }
    } else {
      cout << "No" << endl;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    bool flg = true;
    set<char> v({'a', 'i', 'u', 'e', 'o'});
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'n') continue;
      if (v.count(s[i]) == 0) {
        // cout << s[i] << ' ' << s[i + 1] << ' ' << flg << endl;
        flg = flg && (i + 1 < s.size()) && v.count(s[i + 1]);
      }
    }
    cout << (flg ? "YES" : "NO") << endl;
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
    vector<pair<int, int>> v(n);
    each (i, v) cin >> i.first >> i.second;

    if (v[0].first < v[0].second) swap(v[0].first, v[0].second);
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (v[i].first < v[i + 1].first) {
        swap(v[i + 1].first, v[i + 1].second);
      }
      if (v[i].first >= v[i + 1].second && v[i + 1].second > v[i + 1].first) {
        swap(v[i + 1].first, v[i + 1].second);
      }
    }
    
    bool flg = true;
    for (int i = 0; i + 1 < v.size(); ++i) {
      flg = flg && (v[i].first >= v[i + 1].first);
    }
    // each (i, v) cout << i.first << ' ' ; cout << endl;
    cout << (flg ? "YES" : "NO") << endl;
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
    sort(v.begin(), v.end());

    queue<int> a;
    queue<int> b;
    each (i, v) a.push(i);
    each (i, v) b.push(i);

    int cnt = 0;
    while (a.size() && b.size()) {
      if (a.front() < b.front()) {
        ++cnt;
        a.pop();
        b.pop();
      } else {
        b.pop();
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

bool isleap(int y)
{
  if(y%4 == 0){
    if(y%100 == 0 && y%400 != 0)return false;
    return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  int n;
  char of[100];
  char type[100];
  const int D[12] = {31,
                     28 + isleap(2016),
                     31,
                     30, 
                     31, 
                     30, 
                     31, 
                     31, 
                     30, 
                     31, 
                     30, 
                     31};      
  int d[400];
  d[1] = 4;
  for (int i = 2; i < 400; ++i) {
    d[i] = (d[i - 1] + 1) % 7;
  }
  const int N = accumulate(D, D + 12, 0);
  while (scanf("%d%s%s", &n, of, type) == 3) {
    if (strcmp(type, "month") == 0) {
      int sum = 0;
      for (int i = 0; i < 12; ++i) {
        sum += (n <= D[i]);
      }
      printf("%d\n", sum);
    }
    if (strcmp(type, "week") == 0) {
      --n;
      int sum = 0;
      for (int i = 1; i <= N; ++i) {
        sum += (d[i] == n);
      }
      printf("%d\n", sum);
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

string b2s(lli n)
{
  string s;
  while (n) {
    s += '0' + (n % 2);
    n /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}

int main(int argc, char *argv[])
{
  lli a, b;
  while (scanf("%lld%lld", &a, &b) == 2) {
    int cnt = 0;
    for (int len = 0; len < 62; ++len) {
      const lli mask = (1LL << (len - 1)) - 1;
      for (int nth = 0; nth < len - 2; ++nth) {
        const lli x = mask ^ (1LL << nth);
        const bool f = x && (a <= x) && (x <= b) && (mask & (1LL << nth));
        cnt += f;
        if (f) {
          // cout << "> " << b2s(mask) << endl;
          // cout << "> " << b2s((1LL << nth)) << endl;
          // cout << "> " << b2s(x) << endl;          
          // cout << endl;
        }
      }
    }
    printf("%d\n", cnt);
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

const int N = 500 + 10;
char g[N][N];

lli x[N][N];
lli y[N][N];

lli acc_x[N][N];
lli acc_y[N][N];

lli acc[N][N];

int main(int argc, char *argv[])
{
  int h, w;
  while (scanf("%d %d\n", &h, &w) == 2) {
    fill(&g[0][0], &g[N - 1][N - 1] + 1, '#');
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        scanf("%c", &(g[i][j]));
      }
      scanf("\n");
    }

    fill(&x[0][0], &x[N - 1][N - 1], 0);
    fill(&y[0][0], &y[N - 1][N - 1], 0);

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j + 1 < w; ++j) {
        x[i][j] = (g[i][j] == '.' && g[i][j + 1] == '.');
      }
    }

    for (int i = 0; i + 1 < h; ++i) {
      for (int j = 0; j < w; ++j) {
        y[i][j] = (g[i][j] == '.' && g[i + 1][j] == '.');
      }
    }

    fill(&acc_x[0][0], &acc_x[N - 1][N - 1], 0);
    fill(&acc_y[0][0], &acc_y[N - 1][N - 1], 0);

    for (int j = 0; j < N; ++j) {
      for (int i = 1; i < N; ++i) {
        acc_x[i][j] += acc_x[i - 1][j] + x[i - 1][j];
      }
    }
        
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        acc_y[i][j] += acc_y[i][j - 1] + y[i][j - 1];
      }
    }

    fill(&acc[0][0], &acc[N - 1][N - 1], 0);
    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        acc[i][j] += acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
        acc[i][j] += x[i - 1][j - 1] + y[i - 1][j - 1];
      }
    }

    // puts("x");
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     printf(" %lld", x[i][j]);
    //   }
    //   puts("");
    // }
    // puts("acc_x");
    // for (int i = 0; i <= h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     printf(" %lld", acc_x[i][j]);
    //   }
    //   puts("");
    // }
    // puts("y");
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     printf(" %lld", y[i][j]);
    //   }
    //   puts("");
    // }
    // puts("acc_y");
    // for (int i = 0; i <= h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     printf(" %lld", acc_y[i][j]);
    //   }
    //   puts("");
    // }    
    // puts("acc");
    // for (int i = 0; i <= h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     printf("%3lld", acc[i][j]);
    //   }
    //   puts("");
    // }
    int q;
    scanf("%d", &q);
    while (q--) {
      int r1, c1, r2, c2;
      scanf("%d %d %d %d\n", &r1, &c1, &r2, &c2);
      // --r1; --c1; --r2; --c2;
      // cout << make_pair(r1, c1) << ' ' << make_pair(r2, c2) << endl;
      lli sum = acc[r2][c2] - acc[r2][c1 - 1] - acc[r1 - 1][c2] + acc[r1 - 1][c1 - 1];
      // cout << acc[r2][c2] << ' ' << acc[r2][c1 - 1] << ' ' << acc[r1 - 1][c2] << ' ' <<  acc[r1 - 1][c1 - 1] << endl;
      // cout << sum << endl;

      sum -= acc_x[r2][c2 - 1] - acc_x[r1 - 1][c2 - 1];
      // cout << " - " << acc_x[r2][c2 - 1] << ' ' <<  acc_x[r1][c2 - 1] << endl;

      sum -= acc_y[r2 - 1][c2] - acc_y[r2 - 1][c1 - 1];
      // cout << " - " << acc_y[r2 - 1][c2] << ' ' << acc_y[r2 - 1][c1] << endl;

      printf("%lld\n", sum);
      // puts(""); 
    }
    // break;
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
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
      v.push_back((i + 1) * 5);
    }
    int mx = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (bit & (1 << i)) {
          sum += v[i];
        }
      }
      
      if (sum + k <= 4 * 60) {
        mx = max(mx, __builtin_popcount(bit));
      }
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

  string s;
  while (cin >> s) {

    set<char> v = {'a', 'e', 'i', 'o', 'u'};
    int cnt = 0;
    each (c, s) {
      if ('a' <= c && c <= 'z') {
        cnt += v.count(c);
      } else {
        cnt += ((c - '0') % 2 == 1);
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  while (cin >> h >> w) {
    pair<int, int> src, dst;
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'E') dst = make_pair(i, j);
      }
    }

    string s;
    cin >> s;

    int cnt = 0;
    
    string D = "UDLR";
    sort(D.begin(), D.end());
    do {
      pair<int, int> p = src;
      bool succ = false;
      each (c, s) {
        const int d = c - '0';
        if (D[d] == 'U') --p.first;
        if (D[d] == 'D') ++p.first;
        if (D[d] == 'L') --p.second;
        if (D[d] == 'R') ++p.second;
        unless (0 <= p.first && p.first < h) break;
        unless (0 <= p.second && p.second < w) break;
        if (g[p.first][p.second] == '#') break;
        if (p == dst) succ = true;
      }
      cnt += succ;
    } while (next_permutation(D.begin(), D.end()));
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

double dist(point a, point b)
{
  double x = a.real() - b.real();
  double y = a.imag() - b.imag();
  x *= x;
  y *= y;
  return sqrt(x + y);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  double R;
  while (cin >> n >> R) {
    vector<double> xs(n);
    each (i, xs) cin >> i;

    vector<point> ps;
    each (x, xs) {
      double mx = R;
      each (p, ps) {
        if (2.0 * R < abs(p.real() - x)) continue;
        double small = p.imag();
        double large = 1000 * 1000 * 10;
        for (int loop = 50; loop--; ) {
          double mid = (small + large) / 2.0;
          if (dist(p, point(x, mid)) <= 2.0 * R) small = mid;
          else large = mid;
        }
        mx = max(mx, small);
      }
      ps.push_back(point(x, mx));
    }

    for (int i = 0; i < ps.size(); ++i) {
      if (i) printf(" ");
      printf("%.10lf", ps[i].imag());
    }
    puts("");
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

  lli n, m;
  while (cin >> n >> m) {
    vector<lli> v(n);
    each (i, v) cin >> i;
    vector<lli> u;

    lli rem = m;
    each (i, v) {
      // cout << rem << endl;
      if (rem > i) {
        u.push_back(0);
        rem -= i;
      } else {
        lli x = i - rem;
        u.push_back(x / m + 1);
        rem = m - x % m;
      }
    }
    each (i, u) cout << i << ' '; cout << endl;
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

  int n, m, q;
  string s, t;
  while (cin >> n >> m >> q >> s >> t) {
    s += "$";

    const int N = n + 2;
    int occ[N];
    fill(occ, occ + N, 0);

    for (int i = 0; i < n; ++i) {
      bool f = true;
      for (int j = 0; f && j < m; ++j) {
        f = f && (s[i + j] == t[j]);
      }
      occ[i + 1] += f;
    }
    // for (int i = 0; i < N; ++i) cout << i << ' ' << occ[i] << endl;
    for (int i = 0; i <= n; ++i) occ[i + 1] += occ[i];
    // for (int i = 0; i < N; ++i) cout << i << ' ' << occ[i] << endl;
    
    while (q--) {
      int begin;
      int end;
      cin >> begin >> end;
      if (end - begin + 1 < m) {
        cout << 0 << endl;
        continue;
      }
      cout << occ[end - m + 1] - occ[begin - 1] << endl;
      // cout << make_pair(begin, end) << ' ' << make_pair(end - m + 1, begin - 1) << endl;
    }
    // cout << endl;
    // return 0;
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

  lli n, m;
  while (cin >> n >> m) {
    lli x = 0;
    for (int i = 0; i < min<lli>(n, 60); ++i) {
      if (m & (1LL << i)) {
        x |= 1LL << i;
      }
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

const int N = 1000 + 10;
vector<int> g[N];

bool is_leaf(int x)
{
  return g[x].size() == 0;
}

bool rec(int curr)
{
  if (g[curr].size() == 0) return true;
  int sum = 0;
  each (next, g[curr]) sum += is_leaf(next);
  if (sum < 3) return false;
  each (next, g[curr]) if (!rec(next)) return false;
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());

    for (int i = 1; i < n; ++i) {
      int j;
      cin >> j;
      --j;
      g[j].push_back(i);
    }

    cout << (rec(0) ? "Yes" : "No") << endl;
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
  lli L;
  while (cin >> n >> L) {
    const lli N = 35;
    lli cost[N];
    fill(cost, cost + N, 1LL << 60);
    for (int i = 0; i < n; ++i) {
      cin >> cost[i];
    }

    for (int i = 0; i + 1 < N; ++i) {
      cost[i + 1] = min(cost[i + 1], cost[i] * 2);
    }
    
    lli v[N];
    for (int i = 0; i < N; ++i) {
      v[i] = 1LL << i;
    }

    lli mn = 1LL << 60;
    for (int i = n - 1; 0 <= i; --i) {
      lli sum = 0;
      lli x = L;
      for (int j = i; 0 <= j; --j) {
        lli a = x / v[j];
        if (x % v[j]) ++a;
        mn = min(mn, sum + cost[j] * a);

        sum += cost[j] * (x / v[j]);
        x %= v[j];
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

struct S {
  int first, second, idx;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, T;
  while (cin >> n >> T) {
    vector<S> a(n);
    each (i, a) cin >> i.first >> i.second;
    for (int i = 0; i < n; ++i) {
      a[i].idx = i;
    }
    sort(a.begin(), a.end(), [] (auto x, auto y) { return x.second < y.second; });
    auto f = [&] (int m) {
      lli sum = 0;
      int cap = m;
      each (i, a) {
        if (cap == 0) break;
        if (m <= i.first) {
          --cap;
          sum += i.second;
        }
      }
      return cap == 0 && sum <= T;
    };
    int small = 0;
    int large = a.size() + 1;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (f(mid)) small = mid;
      else large = mid;
    }
    cout << small << endl;
    vector<int> v;
    for (int i = 0; i < a.size() && v.size() < small; ++i) {
      if (small <= a[i].first) {
        v.push_back(a[i].idx);
      }
    }
    cout << v.size() << endl;
    each (i, v) cout << i+1 << ' ';
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
  lli a, b, c;
  while (scanf("%lld%lld%lld", &a, &b, &c) == 3) {
    bool f = false;
    for (int i = 0; i <= 10000; ++i) {
      lli d = (c - a * i);
      f = f || (0 <= d && d % b == 0);
    }
    puts(f ? "Yes" : "No");
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

int f(lli n)
{
  int cnt = 0;
  while (n && n % 5 == 0) {
    n /= 5;
    ++cnt;
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  lli n;
  while (scanf("%lld", &n) == 1) {
    lli _5 = 0;
    vector<lli> v;
    for (int i = 5; _5 <= n; ++i) {
      if (i % 5 == 0) _5 += f(i);
      if (_5 == n) v.push_back(i);
    }
    printf("%d\n", (int)v.size());
    for (int i = 0; i < v.size(); ++i) {
      if (i) printf(" ");
      printf("%lld", v[i]);
    }
    if (v.size()) puts("");
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

const int N = 10000 + 10;

const ull P = 37;

ull rhash(string s)
{
  lli h = 0;
  each (c, s) h = (h * P) + (tolower(c) - 'a' + 1);
  return h;
}

string S;
vector<string> v;
vector<ull> vh;
vector<int> path;

ull H[N][1000 +10];
int memo[N];
int rec(int curr)
{
  if (S.size() <= curr) return curr == S.size();
  int& ret = memo[curr];
  if (ret != -1) return ret;

  for (int i = 0; i < v.size(); ++i) {
    if (vh[i] == H[curr][v[i].size()]) {
      if (rec(curr + v[i].size())) {
        path.push_back(i);
        return ret = 1;
      }
    }
  }

  return ret = 0;
}

int main(int argc, char *argv[])
{
  int n, m;
  char buff[10000 + 10];
  while (scanf("%d\n", &n) == 1) {
    v.clear();
    vh.clear();
    path.clear();
    fill(memo, memo + N, -1);
    
    scanf("%s\n", buff);
    S = string(buff);

    scanf("%d\n", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%s\n", buff);
      v.push_back(string(buff));
    }

    reverse(S.begin(), S.end());
    for (int i = 0; i < S.size(); ++i) {
      lli h = 0;
      for (int j = 0; j < 1000 && i + j < S.size(); ++j) {
        h = (h * P) + (tolower(S[i + j]) - 'a' + 1);
        H[i][j + 1] = h;
      }
    }

    for (int i = 0; i < v.size(); ++i) {
      vh.push_back(rhash(v[i]));
    }

    rec(0);
    for (int i = 0; i < path.size(); ++i) {
      if (i) printf(" ");
      printf("%s", v[path[i]].c_str());
    }
    puts("");
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
  while (scanf("%d", &n) == 1) {
    map<lli, int> m;
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      lli x;
      scanf("%lld", &x);
      ++m[x];
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int mx = 2;
    map<pair<lli, lli>, int> vis;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        lli prev = v[i];
        lli curr = v[j];
        --m[prev];
        --m[curr];
        if (m[prev] < 0 || m[curr] < 0) {
          ++m[prev];
          ++m[curr];
          continue;
        }
        vector<lli> fib = {prev, curr};
        while (true) {
          lli next = curr + prev;
          if (m.count(next) == 0 || m[next] <= 0) break;
          fib.push_back(next);
          --m[next]; 
          prev = curr;
          curr = next;
        }
        mx = max<int>(mx, fib.size());
        each (i, fib) ++m[i];
      }
    }
    printf("%d\n", mx);
  }

  return 0;
}
```
