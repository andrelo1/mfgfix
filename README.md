# mfgfix-ae

## Dependencies
- [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE)
- [Detours](https://github.com/microsoft/Detours)
## How to build
Prerequisites:
- Visual Studio 2019
- [vcpkg](https://github.com/microsoft/vcpkg) (for CommonLibSSE)

Open x64 Native Tools Command Prompt for VS 2019.

Clone repository:
```
git clone https://github.com/andrelo1/mfgfix-ae
```
Clone libraries:
```
cd mfgfix-ae
git clone https://github.com/Ryan-rsm-McKenzie/CommonLibSSE
git clone https://github.com/microsoft/Detours
```
Build CommonLibSSE:
```
cd CommonLibSSE
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static-md
```
Build Detours:
```
cd ../Detours/src
nmake
```
Open `mfgfix.sln` in Visual Studio and build solution.
