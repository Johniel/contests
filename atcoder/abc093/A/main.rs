use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let s: String = iter.next().unwrap().parse().unwrap();

    let mut chars: Vec<char> = s.chars().collect();
    chars.sort_by(|a, b| b.cmp(a));

    match s.find('a').and(s.find('b').and(s.find('c'))) {
        Some(ref _p) => println!("Yes"),
        None => println!("No"),
    }
}
