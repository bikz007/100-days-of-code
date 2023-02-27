class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n ;i++)
        {
            result = next_number(result);
        }
        return result;
    }

    string next_number(const string& s)
    {
        string result;
        for(int i=0;i < s.size(); i++)
        {
            int count = 1;
            while(i+1 < s.size() && s[i] == s[i+1])
            {
                ++i, ++count;
            }
            result += to_string(count) + s[i];
        }
        return result;
    }
};