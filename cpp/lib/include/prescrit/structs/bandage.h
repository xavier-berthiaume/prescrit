#ifndef BANDAGE_H
#define BANDAGE_H

#include "premade.h"

class Bandage : public Premade {
protected:
    
	std::tuple<unsigned int, units::SizeUnit> width_, length_;
	std::string identifier_;
public:

    Bandage();
    Bandage(Bandage *);
    ~Bandage();

	std::string getDetailedName() const override;
	std::string getIdentifier() const;
	std::tuple<unsigned int, units::SizeUnit> getWidth() const;
	std::tuple<unsigned int, units::SizeUnit> getLength() const;
	// Catch here is that you have to have a width and height of the same unit
	// To fix this, I'll have to commit to a more robust units library or
	// flesh out my own
	std::tuple<unsigned int, units::AreaUnit> getArea() const;

	void setIdentifier(const std::string&);
	void setWidth(const unsigned int&, units::SizeUnit);
	void setLength(const unsigned int&, units::SizeUnit);
};

#endif
