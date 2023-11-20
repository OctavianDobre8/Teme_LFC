#include "FiniteAutomaton.h"
#include <stdexcept>

FiniteAutomaton::FiniteAutomaton(const std::set<int>& Q, const std::set<char>& Sigma, const std::map<int, std::map<char, std::set<int>>>& delta, int q0, const std::set<int>& F)
	: Q(Q), Sigma(Sigma), delta(delta), q0(q0), F(F) {}

void FiniteAutomaton::verifyAutomaton()
{
	//checks if q0 is in Q
	if (Q.find(q0) == Q.end())
		throw std::runtime_error("Start state q0 is not in the set of states Q.");
	//check if all states in F are in Q 
	for (int state : F)
		if (Q.find(state) == Q.end())
			throw std::runtime_error("An accept state F is not in the set of states Q.");
	//Check if all states and symbols in delta are in Q and Sigma 
	for (const auto& [state, transitions] : delta) {
		if (Q.find(state) == Q.end())
			throw std::runtime_error("A state in the transition function delta is not in the set of states Q.");

		for (const auto& [symbol, nextStates] : transitions) {
			if (Sigma.find(symbol) == Sigma.end())
				throw std::runtime_error("A symbol in the transition function delta is not in the alphabet Sigma.");

			for (int nextState : nextStates)
				if (Q.find(nextState) == Q.end())
					throw std::runtime_error("A state in the transition function delta is not in the set of states Q.");
		}
	}
}

