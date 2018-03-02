option(ENABLE_TESTING "compile the unit test suite")
if (${ENABLE_TESTING})
  enable_testing()
  add_subdirectory(gtest)
  include_directories("${PROJECT_SOURCE_DIR}/gtest/googletest/include")
  include_directories("${PROJECT_SOURCE_DIR}/gtest/googlemock/include")
endif (${ENABLE_TESTING})


