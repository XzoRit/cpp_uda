add_executable(app_exe)

target_sources(app_exe PRIVATE "main.cpp")

target_link_libraries(app_exe PRIVATE lib::counter)

add_test(NAME app::exe COMMAND app_exe "--help")
