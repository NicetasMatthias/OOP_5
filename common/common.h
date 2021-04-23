#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    VALUE_REQUEST = 1,
    VALUE_ANSWER,
    STANDART_REQUEST,
    STANDART_ANSWER,
    CANON_REQUEST,
    CANON_ANSWER,
    ROOTS_REQUEST,
    ROOTS_ANSWER,
};

enum modes
{
    MODE_INT = 1,
    MODE_RATIONAL = 0,
};

extern const QChar separator;

QString& operator<< (QString&,const QString&);

#endif // COMMON_H
