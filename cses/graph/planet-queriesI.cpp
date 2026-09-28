#include<bits/stdc++.h>
using namespace std; 


const int LOG = 30;
vector<vector<int>> up;
void build(vector<int> &parents){
    int n = parents.size(); 
    up.assign(LOG, vector<int> (n)); 

    for (int j = 0; j < n; j++)
    {
        up[0][j] =  parents[j]; 
    }

    // fill the lifting table 

    for (int i = 1; i < LOG; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            up[i][j] = up[i-1][up[i-1][j]]; 
        }
        
    }
}

int query(int start, int jump){
    int current = start; 
    for (int i = 0; i < LOG; i++)
    {
        if(jump&(1<<i)){
            current = up[i][current]; 
        }
    }
    return current;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int n, q; 
    cin >> n >> q;
    
    vector<int> parents(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parents[i]; 
        parents[i]--; 
        // converting it into zero based indexing      
    }

    build(parents); 

    while (q--)
    {
        int a, k; 
        cin >> a >> k;
        a--; 
        cout << query(a, k)+1 << endl; // convert back to 1-based indexing 
    }
    return 0; 
}