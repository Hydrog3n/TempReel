QT += charts\
    network widgets\
    gui

HEADERS += \
    chart.h

SOURCES += \
    chart.cpp \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/dynamicspline
INSTALLS += target
