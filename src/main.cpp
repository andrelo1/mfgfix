#include "mfgfix/mfgfix.h"

namespace
{
	constexpr SKSE::PluginVersionData GetPluginVersion()
	{
		SKSE::PluginVersionData version;

		version.PluginVersion({ Version::MAJOR, Version::MINOR, Version::PATCH, 0 });
		version.PluginName(Version::PROJECT);
		version.UsesAddressLibrary(true);
		version.CompatibleVersions({ SKSE::RUNTIME_1_6_317, SKSE::RUNTIME_1_6_318, {1, 6, 323, 0}, {1, 6, 342, 0} });

		return version;
	}
}

extern "C" DLLEXPORT SKSE::PluginVersionData SKSEPlugin_Version{ GetPluginVersion() };

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface * a_skse)
{
	auto path = logger::log_directory();

	if (path) {
		*path /= Version::PROJECT;
		*path += ".log";
		spdlog::set_default_logger(spdlog::basic_logger_mt("default", path->string(), true));
	}

	spdlog::set_level(spdlog::level::trace);
	spdlog::flush_on(spdlog::level::trace);

	spdlog::info("loaded");

	if (a_skse->IsEditor()) {
		spdlog::critical("loaded in editor, marking as incompatible"sv);
		return false;
	}

	SKSE::Init(a_skse);
	MfgFix::Init();

	return true;
}