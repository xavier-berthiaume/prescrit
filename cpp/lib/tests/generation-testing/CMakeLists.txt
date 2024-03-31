add_executable(ingredientGenerationTest ingredientGenerationTest.cpp)
target_link_libraries(ingredientGenerationTest
  PRIVATE structs
)
add_test(NAME ingredientGenerationTest COMMAND ingredientGenerationTest)

add_executable(dateGenerationTest dateGenerationTest.cpp)
target_link_libraries(dateGenerationTest
    PRIVATE structs
)
add_test(NAME dateGenerationTest COMMAND dateGenerationTest)

add_executable(locationGenerationTest locationGenerationTest.cpp)
target_link_libraries(locationGenerationTest
    PRIVATE structs
)
add_test(NAME locationGenerationTest COMMAND locationGenerationTest)

add_executable(medicationGenerationTest medicationGenerationTest.cpp)
target_link_libraries(medicationGenerationTest
    PRIVATE structs
)
add_test(NAME medicationGenerationTest COMMAND medicationGenerationTest)

add_executable(patientGenerationTest patientGenerationTest.cpp)
target_link_libraries(patientGenerationTest
    PRIVATE structs
)
add_test(NAME patientGenerationTest COMMAND patientGenerationTest)

add_executable(premadeGenerationTest premadeGenerationTest.cpp)
target_link_libraries(premadeGenerationTest
    PRIVATE structs
)
add_test(NAME premadeGenerationTest COMMAND premadeGenerationTest)

add_executable(prescriberGenerationTest prescriberGenerationTest.cpp)
target_link_libraries(prescriberGenerationTest
    PRIVATE structs
)
add_test(NAME prescriberGenerationTest COMMAND prescriberGenerationTest)

add_executable(prescriptionGenerationTest prescriptionGenerationTest.cpp)
target_link_libraries(prescriptionGenerationTest
    PRIVATE structs
)
add_test(NAME prescriptionGenerationTest COMMAND prescriptionGenerationTest)

add_executable(productGenerationTest productGenerationTest.cpp)
target_link_libraries(productGenerationTest
    PRIVATE structs
)
add_test(NAME productGenerationTest COMMAND productGenerationTest)

add_executable(bandageGenerationTest bandageGenerationTest.cpp)
target_link_libraries(bandageGenerationTest
    PRIVATE structs
)
add_test(NAME bandageGenerationTest COMMAND bandageGenerationTest)

add_executable(syringeGenerationTest syringeGenerationTest.cpp)
target_link_libraries(syringeGenerationTest
    PRIVATE structs
)
add_test(NAME syringeGenerationTest COMMAND syringeGenerationTest)

add_executable(normalGenerationTest normalGenerationTest.cpp)
target_link_libraries(normalGenerationTest
    PRIVATE structs
)
add_test(NAME normalGenerationTest COMMAND normalGenerationTest)
