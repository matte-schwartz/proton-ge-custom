#ifndef __VRCLIENT_UNIXLIB_H
#define __VRCLIENT_UNIXLIB_H

#include <stdarg.h>
#include <stddef.h>

#include <windef.h>
#include <winbase.h>
#include <winternl.h>

#include "vrclient_structs.h"

#include "wine/unixlib.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

struct render_model
{
    union
    {
        w_RenderModel_t_0912 w_0912;
    };
    union
    {
        u_RenderModel_t_0912 *u_0912;
    };
};

struct render_model_texture_map
{
    union
    {
        w_RenderModel_TextureMap_t_090 w_090;
        w_RenderModel_TextureMap_t_1237 w_1237;
    };
    union
    {
        u_RenderModel_TextureMap_t_090 *u_090;
        u_RenderModel_TextureMap_t_1237 *u_1237;
    };
};

struct vrclient_init_params
{
    HMODULE winevulkan;
    char *unix_path;
};

extern bool unix_vrclient_init( struct vrclient_init_params *params );
extern void *unix_HmdSystemFactory( const char *name, int *return_code );
extern void *unix_VRClientCoreFactory( const char *name, int *return_code );

typedef NTSTATUS (*unixlib_entry_t)( void *args );
extern const unixlib_entry_t __wine_unix_call_funcs[];

#define VRCLIENT_CALL( code, args ) __wine_unix_call_funcs[unix_ ## code]( args )

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "unixlib_generated.h"

#endif /* __VRCLIENT_UNIXLIB_H */
