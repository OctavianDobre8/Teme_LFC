#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <vector>
#include <string> 
#include "Grammar.h"

int main() 
{
    std::set<std::string> VN = { "A", "B" };
    std::set<std::string> VT = { "a" };
    std::string S = "A";
    std::vector<Production> P = { {"A", {"aB", "c"}}, {"B", {"a"}} };

    Grammar myGrammar(VN, VT, S, P);

    if (myGrammar.isRegular())
        std::cout << "Gramatica este regulata.\n";
    else
        std::cout << "Gramatica nu este regulata.\n";

    return 0;
}
