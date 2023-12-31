#pragma once

#include "beatsaber-hook/shared/utils/logging.hpp"
#include "paper/shared/logger.hpp"
#include "paper/shared/log_level.hpp"
#include <string_view>

namespace ColourSwitcher
{
    Logger &getLogger();
    #define INFO(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::INF>(str, MOD_ID, nullptr)
    #define ERROR(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::ERR>(str, MOD_ID, nullptr)
    #define CRITICAL(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::CRIT>(str, MOD_ID, nullptr)
    #define DEBUG(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::DBG>(str, MOD_ID, nullptr)
    #define WARNING(str, ...) Paper::Logger::fmtLogTag<Paper::LogLevel::WRN>(str, MOD_ID, nullptr)
}