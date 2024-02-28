#pragma once
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string& str, char delimiter);
std::string trim(std::string& to_trim);
std::string r_redundant_spaces(std::string& to_process);

void test_trim();