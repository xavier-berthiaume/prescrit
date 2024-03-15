// Things to test:
// 1. Create a product object
// 2. Set a valid name 
// 3. Set an invalid name and
// validate that the correct data
// isn't overwritten

#include <cassert>
#include <string>
#include <structs/product.h>

int main(int argc, char *argv[]) {

	Product testProduct = Product();

	testProduct.setName(argv[1]);

	assert((testProduct.getName() == argv[1]));
	assert((testProduct.getDetailedName() == argv[1]));

	testProduct.setName("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus euismod, lectus eget blandit tincidunt, turpis mauris fringilla arcu, a consequat felis quam id est. Donec nec consequat turpis. Integer sit amet quam enim. Duis et nisl sagittis, sollicitudin metus at, fermentum elit. Duis vitae velit eu augue tempor elementum vel nec purus. Integer dapibus arcu nec nibh pellentesque, ac mattis metus ultricies. Cras venenatis massa vitae tellus consequat, non aliquet ex dignissim. Sed ut eros in nisi elementum venenatis. Nam vitae accumsan mauris. Morbi interdum felis vel arcu lobortis interdum. In hendrerit rhoncus velit, in euismod metus sodales eu.");

	assert((testProduct.getName() == argv[1]));
	assert((testProduct.getDetailedName() == argv[1]));
}
