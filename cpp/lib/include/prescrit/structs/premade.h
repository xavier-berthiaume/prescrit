#ifndef PREMADE_H
#define PREMADE_H

#include "product.h"

class Premade : public Product {
protected:
	std::string producer_;

public:
    Premade();
    Premade(Premade *);
    virtual ~Premade();

	virtual std::string getDetailedName() const;
	std::string getProducer() const;
	void setProducer(const std::string&);
};

#endif
