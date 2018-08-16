# codeforces/GoodBye2015/C

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
