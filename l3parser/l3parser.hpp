#pragma once

#include "simdjson.h"
#include "simdjson.cpp"
#include "structs.hpp"

using namespace simdjson;

class L3Parser {
public:
    L3Parser(const std::string& exchange, const std::string& symbol) :  _exchange(exchange), _symbol(symbol) 
    {
        _l2s.reserve(1000000);
    }
    
    bool add_message(const std::string& message)
    {
        return false;
    }

    pybind11::array_t<L2Book> books()
    {
        return pybind11::array(_l2s.size(), _l2s.data());
    }


private:
    std::string                    _exchange{""};
    std::string                    _symbol{""};

    std::vector<L2Book>            _l2s;

};