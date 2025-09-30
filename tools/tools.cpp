//
// Created by QinBu_Rua on 2025/9/24.
//

#include "../includes/tools/tools.h"
#include <filesystem>

using namespace tools;

std::wstring tools::string_to_wstring(const std::string &str) {
   std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
   return converter.from_bytes(str);
}

bool tools::is_wspace_custom(wchar_t ch) {
   switch (ch) {
   // 基本ASCII空格字符
   case L' ': // U+0020 空格
   case L'\t': // U+0009 制表符
   case L'\n': // U+000A 换行
   case L'\v': // U+000B 垂直制表符
   case L'\f': // U+000C 换页
   case L'\r': // U+000D 回车

   // Unicode空格字符
   case L'\u00A0': // 不换行空格
   case L'\u1680': // 欧甘空格
   case L'\u2000': // 半身空距
   case L'\u2001': // 全身空距
   case L'\u2002': // 半身空距
   case L'\u2003': // 全身空距
   case L'\u2004': // 三分之一空距
   case L'\u2005': // 四分之一空距
   case L'\u2006': // 六分之一空距
   case L'\u2007': // 数字空距
   case L'\u2008': // 标点空距
   case L'\u2009': // 细空距
   case L'\u200A': // 毛发空距
   case L'\u2028': // 行分隔符
   case L'\u2029': // 段分隔符
   case L'\u202F': // 窄不换行空格
   case L'\u205F': // 中等数学空距
   case L'\u3000': // 表意文字空格
      return true;
   default:
      return false;
   }
}
