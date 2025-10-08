//
// Created by QinBu_Rua on 2025/9/24.
//

#include <codecvt>
#include <string>
#include <vector>
#include <exception>
#include "trainer.h"
#include "tools.h"

using std::wstring;
using std::wstring_view;
using std::string;
using std::string_view;
using std::vector;

using std::runtime_error;

using std::wifstream;

using namespace auto_sm;
using namespace auto_sm::trainer;
using namespace tools;

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

CharacterStateArray& SentencePreprocessor::get_CharacterStates() {
   return m_CharacterStates;
}

std::wstring SentencePreprocessor::get_Sentence() {
   return m_Sentence;
}

string SentencePreprocessor::get_CharacterStatesStr() const {
   string str;
   for (size_t i = 0; i < m_CharacterStates.size(); ++i) {
      str.push_back(CS_TO_STRING[m_CharacterStates.get(i)]);
   }
   return str;
}

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
      if (m_CharacterStates.get(m_Index - 1) == SINGLE
          || m_CharacterStates.get(m_Index - 1) == END) {
         if (is_wspace_custom(m_Peek_char()) || m_RawIndex + 1 == m_RawString.size()) {
            m_CharacterStates.push_back(SINGLE);
            m_Read_char();
         } else {
            m_CharacterStates.push_back(BEGIN);
         }
      } else {
         if (is_wspace_custom(m_Peek_char()) || m_RawIndex + 1 == m_RawString.size()) {
            m_CharacterStates.push_back(END);
            m_Read_char();
         } else {
            m_CharacterStates.push_back(MIDDLE);
         }
      }
   } while (m_Read_char());
}

Preprocessor::Preprocessor(const std::string &file) {
   wifstream wfin;
   wfin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

   wfin.open(file);
   if (wfin.fail()) {
      throw runtime_error("Fail to open file \"" + file + "\"");
   }

   wstring wstr;
   while (std::getline(wfin, wstr)) {
      SentencePreprocessor sp(wstr);
      m_CharacterStates.push_back(std::move(sp.get_CharacterStates()));
   }
}

std::string Preprocessor::get_CharacterStates() {
   string str;
   for (const auto &iter: m_CharacterStates) {
      for (size_t i = 0; i < iter.size(); ++i) {
         str.push_back(CS_TO_STRING[iter.get(i)]);
      }
      str.push_back('\n');
   }
   return str;
}
