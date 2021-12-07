fn main() {
    let mut list = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    println!("{:?}", list);
    reverse(&mut list);
    println!("{:?}", list);
}

fn reverse(list: &mut [i32]) {
    let mut i = 0;
    let mut j = list.len() - 1;

    while i <= j {
        list.swap(i, j);
        i += 1;
        j -= 1;
    }
}
