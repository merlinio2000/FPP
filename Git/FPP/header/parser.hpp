/*
 * parser.hpp
 *
 *  Created on: Mar 16, 2017
 *      Author: kerlin
 */

#pragma once



#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "variables.hpp"
#include "var.hpp"
#include "sl.hpp"


using namespace std;;

class parser {
public:
        
	parser(ifstream& in, variables& v, sl& s) :
			inf(in), vs(v), slib(s) {};

        void parse();
	friend ostream& operator<<(ostream&, const parser&);
	vector<vector<var>>& parameters();
	const vector<string>& functions() const;
        
        size_t linecounter() const;

private:
	ifstream& inf;
	variables& vs;
        sl& slib;
	string instr;
	string function;
	string params;
	vector<var> temp_push_back; //to avoid segfault in 2D vector<var> param use this
	vector<vector<var>> param;
	vector<string> funcs;
	size_t linecntr = 0;
	bool isInQuotes = false;

};
