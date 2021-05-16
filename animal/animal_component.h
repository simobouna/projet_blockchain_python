#include <string>
#include <list>
#include <pybind11/pybind11.h>
#include <nlohmann/json.hpp>
#include <pybind11_json/pybind11_json.hpp>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
namespace py = pybind11;

#include "members_component.h"

struct Pet {
    Pet(const std::string &name);  
    Pet(const nlohmann::json &j);  
    void setName(const std::string &name_); 
    const std::string &getName() const;

    void setLeg( Leg &leg_);
    Leg &getLeg();
    std::list<Leg*> getLegs() ;
    void addLeg(Leg &leg);

    py::object to_json() const;

    std::list<Leg*> legs;
    Leg *leg;
    std::string name;
};

