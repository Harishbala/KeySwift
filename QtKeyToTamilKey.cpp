#include <QtKeyToTamilKey.h>

QtKeyToTamilKey::QtKeyToTamilKey()
{
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_A, TamilKeyMapping("அ", "௹", "அ")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_Q, TamilKeyMapping("ஆ", "ஸ", "\u0BBE")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_S, TamilKeyMapping("இ", "௺", "\u0BBF")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_W, TamilKeyMapping("ஈ", "ஷ", "\u0BC0")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_D, TamilKeyMapping("உ", "௸", "\u0BC1")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_E, TamilKeyMapping("ஊ", "ஜ", "\u0BC2")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_G, TamilKeyMapping("எ", "", "\u0BC6")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_T, TamilKeyMapping("ஏ", "க்ஷ", "\u0BC7")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_R, TamilKeyMapping("ஐ", "ஹ", "\u0BC8")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_C, TamilKeyMapping("ஒ", "௵", "\u0BCA")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_X, TamilKeyMapping("ஓ", "௴", "\u0BCB")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_Z, TamilKeyMapping("ஔ", "௳", "\u0BCC")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_F, TamilKeyMapping("்", "ஃ", "்")));

    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_H, TamilKeyMapping("க", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_Y, TamilKeyMapping("ள", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_J, TamilKeyMapping("ப", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_U, TamilKeyMapping("ற", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_K, TamilKeyMapping("ம", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_I, TamilKeyMapping("ன", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_L, TamilKeyMapping("த", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_O, TamilKeyMapping("ட", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_P, TamilKeyMapping("ண", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_Semicolon, TamilKeyMapping("ந", "௳", "")));
    m_key_map.insert(std::pair<int, TamilKeyMapping>(Key::Key_BraceLeft, TamilKeyMapping("ச", "௳", "")));

    m_consonant_set.insert("க");
    m_consonant_set.insert("ச");
    m_consonant_set.insert("ட");
    m_consonant_set.insert("த");
    m_consonant_set.insert("ப");
    m_consonant_set.insert("ற");
    m_consonant_set.insert("ய");
    m_consonant_set.insert("ர");
    m_consonant_set.insert("ல");
    m_consonant_set.insert("வ");
    m_consonant_set.insert("ழ");
    m_consonant_set.insert("ள");
    m_consonant_set.insert("ஞ");
    m_consonant_set.insert("ங");
    m_consonant_set.insert("ன");
    m_consonant_set.insert("ந");
    m_consonant_set.insert("ம");
    m_consonant_set.insert("ண");
}
const QString QtKeyToTamilKey::getTamilKey(int key)
{
    QString tamilKey = "";
    auto key_element = m_key_map.find(key);
    if(key_element != m_key_map.end())
    {
        if(isPrevKeyTamilConsonant())
        {
            tamilKey = key_element->second.next_to_cons_press;
        }
        else
        {
            tamilKey = key_element->second.simple_press;;
        }
    }

    if(tamilKey != "")
    {
        m_prev_key = tamilKey;
    }
    return tamilKey;
}

bool QtKeyToTamilKey::isPrevKeyTamilConsonant()
{
    return (m_consonant_set.find(m_prev_key) != m_consonant_set.end());
}
