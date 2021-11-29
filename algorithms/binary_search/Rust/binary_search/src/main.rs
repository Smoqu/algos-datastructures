fn main() {
    println!("Hello, world!");

    let list = [1, 2, 3, 4, 5, 7, 9, 256, 500];

    let found = binary_search(&list, 7);

    println!("{}", found);
    let found = binary_search(&list, 800);
    println!("{}", found);

}


fn binary_search(list: &[i32], value: i32) -> bool{
    let mut start = 0;
    let mut end = list.len() - 1;


    while start <= end {
        let middle = (start + end) / 2;


        if value == list[middle] {
            return true
        }

        if value > list[middle] {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }


    false

}
