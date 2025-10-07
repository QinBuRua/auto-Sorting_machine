//
// Created by QinBu_Rua on 2025/9/24.
//

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
using auto_sm::CharacterStateArray;
using auto_sm::CharacterState;

int main() {
   wstring sentence=L"我 爱 数学 你们呢";
   SentencePreprocessor sp(sentence);

   cout<<sp.get_CharacterStatesStr();

   return 0;
}
