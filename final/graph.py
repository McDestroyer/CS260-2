from node import Node
from edge import Edge


class Graph:
    def __init__(self):
        self.graph = {}
        self.nodes = []
        self.edges = []

    def add_node(self, value):
        self.nodes.append(Node(value))
        self.graph[value] = []

    def add_edge(self, from_node, to_node, weight):
        self.edges.append(Edge(from_node, to_node, weight))
        self.graph[from_node].append(to_node)
        self.graph[to_node].append(from_node)

    def __str__(self):
        return str(self.graph)

    def get_nodes(self):
        return self.nodes

    def get_node_names(self):
        return [node.name for node in self.nodes]

    def get_edges(self):
        return self.edges

    def get_neighbors(self, node):
        if node not in self.graph:
            return None
        return self.graph[node]

    def get_weight(self, from_node, to_node):
        for edge in self.edges:
            if edge.get_nodes() == (from_node, to_node) or edge.get_nodes() == (to_node, from_node):
                return edge.get_weight()
        return None

    def get_node(self, node_name):
        for node in self.nodes:
            if node.name == node_name:
                return node
        return None

    def remove_node(self, node_name):
        node = self.get_node(node_name)
        # Remove the node from the list of nodes.
        self.nodes.remove(node)
        new_edges = []
        # Remove all edges that contain the node.
        for edge in self.edges:
            if node_name not in edge.get_nodes():
                new_edges.append(edge)
        self.edges = new_edges.copy()
        # Remove the node from the graph.
        del self.graph[node_name]
        for key in self.graph:
            if node_name in self.graph[key]:
                self.graph[key].remove(node_name)
        return node

    def remove_edge(self, from_node, to_node):
        for edge in self.edges:
            if edge.get_nodes() == (from_node, to_node) or edge.get_nodes() == (to_node, from_node):
                self.edges.remove(edge)
                self.graph[from_node].remove(to_node)
                self.graph[to_node].remove(from_node)
        return None

    def generate_minimum_spanning_tree(self):
        tree = Graph()

        # Get all the edges in the graph and sort them by weight.
        edges = self.edges.copy()
        edges.sort(key=lambda edge: edge.weight)

        for edge in edges:
            # If the edge's endpoints are already in the tree, skip it.
            if edge.src in tree.get_node_names() and edge.dest in tree.get_node_names() and \
                    self.generate_shortest_path(edge.src, edge.dest, tree)[0] != float("inf"):
                continue
            # If the edge's endpoints are not in the tree, add them.
            if edge.src not in tree.get_node_names():
                tree.add_node(edge.src)
            if edge.dest not in tree.get_node_names():
                tree.add_node(edge.dest)
            tree.add_edge(edge.src, edge.dest, edge.weight)
            # If the tree is complete, return it.
            if type(tree.tree_complete()) != list and len(tree.get_node_names()) == len(self.get_node_names()):
                return tree
        return tree, [node.name for node in self.nodes if node.name not in tree.get_node_names()]

    def generate_shortest_path(self, start, end, graph=None):
        # Some algorithm that I just barely remembered from MTH 231. It takes the lowest value of the unanalyzed nodes
        # and then updates the distances of the neighbors of that node. It then repeats until all nodes are analyzed.
        if not graph:
            graph = self

        # Initialize the distances of the nodes.
        node_distances = {start: [0, None]}
        unanalyzed_nodes = graph.get_node_names().copy()
        if start in unanalyzed_nodes:
            unanalyzed_nodes.remove(start)
        else:
            # If the start node is not in the graph, return infinity because there is no path.
            return float("inf"), None
        for node in unanalyzed_nodes:
            node_distances[node] = [float("inf"), None]
        unanalyzed_nodes += [start]

        # Update the distances of the neighbors of the current node until all are done.
        while len(unanalyzed_nodes) > 0:
            current_node = min(unanalyzed_nodes, key=lambda node: node_distances[node][0])
            unanalyzed_nodes.remove(current_node)
            for node in graph.get_neighbors(current_node):
                if node_distances[node][0] > node_distances[current_node][0] + graph.get_weight(current_node, node):
                    node_distances[node] = [node_distances[current_node][0] + graph.get_weight(current_node, node),
                                            current_node]
                    # We're saving the contributor node's name so that we can trace back the path later.
                    node_distances[node][1] = current_node

        # Later is now. We're tracing back the path it found to hand to the user.
        path = ""
        current_node = end
        while current_node:
            path = current_node + path
            current_node = node_distances[current_node][1]
            if current_node:
                path = "->" + path

        return node_distances[end][0], path

    def tree_complete(self):
        nodes = self.get_node_names()
        for node in nodes:
            for node2 in nodes:
                if node == node2:
                    continue
                # If there is a pair of nodes that are not connected, return them.
                if self.generate_shortest_path(node, node2)[0] == float("inf"):
                    return [node, node2]
        return True
