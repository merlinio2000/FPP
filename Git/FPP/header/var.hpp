/*
 * var.hpp
 *
 *  Created on: Mar 16, 2017
 *      Author: kerlin
 */

#pragma once

#include <string>
#include <vector>


struct var_complete
{
    std::string s_val = "this is the default value for a string in var";
    long double n_val = 0.0;
    bool b_val = false;
    bool empty = true;
};

class var
{
private:
    var_complete var_c{};
    std::vector<var_complete> tpl = {};
    

public:
    var(const std::string& s)  {this->var_c.s_val  = s;};
    var(const std::vector<var_complete>& t)   {this->tpl = t;};
    var(const long double& n)   {this->var_c.n_val = n;};
    var(const bool b) {this->var_c.b_val = b;};
    var() = default;
    var(std::nullptr_t) {var_c.empty = true;};
    
    const std::string& get_string() const;
    const std::vector<var_complete>& get_tuple() const;
    const long double& get_num() const;
    const bool& get_bool() const;
    const var_complete& get_complete() const;
    
    var(const var& other) : var_c(other.get_complete()) {};
};

