#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "qjson-qt5" for configuration "Debug"
set_property(TARGET qjson-qt5 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(qjson-qt5 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Program Files (x86)/qjson/lib/qjson-qt5d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "Qt5::Core"
  IMPORTED_LOCATION_DEBUG "C:/Program Files (x86)/qjson/bin/qjson-qt5d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS qjson-qt5 )
list(APPEND _IMPORT_CHECK_FILES_FOR_qjson-qt5 "C:/Program Files (x86)/qjson/lib/qjson-qt5d.lib" "C:/Program Files (x86)/qjson/bin/qjson-qt5d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
