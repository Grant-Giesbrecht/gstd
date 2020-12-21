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
std::string bool_to_str(bool b, char format='f');

std::vector<bool> int_to_bin(int x, int num_bits=8);
std::string bin_to_str(std::vector<bool> x, int pad_to_bits=8, bool LSB_right = true);

std::string to_upper(std::string s);
std::string to_lower(std::string s);

std::vector<std::string> parse(std::string input, std::string delin, std::string keep_delin="", bool preserve_strings=false);
std::vector<string_idx> parseIdx(std::string input, std::string delin, std::string keep_delin="", bool preserve_strings=false);

void ensure_whitespace(std::string& in, std::string targets);
void trim_whitespace(std::string& in);

std::string get_string(std::string in, size_t& end, size_t start=0);

std::vector<double> to_dvec(std::string in);
std::vector<std::vector<double> > to_dvec2D(std::string in);
std::vector<std::string> to_svec(std::string in);
std::vector<std::vector<std::string> > to_svec2D(std::string in);
std::vector<bool> to_bvec(std::string in);
std::vector<std::vector<bool> > to_bvec2D(std::string in);

std::string to_gstring(double x, size_t buf_size=30, size_t precision=6);

std::vector<size_t> all_occurances(std::string in, std::string target);
size_t findAndReplace(std::string& line, std::string search, std::string repl);

/*
Checks if the specified value 'val' is included in the vector 'vec'. Returns
true if so, else false.
*/
template<typename T>
bool inVector(T val, std::vector<T> vec){
	return (std::find(vec.begin(), vec.end(), val) != vec.end());
}

}

#endif
