isEmpty(PREFIX){
    PREFIX = /usr/local
}

DEFINES += QT_MESSAGELOGCONTEXT

ARCH = $$QMAKE_HOST.arch
isEqual(ARCH, mips64) | isEqual(ARCH, mips32) {
    DEFINES += ARCH_MIPSEL
}

isEqual(DISABLE_TEXT_SHADOW, YES) {
    DEFINES += DISABLE_TEXT_SHADOW
}
