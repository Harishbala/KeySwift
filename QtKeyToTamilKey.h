#ifndef QTKEYTOTAMILKEY_H
#define QTKEYTOTAMILKEY_H
#include <map>
#include <set>
#include <QKeyEvent>

using namespace Qt;

class TamilKeyMapping
{
public:
    TamilKeyMapping() :
        simple_press(""),
        next_to_cons_press("")
    {}

    TamilKeyMapping(QString param1, QString param3) :
        simple_press(param1),
        next_to_cons_press(param3)
    {}

    QString simple_press;
    QString next_to_cons_press;
};

class QtKeyToTamilKey
{
public:
    QtKeyToTamilKey();
    const QString getTamilKey(QKeyEvent* event);
private:
    bool isPrevKeyTamilConsonant();
    bool isTamilVowel(QString letter);

    QString m_prev_key = "";
    std::map<QString, TamilKeyMapping> m_key_map;
    std::set<QString> m_vowel_set;
    std::set<QString> m_consonant_set;
};

#endif // QTKEYTOTAMILKEY_H
