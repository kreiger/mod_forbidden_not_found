#include "httpd.h"
#include "http_log.h"
#include "http_protocol.h"

static void forbidden_not_found_filter(request_rec *r)
{
    if (r->status == HTTP_FORBIDDEN)
    {
        r->status = HTTP_NOT_FOUND;
        ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r, "forbidden_not_found_filter: Replaced 403 with 404.");
    }
}

static void register_hooks(apr_pool_t *p)
{
    ap_hook_insert_error_filter(forbidden_not_found_filter, NULL, NULL, APR_HOOK_MIDDLE);
}

AP_DECLARE_MODULE(forbidden_not_found) =
{
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    register_hooks,
};
