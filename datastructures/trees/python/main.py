import json


class Node:
    name: str = ""

    def __init__(self, name: str):
        self.name = name

    def __str__(self):
        # return "\n\tName: {self.name}".format(self=self)
        return str(self.__dict__)

    __repr__ = __str__


class Branch:
    node: Node = None
    nodes = []

    def __init__(self, node: Node, nodes):
        self.node = node
        self.nodes = nodes

    def __str__(self):
        # return "\n\t\t(Node: {self.node}; \n\t\tNodes: \t{self.nodes})".format(self=self)
        return str(self.__dict__)

    __repr__ = __str__


class Tree:
    branches = []
    node: Node = None

    def __init__(self, node: Node, branches):
        self.node = node
        self.branches = branches

    def __str__(self):
        # return "Node: {self.node}; \n\tBranches: {self.branches}".format(self=self)
        return str(self.__dict__)

    # def __repr__(self):
        # return self.__dict__

    __repr__ = __str__


def main():
    tree = Tree(
        Node("+"),
        [
            Branch("*", [Node("a"), Node("b")]),
            Branch("-", [Node("c"), Branch("+", [Node("d"), Node("e")])])
        ]
    )

    print(json.dumps(tree, indent=2))


if __name__ == "__main__":
    main()
