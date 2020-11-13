#include "dynamicLib1.h"

//  定义 DLL 应用程序的导出函数。


void MYDLL::disp(void)
{
	std::cout << "调用了静态库staticLib1中的MYDLL::disp()函数" << std::endl;
}



double MYDLL::calculator::Add(double a, double b)

{
	std::cout << "调用了静态库staticLib1中的MYDLL::add函数" << std::endl;
	return a + b;

}



double MYDLL::calculator::Subtract(double a, double b)
{
	std::cout << "调用了静态库staticLib1中的MYDLL::calculator::Subtract方法" << std::endl;
	return a - b;

}



double MYDLL::calculator::Multiply(double a, double b)
{
	std::cout << "调用了静态库staticLib1中的MYDLL::calculator::Multiply方法" << std::endl;
	return a * b;

}



double MYDLL::calculator::Divide(double a, double b)
{
	std::cout << "调用了静态库staticLib1中的MYDLL::calculator::Divide方法" << std::endl;
	return a / b;
}




