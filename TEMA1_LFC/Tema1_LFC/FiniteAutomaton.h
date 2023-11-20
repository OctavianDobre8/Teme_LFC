#pragma once
#include <set>
#include <map>


class FiniteAutomaton
{
public:

	FiniteAutomaton(const std::set<int>& Q, const std::set<char>& Sigma, const std::map<int, std::map<char, std::set<int>>>& delta, int q0, const std::set<int>& F);

	void verifyAutomaton();

	void printAutomaton();

	void checkWord();

	void isDeterministic();
private:
	std::set<int> Q; // Set of states
	std::set<char> Sigma; // Alphabet
	std::map<int, std::map<char, std::set<int>>> delta; // Transition function
	int q0; // Start state
	std::set<int> F; // Set of accept states

};

