#include <string>
#include <nlohmann/json.hpp>
#include "members_component.h"

Leg::Leg(const std::string &name) : name (name) {
	}

__attribute__ ((visibility ("default"))) Leg::Leg(const nlohmann::json &j){
   name = j["name"];
}

void Leg::setName(const std::string &name_) {
   name = name_;
}

const std::string &Leg::getName() const { 
   return name; 
}

__attribute__ ((visibility ("default"))) py::object Leg::to_json() const{
   nlohmann::json j;
   j["name"] = name;
   return j;
}




PYBIND11_MODULE(members_component, m) {
    py::class_<Leg>(m, "Leg")
        .def(py::init<const std::string &>())
        .def(py::init<const nlohmann::json &>())
        .def("to_json", &Leg::to_json)
        .def("setName", &Leg::setName)
        .def("getName", &Leg::getName);
}
