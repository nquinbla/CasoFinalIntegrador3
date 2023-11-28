//1. Definir e implementar una clase Variant. Esta clase deberá ser capaz de representar diferentes tipos de datos, incluyendo símbolos, números, listas y procedimientos.
//2. Implementar un método to_string() para la clase Variant que convierta una instancia de la clase a una cadena de texto.
//3. Implementar un método to_json_string() para la clase Variant que convierta una instancia de la clase a una representación en formato JSON.
//4. Implementar un método estático from_json_string() que tome una cadena en formato JSON y la convierta a una instancia de la clase Variant.
//5. Implementar un método parse_json() que tome una cadena en formato JSON y la convierta a una instancia de la clase Variant.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <json11.cpp>
#include <jsonlib.hpp>


struct Entorno;

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
    string to_string() {
        switch (type) {
            case Type::SYMBOL:
                return symbol;
            case Type::NUMBER:
                return std::to_string(number);
            case Type::LIST:
                {
                    string result = "(";
                    for (int i = 0; i < list.size(); i++) {
                        result += list[i].to_string();
                        if (i < list.size() - 1) {
                            result += " ";
                        }
                    }
                    result += ")";
                    return result;
                }
            case Type::PROCEDURE:
                return "<procedure>";
        }
    }
    string to_json_string() {
        switch (type) {
            case Type::SYMBOL:
                return "\"" + symbol + "\"";
            case Type::NUMBER:
                return std::to_string(number);
            case Type::LIST:
                {
                    string result = "[";
                    for (int i = 0; i < list.size(); i++) {
                        result += list[i].to_json_string();
                        if (i < list.size() - 1) {
                            result += ", ";
                        }
                    }
                    result += "]";
                    return result;
                }
            case Type::PROCEDURE:
                return "<procedure>";
        }
    }
    static Variant from_json_string(string json) {
        if (json[0] == '"') {
            return Variant(json.substr(1, json.size() - 2));
        } else if (json[0] == '[') {
            vector<Variant> list;
            int i = 1;
            while (i < json.size() - 1) {
                int j = i;
                int depth = 0;
                while (j < json.size() - 1) {
                    if (json[j] ==
};
