set(INCLUDES 
    ${THIRD_PARTY_DIR}/dirent/include
    ${THIRD_PARTY_DIR}/lua/src
    ${THIRD_PARTY_DIR}/lua/build    #for luaconf.h
    )

set(LIBS 
    glm
    liblua
    sol2
    StringId
    CelesteStl
    FileSystem)

if (${BUILD_TESTS})
    cbt_build_project(
        NAME TestUtils 
        FOLDER Testing 
        TYPE STATIC 
        INCLUDES "${INCLUDES}"
        LIBS "${LIBS}")

    target_compile_definitions(TestUtils PUBLIC -DGLM_FORCE_SILENT_WARNINGS)
endif()