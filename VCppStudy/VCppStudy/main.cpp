#include <iostream>
#include <string>
#include "staticLib1.h"
#include "dynamicLib1.h"
#include <windows.h>



using namespace std;

typedef void (__cdecl *pfun)(void);
typedef int(__stdcall *f_funci)();


// 调用静态库
/*
			调用静态库配置：
					1. #include静态库头文件。 
					2. 下面的操作二选一
							2.1 使用#pragma comment()宏函数加载.lib文件。
							2.2 项目属性->链接器->附加依赖项中加入希望调用的.lib文件;
									VC++包含目录添加静态库头文件所在路径(或者手动在项目头文件目录下添加所需头文件)；
									VC++库目录添加.lib文件所在目录。


*/

#pragma comment(lib,"staticLib1.lib")			// 如果项目属性->链接器->附加依赖项之中加入了.lib文件，则不需要该预处理命令 


void test1_1() 
{
	add(1,2);

}



// test1_2 调用动态库
/*
	有两种方式调用动态库——静态调用、动态调用
			静态(隐式)调用
					需要DLL文件，LIB文件，头文件。
					使用#pragma comment()宏函数加载作为导入库文件的.lib文件。
			动态(显式)调用
					只需要DLL文件和头文件，不需要LIB文件
					通过调用windowsAPI来加载和卸载DLL
					LoadLibrary()

*/
#pragma comment(lib,"dynamicLib1.lib")	// 如果在项目属性->链接器->附加依赖项之中加入.lib文件，则不需要该预处理命令。
void test1_2() 
{
	MYDLL::disp();
	MYDLL::calculator calc;
	cout << "calc.Add(1,2) == " << calc.Add(1, 2) << endl;



}




// 目前有错误
void test1_3() 
{

	pfun pfoo;
	HINSTANCE hDLL = LoadLibrary(TEXT("D:\\workstation\\gitRepositories\\VCppStudy\\VCppStudy\\Release\\dynamicLib1.dll"));


	if (hDLL == NULL)
	{
		std::cout << "动态库load错误" << endl;
		return;
	}


	pfoo = (pfun)GetProcAddress(hDLL, "dllDisp");

	if (pfoo == NULL)
	{
		cout << "函数load失败" << endl;
		return;
	}

	pfoo();


	FreeLibrary(hDLL);


}




int main()
{
 

	getchar();
    return 0;
}

