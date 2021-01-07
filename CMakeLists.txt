cmake_minimum_required(VERSION 3.19)
project(blank_project)

add_subdirectory(src)
add_subdirectory(examples)

# ## Documentation
# # Doxygen
find_package(Doxygen REQUIRED)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen)
set(DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/examples)
set(DOXYGEN_GENERATE_XML YES)
set(DOXYGEN_USE_MATHJAX YES)

file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}) #Doxygen won't create this for us

doxygen_add_docs(doxygen ${CMAKE_CURRENT_SOURCE_DIR} ALL)

# # Sphinx
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH}) 
find_package(Sphinx REQUIRED)

set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/docs)
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/docs/sphinx)
set(SPHINX_INDEX_FILE ${SPHINX_BUILD}/index.html)

add_custom_command(
  OUTPUT ${SPHINX_INDEX_FILE}
  COMMAND  ${SPHINX_EXECUTABLE} -b html -Dbreathe_projects.blank_project=${DOXYGEN_OUTPUT_DIRECTORY}/xml ${SPHINX_SOURCE} ${SPHINX_BUILD}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${SPHINX_SOURCE}/index.rst ${DOXYGEN_INDEX_FILE}
  MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
  COMMENT "Generating documentation with Sphinx")

# # Nice named target so we can run the job easily
add_custom_target(Sphinx ALL DEPENDS ${SPHINX_INDEX_FILE})
