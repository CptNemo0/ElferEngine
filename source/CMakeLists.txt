# Add source files
file(GLOB_RECURSE SOURCE_FILES
	 *.c
	 *.cpp
	 *.cc)

# Add header files
file(GLOB_RECURSE HEADER_FILES
	 *.h
	 *.hpp)

# Search for the assets files
file(GLOB_RECURSE ASSETS_FILES ${CMAKE_SOURCE_DIR}/resources/*.*)

if (MSVC)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")
endif()

set_source_files_properties(${ASSETS_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER_FILES})
source_group(TREE ${CMAKE_SOURCE_DIR}         FILES ${ASSETS_FILES})

# Define the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${ASSETS_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC NOMINMAX)
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Debug)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Release)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E create_symlink
				   ${CMAKE_SOURCE_DIR}/resources
				   ${CMAKE_CURRENT_BINARY_DIR}/resources)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E create_symlink
				   ${CMAKE_SOURCE_DIR}/resources
				   ${CMAKE_CURRENT_BINARY_DIR}/Debug/resources)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E create_symlink
				   ${CMAKE_SOURCE_DIR}/resources
				   ${CMAKE_CURRENT_BINARY_DIR}/Release/resources)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "ElferEngine")
