from typing import List 
from math import inf 
import heapq as h 


def dijkstra(graph: dict, source: int) -> List[float]:
    dist = [inf] * len(graph)
    dist[source] = 0
    queue = [(0, source)]

    while len(queue):
        u = h.heappop(queue)
        pass

    return dist


if __name__ == "__main__":
    pass


