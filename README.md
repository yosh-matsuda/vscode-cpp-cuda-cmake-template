# CMake C++/CUDA Multi-Platform Template for Visual Studio Code

This CMake project serves as a template for C++ and CUDA development. It includes the following directories and files:

*   `my_header_lib`: C++ header-only library
*   `my_static_lib`: C++ static library
*   `my_shared_lib`: C++ shared library
*   `main`: Executable
*   `test`: Tests using [Google Test](https://github.com/google/googletest)
*   `cuda/cuda_main`: (Optional) CUDA executable
*   `cuda/my_cuda_lib`: (Optional) CUDA static library

Preconfigured linter and formatter settings based on the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) are included.

*   `.clang-format`: [ClangFormat 20](https://clang.llvm.org/docs/ClangFormat.html)
*   `.clang-tidy`: [Clang-Tidy 20](https://clang.llvm.org/extra/clang-tidy/)
*   `.clang-tidy-lower`: Lower-case version of the above. Please rename it if needed.

[vcpkg](https://github.com/microsoft/vcpkg) is included as a submodule:

*   `vcpkg.json`: List of dependencies

## Setting Up the C++ Environment

### Linux

**Using apt**

For Ubuntu 24.04, please install the following:

```bash
$ sudo apt install build-essential gdb g++-14 clang-20 clangd-20 cmake ninja-build pkg-config
```

Then, add the clangd path to the [`.vscode/settings.json`](.vscode/settings.json) file:

```json
{
    "clangd.path": "/usr/bin/clangd-20"
}
```

**Using Homebrew**

If you prefer the latest compiler versions:

```bash
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
$ brew install gcc llvm cmake ninja gdb
```

### macOS

**Using Apple Clang**

```bash
$ xcode-select –install
```

**Using Homebrew**

```bash
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
$ brew install gcc llvm cmake ninja gdb
```

### Windows

Please install [Visual Studio](https://visualstudio.microsoft.com/) (or Build Tools for Visual Studio for command-line use) with the C++ development workload.

### Other Dependencies

To generate `compile_commands.json` with header files, install [compdb](https://github.com/Sarcasm/compdb):

```bash
$ sudo apt install pipx
$ pipx install compdb
```

> [!NOTE]
> Note that compdb currently does not support Windows.

## Getting Started

### Opening the Project Template

1.  Clone this repository with `--recursive` to include submodules.  

    ```bash
    $ git clone --recursive https://github.com/yosh-matsuda/vscode-cpp-cuda-cmake-template.git
    ```

1.  Open the project in VSCode.  

    ```bash
    $ code vscode-cpp-cuda-cmake-template
    ```

1.  Please install the following VSCode extensions:

*   [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)
*   [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)

### Building and Running

1.  Select the compiler and build type in CMake Tools.
2.  Press `F7` to configure and build the project.
3.  Press `F1` and run `clangd: Restart language server` to load `compile_commands.json` and restart clangd.
4.  Press `F5` to debug the target executable.

    *   For Linux: `(gdb) Launch`
    *   For Windows: `(Windows) Launch`
    *   For macOS: `(lldb) Launch`
        *   You may need to enable Developer mode:  
        ```bash
        $ sudo DevToolsSecurity -enable
        ```

### Starting Your Project

1.  Untrack the `.vscode` directory and commit the change.  

    ```bash
    $ git rm --cached -r .vscode
    $ git commit -m "Remove VSCode settings"
    ```

1.  Remove unnecessary directories and `add_subdirectory` entries in `CMakeLists.txt`.
1.  Update project names and directories in `CMakeLists.txt` and `vcpkg.json`.
1.  Add your dependencies to `CMakeLists.txt` and `vcpkg.json`.

### Updating vcpkg

1.  Update the vcpkg submodule to the specified commit hash.
2.  Edit the `builtin-baseline` in `vcpkg.json` to match the hash above.
