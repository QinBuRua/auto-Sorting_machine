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
   CharacterStateArray characterStates(16);
   characterStates.set(5, CharacterState::BEGIN);
   characterStates.set(7, CharacterState::MIDDLE);

   cout << characterStates.get(5) << ' ';
   cout << characterStates.get(7) << ' ';

   return 0;
}
