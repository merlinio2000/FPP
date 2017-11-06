/*
 * parser.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: kerlin
 */

#define DEBUG_PARSER_ALL

#ifdef DEBUG_PARSER_ALL
    #define DEBUG_PARSER_VAR
    #define DEBUG_PARSER_TEMP_PARAM
    #define DEBUG_PARSER_FUNCTION
#endif

#include "../header/parser.hpp"

void parser::parse() 
{
	std::string temp_param;//string for one param at a time
	while (std::getline(inf, instr))//read every line from filestream inf into the string instr
        {
                //the part of instr from beginning till *space* is the function being executed
		function = instr.substr(0, instr.find(' '));
		#ifdef DEBUG_PARSER_FUNCTION
                    std::cout << function + "\n";//output debugging information
                #endif
		params = instr.substr(function.size(), instr.size());//the rest of instr is the parameters

		for (size_t i = 0; i <= params.size(); ++i) //loop through each char in the parameters
                {
			if (params[i] == ' ' && isInQuotes == false) 
                        {
				params.erase(i, 1);
			}

			if (params[i] == '\"' && isInQuotes == false) 
                        {
				isInQuotes = true;
			} else if (params[i] == '\"' && isInQuotes == true) 
                        {
				isInQuotes = false;
			}

			if (((params[i] == ',' || params[i] == ' ') && isInQuotes == false)
					|| (i == params.size())) 
                        {
                            if (vs.contains(temp_param))
                            {
                                temp_push_back.emplace_back(vs.at(temp_param));
                                #ifdef DEBUG_PARSER_VAR
                                    std::cout << "found var with name " << temp_param << ";\n";
                                #endif
                            } else 
                            {
                                #ifdef DEBUG_PARSER_TEMP_PARAM
                                    std::cout << "temp_param " <<  temp_param << ";\n";
                                #endif
                                temp_push_back.emplace_back(temp_param);
                            }
				temp_param = "";
			}

			if (!((params[i] == ',' || params[i] == ' ') && isInQuotes == false)) 
                        {
				temp_param += params[i];
			}

		}
		std::cout << vs.at("a").get_string() + "\n";
		this->slib.exec(function, temp_push_back);
		this->linecntr++;
		this->param.push_back(temp_push_back);
                this->temp_push_back.clear();
		funcs.push_back(move(function));
	}
}

std::ostream& operator<<(std::ostream& os, const parser& p)
{
	os << "Function: " << p.function << "\tParams: " << p.params;
	return os;
}

std::vector<std::vector<var>>& parser::parameters() 
{
	return param;
}


const std::vector<std::string>& parser::functions() const
{
    return this->funcs;
}

size_t parser::linecounter() const 
{
    return linecntr;
}






