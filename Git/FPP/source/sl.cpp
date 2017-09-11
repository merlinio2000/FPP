/*
 * sl.cpp
 *
 *  Created on: May 28, 2016
 *      Author: lerlin
 */

#include "../header/sl.hpp"
#define DEBUG_SL_ALL

#ifdef DEBUG_SL_ALL
    #define DEBUG_SL_VAR_CREATION
    #define DEBUG_SL_EXEC
#endif


bool visible(std::vector<var>& p)
{
    std::cout << "start of visible\n";
    for(const auto& e: p)
    {
                std::cout << e.get_string() << "\n";
    }
    std::cout << "end of visible\n";
    return true;
}



sl::sl(variables& v) :  vs(v)
{
    functions["visible"] = visible;
    functions["="] = [&](std::vector<var>& p) 
    {
        std::cout  << "start of =\n";
        vs.at(p[0].get_string()) =  p[1];
            #ifdef DEBUG_SL_VAR_CREATION
                std::cout << p[0].get_string() << " is " << vs.at(p[0].get_string()).get_string() << "\n";
            #endif
                
        std::cout << "end of =\n";
        
        return true; 
        
    };
}


bool sl::exec(const std::string& name, std::vector<var>& param)
{
    #ifdef DEBUG_SL_EXEC
        std::cout << "sl::exec running function " + name + " with params:\n";
        for(var& v: param)
        {
            std::cout << "\t" + v.get_string() + "\n";
        }
    #endif
    if (functions.count(name))
    {
        std::cout << "found function " + name + "\n";
        functions[name](param);
        return true;
    }else {
        std::cout << "didn't find function " + name + "\n";
        return false;
    }
}
