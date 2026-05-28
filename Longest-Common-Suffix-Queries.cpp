1class Trie {
2public:
3    struct node {
4      
5        int idx = INT_MAX;
6        int len = INT_MAX;
7        node* children[26];
8    };
9    node* root = new node();
10    node* temp = root;
11
12    void insert(string& word, int id) {
13            ios_base::sync_with_stdio(0);
14            temp = root;
15            int len = word.size();
16            for (int i = len - 1; i >= 0 ; i -= 1) {
17                if (temp->children[word[i] - 'a']) {
18                    temp = temp->children[word[i] - 'a'];
19                    if (temp -> len > len) {
20                        temp -> len = len;
21                        temp -> idx = id;
22                    }
23    
24                }
25                else {
26                    node* obj = new node();
27                    // obj->e = false;
28                    temp->children[word[i] - 'a'] = obj;
29                    temp = obj;
30                    if (obj -> len > len) {
31                        obj -> len = len;
32                        obj -> idx = id;
33                    }
34                }
35            }
36    }
37    int startsWith(string& suffix) {
38        temp = root;
39        int ans = -1;
40        for (int i = suffix.size() - 1; i >= 0; i -= 1){
41            char ch = suffix[i];
42            if (temp->children[ch - 'a']) {
43                temp = temp->children[ch - 'a'];
44                ans = temp->idx;
45            }
46            else  break;
47        }
48        return ans;
49    }
50
51    void destroy(node* temp) {
52        if (!temp) 
53            return;
54        for (int i = 0; i < 26; i += 1) 
55            destroy(temp->children[i]);
56        delete temp;
57    }
58
59    void d() {
60        destroy(root);
61    }
62};
63
64class Solution {
65public:
66    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
67        Trie obj;
68        
69        int n = wordsContainer.size();
70        int mx = INT_MAX;
71        int smallidx = INT_MAX;
72        for (int i = 0; i < n; i += 1) {
73            obj.insert(wordsContainer[i], i);
74            int x = wordsContainer[i].size();
75            if (mx > x) {
76                mx = x;
77                smallidx = i;
78            }
79        }
80        
81        int qn = wordsQuery.size();
82        vector <int> ans (qn, 0);
83
84        int xxx = 0;
85
86        for (auto& i: wordsQuery) {
87            int res = obj.startsWith(i);
88            ans[xxx++] = (res == -1) ? smallidx: res;
89        }
90        obj.d() ;
91        return ans;
92    }
93};