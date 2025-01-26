#include <svdpi.h>
#include <fstream>
#include <QProcess>
#include <QMessageBox>

// Global variables to share with SystemVerilog
int g_opcode = 0, g_A = 0, g_B = 0, g_result = 0;

// DPI functions
extern "C" {
void set_inputs(int opcode, int A, int B) {
    g_opcode = opcode;
    g_A = A;
    g_B = B;
}

void simulate_alu() {
    // Write inputs to file
    std::ofstream file("E:/projects/QT/Alu_GUI/build/inputs.txt");
    if (!file.is_open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to write inputs.txt!");
        return;
    }
    file << g_opcode << " " << g_A << " " << g_B;
    file.close();

    // Run Questa Sim
    QProcess questa;
    questa.setWorkingDirectory("E:/projects/verilog");
    questa.start("vsim", {"-c", "-do", "run_simulation.tcl"});
    if (!questa.waitForFinished()) {
        QMessageBox::critical(nullptr, "Error", "Questa Sim failed to run!");
        return;
    }

    // Read result from file
    std::ifstream result_file("E:/projects/QT/Alu_GUI/build/result.txt");
    if (!result_file.is_open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to read result.txt!");
        return;
    }
    result_file >> g_result;
    result_file.close();
}

int get_result() {
    return g_result;
}
}
