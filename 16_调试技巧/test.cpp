#include <iostream>
using namespace std;


// do nothing
void Loop()
{
    int count = 0;
    for(; count < 20000000; ++count);
}

// call Loop inside
void Loop1()
{
    int count = 0;
    for(; count < 60000000; ++count);

    Loop();
}

void Loop2()
{
    int count = 0;
    for(; count < 20000000; ++count);
}
/*
2. 在test.cpp目录下执行命令：$g++ -pg -o test test.cpp，生成test可执行文件；
3. 运行test可执行文件，程序退出之后，会在当前目录生成gmon.out文件；
4. 使用gprof工具生成测试报告， 执行命令 $gprof -b xxx gmon.out > report.txt
*/
int main()
{
    Loop1();
    Loop2();
    Loop2();

    return 0;
}
