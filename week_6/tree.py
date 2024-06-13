from node import TreeNode


class Tree:
    def __init__(self, root_value):
        self.root = TreeNode(root_value)

    def add_node(self, parent_value, child_value):
        parent_node = self.find_node(parent_value)
        if parent_node:
            return parent_node.add_child(child_value)
        return None

    def insert_node(self, child_value):
        current_node = self.root
        while True:
            if current_node.get_value() <= child_value:
                if current_node.get_child_1() is None:
                    return current_node.set_child_1(child_value)
                else:
                    current_node = current_node.get_child_1()
            else:
                if current_node.get_child_2() is None:
                    return current_node.set_child_2(child_value)
                else:
                    current_node = current_node.get_child_2()

    def remove_node(self, value):
        node = self.find_node(value)
        if node:
            parent = node.get_parent()
            if parent:
                parent.remove_child(node.get_value())

                for child in node.get_descendants():
                    self.insert_node(child.get_value())
                self.sort()
            else:
                if node.get_child_1():
                    self.root = node.get_child_1()
                    for child in node.get_child_2().get_descendants():
                        self.insert_node(child.get_value())
                    self.sort()
        return node

    def find_node(self, value):
        nodes_to_visit = [self.root]
        while nodes_to_visit:
            current_node = nodes_to_visit.pop()
            if current_node and current_node.get_value() == value:
                return current_node
            if current_node.get_child_1():
                nodes_to_visit.append(current_node.get_child_1())
            if current_node.get_child_2():
                nodes_to_visit.append(current_node.get_child_2())
        return None

    def list_items(self):
        nodes_to_visit = [self.root]
        node_list = []
        while nodes_to_visit:
            current_node = nodes_to_visit.pop()
            ancestors = current_node.get_ancestors()
            ancestors.reverse()
            print("/".join([node.get_value() for node in ancestors]) + "/" + current_node.get_value())
            node_list.append(current_node.get_value())
            if current_node.get_child_1():
                nodes_to_visit.append(current_node.get_child_1())
            if current_node.get_child_2():
                nodes_to_visit.append(current_node.get_child_2())

    def traverse_to(self, item: str):
        return traverse_to(self.root, item)

    def sort(self):
        node_list = self.root.get_descendants()
        vals = [self.root.get_value()]

        for node in node_list:
            vals.append(node.get_value())

        vals.sort()

        pos = int(len(vals) / 2)
        self.root = TreeNode(vals.pop(pos))

        left_arr = vals[:pos]
        right_arr = vals[pos:]

        balance_descendants(self.root, left_arr, right_arr)


def balance_descendants(parent, left_arr, right_arr):
    if len(left_arr) > 0:
        pos = int(len(left_arr) / 2)
        parent.add_child(left_arr.pop(pos))
        balance_descendants(parent.get_child_1(), left_arr[:pos], left_arr[pos:])
    if len(right_arr) > 0:
        pos = int(len(right_arr) / 2)
        parent.add_child(right_arr.pop(pos))
        balance_descendants(parent.get_child_2(), right_arr[:pos], right_arr[pos:])

def traverse_to(current_node: TreeNode, item: str, path="/") -> str:
    if item == current_node.get_value():
        path += current_node.get_value()
        return path
    if item < current_node.get_value():
        path += current_node.get_value() + "/"
        return traverse_to(current_node.get_child_1(), item, path)
    path += current_node.get_value() + "/"
    return traverse_to(current_node.get_child_2(), item, path)
