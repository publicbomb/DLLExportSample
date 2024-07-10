#pragma once

#ifdef DECLSPEC_EXPORTS
#define DECLSPEC_API __declspec(dllexport)
#else
#define DECLSPEC_API __declspec(dllimport)
#endif

DECLSPEC_API int AddTest(int A, int B);
DECLSPEC_API int AddTest_Arg3(int A, int B, int C);
