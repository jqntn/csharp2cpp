#include <Windows.h>
#include <iostream>
#include <libloaderapi.h>

typedef void (*Print)();

int
main()
{
  // NativeAOT

  HMODULE hmoduleNativeAOT =
    LoadLibraryA("../../csharp/NativeAOT/ClassLibrary/bin/Release/"
                 "net8.0/publish/win-x64/ClassLibrary.dll");

  if (nullptr == hmoduleNativeAOT) {
    std::cout << "LoadLibrary failed for NativeAOT\n";
    return 1;
  }

  Print printNativeAOT =
    reinterpret_cast<Print>(GetProcAddress(hmoduleNativeAOT, "Print"));

  printNativeAOT();

  // DllExport

  HMODULE hmoduleDllExport =
    LoadLibraryA("../../csharp/DllExport/ClassLibrary/bin/Release/"
                 "netstandard2.0/ClassLibrary.dll");

  if (nullptr == hmoduleDllExport) {
    std::cout << "LoadLibrary failed for DllExport\n";
    return 1;
  }

  Print printDllExport =
    reinterpret_cast<Print>(GetProcAddress(hmoduleDllExport, "Print"));

  printDllExport();
}