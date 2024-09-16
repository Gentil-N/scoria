#ifndef __LOG_H__
#define __LOG_H__

#include "ctools.h"

LOG_DEFINE(sc, internal_log)

#define log_info(...) _sc_throw_internal_log(SC_LOG_LEVEL_INFO, 0, __FILE__, __LINE__, __VA_ARGS__)
#ifndef NDEBUG
#define log_debug(...) _sc_throw_internal_log(SC_LOG_LEVEL_DEBUG, 0, __FILE__, __LINE__, __VA_ARGS__)
#else
#define log_debug(...)
#endif // NDEBUG
#define log_warn(...) _sc_throw_internal_log(SC_LOG_LEVEL_WARN, 0, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) _sc_throw_internal_log(SC_LOG_LEVEL_ERROR, 0, __FILE__, __LINE__, __VA_ARGS__)

#endif // __LOG_H__
