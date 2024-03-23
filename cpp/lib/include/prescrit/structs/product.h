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
	~Product();

	std::string getName() const;
	virtual std::string getDetailedName() const;

	void setName(const std::string&);
};

class Premade : public Product {
protected:
	std::string producer_;

public:
	virtual std::string getDetailedName() const;
	std::string getProducer() const;
	void setProducer(const std::string&);
};

class Medication : public Premade {
protected:
	IngredientList *ingredients_;

	std::string din_;

	ValidPrescriptionTypes annex_;

public:
	Medication();
	Medication(Medication *);
	~Medication();

	std::string getDetailedName() const override;
	std::string getDIN() const;
	IngredientList *getActiveIngredients() const;
	ValidPrescriptionTypes getAnnex() const;

	void setDIN(const std::string&);
	void setAnnex(ValidPrescriptionTypes);
	void AddIngredient(const std::string&, const unsigned int&, units::DoseUnit);
};

class Bandage : public Premade {
protected:
	std::tuple<unsigned int, units::SizeUnit> width_, length_;
	std::string identifier_;

public:
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

class Syringe : public Premade {
protected:
	unsigned short guage_;
	std::string identifier_;

public:
	std::string getDetailedName() const override;
	std::string getIdentifier() const;
	unsigned short getGuage() const;

	void setIdentifier(const std::string&);
	void setGuage(const unsigned short&);
};

#endif // !PRODUCT_H
