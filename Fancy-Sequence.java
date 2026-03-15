1class Fancy {
2
3    final static int mod = 1000000007;
4    List <Integer> arr;
5    long add, mul;
6    public Fancy() {
7        // List <Integer> arr = new ArrayList <>();
8        // int add = 0, mul = 1;
9        this.arr = new ArrayList<>();
10        this.add = 0;
11        this.mul = 1;
12    }
13    
14    public void append(int val) {
15        long number = ((long)(val - this.add + mod) * findPower(this.mul)) % mod;
16        arr.add((int)number);
17    }
18    
19    public void addAll(int inc) {
20        this.add = (this.add + inc) % mod;
21    }
22    
23    public void multAll(int m) {
24        this.mul = (this.mul * m) % mod;
25        this.add = (this.add * m) % mod;
26    }
27    
28    // public int getIndex(int idx) {
29    //     if (idx >= this.arr.size()) return -1;
30    //     return (int)(((long)(this.arr.get(idx) * this.mul) + this.add)) % mod; 
31    // }
32
33    public int getIndex(int idx) {
34    if (idx >= arr.size()) return -1;
35    long num = (long) this.arr.get(idx);
36    return (int)((num * this.mul) % mod + this.add) % mod;
37}
38
39    public static int findPower(long n) {
40        long exp = 1;
41        long base = Fancy.mod - 2;
42        // int base = 10;
43        while (base != 0) {
44            if ((base & 1)== 1) 
45                exp = (exp * n) % mod;
46            n = (n * n) % mod;
47            base >>= 1;
48        }
49        return (int)exp;
50    }
51}
52
53// /**
54//  * Your Fancy object will be instantiated and called as such:
55//  * Fancy obj = new Fancy();
56//  * obj.append(val);
57//  * obj.addAll(inc);
58//  * obj.multAll(m);
59//  * int param_4 = obj.getIndex(idx);
60//  */
61
62
63// class Fancy {
64
65//     final static int mod = 1000000007;
66//     List <Integer> arr;
67//     int add, mul;
68//     public Fancy() {
69//         this.arr = new ArrayList<>();
70//         this.add = 0;
71//         this.mul = 1;
72//     }
73    
74//     public void append(int val) {
75//         long number = (long)(val - this.add + mod) % mod * findPower(this.mul) % mod;
76//         arr.add((int)number);
77//     }
78    
79//     public void addAll(int inc) {
80//         this.add = (this.add + inc) % mod;
81//     }
82    
83//     public void multAll(int m) {
84//         this.mul = (int)((long)this.mul * m % mod);
85//         this.add = (int)((long)this.add * m % mod);
86//     }
87
88//     public int getIndex(int idx) {
89//         if (idx >= arr.size()) return -1;
90//         return (int)(((long)arr.get(idx) * this.mul % mod + this.add) % mod);
91//     }
92
93//     public static int findPower(int n) {
94//         int res = 1;
95//         int exp = mod - 2;
96//         while (exp > 0) {
97//             if ((exp & 1) == 1) res = (int)((long)res * n % mod);
98//             n = (int)((long)n * n % mod);
99//             exp >>= 1;
100//         }
101//         return res;
102//     }
103// }
104
105// /**
106//  * Your Fancy object will be instantiated and called as such:
107//  * Fancy obj = new Fancy();
108//  * obj.append(val);
109//  * obj.addAll(inc);
110//  * obj.multAll(m);
111//  * int param_4 = obj.getIndex(idx);
112//  */