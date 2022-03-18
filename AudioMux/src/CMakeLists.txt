CMAKE_MINIMUM_REQUIRED (VERSION 3.15 )
# project setting
SET( BINARY ${CMAKE_PROJECT_NAME} )
SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} )
SET( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR} )

# set source and headers
SET (SRC_FILES
    main.cpp 
    AudioData.cpp 
    AudioMux.cpp 
    AudioMuxModule.cpp 
    Producer.cpp 
    Encoder.cpp 

    AudioData.h
    AudioMux.h
    AudioMuxModule.h 
    Producer.h 
    Encoder.h 
    )

# build 
ADD_EXECUTABLE( ${BINARY}_run  ${SRC_FILES} )
ADD_LIBRARY( ${BINARY}_lib STATIC ${SRC_FILES} )
TARGET_LINK_LIBRARIES( ${BINARY}_run pthread)
TARGET_LINK_LIBRARIES( ${BINARY}_lib )

