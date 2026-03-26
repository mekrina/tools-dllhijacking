修改自：https://github.com/tothi/dll-hijack-by-proxying.git

step:

copy target dll to this dir
gen def file by python script
use i686-w64-mingw32-gcc(32 bits)/x86_64-w64-mingw32-gcc(64 bits) to compile the dllmain.c with the def file
	for example: `x86_64-w64-mingw32-gcc -shared -o target.dll dllmain.c proxy.def -s`
cp or upload the generated dll (malicious) and the original dll (to make the app run normally) to the app dir which exe file exists

run the exe file

pwn!!

原理：
使用pefile这个python库分析原来的dll文件，看它提供了哪些函数，再据此生成def文件定义这些函数，让他们转发到原来的dll文件，从而保持原有功能不变
（这就要求原来的dll也要能够被找到）

dllmain函数定义了恶意逻辑，当dll文件被加载时执行恶意命令。

Q:
为什么不直接反编译原dll，然后改写dllmain添加恶意逻辑？
A：
反编译困难
