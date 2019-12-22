#ifndef GSTD_HPP
#define GSTD_HPP

#include <vector>
#include <string>

namespace gstd{

/*
 Struct containing a string and a size_t. Designed to contain a subtring
 and it's start index in the original string.
 */
typedef struct{
    std::string str;
    size_t idx;
}string_idx;

bool to_bool(std::string bstr);

std::string to_upper(std::string s);
std::string to_lower(std::string s);

std::vector<std::string> parse(std::string input, std::string delin);
std::vector<string_idx> parseIdx(std::string input, std::string delin);

void ensure_whitespace(std::string& in, std::string targets);
void trim_whitespace(std::string& in);

std::string get_string(std::string in, size_t& end, size_t start=0);

std::vector<double> to_dvec(std::string in);
std::vector<std::vector<double> > to_dvec2D(std::string in);
std::vector<std::string> to_svec(std::string in);
std::vector<std::vector<std::string> > to_svec2D(std::string in);
std::vector<bool> to_bvec(std::string in);
std::vector<std::vector<bool> > to_bvec2D(std::string in);

}

#endif
