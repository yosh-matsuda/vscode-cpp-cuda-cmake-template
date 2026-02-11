#pragma once
#include <string>

#ifdef _MSC_VER  // Windows
#ifdef MY_SHARED_LIB_BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT __attribute__((visibility("default")))
#endif

DLL_EXPORT void SharedLibFunc(const std::string& s);

#undef DLL_EXPORT
