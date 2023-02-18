find_package(Boost REQUIRED)

add_library(counter)
set(counter_inc ${CMAKE_CURRENT_SOURCE_DIR})
set(counter_src ${counter_inc}/counter)
target_sources(counter PRIVATE "${counter_src}/counter.cpp" "${counter_src}/counter.hpp")
target_include_directories(counter PUBLIC ${counter_inc})
add_library(lib::counter ALIAS counter)

add_executable(counter_test)
target_sources(
  counter_test PRIVATE "${counter_src}/counter.test.cpp" "${counter_src}/main.test.cpp"
)
target_link_libraries(counter_test PRIVATE lib::counter)
target_link_libraries(counter_test PRIVATE Boost::headers)
add_test(NAME lib::conuter_test COMMAND counter_test)

add_library(console)
set(console_inc ${CMAKE_CURRENT_SOURCE_DIR})
set(console_src ${console_inc}/console)
target_sources(console PRIVATE "${console_src}/console.cpp" "${console_src}/console.hpp")
target_include_directories(console PUBLIC ${console_inc})
target_link_libraries(console PRIVATE lib::counter)
add_library(lib::console ALIAS console)

add_executable(console_test)
target_sources(
  console_test PRIVATE "${console_src}/console.test.cpp" "${console_src}/main.test.cpp"
)
target_link_libraries(console_test PRIVATE lib::counter)
target_link_libraries(console_test PRIVATE lib::console)
target_link_libraries(console_test PRIVATE Boost::headers)
add_test(NAME lib::console_test COMMAND console_test)
