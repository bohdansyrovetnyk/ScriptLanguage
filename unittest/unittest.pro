TEMPLATE = app

CONFIG += c++14

include(gtest_dependency.pri)
include($$PWD/../Language/Language.pri)

SOURCES += \
        main.cpp \
        lexertest.cpp

INCLUDEPATH += $$PWD/../
