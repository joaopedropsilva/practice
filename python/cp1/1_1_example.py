import math 


def euclidean(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

points = [(1,1), (8,6), (6,8), (1,3)]
dists = []
seen = []
for x1, y1 in points:
    for x2, y2 in points:
        if x1 == x2 and y1 == y2:
            continue

        p_id = f"{x1}{y1}{x2}{y2}" 
        p_id_inverse = f"{x2}{y2}{x1}{y1}" 
        if p_id in seen or p_id_inverse in seen:
            continue

        seen.append(p_id)
        dists.append(euclidean(x1, y1, x2, y2))

cost = float('inf')
for i, d1 in enumerate(dists):
    for _, d2 in enumerate(dists, start=i+1):
        new_cost = d1 + d2
        print(f"{i} {_} = {new_cost}")
        if new_cost < cost:
            cost = new_cost
print(cost)
print(seen[2])
print(seen[4])

# wrong seen[2] 1113 and seen[4] 8613 are being combined, but 13 was already picked
# calculate cost when analyzing distances
