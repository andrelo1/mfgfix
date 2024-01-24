# mfgfix

## Dependencies
- [CommonLibSSE](https://github.com/powerof3/CommonLibSSE)

## Building
Prerequisites:
- Visual Studio 2022
- [vcpkg](https://github.com/microsoft/vcpkg) (for CommonLibSSE)

Open x64 Native Tools Command Prompt for VS 2022.

Clone repository:
```
git clone --recurse-submodules https://github.com/andrelo1/mfgfix
```

Set environment variables for:
- `VCPKG_ROOT=[path to vcpkg]`
- `VCPKG_INSTALLATION_ROOT=[path to vcpkg]`

Open folder in Visual Studio, after the cmake has self-configured, select target `vs2022-windows-vcpkg-ae-Release` or `vs2022-windows-vcpkg-se-Release` and build away.

You can probably do something like this, but ymmv:

```
cmake -B build -S . -DVCPKG_ROOT=[path to vcpkg] -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=vs2022-windows-vcpkg-[ae or se]
cmake --build build --config Release
```
