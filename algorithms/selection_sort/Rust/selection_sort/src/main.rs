fn main() {
    let mut array = [3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48];

    println!("{:?}", array);
    selection_sort(&mut array);
    println!("{:?}", array);

}

fn selection_sort(array: &mut [i32]) {
   
    for i in 0..array.len() {
        let mut pivot = i;
        for j in i..array.len() {
            if array[j] < array[pivot] {
               pivot = j; 
            }  
        }

        array.swap(i, pivot);
    }

}
