Plan:
* Use Python bc it's so much less of a pain.
1. Node object
* Contains Name
2. Edge object
* Contains Source
* Contains Destination
* Contains Weight
3. Graph object
* Contains Nodes
* Contains Edges
* Contains a function to add a node
* Contains a function to add an edge
* Contains a function to remove a node
* Contains a function to remove an edge
* Contains a function to get the shortest path between two nodes
* Contains a function to get the minimum spanning tree
* Contains a function to check if the graph is connected

This graph could be used as a subway map, where the nodes are the stations and the edges are the connections between them. The functions could be used to find the shortest path between two stations, the minimum number of connections between two stations, and to check if the subway system is connected.

This graph could also be used as a social network, where the nodes are people and the edges are relationships between them.

The complexities of the functions are as follows:
* Add Node: O(1)
* Add Edge: O(1)
* Remove Node: O(n)
* Remove Edge: O(n)
* Shortest Path: O(n^2)
* Minimum Spanning Tree: O(n^3)
* Is Connected: O(n^2)
* Where n is the number of nodes in the graph.

The functions are tested on the following lines of the mein.py file:
* Add Node: 6-12
* Add Edge: 14-21
* Display Graph: 23/36
* Remove Node: 34/83
* Remove Edge: 42/73
* Shortest Path: 57/59/61/63/65
* Minimum Spanning Tree: 69/75/85
* Is Connected: 54, 80

