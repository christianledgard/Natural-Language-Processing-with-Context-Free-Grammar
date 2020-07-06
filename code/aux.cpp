#ifndef _AUXILIAR_FUNCTIONS_
#define _AUXILIAR_FUNCTIONS_

#include "aux.h"

static vector<string> splitString(string str,char del=' '){
    vector<string> vec;
    stringstream input(str);
    string token;

    while(getline(input,token,del))
        vec.push_back(token);
    return vec;
}
#endif
