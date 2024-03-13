add_executable(patientTest patientTest.cpp)
target_link_libraries(patientTest
  PRIVATE structs
)
add_test(NAME patientTest COMMAND patientTest Xavier Berthiaume 13 4 1997)
