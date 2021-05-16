#include <string>
#include <pybind11/pybind11.h>
#include <pybind11_json/pybind11_json.hpp>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
namespace py = pybind11;


struct Leg {
    Leg(const std::string &name);
    Leg(const nlohmann::json& json);

    void setName(const std::string &name_);
    const std::string &getName() const;

    py::object to_json() const;

    std::string name;
};


