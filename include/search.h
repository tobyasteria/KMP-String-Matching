#pragma once

#include <string>
#include <vector>

std::vector<int> NaiveSearch( const std::string& text, const std::string& pattern);

std::vector<int> buildLPS(const std::string& pattern);
