// Things to test:
// 1. Ingredients create successfully
// 2. getFormattedDose returns a correctly formatted string
// 3. getFormattedName returns a correctly formatted name	
// 4. IngredientsList functions as a linked list correctly
// 4.1. Nodes add without error (removal not necessary)
// 4.2. Get next returns without error

#include <structs/units.h>
#include <structs/ingredient.h>

int main(int argc, char *argv[]) {

	IngredientList list = IngredientList();

	list.addIngredient("Test", 320, units::mg);
	list.addIngredient("Acetaminophen", 500, units::mg);

	Ingredient *ingredient {nullptr};
	for(int x = 0; x < 15; x++)
	ingredient = list.getNextIngredient(ingredient);
}
