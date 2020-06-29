#include <QtKeyToTamilKey.h>


const QString QtKeyToTamilKey::getTamilKey(int key)
{
    QString tamilKey = "";
    switch(key)
    {
        case Key::Key_A:
            tamilKey = "அ"; break;
        case Key::Key_Q:
            tamilKey = "ஆ"; break;
        case Key::Key_S:
            tamilKey = "இ"; break;
        case Key::Key_H:
            tamilKey = "க"; break;
        case Key::Key_Space:
            tamilKey = " "; break;
        default:
            break;
    }

    if(key == Key::Key_S)
    {
        if(isPrevKeyTamilConsonant())
        {
            tamilKey = "\u0BBF";
        }
        else
        {
            tamilKey = "இ";
        }
    }
    m_prev_key = tamilKey;

    return tamilKey;
}

bool QtKeyToTamilKey::isPrevKeyTamilConsonant()
{
    bool isConsonant = false;
    if(m_prev_key == "க")
    {
        // a lot more consonants to be added
        isConsonant = true;
    }
    return isConsonant;
}
