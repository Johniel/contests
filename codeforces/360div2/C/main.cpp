#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

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
