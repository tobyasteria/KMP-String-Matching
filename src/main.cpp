#include <iostream>
#include "search.h"

int main() {
    std::string text;
    std::string pattern;
    std::cout<<"enter text:";
    std::getline(std::cin,text);
    std::cout<<"enter pattern:";
    std::getline(std::cin,pattern);

    std::vector<int> naiveResult = NaiveSearch(text, pattern);
    std::vector<int> kmpResult = KMPSearch(text, pattern);
    std::vector<int> lps = buildLPS(pattern);

    std::cout << "\nLPS Array: ";
    for (int value : lps) {
        std::cout << value << " ";
    }

    std::cout << "\nNaive matches: ";
    for (int pos : naiveResult) {
        std::cout << pos << " ";
    }

    std::cout << "\nKMP matches: ";
    for (int pos : kmpResult) {
        std::cout << pos << " ";
    }

    std::cout << "\n\nVerification: ";
    if (naiveResult == kmpResult) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\n";
    }





}