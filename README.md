# HHS-Computer-Vision
The Hague University of Applied Sciences training course learning OpenCV.

The given assignments are documented in dutch, these are available in markdown [here](./Practicumhandleiding/1920%20H-NSE-IMVIS%20Practicumhandleiding.md) (This was a docx document that has been converted to markdown. The markdown document is chaotic and incomplete).

# Installation
This project requires CMake, GCC and OpenCV. With a optional dependency of vscode.

**Important: On Linux you might be required to build OpenCV from source, [Installation Guide](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html)**

## Build Project
```
mkdir build && cd build
```

```
cmake ..
```

Build the complete project
```
cmake --build .
```

Build a specific part of the project
```
cmake --build Example
```
```
cmake --build Assignment
```