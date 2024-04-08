add_executable(getAgeTest getAgeTest.cpp)
target_link_libraries(getAgeTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME getAgeTest COMMAND getAgeTest)

add_executable(patientTest patientTest.cpp)
target_link_libraries(patientTest
  PRIVATE structs
  PRIVATE testframework
)
add_test(NAME patientTest COMMAND patientTest Xavier Berthiaume 13 4 1997)
