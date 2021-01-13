#include <iostream>
#include <string>
#include "staticLib1.h"
#include "dynamicLib1.h"
#include <windows.h>



using namespace std;

typedef void (__cdecl *pfun)(void);
typedef int(__stdcall *f_funci)();


// ���þ�̬��
/*
			���þ�̬�����ã�
					1. #include��̬��ͷ�ļ��� 
					2. ����Ĳ�����ѡһ
							2.1 ʹ��#pragma comment()�꺯������.lib�ļ���
							2.2 ��Ŀ����->������->�����������м���ϣ�����õ�.lib�ļ�;
									VC++����Ŀ¼��Ӿ�̬��ͷ�ļ�����·��(�����ֶ�����Ŀͷ�ļ�Ŀ¼���������ͷ�ļ�)��
									VC++��Ŀ¼���.lib�ļ�����Ŀ¼��


*/

#pragma comment(lib,"staticLib1.lib")			// �����Ŀ����->������->����������֮�м�����.lib�ļ�������Ҫ��Ԥ�������� 


void test1_1() 
{
	add(1,2);

}




// test1_2 ���ö�̬��
/*
	�����ַ�ʽ���ö�̬�⡪����̬���á���̬����
			��̬(��ʽ)����
					��ҪDLL�ļ���LIB�ļ���ͷ�ļ���
					ʹ��#pragma comment()�꺯��������Ϊ������ļ���.lib�ļ���
			��̬(��ʽ)����
					ֻ��ҪDLL�ļ���ͷ�ļ�������ҪLIB�ļ�
					ͨ������windowsAPI�����غ�ж��DLL
					LoadLibrary()

*/
//#pragma comment(lib,"dynamicLib1.lib")	// �������Ŀ����->������->����������֮�м���.lib�ļ�������Ҫ��Ԥ�������
//void test1_2() 
//{
//	MYDLL::disp();
//	MYDLL::calculator calc;
//	cout << "calc.Add(1,2) == " << calc.Add(1, 2) << endl;
//
//}




// ʹ��WINDOWSϵͳ��HMODULE�����ö�̬�⡪��Ŀǰ�д��󣬶�̬��������ȡ��ֵ�����Ǻ���ָ���޷��Ӷ�̬������ȡ������ַ��
HMODULE Hdll = nullptr;
using pDDD = double(*)(double, double);
using pVV = void(*)(void);
typedef void (fVV)(void);
using pIV = int(*)(void);
pDDD pfuncD = nullptr;
fVV* pfuncV = nullptr;
pIV pfuncI = nullptr;
void test1_3() 
{
	cout << "start:" << endl;

	Hdll = LoadLibrary(L"dynamicLib1.dll");
 
	if (nullptr == Hdll) 
	{
		cout << "���ض�̬��ʧ��" << endl;
	}
	else 
	{
		pfuncI = (pIV)(GetProcAddress(Hdll, "funci"));
		int num = (*pfuncI)();
		cout << num << endl;
	}
}




int main()
{
	test1_3();

	getchar();
    return 0;
}

