#ifndef SYRINGE_H
#define SYRINGE_H

#include "premade.h"

class Syringe : public Premade {
protected:

	unsigned short guage_;
	std::string identifier_;
public:

    Syringe();
    Syringe(Syringe *);
    ~Syringe();

	std::string getDetailedName() const override;
	std::string getIdentifier() const;
	unsigned short getGuage() const;

	void setIdentifier(const std::string&);
	void setGuage(const unsigned short&);
};


#endif
