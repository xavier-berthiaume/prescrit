// Things to test
// 1. Addition of ingredients to the ingredients list
// 2. Copying (deep) an ingredients list
// 3. Deletion of the ingredients list

#include <structs/ingredient.h>

int main(int argc, char *argv[]) {
	
	Ingredient *ingredient1 = new Ingredient("acetaminophen", 500, units::mg);
	Ingredient *ingredient2 = new Ingredient("ibuprofen", 200, units::mg);
	Ingredient *ingredient3 = new Ingredient("oxycodone", 30, units::mg);
	
	IngredientList testlist = IngredientList();

	return 0;
}
