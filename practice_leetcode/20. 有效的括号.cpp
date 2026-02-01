#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       for(int i=0;i<s.size();i++){
       if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        st.push(s[i]);}
        else{
            if (st.empty()) return false;
            char topChar = st.top();
            if (s[i] == ')' && topChar != '(') return false;
                if (s[i] == ']' && topChar != '[') return false;
                if (s[i] == '}' && topChar != '{') return false;
                st.pop();
        }
    }
return st.empty();
};};