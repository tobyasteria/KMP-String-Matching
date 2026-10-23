#include "search.h"

std::vector<int> buildLPS(const std::string& pattern) {
    int m = static_cast<int>(pattern.size());
    std::vector<int> lps(m, 0);

    int len = 0;
    
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } 
        else if (len != 0) {
            len = lps[len - 1];
        } 
        else {
            lps[i++] = 0;
        }
    }

    return lps;
}

std::vector<int> KMPSearch(const std::string& text, const std::string& pattern){

    std::vector<int> ans;

    int n=text.size();
    int m=pattern.size();

    if (m==0 || n<m) return ans;

    std::vector<int> lps = buildLPS(pattern);

    int i=0;
    int j=0;

    while (i<n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            ans.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return ans;
}