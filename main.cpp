#include <iostream>
#include <fstream>

#include "header/parser.hpp"
#include "header/sl.hpp"
#include "header/var.hpp"
#include "header/variables.hpp"

using namespace std;

int main() {
    variables vars;
    sl std_lib(vars);
    ifstream ifs{"sample.fpp"};
    parser p{ifs,vars, std_lib};
    p.parse();
    /*std_lib.exec(p.functions().at(0), p.parameters().at(0));
    std_lib.exec(p.functions().at(1), p.parameters().at(1));*/
    /*std::vector<var> temp = {"a",  "\"b\""};
    std_lib.exec("="s, temp);*/
    cout << vars.at("a").get_string() << "\n";
    
    return 0;
}
