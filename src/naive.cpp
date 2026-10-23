#include "search.h"

std::vector<int> NaiveSearch(const std::string& text, const std::string& pattern){
    std::vector <int> ans;
    int n=text.size();
    int m=pattern.size();

    if (m==0 || n<m) return ans;

    for (int i=0;i<=n-m;i++){
        int j=0;

        while (j<m && text[i+j] == pattern[j]) j++;

        if (j==m) ans.emplace_back(i);
    }
    
    return ans;

}

