# Global Round 19 1637E - Best Pair
[解説](https://codeforces.com/blog/entry/99883)。

この計算量の出し方が分からない。(N+M)logMの部分。

---

分かった。まず、頻度を増やそうとすると出現1回、出現2回、出現3回、という数字を作らないといけない。
等差数列の和になるのでN>=P(P+1)/2なPを考えると√Nになる。これを２重ループで選択するのだからO(N)になる。

M=0のときを考える。CNTpとCNTqを決めたとしたら、その頻度になっている最大の数を選択することが最適に決まっている。つまりO(1)。
ではM!=0のときはどうか？CNTpとCNTqに該当する数字を全通り試す必要はない。何故なら大きい方から試していってスキップしなければならない回数は全体でM回だから。

頻度全通りN、スキップ回数M回、タブーに相当するかの検証logMで、O((N+M)logM)？

---

TLEを量産した結果、mapへのアクセスを無くしたらAC。

```c++
    vec<lli> a(n);
    map<lli, lli> cnt;
    vector<lli> occ[n+1];
    each (i, a) {
      occ[cnt[i]].push_back(i);
    }
```
略した部分もあるけれど↑が駄目で
```c++
    vec<lli> a(n);
    vector<lli> occ[n+1];
    each (i, cnt) {
      occ[i.first].push_back(i.second);
    }
```
が通るの厳しくない？codeforcesは度々logを減らさないと通らない問題が出題されるけれども。問題の核心と違う部分の最適化は無駄だと思うんだけれどなあ。
