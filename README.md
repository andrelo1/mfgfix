# mfgfix

## Dependencies
- [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE)
- [Detours](https://github.com/microsoft/Detours)
## Building
Prerequisites:
- Visual Studio 2022
- [vcpkg](https://github.com/microsoft/vcpkg) (for CommonLibSSE)

Open x64 Native Tools Command Prompt for VS 2022.

Clone repository:
```
git clone --recurse-submodules https://github.com/andrelo1/mfgfix
```
Build CommonLibSSE:

```
cd mfgfix/ext/CommonLibSSE
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static-md
cmake --build build --config Release
```
Build Detours:
```
cd ../Detours/
nmake
```
Build mfgfix:

Open and build `mfgfix.sln` in Visual Studio.
