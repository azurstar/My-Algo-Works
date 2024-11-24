#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 128;
int graph[maxn][maxn];  // 邻接矩阵

struct Edge {
    int u, v, w;  // u, v: 边的两个端点, w: 边的权重
};

vector<Edge> edges;  // 边的列表

bool cmp(Edge a, Edge b) {
    return a.w < b.w;  // 按权重升序排序
}

// 并查集数据结构
int parent[maxn];
int size[maxn];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // 初始化父节点为自身
        size[i] = 1;    // 初始化每个集合的大小为 1
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 路径压缩
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // 按秩合并
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
}

void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
    Edge e = {u, v, w};
    edges.push_back(e);
}

void kruskal(int n) {
    sort(edges.begin(), edges.end(), cmp);  // 按照边权重排序

    init(n);  // 初始化并查集
    int mstWeight = 0;  // 最小生成树的权重和
    vector<Edge> mstEdges;  // 存储最小生成树的边

    for (Edge e : edges) {
        int u = e.u, v = e.v, w = e.w;

        if (find(u) != find(v)) {  // 如果u和v不在同一个连通分量
            unionSet(u, v);  // 合并两个连通分量
            mstEdges.push_back(e);  // 将这条边加入最小生成树
            mstWeight += w;  // 更新最小生成树的权重和
        }
    }

    // 输出最小生成树
    cout << "最小生成树的权重和: " << mstWeight << endl;
    cout << "最小生成树的边: " << endl;
    for (Edge e : mstEdges) {
        cout << e.u << " - " << e.v << " 权重: " << e.w << endl;
    }
}

int main() {
    int n = 6;  // 图的节点数
    addEdge(0, 3, 5);
    addEdge(3, 5, 2);
    addEdge(0, 2, 1);
    addEdge(2, 3, 5);
    addEdge(2, 5, 4);
    addEdge(0, 1, 6);
    addEdge(1, 2, 5);
    addEdge(1, 4, 3);
    addEdge(2, 4, 6);
    addEdge(4, 5, 6);

    kruskal(n);  // 执行 Kruskal 算法
}
