cmake_minimum_required(VERSION 2.8)
project(fichin CXX)

# agrega el directorio de includes de fichin
include_directories(include)

# add the subdirectories
aux_source_directory("src/fichin" LIBSRC)

set(LIB_OUTPUT_FILE fichin)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g2")
add_library(${LIB_OUTPUT_FILE} SHARED ${LIBSRC})

target_link_libraries(fichin sfml-window sfml-system sfml-graphics sfml-audio)

install(DIRECTORY include/fichin DESTINATION include)
install(FILES lib${LIB_OUTPUT_FILE}.so DESTINATION lib)
