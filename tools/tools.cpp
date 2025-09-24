//
// Created by QinBu_Rua on 2025/9/24.
//

#include "tools.h"
#include <filesystem>

using namespace tools;

std::wstring tools::string_to_wstring(const std::string &str) {
   return std::filesystem::path(str).wstring();
}
