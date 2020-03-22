# atcoder/abc097/B

## Code
main.rs
{% raw %}
```rs
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let x: i32 = iter.next().unwrap().parse().unwrap();
    let mut mx: i32 = 1;

    for i in 2..(x + 1) {
        let mut j: i32 = i * i;
        while j <= x {
            if mx <= j {
                mx = j;
            }
            j *= i;
        }
    }
    println!("{}", mx);
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc097/B)
