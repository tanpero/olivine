cmake_minimum_required (VERSION 3.0)
project (olivine)

aux_source_directory (src/core/base CORE_BASE_SRC)
aux_source_directory (src/gui/base GUI_BASE_SRC)
add_library (olivine.gui STATIC
    ${CORE_BASE_SRC}
    ${GUI_BASE_SRC}
)

set_property (TARGET olivine.gui PROPERTY CXX_STANDARD 17)

target_include_directories (olivine.gui PUBLIC src)

add_executable (olivine.gui-test tests/gui-main.cc)
target_include_directories (olivine.gui-test PUBLIC src)
target_link_libraries (olivine.gui-test olivine.gui)
