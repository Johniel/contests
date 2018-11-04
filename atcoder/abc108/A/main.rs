use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();

    let mut iter = buff.split_whitespace();
    let k: i32 = iter.next().unwrap().parse().unwrap();

    let a = k / 2;
    let b = (k + 1) / 2;
    println!("{}", a * b);
    ()
}
