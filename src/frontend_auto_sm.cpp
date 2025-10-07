//
// Created by QinBu_Rua on 2025/10/7.
//

#include "frontend_auto_sm.h"
#include "tools.h"
#include <stdexcept>

using namespace auto_sm;

using std::string;

const string auto_sm::CharacterState_TO_STRING[STATE_COUNT] = {
   "SINGLE",
   "BEGIN",
   "MIDDLE",
   "END"
};

const char auto_sm::CS_TO_STRING[STATE_COUNT]{'S', 'B', 'M', 'E'};

CharacterStateArray::CharacterStateArray() : CharacterStateArray(4) {
}

CharacterStateArray::CharacterStateArray(size_t size) {
   m_Size = size;
   m_Capacity = (m_Size + 3) / 4;
   m_Value = std::make_unique<uint8_t[]>(m_Capacity);
}

CharacterStateArray::~CharacterStateArray() = default;

CharacterState CharacterStateArray::get(size_t index) const {
   if (index >= m_Size) {
      throw std::out_of_range("");
   }
   return static_cast<CharacterState>((m_Value[index / 4] & m_Sieve[index % 4]) >> (index % 4 * 2));
}

void CharacterStateArray::set(size_t index, CharacterState state) {
   if (index >= m_Size) {
      throw std::out_of_range("");
   }
   uint8_t tmp = m_Value[index / 4] & (m_Sieve[index % 4] ^ 0b11111111);
   tmp |= static_cast<uint8_t>(state) << (index % 4 * 2);
   m_Value[index / 4] = tmp;
}

const uint8_t CharacterStateArray::m_Sieve[4] = {
   0b00000011,
   0b00001100,
   0b00110000,
   0b11000000,
};
