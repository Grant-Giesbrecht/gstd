#include "gstd.hpp"

#include <regex>
#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;
namespace gstd {

/*
 Converts a string to a boolean. Non-case sensitive. Converts, T, True, 1 to true,
 and F, False, 0 to false. Any other input throws an invalid_argument exception.
 */
bool to_bool(std::string bstr){
    
    bstr = to_upper(bstr);
    
    if (bstr == "T" || bstr == "TRUE" || bstr == "1"){
        return true;
    }else if(bstr == "F" || bstr == "FALSE" || bstr == "0"){
        return false;
    }else{
        throw invalid_argument("Failed to convert string to boolean. Must be T/F, True/False, 1/0.");
    }
    
}

/*
 Returns the string 's' with all characters converted to upper case.
 */
string to_upper(std::string s){
    for (int i = 0; i < s.length() ; i++){
        s[i] = toupper(s[i]);
    }
    return s;
}

/*
Returns the string 's' with all characters converted to lower case.
*/
string to_lower(std::string s){
        for (int i = 0; i < s.length() ; i++){
            s[i] = tolower(s[i]);
        }
        return s;
    }

/*
 Breaks a string into a vector of substrings. Each character in 'delin' indicates a character used to
 indicate a break between words. Deliniating characters are not included in words.
 
 input - string to parse
 delin - deliniating characters (these are deleted from the returned words)
 keep_delin - characters that will always be recognized as words, will not be removed, and will always be lone
 
 Returns a vector of parsed strings
 */
vector<string> parse(string input, string delin, string keep_delin){
    
    vector<string> output;
    
    int len_counter = 0; //Number of elements in the deliated section
    for (size_t i = 0; i < input.length() ; i++){
        
        if ((delin.find(input[i]) != string::npos)){ //Deliniator found
            
            //Add block to output if section exists (not two deliniators in a row)
            if (len_counter > 0){
                output.push_back(input.substr(i-len_counter , len_counter));
            }
            
            //Reset length counter
            len_counter = 0;
            
        }else if ((keep_delin.find(input[i]) != string::npos)){ //Keep-deliniator found
        
            //Add block to output
            if (len_counter > 0){
                output.push_back(input.substr(i-len_counter , len_counter));
            }
        
            //Reset length counter
            len_counter = 0;
            
            output.push_back(string(1, input[i]));
            
        }else if(i+1 == input.length()){ //Handle end conditions
            len_counter++;
            
            if (input.substr(i-len_counter+1 , len_counter).length() > 0){
                output.push_back(input.substr(i-len_counter+1 , len_counter));
            }
            
        }else{
            
            //Increment length counter
            len_counter++;
            
        }
    }
    
    return output;
}

/*
 Breaks a string into a vector of substrings. Each character in 'delin' indicates a character used to
 indicate a break between words. Deliniating characters are not included in words.
 
 input - string to parse
 delin - deliniating characters
 
 Returns a vector of parsed strings along with the index of the first character of the substring in
 the original string.
 */
vector<string_idx> parseIdx(string input, string delin, string keep_delin){
    
    vector<string_idx> output;
    
    int len_counter = 0; //Number of elements in the deliated section
    for (size_t i = 0; i < input.length() ; i++){
        
        if ((delin.find(input[i]) != string::npos)){ //Deliniator found
            
            //Add block to output if section exists (not two deliniators in a row)
            if (len_counter > 0){
                
                string_idx tempSI;
                tempSI.str = input.substr(i-len_counter , len_counter);
                tempSI.idx = i-tempSI.str.length();
                
                output.push_back(tempSI);
            }
            
            //Reset length counter
            len_counter = 0;
            
        }else if ((keep_delin.find(input[i]) != string::npos)){ //Keep-deliniator found
        
            //Add block to output
            if (len_counter > 0){
                string_idx tempSI;
                tempSI.str = input.substr(i-len_counter , len_counter);
                tempSI.idx = i-tempSI.str.length();
                output.push_back(tempSI);
            }
        
            //Reset length counter
            len_counter = 0;
            
            //Add keep-delin word
            string_idx tempSI;
            tempSI.str = input[i];
            tempSI.idx = i;
            output.push_back(tempSI);
            
        }else if(i+1 == input.length()){ //Handle end conditions
            len_counter++;
            
            if (input.substr(i-len_counter+1 , len_counter).length() > 0){
                
                string_idx tempSI;
                tempSI.str = input.substr(i-len_counter+1 , len_counter);
                tempSI.idx = i-tempSI.str.length()+1;
                
                output.push_back(tempSI);
            }
            
        }else{
            
            //Increment length counter
            len_counter++;
            
        }
    }
    
    return output;
}

/*
 Adds whitespace around every instance of a character in 'in' that is contained in
 'targets'.
 
 in - string in which to ensure targets surrounded by whitespace
 targets - characters to surround with whitespace
 
 Void return
 */
void ensure_whitespace(string& in, string targets){
    
    //Add whitespace buffer around all target characters
    for (size_t i = 0 ; i < in.length() ; i++){
        if (targets.find(in[i]) != string::npos){ //Found in string
            in = in.substr(0, i) + " " + in[i] + " " + in.substr(i+1);
            i++;
        }
    }
    
    //Remove excess white space - no consecutive spaces
    for (size_t i = 0; i+1 < in.length() ; i++){
        if (in[i] == ' ' && in[i+1] == ' '){
            in = in.substr(0, i) + in.substr(i+1);
            i--;
        }
    }
    
}

/*
 Removes leading and trailing whitespace from 'in'. Void return.
 
 Credit to Stack Overflow's Evgeny Karpov, who's answer to
 https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
 is the single active line of this function.
 */
void trim_whitespace(string& in){
    in = std::regex_replace(in, std::regex("^ +| +$|( ) +"), "$1");
}

/*
 Looks for a string in 'in'. Starts the search at 'start' and saves the
 first character after the found string in 'end'. The string it searches
 for is defined by being enclosed in double quotes. Double quotes escaped
 by a backslash will not mark the end of a string.
 
 If no string is found, 'end' is set equal to zero.
 */
std::string get_string(std::string in, size_t& end, size_t start){
    
    end = 0;
    
    bool was_backslash = false;
    bool in_string = false;
    size_t start_char;
    
    //Set was_backslash correctly if 'start' is not zero
    if (start != 0){
        was_backslash = (in[start-1] == '\\');
    }
    
    for (size_t i = start ; i < in.length() ; i++){ //Scan through each character...
        
        if (in[i] == '"'){
            if (was_backslash){
                //do nothing - escaped
                was_backslash = false;
            }else{
                if (in_string){ //found end
                    end = i+1; //Set end correctly
                    return in.substr(start_char, end-start_char-1); //Return interior
                }else{ //found start
                    in_string = true;
                    start_char  = i+1; //Next char is where string inside begins
                }
            }
        }else if (in[i] == '\\'){
            was_backslash = !was_backslash; //two backslashes are a backslash char, not an escape char
        }else if (was_backslash){
            was_backslash = false;
        }
        
    }
    
    return "";
}

/*
 Reads 'in' as a vector of doubles. Expects no leading or trailing square or
 curly brackets. Commas separate elements. Whitespace is tolerated. Any format
 accepted by stod() is accepted in this function.
 
 EXCEPTIONS:1
 If 'in' can not be converted to a vector<double>, invalid_argument exception
 is thrown.
 */
std::vector<double> to_dvec(std::string in){

    std::stringstream input(in);
    std::string element;

    std::vector<double> vec;
    
    while(std::getline(input, element, ',')){ //break line at every comma
        
        //Remove extra whitespace
        trim_whitespace(element);
        
        vec.push_back(stod(element));
        
    }
    
    return vec;
}

std::vector<std::vector<double> > to_dvec2D(std::string in){
    
}

/*
 Reads 'in' as a vector of strings. Expects no leading or trailing square or
 curly brackets. Commas separate elements. Whitespace is tolerated. Any format
 accepted by stod() is accepted in this function. Strings are surrounded by double
 quotes. Double quotes can be contained in the detected string, they need to be
 escpaed with a backslash.
 
 TODO: Does not enforce 1.) requiring exactly 1 comma between strings 2.) extraneous characters outside of the strings
 
 EXCEPTIONS:1
 If 'in' can not be converted to a vector<double>, invalid_argument exception
 is thrown.
 */
std::vector<std::string> to_svec(std::string in){

    std::vector<std::string> vec;
    
    size_t end = 0;
    size_t idx = 0;
    std::string stemp;
    
    do{
        stemp = gstd::get_string(in, idx, idx);
        if (stemp != ""){
            vec.push_back(stemp);
        }
    }while(idx < in.length());
    
    return vec;

}

std::vector<std::vector<std::string> > to_svec2D(std::string in){
    
}

/*
Reads 'in' as a vector of doubles. Expects no leading or trailing square or
curly brackets. Commas separate elements. Whitespace is tolerated. Any format
accepted by stod() is accepted in this function.

EXCEPTIONS:1
If 'in' can not be converted to a vector<double>, invalid_argument exception
is thrown.
*/
std::vector<bool> to_bvec(std::string in){
    
    std::stringstream input(in);
    std::string element;

    std::vector<bool> vec;
    
    while(std::getline(input, element, ',')){ //break line at every comma
        
        //Remove extra whitespace
        trim_whitespace(element);
        
        vec.push_back(to_bool(element));
        
    }
    
    return vec;
    
}

std::vector<std::vector<bool> > to_bvec2D(std::string in){
    
}



}

