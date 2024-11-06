#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <string>
#include <array>

namespace seneca {
    class SpellChecker {
        std::array<std::string, 6> m_badWords;
        std::array<std::string, 6> m_goodWords;
        std::array<int, 6> m_replacements{};

    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif

