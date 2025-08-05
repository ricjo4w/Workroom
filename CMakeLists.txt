cmake_minimum_required(VERSION 3.19)
project(Workroom LANGUAGES CXX)

add_subdirectory(external/QtADS)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(Workroom
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    collectionfile.h collectionfile.cpp
    collection.h collection.cpp
    collectionmanager.h collectionmanager.cpp
    viewerfactory.h viewerfactory.cpp
    imagefile.h imagefile.cpp
)

target_link_libraries(Workroom PRIVATE qtadvanceddocking)

target_link_libraries(Workroom
    PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Workroom
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Workroom
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
