#ifndef GSTD_HPP
#define GSTD_HPP

#include <vector>
#include <string>

/*
 Struct containing a string and a size_t. Designed to contain a subtring
 and it's start index in the original string.
 */
typedef struct{
    std::string str;
    size_t idx;
}string_idx;

std::vector<std::string> parse(std::string input, std::string delin);
std::vector<std::string_idx> parseIdx(std::string input, std::string delin);
void ensure_whitespace(string& in, string targets);

#endif
