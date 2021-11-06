#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Example 1
// Input: "abcda"
// Output: 5
// Explanation:
// The longest scene is "abcda".

// Example 2
// Input: "abcab"
// Output: 5
// Explanation:
// The longest scene is "abcab".


class Solution {
public:
    /**
     * @param str: The scene string
     * @return: Return the length longest scene
     */
    int getLongestScene(string &str) {
        // Write your code here
        //
        //
        int N = str.length();
        if (N <= 1) return N;

        vector<int> start = vector<int>(26, N);
        vector<int> end = vector<int>(26, -1);
        //unordered_map<char, int> charPos;

        for (int i=0; i<N; i++) {
            char ch = str[i];
            int idx = ch - 'a';
            if (i < start[idx]) {
                start[idx] = i;
            }
            if (i > end[idx]) {
                end[idx] = i;
            }
        }

        // Merge algorithm for intervals
        int res = end[0] - start[0] + 1;
        int curr_start = start[0];
        int curr_end = end[0];
        for (int i = 1; i < end.size(); i++) {
            int s = start[i];
            int e = end[i];

            //cout << "i:" << s << " " << e << endl;
            //cout << "curr:" << curr_start << " " << curr_end << endl;
            if (s <= curr_end) {
                curr_end = max(e, curr_end);
                curr_start = min(s, curr_start);
                if (curr_end - curr_start + 1 > res) {
                    res = curr_end - curr_start + 1;
                }
            } else {
                curr_start = s;
                curr_end = e;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int res;

    string str = string("abcda");
    res = sol.getLongestScene(str);
    cout << res << endl;

    str = string("abcab");
    res = sol.getLongestScene(str);
    cout << res << endl;

    return 0;
}
