//
// Created by QinBu_Rua on 2025/10/7.
//

#include "frontend_auto_sm.h"
#include "tools.h"
#include <stdexcept>

using namespace auto_sm;

using std::unique_ptr;

using std::string;

const string auto_sm::CharacterState_TO_STRING[STATE_COUNT] = {
   "SINGLE",
   "BEGIN",
   "MIDDLE",
   "END"
};

const char auto_sm::CS_TO_STRING[STATE_COUNT]{'S', 'B', 'M', 'E'};

CharacterStateArray::CharacterStateArray() {
   m_Size = 0;
   m_Capacity = 4;
   m_Value = std::make_unique<uint8_t[]>(m_Capacity);
}

CharacterStateArray::CharacterStateArray(size_t size) {
   m_Size = size;
   m_Capacity = (m_Size + 3) / 4;
   m_Value = std::make_unique<uint8_t[]>(m_Capacity);
}

CharacterStateArray::~CharacterStateArray() = default;

size_t CharacterStateArray::size() const {
   return m_Size;
}

size_t CharacterStateArray::capacity() const {
   return m_Capacity * 4;
}

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

void CharacterStateArray::resize(size_t size) {
   if ((size + 3) / 4 > m_Capacity) {
      m_Size = size;
      m_Capacity = (m_Size + 3) / 4;
      auto tmp = std::make_unique<uint8_t[]>(m_Capacity);
      std::copy(m_Value.get(), m_Value.get() + (m_Size + 3) / 4, tmp.get());
      m_Value = std::move(tmp);
   } else {
      m_Size = size;
   }

}

void CharacterStateArray::reserve(size_t capacity) {
   if ((capacity + 3) / 4 <= m_Capacity) {
      return;
   }
   m_Capacity = (capacity + 3) / 4;
   auto tmp = std::make_unique<uint8_t[]>(m_Capacity);
   std::copy(m_Value.get(), m_Value.get() + (m_Size + 3) / 4, tmp.get());
   m_Value = std::move(tmp);
}

void CharacterStateArray::push_back(CharacterState state) {
   if (m_Size / 4 >= m_Capacity) {
      reserve(m_Capacity * 2);
   }
   m_Size++;
   set(m_Size - 1, state);
}

const uint8_t CharacterStateArray::m_Sieve[4] = {
   0b00000011,
   0b00001100,
   0b00110000,
   0b11000000,
};
