#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <tuple>
#include <vector>

#include "globalDefinitions.h"
#include "ingredient.h"
#include "units.h"

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

public:
	std::string getDetailedName() const override;
	std::string getDIN() const;
	IngredientList getActiveIngredients() const;

	void setDIN(const std::string&);
	void AddIngredient(const Ingredient&);
	void removeIngredient(const Ingredient&);
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
	std::tuple<unsigned int, units::SizeUnit> getArea() const;

	void setWidth(const unsigned int&, units::SizeUnit);
	void setLength(const unsigned int&, units::SizeUnit);

};

class Syringe : public Premade {

};

#endif // !PRODUCT_H
