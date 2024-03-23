add_executable(frameworkTest frameworkTest.cpp)
target_link_libraries(frameworkTest
    PRIVATE structs
)
add_test(NAME frameworkTest COMMAND frameworkTest)

add_executable(patientTest patientTest.cpp)
target_link_libraries(patientTest
  PRIVATE structs
)
add_test(NAME patientTest COMMAND patientTest Xavier Berthiaume 13 4 1997)

add_executable(ingredientTest ingredientTest.cpp)
target_link_libraries(ingredientTest
  PRIVATE structs
)
add_test(NAME ingredientTest COMMAND ingredientTest acetaminophen 325 mg)

add_executable(productTest productTest.cpp)
target_link_libraries(productTest
  PRIVATE structs
)
add_test(NAME productTest COMMAND productTest mytestproduct)

add_executable(premadeTest premadeTest.cpp)
target_link_libraries(premadeTest
  PRIVATE structs
)
add_test(NAME premadeTest COMMAND premadeTest jamp mytestproduct)

add_executable(medicationTest medicationTest.cpp)
target_link_libraries(medicationTest
  PRIVATE structs
)
add_test(NAME medicationTest COMMAND medicationTest jamp testmedication 12345678 acetaminophen 500)

add_executable(bandageTest bandageTest.cpp)
target_link_libraries(bandageTest
  PRIVATE structs
)
add_test(NAME bandageTest COMMAND bandageTest medicus mepilex 5 15 12345677)

add_executable(syringeTest syringeTest.cpp)
target_link_libraries(syringeTest
  PRIVATE structs
)
add_test(NAME syringeTest COMMAND syringeTest bd luerlock 33 1232322)

add_executable(prescriptionTest prescriptionTest.cpp)
target_link_libraries(prescriptionTest
  PRIVATE structs
)
add_test(NAME prescriptionTest COMMAND prescriptionTest)

add_executable(prescriptionListTest prescriptionListTest.cpp)
target_link_libraries(prescriptionListTest
  PRIVATE structs
)
add_test(NAME prescriptionListTest COMMAND prescriptionListTest)

add_executable(prescriberTest prescriberTest.cpp)
target_link_libraries(prescriberTest
  PRIVATE structs
)
add_test(NAME prescriberTest COMMAND prescriberTest Jean Tremblay 123456)

add_executable(insuranceTest insuranceTest.cpp)
target_link_libraries(insuranceTest
  PRIVATE structs
)
add_test(NAME insuranceTest COMMAND insuranceTest asc 80123123 000000000901)
