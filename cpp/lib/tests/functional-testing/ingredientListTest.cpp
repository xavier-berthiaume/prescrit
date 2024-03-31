// Things to test
// 1. Addition of ingredients to the ingredients list
// 2. Copying (deep) an ingredients list
// 3. Deletion of the ingredients list

#include <prescrit/structs.h>

int main(int argc, char *argv[]) {
	
	Ingredient *ingredient1 = new Ingredient("acetaminophen", 500, units::mg);
	Ingredient *ingredient2 = new Ingredient("ibuprofen", 200, units::mg);
	Ingredient *ingredient3 = new Ingredient("oxycodone", 30, units::mg);
	
	IngredientList testlist = IngredientList();

    testlist.addIngredient(ingredient1);
    testlist.addIngredient(ingredient2);
    testlist.addIngredient(ingredient3);

    delete ingredient1;
    delete ingredient2;
    delete ingredient3;

    IngredientList *secondList = new IngredientList(&testlist);

    delete secondList;

	return 0;
}
