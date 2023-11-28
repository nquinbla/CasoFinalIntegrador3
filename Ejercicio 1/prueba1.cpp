//Definir e implementar una clase Variant. Esta clase deberá ser capaz de representar diferentes tipos de datos, incluyendo símbolos, números, listas y procedimientos.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <initializer_list>
#include <sstream>
#include <functional>

using namespace std;

class Variant {
public:
    enum class Type { SYMBOL, NUMBER, LIST, PROCEDURE
    };
    Variant() : type(Type::SYMBOL), symbol("") {}
    Variant(string symbol) : type(Type::SYMBOL), symbol(symbol) {}
    Variant(double number) : type(Type::NUMBER), number(number) {}
    Variant(vector<Variant> list) : type(Type::LIST), list(list) {}
    Variant(function<Variant(vector<Variant>)> procedure) : type(Type::PROCEDURE), procedure(procedure) {}
    Type type;
    string symbol;
    double number;
    vector<Variant> list;
    function<Variant(vector<Variant>)> procedure;
};


