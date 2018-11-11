use std::io::Read;

fn main() {
    let mut buff = String::new();
    std::io::stdin().read_to_string(&mut buff).unwrap();
    let mut iter = buff.split_whitespace();

    let h: usize = iter.next().unwrap().parse().unwrap();
    let w: usize = iter.next().unwrap().parse().unwrap();

    let mut g = Vec::new();
    for _i in 0..h {
        let s: String = iter.next().unwrap().parse().unwrap();
        let mut h = Vec::new();
        for c in s.chars() {
            h.push(c)
        }
        g.push(h);
    }

    for i in 0..h {
        let mut cnt: usize = 0;
        for j in 0..w {
            if g[i][j] != '#' {
                cnt = cnt + 1;
            }
        }
        if cnt == w {
            for j in 0..w {
                g[i][j] = '@';
            }
        }
    }

    for j in 0..w {
        let mut cnt: usize = 0;
        for i in 0..h {
            if g[i][j] != '#' {
                cnt = cnt + 1;
            }
        }
        if cnt == h {
            for i in 0..h {
                g[i][j] = '@'
            }
        }
    }

    for i in 0..h {
        let mut cnt: i32 = 0;
        for j in 0..w {
            if g[i][j] != '@' {
                cnt = cnt + 1;
                print!("{}", g[i][j]);
            }
        }
        if cnt != 0 {
            println!("");
        }
    }

    ()
}
