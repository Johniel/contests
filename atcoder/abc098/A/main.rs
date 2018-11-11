use std::cmp;
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let a: i32 = iter.next().unwrap().parse().unwrap();
    let b: i32 = iter.next().unwrap().parse().unwrap();

    let x = a + b;
    let y = a * b;
    let z = a - b;

    println!("{}", cmp::max(x, cmp::max(y, z)));

    ()
}
