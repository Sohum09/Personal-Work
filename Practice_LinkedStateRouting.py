#Script to implement Linked State Routing
import sys

#Implement Djikstra's Algorithm
class Graph():
    def __init__(self, Vertices) -> None:
        self.V = Vertices
        self.graph = [[0 for column in range (Vertices)] for row in range (Vertices)]

    def printSolution(self, dist):
        print("Node  Cost")
        for i in range (self.V):
            print(i+1, "   ", dist[i])
        
    def minDistance(self, dist, sptSet):
        min = sys.maxsize
        minIndex = 0
        for i in range(self.V):
            if dist[i] < min and sptSet[i]==False:
                min = dist[i]
                minIndex = i
        return minIndex 
    
    def djikstra(self, src):
        dist = [sys.maxsize] * (self.V)
        dist[src] = 0
        sptSet = [False] * (self.V)

        for count in range (self.V):
            x = self.minDistance(dist, sptSet)
            sptSet[x] = True
            for y in range(self.V):
                if sptSet[y]==False and self.graph[x][y] > 0 and dist[y] > dist[x] + self.graph[x][y]:
                    dist[y] = dist[x] + self.graph[x][y]
        self.printSolution(dist)

g = Graph(9)
g.graph =  [[0, 4, 0, 0, 0, 0, 0, 8, 0],
            [4, 0, 8, 0, 0, 0, 0, 11, 0],
            [0, 8, 0, 7, 0, 4, 0, 0, 2],
            [0, 0, 7, 0, 9, 14, 0, 0, 0],
            [0, 0, 0, 9, 0, 10, 0, 0, 0],
            [0, 0, 4, 14, 10, 0, 2, 0, 0],
            [0, 0, 0, 0, 0, 2, 0, 1, 6],
            [8, 11, 0, 0, 0, 0, 1, 0, 7],
            [0, 0, 2, 0, 0, 0, 6, 7, 0]]

for i in range (9):
    print("For node", i+1, ": ")
    g.djikstra(i)
    print("\n")