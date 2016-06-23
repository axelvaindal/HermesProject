#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "qjson-qt5" for configuration "RelWithDebInfo"
set_property(TARGET qjson-qt5 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(qjson-qt5 PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Program Files (x86)/qjson/lib/qjson-qt5.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "Qt5::Core"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Program Files (x86)/qjson/bin/qjson-qt5.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS qjson-qt5 )
list(APPEND _IMPORT_CHECK_FILES_FOR_qjson-qt5 "C:/Program Files (x86)/qjson/lib/qjson-qt5.lib" "C:/Program Files (x86)/qjson/bin/qjson-qt5.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
