#include<bits/stdc++.h>
using namespace std;
int parent[500];
// make
void make(int v) {
    parent[v] = v;
}

// find
int find_op(int a) {
    if (parent[a] == a) return a;
    return find_op(parent[a]);
}

// union 
void union_op(int a, int b) {
    int parentA = find_op(a);
    int parentB = find_op(b);
    if(parentA != parentB) {
        parent[parentA] = parentB;
    }
}

// connect
bool isConnected(int a, int b) {
    return find_op(a) == find_op(b);
}

int main() {
    make(1);
    make(0);
    make(3);
    make(4);
    make(2);
    union_op(1, 2);
    cout<<find_op(1)<<endl;
    union_op(2, 3);
    cout<<isConnected(1, 3)<<endl;
    for(int i= 0; i<=4; i++) {
        cout<<parent[i]<< " ";  
    }
}
