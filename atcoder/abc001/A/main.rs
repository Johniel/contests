use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let s: String = iter.next().unwrap().parse().unwrap();
    let t: String = iter.next().unwrap().parse().unwrap();

    let h1 = s.parse::<i32>().unwrap();
    let h2 = t.parse::<i32>().unwrap();

    println!("{}", h1 - h2)
}
