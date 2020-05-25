add_executable(main
main.cc
)
target_link_libraries(main cimHWSim ${ONNC_RT_LIB})

add_executable(matmul-layer
matmul-layer.cc
)
target_link_libraries(matmul-layer cimHWSim ${ONNC_RT_LIB})

# the installation path
# install(TARGETS main
#   RUNTIME DESTINATION bin
# )