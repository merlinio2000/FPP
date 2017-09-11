 /*
 * var.cpp
 *
 *  Created on: August 8, 2016
 *      Author: kerlin
 */
#include "../header/var.hpp"



const std::string& var::get_string() const
{
    return var_c.s_val;
}

const std::vector<var_complete>& var::get_tuple() const
{
    return tpl;
}

const long double& var::get_num() const
{
    return var_c.n_val;
}

const bool& var::get_bool() const
{
    return var_c.b_val;
}

const var_complete& var::get_complete() const
{
    return var_c;
}
