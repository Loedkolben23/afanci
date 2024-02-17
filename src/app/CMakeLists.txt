qt_add_executable(afanci
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)

target_link_libraries(afanci PRIVATE Qt6::Widgets)

set_target_properties(afanci PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)