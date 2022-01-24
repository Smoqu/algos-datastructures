use std::cmp::Ordering::*;

fn main() {
    let array = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let bin_tree = BinTree::from_array(&array);
    println!("{:?}", bin_tree);
}

#[derive(Clone, Debug)]
struct Node<T: std::cmp::PartialOrd + std::cmp::PartialEq + Copy + Clone> {
    value: Option<T>,
}

impl<T: std::cmp::PartialOrd + std::cmp::PartialEq + Copy + Clone> std::cmp::PartialEq for Node<T> {
    fn ne(&self, other: &Self) -> bool {
        matches!(self.partial_cmp(other), Some(Greater | Equal))
    }

    fn eq(&self, other: &Self) -> bool {
        self.value == other.value
    }
}

impl<T: std::cmp::PartialOrd + std::cmp::PartialEq + Copy + Clone> std::cmp::PartialOrd
    for Node<T>
{
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        self.value.partial_cmp(&other.value)
    }
    fn lt(&self, other: &Self) -> bool {
        matches!(self.value.partial_cmp(&other.value), Some(Less))
    }

    fn le(&self, other: &Self) -> bool {
        // Pattern `Some(Less | Eq)` optimizes worse than negating `None | Some(Greater)`.
        // FIXME: The root cause was fixed upstream in LLVM with:
        // https://github.com/llvm/llvm-project/commit/9bad7de9a3fb844f1ca2965f35d0c2a3d1e11775
        // Revert this workaround once support for LLVM 12 gets dropped.
        !matches!(self.partial_cmp(other), None | Some(Greater))
    }

    fn gt(&self, other: &Self) -> bool {
        matches!(self.partial_cmp(other), Some(Greater))
    }

    fn ge(&self, other: &Self) -> bool {
        matches!(self.value.partial_cmp(&other.value), Some(Greater))
    }
}

#[derive(Clone, Debug)]
struct BinTree<T: std::cmp::PartialOrd + std::cmp::PartialEq + Copy + Clone> {
    root: Option<Node<T>>,
    left: Box<BinTree<T>>,
    right: Box<BinTree<T>>,
}

impl<T: std::cmp::PartialOrd + std::cmp::PartialEq + Copy + Clone> BinTree<T> {
    pub fn new(val: Option<T>) -> BinTree<T> {
        let bin_tree = BinTree {
            root: Some(Node { value: val }),
            left: Box::new(BinTree::empty()),
            right: Box::new(BinTree::empty()),
        };
        bin_tree
    }

    pub fn empty() -> BinTree<T> {
        BinTree {
            root: None,
            left: Box::new(BinTree::new(None)),
            right: Box::new(BinTree::new(None)),
        }
    }

    pub fn insert(self, value: &T) -> BinTree<T> {
        if &self.root.as_ref().unwrap().value.unwrap() == value {
            return self;
        }

        if self.root.is_none() {
            return BinTree::new(Some(*value));
        } else if value < &self.root.as_ref().unwrap().value.unwrap() {
            return self.left.insert(value);
        } else if value > &self.root.as_ref().unwrap().value.unwrap() {
            return self.right.insert(value);
        }
        return BinTree::new(Some(*value));
    }

    pub fn from_array(array: &[T]) -> BinTree<T> {
        let first = array.first().copied();
        let bin_tree = BinTree::new(first);
        for (idx, item) in array.iter().enumerate() {
            if idx != 0 {
                bin_tree.clone().insert(item);
            }
        }
        bin_tree
    }
}
