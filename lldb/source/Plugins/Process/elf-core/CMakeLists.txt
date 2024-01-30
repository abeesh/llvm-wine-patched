lldb_tablegen(ProcessElfCoreProperties.inc -gen-lldb-property-defs
  SOURCE ProcessElfCoreProperties.td
  TARGET LLDBPluginProcessElfCorePropertiesGen)

lldb_tablegen(ProcessElfCorePropertiesEnum.inc -gen-lldb-property-enum-defs
  SOURCE ProcessElfCoreProperties.td
  TARGET LLDBPluginProcessElfCorePropertiesEnumGen)

add_lldb_library(lldbPluginProcessElfCore PLUGIN
  ProcessElfCore.cpp
  ThreadElfCore.cpp
  RegisterContextPOSIXCore_arm.cpp
  RegisterContextPOSIXCore_arm64.cpp
  RegisterContextPOSIXCore_mips64.cpp
  RegisterContextPOSIXCore_powerpc.cpp
  RegisterContextPOSIXCore_ppc64le.cpp
  RegisterContextPOSIXCore_s390x.cpp
  RegisterContextPOSIXCore_x86_64.cpp
  RegisterUtilities.cpp

  LINK_LIBS
    lldbCore
    lldbTarget
    lldbPluginDynamicLoaderPosixDYLD
    lldbPluginObjectFileELF
    lldbPluginProcessUtility
  LINK_COMPONENTS
    BinaryFormat
    Support
  )

add_dependencies(lldbPluginProcessElfCore
  LLDBPluginProcessElfCorePropertiesGen
  LLDBPluginProcessElfCorePropertiesEnumGen)