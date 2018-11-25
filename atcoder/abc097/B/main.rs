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
