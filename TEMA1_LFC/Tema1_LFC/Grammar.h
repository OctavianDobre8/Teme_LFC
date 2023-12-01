#pragma once
#include <string>
#include <set>
#include <vector>


struct Production
{
	std::string nonTerminal;
	std::vector<std::string>productions;
};

class Grammar
{
public:
	Grammar();
	Grammar(const std::set<std::string>& VN, const std::set<std::string>& VT, const std::string& S, const std::vector<Production>& P);

	void verifyGrammar();

	bool isRegular();

	void generateWord(std::string S);

	friend std::ostream& operator<<(std::ostream& output, const Grammar& grammar);

	friend std::istream& operator>>(std::istream& input, Grammar& grammar);

private:
	std::set<std::string> VN;
	std::set<std::string> VT;
	std::string S;
	std::vector<Production> P;


};

