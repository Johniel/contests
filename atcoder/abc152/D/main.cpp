// atcoder/abc152/D/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    map<pair<int, int>, lli> cnt;
    for (int i = 1; i <= n; ++i) {
      string s = to_string(i);
      int a = s.front() - '0';
      int b = s.back() - '0';
      ++cnt[make_pair(a, b)];
    }
    lli sum = 0;
    for (int i = 0; i <= 9; ++i) {
      for (int j = 0; j <= 9; ++j) {
        sum += cnt[make_pair(i, j)] * cnt[make_pair(j, i)];
      }
    }
    cout << sum << endl;
  }

  return 0;
}


// // atcoder/abc152/D/main.cpp
// // author: @___Johniel
// // github: https://github.com/johniel/

// #include <bits/stdc++.h>

// #define each(i, c) for (auto& i : c)
// #define unless(cond) if (!(cond))

// using namespace std;

// typedef long long int lli;
// typedef unsigned long long ull;
// typedef complex<double> point;

// template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
// template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
// template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
// template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

// template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
// template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

// constexpr lli mod = 1e9 + 7;

// int main(int argc, char *argv[])
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   int n;
//   while (cin >> n) {
//     const string s = to_string(n);

//     const int N = 6;
//     const int M = 10;
//     const int K = 2;
//     static lli dp[N][M][M][K];
//     fill(&dp[0][0][0][0], &dp[N - 1][M - 1][M - 1][K - 1] + 1, 0);
//     // for (int i = 1; i <= s.front() - '0'; ++i) {
//     //   dp[1][i][i][false] = 1;
//     //   cout << 0 << ' ' <<i << ' ' << false << " = " << 1 << endl;
//     // }
//     dp[0][0][0][0] = 1;

//     for (int i = 0; i < s.size(); ++i) {
//       for (int begin = 0; begin <= 9; ++begin) {
//         for (int j = 0; j <= 9; ++j) {
//           for (int k = false; k <= true; ++k) {
//             for (int a = 0; a <= (k ? 9 : s[i] - '0'); ++a) {
//               int b = begin;
//               if (begin == 0 && a) b = a;
//               dp[i + 1][b][a][a < s[i] - '0'] += dp[i][begin][j][k];
//             }
//           }
//         }
//       }
//     }

//     lli sum = 0;
//     for (int i = 1; i <= 9; ++i) {
//       for (int j = 1; j <= 9; ++j) {
//         // lli a = 0;
//         // lli b = 0;
//         // for (int k = 1; k <= s.size(); ++k) {
//         //   lli x = dp[k][i][j][true] + dp[k][i][j][false];
//         //   lli y = dp[k][j][i][true] + dp[k][j][i][false];
//         //   a += dp[k][i][j][true] + dp[k][i][j][false];
//         //   b += dp[k][j][i][true] + dp[k][j][i][false];
//         //   // if (a && b) cout << make_pair(i, j) << k << ' ' << x << ' ' << y << endl;
//         // }
//         lli a = dp[s.size()][i][j][true] + dp[s.size()][i][j][false];
//         lli b = dp[s.size()][j][i][true] + dp[s.size()][j][i][false];
//         sum += a * b;
//       }
//     }
//     cout << sum << endl;
//   }

//   return 0;
// }
