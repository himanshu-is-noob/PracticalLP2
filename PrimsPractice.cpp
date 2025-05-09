#include <iostream>
#include <vector>
#include <queue>

using namespace std ;
typedef pair<int,int>P ;

int MinimumSpanningTree(int V , vector<vector<int>> adj[]){
    priority_queue<P , vector<P> , greater<P>> pq; 
    pq.push({0,0}) ;
    int sum = 0;

    vector<bool>inMST(V , false) ;

    while(!pq.empty()){
        auto p = pq.top() ;
        pq.pop(); 

        int wt = p.first ;
        int node = p.second ;

        if(inMST[node])
        continue ;

        inMST[node] = true ; 
        sum += wt ; 

        for(auto &tmp : adj[node]){
            int neighbor = tmp[0];
            int neighbor_wt = tmp[1] ;

            if(!inMST[neighbor]){
                pq.push({neighbor_wt , neighbor}) ;
            }
        }

    }

    return sum ; 
}

int main()
{
    int V = 5 ; 

    vector<vector<int>>adj[V] ; 

    adj[0].push_back({1,5});
    adj[1].push_back({0,5});

    adj[0].push_back({2,4}) ;
    adj[2].push_back({0,4}) ;

    adj[0].push_back({3,8}) ;
    adj[3].push_back({0,8}) ;

    adj[1].push_back({2,9}) ;
    adj[2].push_back({1,9}) ;

    adj[2].push_back({4,3}) ;
    adj[4].push_back({2,3}) ;

    adj[3].push_back({4,2}) ;
    adj[4].push_back({3,2}) ;

    int result = MinimumSpanningTree(V, adj) ;
    cout << "Minimum Spanning Tree " << result << endl ;

    return 0 ;
}