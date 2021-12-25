#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#include <spdlog/sinks/basic_file_sink.h>

using namespace std::literals;

#define DLLEXPORT __declspec(dllexport)

#include "version.h"

#define NOMINMAX
#include <windows.h>
#include "Detours/include/detours.h"