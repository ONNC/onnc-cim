#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <memory>
#include <type_traits>
#include <cassert>
#include <vector>

namespace statistics {

class Datum {
public:
	virtual ~Datum() = 0;
	virtual std::ostream& print(std::ostream& os) const = 0;
	virtual std::string type() const = 0;
	const std::string &name() const;
	const std::string &desc() const;
protected:
	Datum(const std::string &name, const std::string &desc)
		: name_v{name}
		, desc_v{desc}
		{}
private:
	std::string name_v;
	std::string desc_v;
};

class Counter : public Datum {
public:
	using value_type = int32_t;
	Counter(const std::string &name, const std::string &description, value_type value=0)
		: Datum{name, description}
		, val{value} 
		{}
	~Counter() = default;
	Counter(const Counter &counter) = default;
	Counter& operator++();
	Counter operator++(int);
	Counter& operator--();
	Counter operator--(int);
	Counter& operator+=(const value_type value);
	Counter& operator-=(const value_type value);
	operator value_type() const;
	std::ostream& print(std::ostream& os) const override;
	value_type value() const;
	std::string type() const override;
private:
	value_type val;
};

// TODO: Implement class Histogram
class Histogram : public Datum {
public:
	Histogram() : Datum{"",""} {}
	~Histogram() = default;
	std::string type() const override;
	std::ostream& print(std::ostream& os) const override;
};

// TODO: Add other data types by inheriting class Datum

namespace storage {
extern std::unordered_map<std::string, std::unique_ptr<Datum>> statisticsDB;
}

template<typename T, typename... Args>
T& registerStat(const std::string &name, const std::string &description, Args&&... args) {
	using namespace storage;
	assert(statisticsDB.find(name) == statisticsDB.end());
	assert((std::is_base_of<Datum, T>()));
	statisticsDB[name] = std::make_unique<T>(name, description, args...);
	return dynamic_cast<T&>(*statisticsDB[name]);
} 

template<typename T>
T& getStat(const std::string &name) {
	using namespace storage;
	auto it = statisticsDB.find(name);
	assert(it != statisticsDB.end());
	assert((std::is_base_of<Datum, T>()));
	return dynamic_cast<T&>(*it->second);
	/*
	if(ptr == nullptr) {
		std::cerr << "Fatal: Datum in key \"" << name << "\" is of another type.\n";
		exit(1);
	}
	return *ptr;
	*/
}

void dumpStats(std::ostream& os=std::cout);
void clearStats();

} // namespace statistics

