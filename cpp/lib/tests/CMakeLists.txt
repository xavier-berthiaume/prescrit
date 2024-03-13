add_executable(patient_tests patientTest.cpp)
target_link_libraries(patient_tests
  PRIVATE structs
)
add_test(NAME patient_tests COMMAND patientTest)
