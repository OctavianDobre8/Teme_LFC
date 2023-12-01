#include "Grammar.h"
#include<fstream>
#include<iostream>

std::ostream& operator<<(std::ostream& output, const Grammar& grammar)
{
	output << "Simbolurile neterminale (VN) sunt: ";
	for (const std::string& vnSymbol : grammar.VN)
		output << vnSymbol << ' ';
	output << '\n';

	output << "Simbolurile terminale (VT) sunt: ";
	for (const std::string& vtSymbol : grammar.VT)
		output << vtSymbol << ' ';
	output << '\n';

	output << "Simbolul de start (S) este :" << grammar.S << '\n';

	output << "Productii:\n";
	for (const Production& prod : grammar.P)
	{
		output << prod.nonTerminal << "->";
		for (const std::string& production : prod.productions)
			output << production << "|";
		output << '\n';
	}
	return output;
}

std::istream& operator>>(std::istream& input, Grammar& grammar)
{
	int vnCount, vtCount, productionCount;

	input >> vnCount;
	grammar.VN.clear();
	for (int i = 0; i < vnCount; ++i)
	{
		std::string vnSymbol;
		input >> vnSymbol;
		grammar.VN.insert(vnSymbol);

	}

	input >> vtCount;
	grammar.VT.clear();
	for (int i = 0; i < vtCount; ++i)
	{
		std::string vtSymbol;
		input >> vtSymbol;
		grammar.VT.insert(vtSymbol);
	}

	input >> grammar.S;

	input >> productionCount;
	grammar.P.clear();
	for (int i = 0; i < productionCount; ++i)
	{
		Production prod;
		input >> prod.nonTerminal;
		int numProductions;
		input >> numProductions;
		for (int j = 0; j < numProductions; ++j)
		{
			std::string production;
			input >> production;
			prod.productions.push_back(production);
		}
		grammar.P.push_back(prod);
	}
	return input;
}

Grammar::Grammar(const std::set<std::string>& VN,
	const std::set<std::string>& VT,
	const std::string& S,
	const std::vector<Production>& P)
	: VN(VN), VT(VT), S(S), P(P)
{}

Grammar::Grammar() {};

bool Grammar::isRegular()
{
	for (const auto& production : P)
	{
		std::string nonTerminal = production.nonTerminal;
		std::vector<std::string> alternatives = production.productions;

		for (const auto& alternative : alternatives)
		{
			if (alternative.size() == 1) // A -> aB || A -> a
				if (VN.find(nonTerminal) == VN.end() || VT.find(alternative) == VT.end()) // A -> a
					return false;
				else if (alternative.size() == 2) // A -> aB
					if (VN.find(nonTerminal) == VN.end() || VT.find(alternative.substr(0, 1)) == VT.end() || VT.find(alternative.substr(1, 1)) == VT.end())
						return false;
					else return false;

		}

	}
	return true;
}

