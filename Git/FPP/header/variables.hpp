/*
 * variables.hpp
 *
 *  Created on: Mar 16, 2017
 *      Author: kerlin
 */

#pragma once

#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>

#include "var.hpp"

using namespace std;;

class variables
{
public:
	bool contains(const string&) const;
	var& at(const string&);
	void print() const;
	variables() = default;

private:
	unordered_map<string, var> varmap{};
};
