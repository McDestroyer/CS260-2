from tree import Tree, TreeNode

def main():

    tree = Tree("node 0")

    tree.insert_node("node 6")
    tree.insert_node("node 1")
    tree.insert_node("node 4")
    tree.insert_node("node 2")
    tree.insert_node("node 5")
    tree.insert_node("node 7")
    tree.insert_node("node 3")

    print("List contents:")
    tree.list_items()
    print()

    print("Sort and balance the contents.\n")
    tree.sort()

    print("List contents:")
    tree.list_items()
    print()

    print("Get the parent of node 3:")
    print(tree.find_node("node 3").get_parent().get_value() + "\n")

    print("Remove node 3:")
    print(tree.remove_node("node 3"))
    print()

    print("List contents:")
    tree.list_items()
    print()

    print("Get node 3 (Should be None):")
    print(tree.find_node("node 3"), "\n")

    print("Get node 4 and its ancestors:")
    print(tree.find_node("node 4").get_value(), [node.get_value() for node in tree.find_node("node 4").get_ancestors()], "\n")

    print("Remove node 4:")
    print(tree.remove_node("node 4"), "\n")

    print("List contents:")
    tree.list_items()

    print("Traverse to node 0")
    print(tree.traverse_to("node 0"))


if __name__ == "__main__":
    main()
