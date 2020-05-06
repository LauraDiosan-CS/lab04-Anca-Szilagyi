#pragma once
#include <string>
class Pet
{
public:
	Pet() = default;
	Pet(std::string t, std::string s, double p) :type{ t }, species{ s }, price{ p } {
	}
	double getPrice() const noexcept {
		return price;
	}
	std::string getType() const {
		return type;
	}

	bool operator == (Pet const& rhs) {
		return type == rhs.type && species == rhs.species && price == rhs.price;
	}
private:
	std::string type;
	std::string species;
	double price=-1.0;
};

