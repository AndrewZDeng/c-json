cmake_minimum_required(VERSION 3.14)

project(c-json)

list(APPEND INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

list(APPEND SOURCE_CODES ${PROJECT_SOURCE_DIR}/src/main.c
                         ${PROJECT_SOURCE_DIR}/src/cJSON.c
						 )

add_executable(${PROJECT_NAME} ${SOURCE_CODES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})