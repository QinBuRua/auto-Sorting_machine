//
// Created by QinBu_Rua on 2025/9/24.
//

#ifndef AUTO_SORTING_MACHINE_FRONTEND_AUTO_SM_H
#define AUTO_SORTING_MACHINE_FRONTEND_AUTO_SM_H

#include <memory>
#include <string>

namespace auto_sm {

enum CharacterState {
   SINGLE = 0,
   BEGIN,
   MIDDLE,
   END,
   STATE_COUNT
};

extern const std::string CharacterState_TO_STRING[STATE_COUNT];
extern const char CS_TO_STRING[STATE_COUNT];

class CharacterStateArray {
public:
   CharacterStateArray();
   CharacterStateArray(size_t size);
   CharacterStateArray(CharacterStateArray&& that);
   ~CharacterStateArray();

   size_t size() const;
   size_t capacity() const;

   CharacterState get(size_t index) const;
   void set(size_t index, CharacterState state);

   void resize(size_t size);
   void reserve(size_t capacity);
   void push_back(CharacterState state);

private:
   std::unique_ptr<uint8_t[]> m_Value = nullptr;
   size_t m_Size;
   size_t m_Capacity;
   static const uint8_t m_Sieve[4];
};

}

#endif //AUTO_SORTING_MACHINE_FRONTEND_AUTO_SM_H
