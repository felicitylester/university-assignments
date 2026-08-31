from collections import defaultdict

def read_graph(filename):
    graph = defaultdict(list)
    with open(filename, 'r') as f:
        for line in f:
            u, v = map(int, line.strip().split())
            graph[u].append(v)
    return graph

def reverse_graph(graph):
    rev_graph = defaultdict(list)
    for u in graph:
        for v in graph[u]:
            rev_graph[v].append(u)
    return rev_graph

def dfs_iterative(graph, start, visited, stack=None):
    temp_stack = [start]
    while temp_stack:
        node = temp_stack[-1]
        if node not in visited:
            visited.add(node)
            neighbors = [n for n in graph[node] if n not in visited]
            if neighbors:
                temp_stack.extend(neighbors)
            else:
                popped = temp_stack.pop()
                if stack is not None:
                    stack.append(popped)
        else:
            popped = temp_stack.pop()
            if stack is not None and popped not in stack:
                stack.append(popped)

def dfs_collect_iterative(graph, start, visited, component):
    temp_stack = [start]
    while temp_stack:
        node = temp_stack.pop()
        if node not in visited:
            visited.add(node)
            component.append(node)
            temp_stack.extend(graph[node])

def find_sccs(graph):
    stack = []
    visited = set()

    # First pass on reversed graph
    rev_graph = reverse_graph(graph)
    for node in range(max(graph)+1):
        if node in rev_graph and node not in visited:
            dfs_iterative(rev_graph, node, visited, stack)

    # Second pass on original graph
    visited.clear()
    sccs = []

    while stack:
        node = stack.pop()
        if node not in visited and node in graph:
            component = []
            dfs_collect_iterative(graph, node, visited, component)
            sccs.append(component)

    return sccs


def write_largest_scc(sccs, output_filename):
    largest_scc = max(sccs, key=len)
    largest_scc.sort()
    with open(output_filename, 'w') as f:
        for node in largest_scc:
            f.write(f"{node}\n")

def main():
    input_file = "Graph.txt"
    output_file = "LSCC.txt"
    
    print("Reading graph...")
    graph = read_graph(input_file)

    print(f"Total nodes with outgoing edges: {len(graph)}")
    edge_count = sum(len(v) for v in graph.values())
    print(f"Total edges: {edge_count}")

    
    print("Finding strongly connected components...")
    sccs = find_sccs(graph)

    print(f"Total SCCs found: {len(sccs)}")
    if sccs:
        print(f"Largest SCC size: {len(max(sccs, key=len))}")

    
    print("Writing largest SCC to output...")
    write_largest_scc(sccs, output_file)
    print("Done!")

if __name__ == "__main__":
    main()
