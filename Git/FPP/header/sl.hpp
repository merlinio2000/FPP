/*
 * sl.hpp
 *
 *  Created on: Mar 16, 2017
 *      Author: kerlin
 */

#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <iostream>


#include "variables.hpp"
#include "var.hpp"

class sl {
private:
        variables & vs;
public:
	sl(variables&);
	bool exec(const std::string&, std::vector<var>&);
        std::unordered_map<std::string, std::function<var(std::vector<var>&)>> functions;
};
