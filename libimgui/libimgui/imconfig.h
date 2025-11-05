#pragma once

#ifdef _WIN32
#  ifndef IMGUI_STATIC
#    ifdef IMGUI_EXPORT
#      define IMGUI_API __declspec (dllexport)
#    else
#      define IMGUI_API __declspec (dllimport)
#    endif
#    ifdef IMGUI_IMPL_EXPORT
#      define IMGUI_IMPL_API __declspec (dllexport)
#    else
#      define IMGUI_IMPL_API __declspec (dllimport)
#    endif
#  endif
#endif






































