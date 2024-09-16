#include "log.h"

#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>

#include "../include/scoria.h"

LOG_DECLARE(sc, internal_log)

int sc_set_log_callback(sc_log_callback_fn fn)
{
    return sc_set_internal_log_callback((sc_internal_log_callback_fn)fn);
}
