//
// Created by QinBu_Rua on 2025/9/30.
//

#ifndef AUTO_SORTING_MACHINE_TRAINER_H
#define AUTO_SORTING_MACHINE_TRAINER_H

#include <vector>
#include <string>
#include <fstream>
#include "frontend_auto_sm.h"

namespace auto_sm::trainer {

class SentencePreprocessor {
public:
   SentencePreprocessor(std::wstring_view rawString);

   CharacterStateArray& get_CharacterStates();
   std::wstring get_Sentence();
   std::string get_CharacterStatesStr() const;

private:
   std::wstring_view m_RawString;

   CharacterStateArray m_CharacterStates;
   std::wstring m_Sentence;

   wchar_t m_Wch;
   size_t m_RawIndex;
   size_t m_Index;

   bool m_Read_char();
   [[nodiscard]] wchar_t m_Peek_char() const;

   void m_Process();
};

class Preprocessor {
public:
   Preprocessor(const std::string &file);

   std::string get_CharacterStates();

private:
   std::vector<std::wstring> m_Strings;
   std::vector<CharacterStateArray> m_CharacterStates;
};

}

#endif //AUTO_SORTING_MACHINE_TRAINER_H
