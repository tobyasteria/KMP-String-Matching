#include <iostream>
#include "search.h"

int main() {
    std::string text = "AAAAA";
    std::string pattern = "AAA";

    std::vector<int> result = NaiveSearch(text, pattern);

    for (int pos : result) {
        std::cout << pos << " ";
    }

    return 0;
}