class Solution {
public:
    int countSeniors(const std::vector<std::string>& s) {
        int ans = 0;
        for (const auto& ss : s) {
            if ((ss[11] - '0') * 10 + (ss[12] - '0') > 60) {
                ans++;
            }
        }
        return ans;
    }
};