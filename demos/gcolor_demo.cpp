#include <iostream>
#include <vector>
#include <string>
#include <ktable.hpp>
#include <gstd.hpp>
#include <gcolors.hpp>
#include <cmath>
#include <ctgmath>
using namespace std;

using namespace gstd;

//CXCOMPILE clang++ -o sandbox sandbox.cpp -std=c++11 -lgstd -lktable
//CXPRINTCOM FALSE

void print_address(long address);


int main(){


	cout << "Red: \033[1mThis should be bold/bright\033[0mThis is back to normal" << endl;
	cout << gcolor::red << "This should be red" << gcolor::green << gcolor::redBg << "now the background should be red with a green fg" << gcolor::bb << "now bold too"  << endl;
	cout << "same" << gcolor::normal << "now normal" << endl;

	cout << gcolor::normal << gcolor::red << "WARNING:" << gcolor::normal << " this is a warning" << endl;


	return 0;
}
