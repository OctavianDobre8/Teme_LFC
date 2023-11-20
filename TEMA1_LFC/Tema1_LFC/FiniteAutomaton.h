#pragma once
#include <string>
#include <set>

class FiniteAutomaton
{
public:
	void verifyAutomaton();

	void printAutomaton();

	void checkWord();

	void isDeterministic();
private:
	std::set<std::string> Q;
	std::set<std::string> epsilon;
	std::string q_0;
	std::set<std::string> F;
};

