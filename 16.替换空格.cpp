class Solution {
public:
    string replaceSpaces(string &str) {
        string temp;
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] == ' ')
                temp += "%20";
            else temp += str[i];
        }
        return temp;
    }
};