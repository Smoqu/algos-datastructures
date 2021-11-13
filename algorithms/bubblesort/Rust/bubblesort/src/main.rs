fn main() {
    
    let mut array: [i32; 12] = [8, 7, 5, 6, 9, 8, 9, 7, 256, 14, 21, -2];

    bubblesort(&mut array);


    for ele in array {
        println!("{}", ele);
    }
}


fn bubblesort(array: &mut [i32]) {

    let length = array.len();
    let k = length;

    for _ in 0..length  {
        for y in 0..(k-1) {
            if array[y] > array[y+1] {
                array.swap(y, y+1);
            }
        }
         
    }
    
}
