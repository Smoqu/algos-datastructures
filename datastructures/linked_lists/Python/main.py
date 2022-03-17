class Node:
    value = None
    next = None

    def __init__(self, value):
        self.value = value

    def get_next(self):
        return self.next

    def set_next(self, next):
        self.next = next

    def get_value(self):
        return self.value


    def set_value(self, new_value):
        self.value = new_value

    def __str__(self):
        return str(self.get_value())


    def __repr__(self) -> str:
        return self.__str__()


class LinkedList:
    head: Node | None = None
    length: int = 0

    def __init__(self, head: Node):
        self.head = head
        self.length = 1

    def push(self, node: Node):
        """
        Push a node at the end of the linked list
        """
        # Increment its length by one
        self.length += 1

        # If the list is empty set the inserted node as the head 
        if self.head == None:
            self.head = node
            return

        _node: Node = self.head
        
        # Get to the last node
        while _node.get_next() != None:
            _node = _node.get_next()

        # And inserts the new node at the end
        _node.set_next(node)

    def iterate(self, callback):
        current = self.head
        while current != None:
            callback(current)
            current = current.get_next()

    def insert_at(self, idx: int, node: Node):
        """
        Insert a new node at a certain index in the linked list
        """

        # If the index is over the length of the list: AssertionError
        assert idx < self.length
        # If the index is less than 0: AssertionError
        assert idx >= 0

        # Increment its length by one
        self.length += 1

        # If the index is 0 then then it becomes the new head
        if idx == 0:
            node.set_next(self.head)
            self.head = node
            return


        # Keeps track of the current index we're at
        i = 0
        # Keeps track of the current node
        current = self.head
        # Keeps track of the previous node
        prev = None

        # Get to the right index in the linked list
        while current.get_next() != None and i < idx:
            # Set the previous node to the current node
            prev = current
            # Set the current node to the next node
            current = current.get_next()

            i += 1

        # Set the new node as the next node of the previous one
        prev.set_next(node)
        # Set the current node as the next node of the new node
        node.set_next(current)
        
    def pop(self):
        """
        Removes the last index of the linked list
        """
        # If the length is less than 0: AssertionError
        assert self.length > 0

        # Decrements by one the length of the list
        self.length -= 1
        # If the length is 0: pops the head off
        if self.length == 0:
            self.head = None
            return 
        
        # Keeps track of the previous node
        prev = None
        # Keeps track of the current node
        current = self.head

        # Get to the end of the list
        while current.get_next() != None:
            # Set the previous node as the current one
            prev = current
            # Set the current node as the next
            current = current.get_next()

        # Set next node of the previous one as None
        prev.set_next(None)
        # Deletes the current one
        del current
        
    def pop_at(self, idx: int):
        assert idx < self.length
        assert idx > 0

        self.length -= 1
        i = 0
        prev = None
        current = self.head

        while current.get_next() != None and i < idx:
            prev = current
            current = current.get_next()
            i += 1

        next = current.get_next()
        if next == None:
            del current
            return

        prev.set_next(next)
        del current



    def __str__(self) -> str:
        if self.length == 0:
            return "[]"

        node = self.head
        s = f"[ {node.get_value()}"
        while (node:= node.get_next()) != None:
            s += f" {node.get_value()}"

        s += " ]"

        return s

    def __repr__(self) -> str:
        return self.__str__()


def main():
    ll = LinkedList(Node(1))
    ll2 = LinkedList(Node("hello"))
    ll2.push(Node("world"))

    ll.push(Node(5))

    ll.insert_at(1, Node(6))
    ll.insert_at(0, Node(8))
    ll.insert_at(1, Node(ll2))
    

    print(ll)


if __name__ == "__main__":
    main()
