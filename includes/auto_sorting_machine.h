//
// Created by QinBu_Rua on 2025/9/24.
//

#ifndef AUTO_SORTING_MACHINE_AUTO_SORTING_MACHINE_H
#define AUTO_SORTING_MACHINE_AUTO_SORTING_MACHINE_H
#include <string>
#include <vector>

namespace auto_sm {

using std::vector;
using std::string;
using std::wstring;
using std::wstring_view;

enum CharacterState {
   SINGLE = 0,
   BEGIN,
   MIDDLE,
   END,
   STATE_COUNT
};

extern const string CharacterState_TO_STRING[STATE_COUNT];
extern const char CS_TO_STRING[STATE_COUNT];

namespace train {

class SentencePreprocessor {
private:
   wstring_view m_RawString;

   vector<CharacterState> m_CharacterStates;
   wstring m_Sentence;

   wchar_t m_Wch;
   size_t m_RawIndex;
   size_t m_Index;

   bool m_Read_char();
   wchar_t m_Peek_char();

   void m_Process();

public:
   SentencePreprocessor(wstring_view rawString);

   vector<CharacterState>& get_CharacterStates();
   string get_CharacterStatesStr() const;
};

class Preprocessor {
private:
   vector<wstring> m_RawStrings;

   vector<wstring> m_Strings;
   vector<vector<CharacterState>> m_CharacterStates;

   wchar_t read_wchar();

public:
   Preprocessor(vector<wstring> rawStrings);

};

}

}

#endif //AUTO_SORTING_MACHINE_AUTO_SORTING_MACHINE_H
