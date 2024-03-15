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
