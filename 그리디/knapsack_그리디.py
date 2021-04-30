import sys

def fKnapsack(materials, m) :
    materials = sorted(materials, key=lambda x : x[1]/x[0], reverse=True)

    weight = 0
    value = 0

    for i in range(len(materials)) :
        if weight + materials[i][0] < m :
            weight += materials[i][0]
            value += materials[i][1]
        elif weight + materials[i][0] == m :
            weight += materials[i][0]
            value += materials[i][1]
            return value
        else :
            tmp = m - weight
            value += tmp * (materials[i][1] / materials[i][0])
            return value
    
    return value

def main() :
    line = [int(x) for x in input().split()]

    n = line[0]
    m = line[1]

    materials = []

    for i in range(n) :
        data = [int(x) for x in input().split()]
        materials.append((data[0], data[1]))

    print("%.3lf" % fKnapsack(materials, m))

if __name__ == "__main__" :
    main()

'''
4 10
3 10
2 7
4 9
5 13
> 30.000

4 11
3 10
2 7
4 9
5 13
> 32.250
'''
