#pragma once

// C接口导出宏的最佳实践
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C 
#endif

// 导出宏定义
#ifdef MATH_DLL_EXPORTS
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif

// 导出类
class MATH_API MathLibrary {
public:
	static int Rect_C(int a, int b);
};



