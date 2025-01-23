# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MAIN_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MAIN_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\SudokuSolverApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SudokuSolverApp_autogen.dir\\ParseCache.txt"
  "MAIN_autogen"
  "SudokuSolverApp_autogen"
  )
endif()
