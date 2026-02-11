# CMake C++/CUDA multi-platform template for Visual Studio Code

This CMake project contains the following directories and files:

*   `my_header_lib`: C++ header-only library
*   `my_static_lib`: C++ static library
*   `my_shared_lib`: C++ shared library
*   `main`: Executable
*   `test`: Test with [Google Test](https://github.com/google/googletest)
*   `cuda/cuda_main`: (option) CUDA executable
*   `cuda/my_cuda_lib`: (option) CUDA static library

The preconfigured linter and formatter settings based on the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) are included.

*   `.clang-format`: [ClangFormat 20](https://clang.llvm.org/docs/ClangFormat.html)
*   `.clang-tidy`: [Clang-Tidy 20](https://clang.llvm.org/extra/clang-tidy/)

The [vcpkg](https://github.com/microsoft/vcpkg) is included as a submodule:

*   `vcpkg.json`: List of dependencies

## Setting up C++ environment

### Linux

**Using apt**

For Ubuntu 24.04:

```bash
$ sudo apt install build-essential gdb g++-14 clang-20 clangd-20 cmake ninja-build pkg-config
```

Add clangd path to the [`.vscode/settings.json`](.vscode/settings.json) file:

```json
{
    "clangd.path": "/usr/bin/clangd-20",
}
```

**Using homebrew**

For those who want to use the latest version of the compiler:

```bash
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
$ brew install gcc llvm cmake ninja gdb
```

### MacOS

**Using Apple Clang**

```bash
$ xcode-select –install
```

**Using homebrew**

```bash
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
$ brew install gcc llvm cmake ninja gdb
```

### Windows

Install [Visual Studio](https://visualstudio.microsoft.com/) (or Build Tools for Visual Studio for command line only) with C++ development workload.

### Other dependencies

To generate `compile_commands.json` with header files, install [compdb](https://github.com/Sarcasm/compdb)

```bash
$ sudo apt install pipx
$ pipx install compdb
```

> [!NOTE]
> Currently, compdb does not seem to support Windows.

## Getting started

### Open the project template

1.  Clone this repository with `--recursive` to include submodules.  
    ```bash
    $ git clone --recursive https://github.com/yosh-matsuda/vscode-cpp-cuda-cmake-template.git
    ```
1.  Open the project in VSCode.  
    ```bash
    $ code vscode-cpp-cuda-cmake-template
    ```
1.  Install VSCode extensions
    *   [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd).
    *   [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack).

### Build and run

1.  Select compiler and build type in CMake Tools.
1.  Press `F7` to configure and build the project.
1.  Press `F1` and run `clangd: Restart language server` to load `compile_commands.json` and clangd will restart.
1.  Press `F5` to debug the target executable.
    *   `(gdb) Launch` for Linux
    *   `(Windows) Launch` for Windows
    *   `(lldb) Launch` for MacOS
        *   You may need to enable the Developer mode  
            ```bash
            $ sudo DevToolsSecurity -enable
            ```

### Start your project

1.  Untrack the `.vscode` directory and commit.  
    ```bash
    $ git rm --cached -r .vscode
    $ git commit -m "Remove VSCode settings"
    ```
1.  Delete unnecessary directories and `add_subdirectory` in `CMakeLists.txt`.
1.  Change the project names and directories in `CMakeLists.txt` and `vcpkg.json`.
1.  Add your dependencies to `CMakeLists.txt` and `vcpkg.json`.

### Update vcpkg

1.  Update vcpkg submodule to the specified commit hash.
1.  Edit the `builtin-baseline` in `vcpkg.json` to put the same hash as above.
