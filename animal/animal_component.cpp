#include <string>
#include <list>

#include "animal_component.h"

Pet::Pet(const std::string &name) : name(name) { 
    }

Pet::Pet(const nlohmann::json &j) {
	name = j["name"];
	nlohmann::json jLegs = j["legs"];
	for (nlohmann::json::const_iterator it=jLegs.begin(); it !=jLegs.end(); ++it) {
	   Leg *leg=new Leg(*it);
	   legs.push_back(leg);
	}
}

void Pet::setName(const std::string &name_) { 
    name = name_; 
}

const std::string &Pet::getName() const { 
    return name; 
}

void Pet::setLeg( Leg &leg_) {
    leg = &leg_;
}

Leg &Pet::getLeg() {
    return *leg;
}

std::list<Leg*> Pet::getLegs() {
    return legs;
}

void Pet::addLeg(Leg &leg) {
    legs.push_front(&leg);
}

py::object Pet::to_json() const {
	nlohmann::json j;

	j["name"]=name;
	j["leg"]=0;

	nlohmann::json jLegs;
	for (std::list<Leg*>::const_iterator it=legs.begin(); it != legs.end(); ++it) {
		jLegs.push_back((**it).to_json());
	}
	j["legs"]=jLegs;
	return j;
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(animal_component, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def(py::init<const nlohmann::json &>())
        .def("to_json", &Pet::to_json)
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("getLegs", &Pet::getLegs)
        .def("addLeg", &Pet::addLeg)
        .def("setLeg", &Pet::setLeg)
        .def("getLeg", &Pet::getLeg);
}
