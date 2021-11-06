#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * @param str: The scene string
     * @return: Return the length longest scene
     */
    int getLongestScene(string &str) {
        // Write your code here
        //
        int len = str.length();
        // for string len <= 1
        if (str.length() <= 1) {
            return len;
        }       
        
    }
};

