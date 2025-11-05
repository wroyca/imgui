# libimgui-docking - A C++ library

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
C++ library (docking branch). It provides a bloat-free graphical user interface
library for C++ with docking and multi-viewport features.


## Usage

To start using `libimgui-docking` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-docking ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libimgui-docking%lib{imgui-docking}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-docking}
```

The main library target includes the core Dear ImGui functionality with docking
and multi-viewport support. Backend implementations can be conditionally included
via the `config.libimgui_docking.backend` configuration variable (see below).


## Configuration variables

This package provides the following configuration variables:

### Backend Selection

```
[strings] config.libimgui_docking.backend ?= [null]
```

List of backend implementations to include. Supported values: `glfw`, `win32`,
`opengl2`, `opengl3`, `vulkan`, `dx9`, `dx10`, `dx11`, `dx12`, `metal`, `wgpu`,
`sdlrenderer2`, `sdlrenderer3`, `sdlgpu3`. Multiple backends can be specified.

```
[string] config.libimgui_docking.vulkan_sdk_root ?= [null]
```

Path to Vulkan SDK root (optional).

### Feature Flags

```
[bool] config.libimgui_docking.disable_obsolete_functions ?= false
[bool] config.libimgui_docking.disable ?= false
[bool] config.libimgui_docking.disable_demo_windows ?= false
[bool] config.libimgui_docking.disable_debug_tools ?= false
[bool] config.libimgui_docking.disable_win32_default_clipboard_functions ?= false
[bool] config.libimgui_docking.enable_win32_default_ime_functions ?= false
[bool] config.libimgui_docking.disable_win32_default_ime_functions ?= false
[bool] config.libimgui_docking.disable_win32_functions ?= false
[bool] config.libimgui_docking.enable_osx_default_clipboard_functions ?= false
[bool] config.libimgui_docking.disable_default_shell_functions ?= false
[bool] config.libimgui_docking.disable_default_format_functions ?= false
[bool] config.libimgui_docking.disable_default_math_functions ?= false
[bool] config.libimgui_docking.disable_file_functions ?= false
[bool] config.libimgui_docking.disable_default_file_functions ?= false
[bool] config.libimgui_docking.disable_default_allocators ?= false
[bool] config.libimgui_docking.disable_default_font ?= false
[bool] config.libimgui_docking.disable_sse ?= false
[bool] config.libimgui_docking.enable_test_engine ?= false
[bool] config.libimgui_docking.include_imgui_user_h ?= false
[bool] config.libimgui_docking.use_bgra_packed_color ?= false
[bool] config.libimgui_docking.use_legacy_crc32_adler ?= false
[bool] config.libimgui_docking.use_wchar32 ?= false
[bool] config.libimgui_docking.disable_stb_truetype_implementation ?= false
[bool] config.libimgui_docking.disable_stb_rect_pack_implementation ?= false
[bool] config.libimgui_docking.disable_stb_sprintf_implementation ?= false
[bool] config.libimgui_docking.use_stb_sprintf ?= false
[bool] config.libimgui_docking.enable_freetype ?= false
[bool] config.libimgui_docking.enable_freetype_plutosvg ?= false
[bool] config.libimgui_docking.enable_freetype_lunasvg ?= false
[bool] config.libimgui_docking.enable_stb_truetype ?= false
[bool] config.libimgui_docking.define_math_operators ?= false
[bool] config.libimgui_docking.debug_highlight_all_id_conflicts ?= false
[bool] config.libimgui_docking.debug_paranoid ?= false
```

### Custom Header Filenames

```
[string] config.libimgui_docking.user_h_filename ?= [null]
[string] config.libimgui_docking.stb_truetype_filename ?= [null]
[string] config.libimgui_docking.stb_rect_pack_filename ?= [null]
[string] config.libimgui_docking.stb_sprintf_filename ?= [null]
```

These configuration variables map directly to the `#define` statements in
`imconfig.h`. See the [Dear ImGui documentation](https://github.com/ocornut/imgui/blob/master/imconfig.h)
for detailed descriptions of each option.
