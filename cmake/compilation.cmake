set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Detect if ccache is installed and use if it is the case.
if (USE_CCACHE)
  find_program(CCACHE ccache)
  if (CCACHE)
    # Specify to launch ccache for compilation and linking globally.
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
  endif()
endif()
