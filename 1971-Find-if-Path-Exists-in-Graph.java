class Solution {
    static void addEdge(int v , int w ,LinkedList<Integer> []adj){
        adj[v].add(w);
        adj[w].add(v);
    }
     static boolean DFS_Traversal2 (int sv ,int n ,int destination ,LinkedList<Integer> []adj){
        Stack<Integer> st = new Stack<>();
        st.add(sv);
        boolean []visited = new boolean[n];
        while(!st.isEmpty()) {
            sv = st.pop();
            visited[sv] = true;
            Iterator<Integer> i = adj[sv].listIterator();
            while (i.hasNext() ){
                    int e = i.next();
                    if (!visited[e]) {
                        if (e == destination) return true;
                        st.add(e);
                        visited[e] = true;
                    }
                }
        }
        return false;
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        if (source == destination) return true;
        LinkedList<Integer> []adj = new LinkedList[n];
        for (int i = 0 ; i < n ; i++)
            adj[i] = new LinkedList<Integer>();

        for (int i = 0 ; i < edges.length ; i++) {
            addEdge(edges[i][0] , edges[i][1] , adj);
        }
        return DFS_Traversal2(source,n,destination,adj);
    }
}