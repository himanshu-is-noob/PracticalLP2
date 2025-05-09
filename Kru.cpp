#include <vector>
#include <algorithm>
#include<iostream>

using namespace std ;
 
struct Edge{
    int src, destination , weight ;
};

bool compareEdge(Edge a , Edge b){
    return a.weight < b.weight ;
}

int findParent(int node , vector<int>&parent){
    if(parent[node] == node){
        return node ;
    }
    return parent[node] = findParent(parent[node] , parent) ;
}

void UnionNodes(int u , int v , vector<int>&parent){
    int parentU = findParent(u,parent) ;
    int parentV = findParent(v , parent) ;

    parent[parentU] = parentV ;
}

int main(){
    int V , E ; 
    cout << "ENTER number of vertices : " ; 
    cin >> V ;

    cout << "Enter number of Edges : " ;
    cin >> E ; 

    vector<int> parent(V) ;
    vector<Edge> edges ;
    vector<Edge> mst  ;

    for(int i=0 ; i<V ; i++){
        parent[i] = i ;
    }

    cout << "(Source dest weight)" << endl ;
    for(int i=0 ;i<E ; i++){
        int src ,dest , w ; 
        cin >> src >>dest >> w ;
        edges.push_back({src,dest,w}) ;   
    }

    sort(edges.begin() , edges.end() , compareEdge) ;

    for(Edge e  : edges){
        int srcParent = findParent(e.src , parent) ;
        int destParent = findParent(e.destination , parent) ;

        if(srcParent != destParent){
            mst.push_back(e) ;
            UnionNodes(e.src , e.destination , parent) ;
        }
    }

    cout << "Minimum Spanning Tree is as follows : " << endl ;
    for(Edge e : mst){
        cout << e.src << " -- " << e.destination << " == " << e.weight << endl ;
    }

}
