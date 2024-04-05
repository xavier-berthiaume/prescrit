#include <prescrit/structs/product.h> 

Product::Product() {}

Product::Product(Product *cpyObject) {

	name_ = cpyObject->getName();
}

Product::~Product() {}

std::string Product::getName() const {

	return name_;
}

std::string Product::getDetailedName() const {

	return name_;
}

void Product::setName(const std::string& nameParam) {

	if(nameParam.length() > MAXNAMELENGTH)
		return;

	name_ = nameParam;
}
