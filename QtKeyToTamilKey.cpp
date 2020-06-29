#include <QtKeyToTamilKey.h>

QtKeyToTamilKey::QtKeyToTamilKey()
{

    m_key_map.insert(std::pair<QString, TamilKeyMapping>("a", TamilKeyMapping("அ", "அ")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("q", TamilKeyMapping("ஆ", "\u0BBE")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("s", TamilKeyMapping("இ", "\u0BBF")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("w", TamilKeyMapping("ஈ", "\u0BC0")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("d", TamilKeyMapping("உ", "\u0BC1")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("e", TamilKeyMapping("ஊ", "\u0BC2")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("g", TamilKeyMapping("எ", "\u0BC6")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("t", TamilKeyMapping("ஏ", "\u0BC7")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("r", TamilKeyMapping("ஐ", "\u0BC8")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("c", TamilKeyMapping("ஒ", "\u0BCA")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("x", TamilKeyMapping("ஓ", "\u0BCB")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("z", TamilKeyMapping("ஔ", "\u0BCC")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("f", TamilKeyMapping("்", "்")));

    m_key_map.insert(std::pair<QString, TamilKeyMapping>("h", TamilKeyMapping("க", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("y", TamilKeyMapping("ள", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("j", TamilKeyMapping("ப", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("u", TamilKeyMapping("ற", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("k", TamilKeyMapping("ம", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("i", TamilKeyMapping("ன", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("l", TamilKeyMapping("த", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("o", TamilKeyMapping("ட", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("p", TamilKeyMapping("ண", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>(";", TamilKeyMapping("ந", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("[", TamilKeyMapping("ச", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("]", TamilKeyMapping("ஞ", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("'", TamilKeyMapping("ய", "")));

    m_key_map.insert(std::pair<QString, TamilKeyMapping>("v", TamilKeyMapping("வ", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("b", TamilKeyMapping("ங", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("n", TamilKeyMapping("ல", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("m", TamilKeyMapping("ர", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("/", TamilKeyMapping("ழ", "")));

    m_key_map.insert(std::pair<QString, TamilKeyMapping>("A", TamilKeyMapping("௹", "அ")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("Q", TamilKeyMapping("ஸ", "\u0BBE")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("S", TamilKeyMapping("௺", "\u0BBF")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("W", TamilKeyMapping("ஷ", "\u0BC0")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("D", TamilKeyMapping("௸", "\u0BC1")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("E", TamilKeyMapping("ஜ", "\u0BC2")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("G", TamilKeyMapping("", "\u0BC6")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("T", TamilKeyMapping("க்ஷ", "\u0BC7")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("R", TamilKeyMapping("ஹ", "\u0BC8")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("C", TamilKeyMapping("௵", "\u0BCA")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("X", TamilKeyMapping("௴", "\u0BCB")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("Z", TamilKeyMapping("௳", "\u0BCC")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("F", TamilKeyMapping("", "்")));

    m_key_map.insert(std::pair<QString, TamilKeyMapping>("H", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("Y", TamilKeyMapping("ஸ்ரீ", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("J", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("U", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("K", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("I", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("L", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("O", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("P", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>(":", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("{", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("}", TamilKeyMapping("", "")));
    m_key_map.insert(std::pair<QString, TamilKeyMapping>("\"", TamilKeyMapping("'", "")));
    m_vowel_set.insert("அ");
    m_vowel_set.insert("ஆ");
    m_vowel_set.insert("இ");
    m_vowel_set.insert("ஈ");
    m_vowel_set.insert("உ");
    m_vowel_set.insert("ஊ");
    m_vowel_set.insert("எ");
    m_vowel_set.insert("ஏ");
    m_vowel_set.insert("ஐ");
    m_vowel_set.insert("ஒ");
    m_vowel_set.insert("ஓ");
    m_vowel_set.insert("ஔ");

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
const QString QtKeyToTamilKey::getTamilKey(QKeyEvent* event)
{
    QString tamilKey = "";
    auto key_element = m_key_map.find(event->text());
    if(key_element != m_key_map.end())
    {
        if(isTamilVowel(key_element->second.simple_press) && isPrevKeyTamilConsonant())
        {
            tamilKey = key_element->second.next_to_cons_press;
        }
        else
        {
            tamilKey = key_element->second.simple_press;;
        }
    }
    else
    {
        tamilKey = event->text();
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

bool QtKeyToTamilKey::isTamilVowel(QString letter)
{
    return (m_vowel_set.find(letter) != m_vowel_set.end());
}
