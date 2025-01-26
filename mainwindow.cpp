#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

// Declare DPI functions
extern "C" {
void set_inputs(int opcode, int A, int B);
void simulate_alu();
int get_result();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialize opcode dropdown (QComboBox)
    ui->opcodeInput->addItems({"0: Add", "1: Subtract", "2: AND", "3: OR"});
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_computeButton_clicked() {
    // Get opcode from QComboBox
    QString opcodeText = ui->opcodeInput->currentText().split(":")[0];
    int opcode = opcodeText.toInt();

    // Get A and B values
    int A = ui->aInput->text().toInt();
    int B = ui->bInput->text().toInt();

    // Validate inputs
    if (opcode < 0 || opcode > 3) {
        QMessageBox::warning(this, "Error", "Invalid opcode!");
        return;
    }

    // Call DPI functions
    set_inputs(opcode, A, B);  // Defined in dpi_alu.cpp
    simulate_alu();            // Defined in dpi_alu.cpp
    int result = get_result(); // Defined in dpi_alu.cpp

    // Display result
    ui->resultLabel->setText(QString("Result: %1").arg(result));
}
