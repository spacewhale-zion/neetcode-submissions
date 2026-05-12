class Solution {
public:
    bool checkValidString(string s) {
        
        int n=s.length();
        stack<int>s1;
        stack<int>s2;

        for (int i=0;i<n;i++){

            if (s[i]=='(')s1.push(i);
            if (s[i]==')'){

                if (!s1.empty())s1.pop();
                else if (!s2.empty())s2.pop();
                else return false;
            }
            if(s[i]=='*')s2.push(i);
        }

        while (!s1.empty()){

            int ind1=s1.top();
            s1.pop();

            if (!s2.empty()){

                int ind2=s2.top();
                s2.pop();
                if (ind1>ind2)return false;

            }
            else {
                return false;
            }
        }

        return true;
    }
};
