#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <vector>
#include <string> 
#include "Grammar.h"

int main() 
{
    std::set<std::string> VN = { "S", "A" };
    std::set<std::string> VT = { "a", "b" };
    std::string S = "S";
    std::vector<Production> P = {
        {"S", {"a", "A", "b"}},
        {"A", {"a", "A"}},
        {"A", {"b"}}
    };

    Grammar myGrammar(VN, VT, S, P);

    if (myGrammar.verifyGrammar())
        std::cout << "Da";
    else std::cout << "Nu";

    std::cout << '\n';


    if (myGrammar.isRegular())
        std::cout << "Gramatica este regulata.\n";
    else
        std::cout << "Gramatica nu este regulata.\n";

    std::cout << std::endl << myGrammar.generateWord();

    return 0;
}
