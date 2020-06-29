#ifndef QTKEYTOTAMILKEY_H
#define QTKEYTOTAMILKEY_H
#include <QKeyEvent>

using namespace Qt;

class QtKeyToTamilKey
{
public:
    const QString getTamilKey(int key);
private:
    bool isPrevKeyTamilConsonant();
    QString m_prev_key = "";
};

#endif // QTKEYTOTAMILKEY_H
