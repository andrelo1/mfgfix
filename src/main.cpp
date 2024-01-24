#include "mfgfix/mfgfixinit.h"

#ifdef SKYRIM_SUPPORT_AE
extern "C" __declspec(dllexport) constinit auto SKSEPlugin_Version = []() {
	SKSE::PluginVersionData v;
	v.PluginVersion(Plugin::VERSION);
	v.PluginName(Plugin::NAME);
	v.AuthorName("andrelo1"sv);
	v.UsesAddressLibrary();
	v.UsesNoStructs();
	// v.UsesUpdatedStructs();
	v.CompatibleVersions({ SKSE::RUNTIME_LATEST });
	// v.CompatibleVersions({ SKSE::RUNTIME_1_6_353 });
	return v;
}();
#else
extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface*, SKSE::PluginInfo* a_info)
{
	a_info->infoVersion = SKSE::PluginInfo::kVersion;
	a_info->name = Plugin::NAME.data();
	a_info->version = Plugin::VERSION.pack();
	return true;
}
#endif

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface * a_skse)
{
	auto path = SKSE::log::log_directory();

	if (path) {
		*path /= Plugin::NAME;
		*path += ".log";
		spdlog::set_default_logger(spdlog::basic_logger_mt("default", path->string(), true));
	}

	spdlog::set_level(spdlog::level::trace);
	spdlog::flush_on(spdlog::level::trace);
	spdlog::info("loaded");

	SKSE::Init(a_skse);
	MfgFix::Init();

	return true;
}
