#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("shutdown -s -t 60");   // shutdown 表示令计算机关机或者重新启动的命令 
	// -s 表示关机
	// -r 表示重新启动
	// -t 60 表示在60秒后关机 （t和60之间有空格）
	return 0;
}

//取消关机命令：system("shutdown -a"); 
