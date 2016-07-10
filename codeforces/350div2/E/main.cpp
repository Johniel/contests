#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

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
