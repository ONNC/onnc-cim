#include <unordered_set>
#include <string>
#include "sim-module/minitrace.h"

class Trace {

private:
static std::unordered_set<std::string> ongoing;
public:
static void init(const std::string &json_name);
static void start(const std::string &catogory, const std::string &name, size_t id) ;
static void step(const std::string &catogory, const std::string &name, size_t id, const std::string step_name) ;
static void finish(const std::string &catogory, const std::string &name, size_t id) ;
static void finalize() ;
};
