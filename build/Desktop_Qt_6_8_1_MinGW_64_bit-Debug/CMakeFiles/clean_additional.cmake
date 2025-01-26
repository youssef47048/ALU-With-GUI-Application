# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Alu_GUI_autogen"
  "CMakeFiles\\Alu_GUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Alu_GUI_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\dpi_alu_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\dpi_alu_autogen.dir\\ParseCache.txt"
  "dpi_alu_autogen"
  )
endif()
