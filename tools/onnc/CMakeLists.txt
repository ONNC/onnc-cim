
include_directories(${ONNC_INCLUDE_DIRS})

add_executable(onnc-cim main.cpp ONNCApp.cpp ONNCConfig.cpp)
target_link_libraries(onnc-cim libonnc onnc-rt)

install(TARGETS onnc-cim
    RUNTIME DESTINATION bin)
