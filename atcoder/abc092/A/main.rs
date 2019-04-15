use std::cmp::min;
use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let a = iter.next().unwrap().parse::<i32>().unwrap();
    let b = iter.next().unwrap().parse::<i32>().unwrap();
    let c = iter.next().unwrap().parse::<i32>().unwrap();
    let d = iter.next().unwrap().parse::<i32>().unwrap();
    println!("{}", min(a, b) + min(c, d));
}
