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
52
53    if (!temp) return;
54
55    for (int i = 0; i < 26; i++) {
56        destroy(temp->children[i]);
57    }
58
59    delete temp;
60}
61
62    ~Trie() {
63        destroy(root);
64    }
65};
66
67class Solution {
68public:
69    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
70        Trie obj;
71        
72        int n = wordsContainer.size();
73        int mx = INT_MAX;
74        int smallidx = INT_MAX;
75        for (int i = 0; i < n; i += 1) {
76            obj.insert(wordsContainer[i], i);
77            int x = wordsContainer[i].size();
78            if (mx > x) {
79                mx = x;
80                smallidx = i;
81            }
82        }
83        
84        int qn = wordsQuery.size();
85        vector <int> ans (qn, 0);
86
87        int xxx = 0;
88
89        for (auto& i: wordsQuery) {
90            int res = obj.startsWith(i);
91            ans[xxx++] = (res == -1) ? smallidx: res;
92        }
93        return ans;
94    }
95};