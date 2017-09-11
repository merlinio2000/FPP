/*
 * values.cpp
 *
 *  Created on: May 28, 2016
 *      Author: lerlin
 */
#include "../header/variables.hpp"



var& variables::at(const std::string& name)
{
        return varmap[name];
}

bool variables::contains(const string& name) const
{
	return varmap.count(name);
}

void variables::print() const
{
	for (const auto& ent : varmap)
	{
		cout << ent.first << "->" << ent.second.get_string() << "\n";
	}
}


