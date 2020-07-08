#ifndef _LIBPRIVOXY_EXPORT_H
#define _LIBPRIVOXY_EXPORT_H

#ifdef LIBPRIVOXY_EXPORTS
#define LIBPRIVOXY_API __declspec(dllexport)
#else
#define LIBPRIVOXY_API __declspec(dllimport)
#endif

#ifdef LIBEXPORT_STDCALL
#define LIBSTDCALL __stdcall
#else
#define LIBSTDCALL
#endif

LIBPRIVOXY_API int LIBSTDCALL StartPrivoxy(char *config_full_path);

LIBPRIVOXY_API void LIBSTDCALL StopPrivoxy();

LIBPRIVOXY_API int LIBSTDCALL IsRunning();

#endif