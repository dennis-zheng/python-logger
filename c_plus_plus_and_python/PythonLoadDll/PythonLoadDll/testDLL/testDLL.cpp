
#include "stdafx.h"
#include "../PythonLoadDll/PythonLoadDll.h"
#include <iostream>

struct StructInfo
{
	int id;
	float idF;
	char* buf;
	int size;
};

int main(int argc, char* argv[])
{
	long handle = 1;
	int ret = PythonLoadDll_init(handle);
	std::cout << "ret:" << ret << std::endl;
	StructInfo info;
	info.buf = new char[255];
	char buf[255] = "buffer test";
	PythonLoadDll_process(handle, 11, buf, strlen(buf), &info);

	std::cout << info.id << ":" << info.idF << ":" << info.buf << ":" << info.size << std::endl;
	PythonLoadDll_uninit(handle);
	return 0;
}