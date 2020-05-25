#include "sim-module/statistics.hh"

namespace statistics {

Datum::~Datum() {}

// class Datum
const std::string& Datum::name() const {
	return name_v;
}

const std::string& Datum::desc() const {
	return desc_v;
}

std::ostream& operator<<(std::ostream &os, const Datum &dat) {
	return dat.print(os);
}

// class Counter
Counter& Counter::operator++() {
	val++;
	return *this;
}

Counter Counter::operator++(int) {
	Counter ret{*this};
	val++;
	return ret;
}

Counter& Counter::operator--() {
	val--;
	return *this;
}

Counter Counter::operator--(int) {
	Counter ret{*this};
	val--;
	return ret;
}
Counter& Counter::operator+=(const value_type value) {
	val += value;
	return *this;
}
Counter& Counter::operator-=(const value_type value) {
	val -= value;
	return *this;
}

Counter::operator value_type() const {
	return val;
}

Counter::value_type Counter::value() const {
	return val;
}

std::string Counter::type() const {
	return "Counter";
}

std::ostream& Counter::print(std::ostream& os) const {
	return os << value();
}

// class Histogram
std::string Histogram::type() const {
	return "Histogram";
}

std::ostream& Histogram::print(std::ostream& os) const {
	return os;
}

// global uitilities
namespace storage {
std::unordered_map<std::string, std::unique_ptr<Datum>> statisticsDB{};
}

void dumpStats(std::ostream& os) {
	using namespace storage;
	os << "------------- Global Statistics -------------\n";
	for(auto &p : statisticsDB) {
		Datum &dat = *p.second;
		os << dat.type() << " " << dat.name() << "(" << dat.desc() << ") : ";
		os << dat;
		os << std::endl;
	}
	os << "------------- End of Statistics -------------\n";
}

void clearStats() {
	using namespace storage;
	statisticsDB.clear();
}

} // namespace statistics

