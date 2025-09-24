//
// Created by QinBu_Rua on 2025/9/24.
//

#include <iostream>

#include "auto_sorting_machine.h"
#include "tools.h"

using std::string;
using std::wstring;

using std::cout;
using std::cin;
using std::wcin;
using std::wcout;

using auto_sm::train::SentencePreprocessor;

int main() {
   wstring wstr = L"我 爱 数学 ";

   SentencePreprocessor sp(wstr);

   cout << sp.get_CharacterStatesStr();

   return 0;
}
