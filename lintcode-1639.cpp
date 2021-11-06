#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * @param stringIn: The original string.
     * @param K: The length of substrings.
     * @return: return the count of substring of length K and exactly K distinct characters.
     */
    int KSubstring(string &stringIn, int K) {
        // Write your code here
        unordered_map<char, int> cnt;
        unordered_set<string> strings;
        int res = 0;
        int start = 0;
        //int end;
        if (stringIn.length() < K) {
            return res;
        } 

        // "abcabc" K=3
        for (int i=0; i<stringIn.length(); i++) {
            char ch = stringIn[i];
            cnt[ch] += 1;
            // Scan a K-length substring
            printf("i=%d, start=%d, cnt.size()=%d, res=%d\n", i, start, cnt.size(), res);
            if ((i - start + 1 == K) && cnt.size() == K) {
                string sub = stringIn.substr(start, K);
                if (strings.count(sub) == 0) {
                    res += 1;
                    strings.insert(sub);
                }
                // more cleanup
                char b = stringIn[start];
                // only appear once just remove
                cnt.erase(b);
                start += 1; 
            } else if (i - start + 1 == K) {
                char b = stringIn[start];
                cnt[b] -= 1;
                if (cnt[b] == 0) {
                    cnt.erase(b);
                }
		start += 1;
            }
        }
        return res;
    }
};

int main()
{
  Solution sol;
  string str("abacab");
  int res = sol.KSubstring(str, 3);
  std::cout << res << std::endl;
}
