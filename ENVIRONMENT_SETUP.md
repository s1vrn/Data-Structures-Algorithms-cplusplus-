# Environment Setup Guide for C++

To run the code in this repository, you need a C++ compiler and a Code Editor. Follow these steps to set up your environment from scratch.

## 1. Install a C++ Compiler (GCC/Clang)

### 🍎 macOS
1.  Open the **Terminal** app (Cmd + Space, type "Terminal").
2.  Install Xcode Command Line Tools by running:
    ```bash
    xcode-select --install
    ```
3.  Verify installation:
    ```bash
    g++ --version
    ```

### 🪟 Windows
1.  Download **MinGW-w64**. (Search "MinGW-w64 builds" and download the installer).
2.  Run the installer. Select architecture `x86_64`.
3.  **Crucial Step**: Add MinGW to your **PATH**.
    *   Search "Environment Variables" in Windows Search.
    *   Click "Environment Variables".
    *   Under "System Variables", find `Path` and click "Edit".
    *   Click "New" and add the path to your `bin` folder (e.g., `C:\Program Files\mingw-w64\...\bin`).
4.  Open Command Prompt (cmd) and type `g++ --version` to verify.

### 🐧 Linux (Ubuntu/Debian)
1.  Open Terminal.
2.  Run:
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```
3.  Verify:
    ```bash
    g++ --version
    ```

---

## 2. Install a Code Editor (VS Code)

We recommend **Visual Studio Code (VS Code)** as it is free, lightweight, and powerful.

1.  Download and install [VS Code](https://code.visualstudio.com/).
2.  Open VS Code.
3.  Go to the **Extensions** view (square icon on the left sidebar).
4.  Search for and install the **"C/C++"** extension by Microsoft.
5.  (Optional) Install **"Code Runner"** extension for a quick "Run" button.

---

## 3. How to Run Code

### Option A: Using Terminal (Recommended for CP)
This method helps you understand how compilation works.

1.  Open Terminal in VS Code (`Terminal` -> `New Terminal`).
2.  Navigate to the folder containing your file:
    ```bash
    cd Basics
    ```
3.  Compile the code:
    ```bash
    g++ -std=c++17 template.cpp -o template
    ```
    *   `-std=c++17`: Uses C++17 standard (modern features).
    *   `-o template`: Names the output executable "template".
4.  Run the executable:
    *   **Mac/Linux**: `./template`
    *   **Windows**: `template.exe`

### Option B: Using Code Runner
1.  Open the C++ file you want to run.
2.  Click the **Play button** (Run) in the top right corner.
3.  *Note: You may need to configure Code Runner to use C++17 in settings.*

---

## 4. Organizing Your Files

For this repository:
1.  Clone or Download this repository to your computer.
2.  Open the main folder (`ECR` or `Data-Structures-Algorithms-cplusplus`) in VS Code.
3.  You will see the directory tree on the left. Click files to edit and run them using the terminal steps above.
