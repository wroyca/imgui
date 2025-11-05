# imgui - Dear ImGui

This is a `build2` package repository for [Dear ImGui](https://github.com/ocornut/imgui),
a bloat-free graphical user interface library for C++.

This repository contains two package variants:

- **libimgui** - The standard Dear ImGui library (master branch)
- **libimgui-docking** - Dear ImGui with docking and multi-viewport support (docking branch)

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`imgui` in your `build2`-based project, then instead see the accompanying
package README files:

- [`libimgui/PACKAGE-README.md`](libimgui/PACKAGE-README.md)
- [`libimgui-docking/PACKAGE-README.md`](libimgui-docking/PACKAGE-README.md)

The development setup for `imgui` uses the standard `bdep`-based workflow.
For example:

```
git clone https://github.com/build2-packaging/imgui.git
cd imgui

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
