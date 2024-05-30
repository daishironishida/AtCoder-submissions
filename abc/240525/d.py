N = int(input())

points = []
for _ in range(N):
    points.append(tuple(map(int, input().split())))

class Node:pass
k = 2

def kdtree(pointList, depth=0):
    if not pointList:
        return

    # 深さに応じて軸を選択し、軸が順次選択されるようにする
    axis = depth % k

    # 点のリストをソートし、中央値の点を選択する
    pointList.sort(key=lambda x:x[axis])
    median = len(pointList)//2 # 中央値を選択

    # ノードを作成し、部分木を構築する
    node = Node()
    node.location = pointList[median]
    node.leftChild = kdtree(pointList[0:median], depth+1)
    node.rightChild = kdtree(pointList[median+1:], depth+1)
    return node

def count_range(node, x_max, y_min, depth=0):
    if node is None:
        return 0
    location = node.location
    axis = depth % k
    value = location[axis]

    if axis == 0:
        # x
        if value > x_max:
            return count_range(node.leftChild, x_max, y_min, depth+1)
        else:
            return count_range(node.leftChild, x_max, y_min, depth+1) + count_range(node.rightChild, x_max, y_min, depth+1) + 1
    else:
        # y
        if value < y_min:
            return count_range(node.rightChild, x_max, y_min, depth+1)
        else:
            return count_range(node.leftChild, x_max, y_min, depth+1) + count_range(node.rightChild, x_max, y_min, depth+1) + 1

rootNode = kdtree(points)

sum = 0
for point in points:
    sum += count_range(rootNode, point[1], point[0])

print((sum - N) // 2)


