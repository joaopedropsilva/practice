from math import inf
from typing import List


def bfs(graph: dict, source_vertex: int) -> List[int]:
    cost = [inf] * len(graph)
    cost[source_vertex] = 0

    queue = [source_vertex]

    while len(queue):
        u = queue.pop(0)

        for v in graph[u]:
            if cost[v] != inf: continue

            cost[v] = cost[u] + 1
            queue.append(v)

    return cost


if __name__ == "__main__":
    graph = {
        0: [1, 2, 3],
        1: [0, 3],
        2: [0, 3],
        3: [0, 1, 2, 4],
        4: [3]
    }

    vertices = ""
    for i in range(len(graph)):
        vertices += f"{i} "

    print("v: ", vertices)
    print("c: ", bfs(graph, 0))
        
