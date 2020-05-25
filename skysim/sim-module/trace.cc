#include "sim-module/trace.hh"

std::unordered_set<std::string> Trace::ongoing = std::unordered_set<std::string>();
void Trace::init(const std::string &json_name) {
	ongoing.clear();
	mtr_init(json_name.c_str());
	mtr_register_sigint_handler();
}
void Trace::start(const std::string &catogory, const std::string &name, size_t id) {
	if(ongoing.count(name) != 0)
		fprintf(stderr, "Warning: Another event with name \"%s\" is not finished yet.\n", name.c_str());
	else
		ongoing.insert(name);
	MTR_START(catogory.c_str(), name.c_str(), (void*)id);
}
void Trace::step(const std::string &catogory, const std::string &name, size_t id, const std::string step_name) {
	MTR_STEP(catogory.c_str(), name.c_str(), (void*)id, step_name.c_str());
}
void Trace::finish(const std::string &catogory, const std::string &name, size_t id) {
	MTR_FINISH(catogory.c_str(), name.c_str(), (void*)id);
	ongoing.erase(name);
}
void Trace::finalize() {
	if(!ongoing.empty())
		fprintf(stderr, "Warning: Some events are not finished yet.\n");
	mtr_flush();
	mtr_shutdown();
}
