find_package(OpenMP)

set(CPP_SOURCES
    main_prover.cpp
    binfile_utils.cpp
    zkey_utils.cpp
    wtns_utils.cpp
    logger.cpp
    ../depends/ffiasm/c/misc.cpp
    ../depends/ffiasm/c/naf.cpp
    ../depends/ffiasm/c/splitparstr.cpp
    ../depends/ffiasm/c/alt_bn128.cpp
    ../build/fq.cpp
    ../build/fq.o
    ../build/fr.cpp
    ../build/fr.o
    )

include_directories(
    ../src
    ../depends/ffiasm/c
    ../depends/json/single_include)


add_executable(prover ${CPP_SOURCES})

target_link_libraries(prover pthread gmp sodium)

if(OpenMP_CXX_FOUND)
    target_link_libraries(prover OpenMP::OpenMP_CXX)
endif()
