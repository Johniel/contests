# atcoder/abc101/B

## Codes
main.rs
{% raw %}
```rs
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let n: i32 = iter.next().unwrap().parse().unwrap();

    let mut sum: i32 = 0;
    let mut m: i32 = n;

    while m != 0 {
        sum += m % 10;
        m /= 10;
    }

    if n % sum == 0 {
        println!("Yes");
    } else {
        println!("No");
    }

    ()
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc101/B)
