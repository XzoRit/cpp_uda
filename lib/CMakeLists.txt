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

find_package(Boost REQUIRED)
add_library(model)
set(model_inc ${CMAKE_CURRENT_SOURCE_DIR})
set(model_src ${model_inc}/model)
target_sources(model PRIVATE "${model_src}/model.cpp" "${model_src}/model.hpp")
target_include_directories(model PUBLIC ${model_inc})
target_link_libraries(model PUBLIC lib::counter)
add_library(lib::model ALIAS model)

add_executable(model_test)
target_sources(
  model_test PRIVATE "${model_src}/model.test.cpp" "${model_src}/main.test.cpp"
)
target_link_libraries(model_test PRIVATE lib::model)
target_link_libraries(model_test PRIVATE Boost::headers)
add_test(NAME lib::model_test COMMAND model_test)

find_package(Boost REQUIRED)
add_library(console)
set(console_inc ${CMAKE_CURRENT_SOURCE_DIR})
set(console_src ${console_inc}/console)
target_sources(console PRIVATE "${console_src}/console.cpp" "${console_src}/console.hpp")
target_include_directories(console PUBLIC ${console_inc})
target_link_libraries(console PUBLIC lib::model)
target_link_libraries(console PUBLIC lib::counter)
add_library(lib::console ALIAS console)

add_executable(console_test)
target_sources(
  console_test PRIVATE "${console_src}/console.test.cpp" "${console_src}/main.test.cpp"
)
target_link_libraries(console_test PRIVATE lib::model)
target_link_libraries(console_test PRIVATE lib::counter)
target_link_libraries(console_test PRIVATE lib::console)
target_link_libraries(console_test PRIVATE Boost::headers)
add_test(NAME lib::console_test COMMAND console_test)

find_package(Boost REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Lager CONFIG REQUIRED)
add_library(imgui)
set(imgui_inc ${CMAKE_CURRENT_SOURCE_DIR})
set(imgui_src ${imgui_inc}/imgui)
target_sources(imgui PRIVATE "${imgui_src}/imgui.cpp" "${imgui_src}/imgui.hpp")
target_include_directories(imgui PUBLIC ${imgui_inc})
target_link_libraries(imgui PUBLIC lib::model)
target_link_libraries(imgui PUBLIC lib::counter)
target_link_libraries(imgui PUBLIC imgui::imgui)
target_link_libraries(imgui PUBLIC lager)
add_library(lib::imgui ALIAS imgui)

add_executable(imgui_test)
target_sources(
  imgui_test PRIVATE "${imgui_src}/imgui.test.cpp" "${imgui_src}/main.test.cpp"
)
target_link_libraries(imgui_test PRIVATE lib::model)
target_link_libraries(imgui_test PRIVATE lib::counter)
target_link_libraries(imgui_test PRIVATE lib::imgui)
target_link_libraries(imgui_test PRIVATE Boost::headers)
add_test(NAME lib::imgui_test COMMAND imgui_test)
