fn main() {
    let mut list = [6, 5, 3, 1, 8, 7, 2, 4];
    println!("{:?}", list);
    insertion_sort(&mut list);
    println!("{:?}", list);
}

fn insertion_sort(list: &mut [i32]) {
    for i in 0..list.len() {
        let actual = list[i];
        let mut j = i as i32 - 1;
        while j >= 0 && list[j as usize] > actual {
            println!("{:?}", list);
            if actual < list[j as usize] {
                list.swap(j as usize + 1, j as usize);
                list[j as usize] = actual;
            }
            j -= 1;
        }
    }
}
