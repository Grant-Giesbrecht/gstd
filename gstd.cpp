#include "gstd.hpp"

using namespace std;

/*
 Breaks a string into a vector of substrings. Each character in 'delin' indicates a character used to
 indicate a break between words. Deliniating characters are not included in words.
 
 input - string to parse
 delin - deliniating characters
 
 Returns a vector of parsed strings
 */
vector<string> parse(string input, string delin){
    
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
 
 Returns a vector of parsed strings
 */
vector<string_idx> parseIdx(string input, string delin){
    
    vector<string> output;
    
    int len_counter = 0; //Number of elements in the deliated section
    for (size_t i = 0; i < input.length() ; i++){
        
        if ((delin.find(input[i]) != string::npos)){ //Deliniator found
            
            //Add block to output if section exists (not two deliniators in a row)
            if (len_counter > 0){
                
                string_idx tempSI;
                tempSI.str = input.substr(i-len_counter , len_counter);
                tempSI.idx = i;
                
                output.push_back(tempSI);
            }
            
            //Reset length counter
            len_counter = 0;
            
        }else if(i+1 == input.length()){ //Handle end conditions
            len_counter++;
            
            if (input.substr(i-len_counter+1 , len_counter).length() > 0){
                
                string_idx tempSI;
                tempSI.str = input.substr(i-len_counter+1 , len_counter);
                tempSI.idx = i;
                
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
