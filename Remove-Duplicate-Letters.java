1class Solution {
2    public String removeDuplicateLetters(String s) {
3        Stack<Character> stk = new Stack<>();
4
5        int fq [] = new int[26];
6
7        int n = s.length();
8
9        for (int i = 0; i < n; i += 1) 
10            fq[s.charAt(i) - 'a'] = i;
11        
12        int used[] = new int[26];
13        // for (int i: fq) System.out.print(i + " ");
14        for (int i = 0; i < n; i += 1) {
15            char ch = s.charAt(i);
16
17            if (used[ch - 'a'] != 0) continue;
18            while (!stk.isEmpty() && stk.peek() > ch && i < fq[stk.peek() - 'a']) {
19                // System.out.println(i);
20                used[stk.peek() - 'a'] = 0;
21                stk.pop();
22            }
23
24            if (used[ch - 'a'] == 0) {
25                stk.push(ch);
26                used[ch - 'a'] = 1;
27            }
28        }
29
30        StringBuilder st = new StringBuilder();
31        while (!stk.isEmpty()) {
32            st.append(stk.peek());
33            stk.pop();
34        }
35        st.reverse();
36
37        return st.toString();
38        
39        
40   }
41}