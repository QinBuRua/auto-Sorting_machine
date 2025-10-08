//
// Created by QinBu_Rua on 2025/9/24.
//

#include <codecvt>
#include <iostream>
#include "json.h"
#include "trainer.h"

using std::string;
using std::wstring;

using std::cout;
using std::cin;
using std::wcin;
using std::wcout;

using auto_sm::trainer::SentencePreprocessor;
using auto_sm::trainer::Preprocessor;
using auto_sm::CharacterStateArray;
using auto_sm::CharacterState;

int main() {
   string file{R"(D:\coding\auto_Sorting-machine\data\train\test.txt)"};
   Preprocessor preprocessor{file};

   cout<<preprocessor.get_CharacterStates();

   std::wifstream fin(file);
   wstring wstr;

   fin.imbue(std::locale(std::locale(),new std::codecvt_utf8<wchar_t>));

   std::getline(fin, wstr);

   wcout<<wstr;

   return 0;
}
