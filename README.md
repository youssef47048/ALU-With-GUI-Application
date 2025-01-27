# ALU-With-GUI-Application
Building a GUI application for an ALU model Written in Verilog 


# ALU Controller with Qt GUI and ModelSim Integration

A project that integrates a Verilog-based Arithmetic Logic Unit (ALU) with a Qt GUI, using ModelSim for hardware simulation and SystemVerilog DPI for communication.

## Features
- **ALU Operations**: Add, Subtract, AND, OR.
- **GUI Controls**: Input operands (A, B) and select opcodes via a dropdown menu.
- **Result Visualization**: Display computed results in the GUI.

## Prerequisites
- **ModelSim**: For Verilog/SystemVerilog simulation.
- **Qt 6.8+**: For GUI development.
- **CMake 3.16+**: For building the project.
- **C++ Compiler** (GCC, MSVC, or MinGW).

## Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/ALU-GUI.git](https://github.com/youssef47048/ALU-With-GUI-Application.git
   cd ALU-With-GUI-Application
```
2. **Build the Project:**

```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH="path/to/Qt/6.8.1/mingw_64"
cmake --build .
```

3. **Update File Paths**:
Replace the paths in CMakeLists.txt and ALU_TB with your own

4. **Run the GUI**:
```bash
./Alu_GUI  # Linux/macOS
Alu_GUI.exe  # Windows
```






