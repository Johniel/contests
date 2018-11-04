use std::io::Read;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();

    s = s.replace("1", "@");
    s = s.replace("9", "1");
    s = s.replace("@", "9");

    println!("{}", s);
    ()
}
