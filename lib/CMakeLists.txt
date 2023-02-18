find_package(Boost REQUIRED)

set(INCLUDE ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE ${INCLUDE}/counter)

add_library(counter)

target_sources(counter PRIVATE "${SOURCE}/counter.cpp" "${SOURCE}/counter.hpp")

target_include_directories(counter PUBLIC ${INCLUDE})

add_library(lib::counter ALIAS counter)

add_executable(counter_test)

target_sources(
  counter_test PRIVATE "${SOURCE}/counter.test.cpp" "${SOURCE}/main.test.cpp"
)

target_link_libraries(counter_test PRIVATE lib::counter)
target_link_libraries(counter_test PRIVATE Boost::headers)

add_test(NAME lib::conuter_test COMMAND counter_test)
