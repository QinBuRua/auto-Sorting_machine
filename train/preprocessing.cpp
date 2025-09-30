//
// Created by QinBu_Rua on 2025/9/24.
//

#include <string>
#include <vector>

#include "trainer.h"
#include "../includes/tools/tools.h"

using std::wstring;
using std::wstring_view;
using std::string;
using std::string_view;

using std::vector;

using auto_sm::CharacterState;

using namespace auto_sm::trainer;
using namespace tools;


bool SentencePreprocessor::m_Read_char() {
   ++m_RawIndex;
   if (m_RawIndex >= m_RawString.size()) {
      return false;
   }
   m_Wch = m_RawString[m_RawIndex];
   if (!tools::is_wspace_custom(m_Wch)) {
      ++m_Index;
   }
   return true;
}

wchar_t SentencePreprocessor::m_Peek_char() const {
   return m_RawString[m_RawIndex + 1];
}

void SentencePreprocessor::m_Process() {
   do {
      m_Sentence.push_back(m_Wch);
      if (m_CharacterStates[m_Index - 1] == SINGLE
          || m_CharacterStates[m_Index - 1] == END) {
         if (is_wspace_custom(m_Peek_char())) {
            m_CharacterStates.push_back(SINGLE);
            m_Read_char();
         } else {
            m_CharacterStates.push_back(BEGIN);
         }
      } else {
         if (is_wspace_custom(m_Peek_char())) {
            m_CharacterStates.push_back(END);
            m_Read_char();
         } else {
            m_CharacterStates.push_back(MIDDLE);
         }
      }
   } while (m_Read_char());
}

SentencePreprocessor::SentencePreprocessor(wstring_view rawString) : m_RawString(rawString) {
   m_RawIndex = 0;
   m_Index = 0;
   m_Wch = m_RawString[m_RawIndex];

   m_Sentence.push_back(m_Wch);
   if (tools::is_wspace_custom(m_Peek_char())) {
      m_CharacterStates.push_back(SINGLE);
      m_Read_char();
   } else {
      m_CharacterStates.push_back(BEGIN);
   }

   m_Read_char();

   m_Process();
}

vector<auto_sm::CharacterState>& SentencePreprocessor::get_CharacterStates() {
   return m_CharacterStates;
}

string SentencePreprocessor::get_CharacterStatesStr() const{
   string str;
   for (const auto iter: m_CharacterStates) {
      str.push_back(CS_TO_STRING[iter]);
   }
   return str;
}

Preprocessor::Preprocessor(vector<wstring> rawStrings) {
   for (auto rawString: rawStrings) {
      vector<CharacterState> characterStates(rawString.size());
      wstring str;
      for (auto ch: rawString) {
         if (ch == L' ') {

         }
      }
   }
}
