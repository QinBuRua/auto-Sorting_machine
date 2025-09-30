//
// Created by QinBu_Rua on 2025/9/24.
//

#ifndef AUTO_SORTING_MACHINE_AUTO_SORTING_MACHINE_H
#define AUTO_SORTING_MACHINE_AUTO_SORTING_MACHINE_H

#include <string>

namespace auto_sm {

enum CharacterState {
   SINGLE = 0,
   BEGIN,
   MIDDLE,
   END,
   STATE_COUNT
};

inline const std::string CharacterState_TO_STRING[STATE_COUNT] = {
   "SINGE",
   "BEGIN",
   "MIDDLE",
   "END"
};

constexpr char CS_TO_STRING[STATE_COUNT]{'S', 'B', 'M', 'E'};

}

#endif //AUTO_SORTING_MACHINE_AUTO_SORTING_MACHINE_H
