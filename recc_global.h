#ifndef RECC_GLOBAL_H
#define RECC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RECC_LIBRARY)
#  define RECCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RECCSHARED_EXPORT Q_DECL_IMPORT
#endif

#define LINE_HEIGHT 16

#endif // RECC_GLOBAL_H
