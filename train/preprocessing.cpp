//
// Created by QinBu_Rua on 2025/9/24.
//

#include "auto_sorting_machine.h"

using std::string;
using auto_sm::CharacterState;

using namespace auto_sm::train;

const string auto_sm::CharacterState_TO_STRING[STATE_COUNT] = {
   "SINGE",
   "BEGIN",
   "MIDDLE",
   "END"
};

const char auto_sm::CS_TO_STRING[STATE_COUNT]{'S', 'B', 'M', 'E'};

bool SentencePreprocessor::m_Read_char() {
   ++m_RawIndex;
   if (m_RawIndex >= m_RawString.size()) {
      return false;
   }
   m_Wch = m_RawString[m_RawIndex];
   if (m_Wch != ' ') {
      ++m_Index;
   }
   return true;
}

wchar_t SentencePreprocessor::m_Peek_char() {
   return m_RawString[m_RawIndex + 1];
}

void SentencePreprocessor::m_Process() {
   do {
      m_Sentence.push_back(m_Wch);
      if (m_CharacterStates[m_Index - 1] == SINGLE
          || m_CharacterStates[m_Index - 1] == END) {
         if (m_Peek_char() == ' ') {
            m_CharacterStates.push_back(SINGLE);
            m_Read_char();
         } else {
            m_CharacterStates.push_back(BEGIN);
         }
      } else {
         if (m_Peek_char() == ' ') {
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
   if (m_Peek_char() == ' ') {
      m_CharacterStates.push_back(SINGLE);
      m_Read_char();
   } else {
      m_CharacterStates.push_back(BEGIN);
   }

   m_Read_char();

   m_Process();
}

std::vector<auto_sm::CharacterState>& SentencePreprocessor::get_CharacterStates() {
   return m_CharacterStates;
}

std::string SentencePreprocessor::get_CharacterStatesStr() const{
   string str;
   for (const auto iter: m_CharacterStates) {
      str.push_back(CS_TO_STRING[iter]);
   }
   return str;
}

wchar_t Preprocessor::read_wchar() {

}

Preprocessor::Preprocessor(vector<wstring> rawStrings) {
   for (auto rawString: rawStrings) {
      vector<CharacterState> characterStates(rawString.size());
      wstring str;
      for (auto ch: rawString) {
         if (ch == ' ') {

         }
      }
   }
}
