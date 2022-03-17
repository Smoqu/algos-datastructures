use std::{collections::HashMap, rc::Rc};

struct Node<T> {
    value: T,
    neighbours: Vec<Rc<Node<T>>>
}


struct Graph<T> {
    nodes: HashMap<T, Node<T>>    
}

impl<T> Graph<T> where T: std::cmp::Eq + std::hash::Hash + Copy {
    fn add_node(&mut self, node: Node<T>) -> bool { 
        let value = node.value;
        if !self.nodes.contains_key(&value) {
            return false;
        }
        self.nodes.insert(value, node); 
        true
    } 

}

fn main() {
    println!("Hello, world!");
}
