// Enter a BrainFuck String into this program and it will give the hex notation of that string. 

// Quite Simple TBH

#include <iostream>
using namespace std;

int main(){
    
    string char1 = "0x2E"; // .
    string char2 = "0x3C"; // <
    string char3 = "0x5D"; // ]
    string char4 = "0x2D"; // -
    string char5 = "0x2B"; // +
    string char6 = "0x5B"; // [
    string char7 = "0x3E"; // >
    
    string inp_str = "";
    cout << "inp_str: ";
    cin >> inp_str;
    
    string op_str = "";
    
    for(int i=0; i<inp_str.size(); i++){
        if(inp_str[i] == '.'){
            op_str = op_str + char1 + ", ";
        }
        else if(inp_str[i] == '<'){
            op_str = op_str + char2 + ", ";
        }
        else if(inp_str[i] == ']'){
            op_str = op_str + char3 + ", ";
        }
        else if(inp_str[i] == '-'){
            op_str = op_str + char4 + ", ";
        }
        else if(inp_str[i] == '+'){
            op_str = op_str + char5 + ", ";
        }
        else if(inp_str[i] == '['){
            op_str = op_str + char6 + ", ";
        }
        else if(inp_str[i] == '>'){
            op_str = op_str + char7 + ", ";
        }
        else {
            op_str = op_str + "error" + ", ";
        }
    }
    cout << op_str << endl;
}