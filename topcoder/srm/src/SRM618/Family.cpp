#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int N = 100+ 10;
vector<int> g[N];

const string T = "Possible";
const string F = "Impossible";

char color[N];

bool rec(int curr, char C)
{
  color[curr] = C;
  for (int i = 0; i < g[curr].size(); ++i) {
    int next = g[curr][i];
    if (color[next] && color[curr] == color[next]) {
      return false;
    }
    if (color[next] && color[curr] != color[next]) {
      continue;
    }
    if (!rec(next, (C == 'A' ? 'B' : 'A'))) {
      return false;
    }
  }
  return true;
}

class Family {
public:
  string isFamily(vector <int> parent1, vector <int> parent2)
  {
    fill(g, g + N, vector<int>());
    const int M = parent2.size();

    vector< pair<int, int> > es;

    for (int i = 0; i < M; ++i) {
      if (parent1[i] == -1 && parent2[i] == -1) continue;
      if (parent1[i] == -1 || parent2[i] == -1) return F;
      if (i < parent1[i] || i < parent2[i]) return F;
      g[parent1[i]].push_back(parent2[i]);
      g[parent2[i]].push_back(parent1[i]);
      es.push_back(make_pair(parent1[i], parent2[i]));
      es.push_back(make_pair(parent2[i], parent1[i]));
    }

    fill(color, color + N, 0);
    for (int i = 0; i < M; ++i) {
      if (!color[i]) {
        if (!rec(i, 'A')) return F;
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        int a = i;
        int b = g[i][j];
        if (!color[a] || !color[b]) {
          return F;
        }
        if (color[a] == color[b]) {
          return F;
        }
      }
    }

    return T;
  }


};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
