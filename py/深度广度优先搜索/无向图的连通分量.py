
class Node:
    def __init__(self, value):
        self.value = value
        self.neighbors = []

def create_graph(edges):
    graph = {}
    for edge in edges:
        if edge[0] not in graph:
            graph[edge[0]] = Node(edge[0])
        if edge[1] not in graph:
            graph[edge[1]] = Node(edge[1])
        graph[edge[0]].neighbors.append(graph[edge[1]])
        graph[edge[1]].neighbors.append(graph[edge[0]])
    return graph


def find_connected_components(graph):

    def dfs(node, visited, component):
        if node is None or node.value in visited:
            return
        visited.add(node.value)
        component.append(node.value)

        for neighbor in node.neighbors:
            dfs(neighbor, visited, component)


    visited = set()
    components = []

    for node in graph.values():
        if node not in visited:
            component = []
            dfs(node, visited, component)
            components.append(component)
    return components


def main() -> None:
    num_nodes, num_edges = map(int, input("请输入节点数量和边的数量: ").split())

    edges = []
    print("请输入每条边的两个节点 (u v):")
    for _ in range(num_edges):
        edge = tuple(map(int, input().split()))
    graph = create_graph(edges)
    components = find_connected_components(graph)
    print("连通分量数量: ", len(components))
    for i, component in enumerate(components):
        print(f"组件 {i + 1}: {component}")


if __name__ == '__main__':
    main()
