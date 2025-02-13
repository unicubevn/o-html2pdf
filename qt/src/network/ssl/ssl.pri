# OpenSSL support; compile in QSslSocket.
include($$QT_SOURCE_TREE/config.tests/unix/openssl/openssl.pri)
HEADERS += ssl/qssl.h \
            ssl/qsslcertificate.h \
            ssl/qsslcertificate_p.h \
        ssl/qsslconfiguration.h \
        ssl/qsslconfiguration_p.h \
            ssl/qsslcipher.h \
            ssl/qsslcipher_p.h \
            ssl/qsslerror.h \
            ssl/qsslkey.h \
            ssl/qsslsocket.h \
            ssl/qsslsocket_openssl_p.h \
            ssl/qsslsocket_openssl_symbols_p.h \
            ssl/qsslsocket_p.h
SOURCES += ssl/qssl.cpp \
            ssl/qsslcertificate.cpp \
            ssl/qsslconfiguration.cpp \
            ssl/qsslcipher.cpp \
            ssl/qsslerror.cpp \
            ssl/qsslkey.cpp \
            ssl/qsslsocket.cpp \
            ssl/qsslsocket_openssl.cpp \
            ssl/qsslsocket_openssl_symbols.cpp

LIBS_PRIVATE += $$QT_LFLAGS_OPENSSL
LIBS += $$QT_LFLAGS_OPENSSL
QMAKE_CXXFLAGS += $$QT_CXXFLAGS_OPENSSL
