// use std::cmp;
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let a: i32 = iter.next().unwrap().parse().unwrap();
    let b: i32 = iter.next().unwrap().parse().unwrap();
    let k: i32 = iter.next().unwrap().parse().unwrap();

    let mut v: Vec<i32> = Vec::new();

    for i in a..(a + k) {
        if i <= b - k || i <= b {
            v.push(i)
        }
    }
    for i in (b - k + 1)..(b + 1) {
        if v.last().unwrap() < &i {
            v.push(i)
        }
    }

    for i in v {
        println!("{}", i)
    }
}
