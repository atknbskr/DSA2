#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> genIp(string s) {
        vector<string> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.size()) {
                result.push_back(join(current));
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;
            string part = s.substr(start, len);
            if (isValid(part)) {
                current.push_back(part);
                backtrack(s, start + len, current, result);
                current.pop_back();
            }
        }
    }

    bool isValid(const string& part) {
        if (part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    string join(const vector<string>& parts) {
        string ip;
        for (const string& part : parts) {
            if (!ip.empty()) ip += '.';
            ip += part;
        }
        return ip;
    }
};

int main() {
    Solution sol;
    string S = "11211";
    vector<string> ips = sol.genIp(S);

    for (const string& ip : ips) {
        cout << ip << endl;
    }

    return 0;
}
