add_subdirectory(patient)

add_executable(ingredientTest ingredientTest.cpp)
target_link_libraries(ingredientTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME ingredientTest COMMAND ingredientTest acetaminophen 325 mg)

add_executable(ingredientListTest ingredientListTest.cpp)
target_link_libraries(ingredientListTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME ingredientListTest COMMAND ingredientListTest)

add_executable(productTest productTest.cpp)
target_link_libraries(productTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME productTest COMMAND productTest mytestproduct)

add_executable(premadeTest premadeTest.cpp)
target_link_libraries(premadeTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME premadeTest COMMAND premadeTest jamp mytestproduct)

add_executable(medicationTest medicationTest.cpp)
target_link_libraries(medicationTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME medicationTest COMMAND medicationTest jamp testmedication 12345678 acetaminophen 500)

add_executable(bandageTest bandageTest.cpp)
target_link_libraries(bandageTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME bandageTest COMMAND bandageTest medicus mepilex 5 15 12345677)

add_executable(syringeTest syringeTest.cpp)
target_link_libraries(syringeTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME syringeTest COMMAND syringeTest bd luerlock 33 1232322)

add_executable(prescriptionTest prescriptionTest.cpp)
target_link_libraries(prescriptionTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME prescriptionTest COMMAND prescriptionTest)

add_executable(prescriptionListTest prescriptionListTest.cpp)
target_link_libraries(prescriptionListTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME prescriptionListTest COMMAND prescriptionListTest)

add_executable(prescriberTest prescriberTest.cpp)
target_link_libraries(prescriberTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME prescriberTest COMMAND prescriberTest Jean Tremblay 123456)

add_executable(insuranceTest insuranceTest.cpp)
target_link_libraries(insuranceTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME insuranceTest COMMAND insuranceTest asc 80123123 000000000901)

add_executable(normalTest normalTest.cpp)
target_link_libraries(normalTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME normalTest COMMAND normalTest)

add_executable(magistralTest magistralTest.cpp)
target_link_libraries(magistralTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME magistralTest COMMAND magistralTest)

add_executable(timeTest timeTest.cpp)
target_link_libraries(timeTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME timeTest COMMAND timeTest)
