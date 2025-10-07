//
// Created by QinBu_Rua on 2025/9/30.
//

#ifndef AUTO_SORTING_MACHINE_TRAINER_H
#define AUTO_SORTING_MACHINE_TRAINER_H

#include <iostream>
#include <vector>
#include "frontend_auto_sm.h"

namespace auto_sm::trainer {

class SentencePreprocessor {
public:
   SentencePreprocessor(std::wstring_view rawString);

   CharacterStateArray& get_CharacterStates();
   std::string get_CharacterStatesStr() const;

private:
   std::wstring_view m_RawString;

   CharacterStateArray m_CharacterStates;

   wchar_t m_Wch;
   size_t m_RawIndex;
   size_t m_Index;

   bool m_Read_char();
   wchar_t m_Peek_char() const;

   void m_Process();
};

class Preprocessor {
public:
   Preprocessor(std::vector<std::wstring>&& rawStrings);

private:
   std::vector<std::wstring> m_RawStrings;

   std::vector<std::wstring> m_Strings;
   std::vector<std::vector<CharacterState>> m_CharacterStates;

   wchar_t read_wchar();

};

}

#endif //AUTO_SORTING_MACHINE_TRAINER_H
