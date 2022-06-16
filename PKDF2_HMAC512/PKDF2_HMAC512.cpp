#include <pybind11/pybind11.h>

char version[]="1.0";

char const* getVersion() {
	return version;
}

class PKDF2_HMAC512
{
    public:
        PKDF2_HMAC512(std::string &password, std::string &random_word, int num_itr) : password(password), random_word(random_word),  num_itr(num_itr) {}
        ~PKDF2_HMAC512() {}

        std::string get_hash() { return password+"43BD48ADE3219A1931115A1DABBE1A7F"; };

    private:
        std::string password;
        std::string random_word;
        int num_itr;
};
 
namespace py = pybind11;


PYBIND11_MODULE(PKDF2_HMAC512,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  greetings.def("getVersion", &getVersion, "a function returning the version");
  
    // bindings to PKDF2_HMAC512 class
    py::class_<PKDF2_HMAC512>(greetings, "PKDF2_HMAC512", py::dynamic_attr())
        .def(py::init<std::string &, std::string &,int>())
        .def("get_hash", &PKDF2_HMAC512::get_hash);
}