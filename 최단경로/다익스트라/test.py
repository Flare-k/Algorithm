from collections import deque
'''
실습 1.
가중치가 없는 그래프 표현이 G=(V,E) 로 주어지는 경우에, 
주어진 source node 와 destination node 간의 
최단 경로를 찾는 파이썬 함수를 코딩하여 보시오.
또한, 이 경우에 [그림 1]에 대하여, 노드 'E' 에서 노드 'N' 까지의 
최단 경로, shortest_path 를 구하고, 
출력이 "The shortest path from node 'E' to node 'N' = shortest_path " 
로 나오도록 해보시오.
'''
# BFS
#def BFS(graph, )


V = {'B', 'E', 'F', 'L', 'N',  'S'}
E = {('B', 'F'), ('B', 'L'), ('B', 'N'), ('B', 'S'), ('E', 'F'),
     ('E', 'L'), ('F', 'L'), ('F', 'N'), ('L', 'N'), ('L', 'S'), ('N', 'S')}
G2 = (V, E)

def Adj_Mat(adjL):
    n = len(adjL)
    nodes = list()
    for key in adjL:
        nodes.append(key)

    adM = [[] for _ in range(n)]  # key 갯수와 같은 리스트 요소를 갖는 리스트 어레이 만듬

    k = 0
    j = 0
    for node in nodes:
        if adjL[node]:
            for s in adjL[node]:
                i = 0
                # print("node={}, str={}".format(node,s))
                while(i < n):
                    if i >= j:
                        if s == nodes[i]:
                            adM[k].append(1)
                            j = i+1
                            i = n
                        else:
                            adM[k].append(0)
                            i += 1
                    else:
                        i += 1
            if j < n:
                for _ in range(j, n):
                    adM[k].append(0)

        else:
            for _ in range(n):
                adM[k].append(0)
        k += 1
        j = 0
    return adM


adjMatrix = Adj_Mat(adjL_s)
print(adjMatrix)
