#include "dynamicLib1.h"

//  ���� DLL Ӧ�ó���ĵ���������


void MYDLL::disp(void)
{
	std::cout << "�����˾�̬��staticLib1�е�MYDLL::disp()����" << std::endl;
}



double MYDLL::calculator::Add(double a, double b)

{
	std::cout << "�����˾�̬��staticLib1�е�MYDLL::add����" << std::endl;
	return a + b;

}



double MYDLL::calculator::Subtract(double a, double b)
{
	std::cout << "�����˾�̬��staticLib1�е�MYDLL::calculator::Subtract����" << std::endl;
	return a - b;

}



double MYDLL::calculator::Multiply(double a, double b)
{
	std::cout << "�����˾�̬��staticLib1�е�MYDLL::calculator::Multiply����" << std::endl;
	return a * b;

}



double MYDLL::calculator::Divide(double a, double b)
{
	std::cout << "�����˾�̬��staticLib1�е�MYDLL::calculator::Divide����" << std::endl;
	return a / b;
}




