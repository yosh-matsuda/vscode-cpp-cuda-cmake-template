# CMake C++/CUDA multi-platform template for Visual Studio Code

This CMake C++ project includes typical templates for

*   C++ header only library: `./my_header_lib`.
*   C++ static library: `./my_static_lib`.
*   Executable: `./main`.
*   [Google Test](https://github.com/google/googletest): `./test`.
*   (option) CUDA executable: `./cuda/cuda_main`.
*   (option) CUDA static library: `./cuda/my_cuda_lib`.

The pre-configured linter and formatter settings are included. They are based on the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

*   [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html): `./.clang-format`
*   [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/): `./.clang-tidy`

The following VSCode extensions are prerequisites:

*   [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd).
*   [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).
*   [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

## Set up C++ development environment (for Linux)

### Compilers

Install the C++ compiler of your choice. GCC-12 and Clang-14 can be installed with apt on Ubuntu 22.04 or later.

```bash
$ sudo apt install g++-12 clang-14
```

If you want to keep your compiler to the latest version, you can use [brew](https://brew.sh/).

```bash
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Note that `PATH` must be set after brew installation. For detailed install instructions, please refer to the official documentation. After successful installation, run brew install.

```bash
$ brew install gcc llvm
```

### CMake

There are pre-compiled binaries available via. apt or brew. You can install it either way.

```bash
$ sudo apt install cmake
```

or

```bash
$ brew install cmake
```

In addition, it is a good idea to install Ninja as well.

```bash
$ sudo apt install ninja-build
```

or

```bash
$ brew install ninja
```

### [vcpkg](https://github.com/microsoft/vcpkg) and packages

In this project, C++ libraries are assumed to be managed by vcpkg.

Firstly, clone and install vcpkg

```bash
$ git clone https://github.com/Microsoft/vcpkg.git
$ cd vcpkg
$ ./bootstrap-vcpkg.sh
$ ./vcpkg integrate install
```

Then, install packages.

```bash
$ sudo apt install pkg-config  # maybe required by boost
$ ./vcpkg install boost gtest
```

### Install other dependencies

To generate `compile_commands.json` with header files, install [compdb](https://github.com/Sarcasm/compdb)

```bash
$ pip3 install compdb
```

## Open the project template

1.  Clone this repository with `--recursive` to include submodule.
2.  Open the project in VSCode.
3.  Replace keyword `PATH_TO_VCPKG` by **your vcpkg path** in `.vscode`. Press `Ctrl + Shift + F` to open search view and replace. The files `.vscode/c_cpp_properties.json` and `.vscode/cmake-kits.json` will be found.
4.  Install VSCode extensions
    *   [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd).
    *   [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).
    *   [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
5.  If you want to change the compilers from clang to gcc/g++, edit `.vscode/cmake-kits.json`.

## The build and configurations steps

Follow the steps below to check if the settings are correct.

1.  Select CMake configure on VSCode status bar: e.g. `Debug`
1.  Select CMake kits on VSCode status bar: e.g. `clang++`
1.  Press `F7` to configure and build the project.
1.  Press `F1` and run `clangd: Restart language server` to load `compile_commands.json` and clangd will restart.
1.  Press `F5` to debug the target executable.

## Start your own project

Delete unnecessary directories according to the format of the binary file you wish to build.  
Chage the project names and directories appropriately and add source files to src/include.
