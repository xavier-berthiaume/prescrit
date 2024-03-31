#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <tuple>
#include <vector>

#include "../globals.h"
#include "../utils.h"

enum ValidPrescriptionTypes {
	Annex1,
	Annex2,
	Annex3
};

// Struct that acts as an interface upon which all the different product
// types are built upon
class Product {
protected:

	std::string name_;
public:

	Product();
	Product(Product *);
	virtual ~Product();

	std::string getName() const;
	virtual std::string getDetailedName() const;

	void setName(const std::string&);
};

#endif // !PRODUCT_H
