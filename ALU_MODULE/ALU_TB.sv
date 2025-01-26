`timescale 1ns/1ps
module tb_ALU;

  // ALU Inputs/Outputs
  reg [3:0] opcode;
  reg [7:0] A, B;
  wire [7:0] result;

  // Instantiate the ALU
  ALU alu_inst (
    .opcode(opcode),
    .A(A),
    .B(B),
    .result(result)
  );

  // ------------------------------------------------------------
  // Simulation Control (Read Inputs from File, Write Results)
  // ------------------------------------------------------------
  integer input_file, result_file;

  initial begin
    // Read inputs from "inputs.txt"
    input_file = $fopen("E:/projects/QT/Alu_GUI/build/inputs.txt", "r");
    if (!input_file) begin
      $display("Error: Could not open inputs.txt!");
      $finish;
    end
    $fscanf(input_file, "%d %d %d", opcode, A, B);
    $fclose(input_file);

    // Wait for ALU to compute (combinational delay)
    #10;

    // Write result to "result.txt"
    result_file = $fopen("E:/projects/QT/Alu_GUI/build/result.txt", "w");
    if (!result_file) begin
      $display("Error: Could not open result.txt!");
      $finish;
    end
    $fdisplay(result_file, "%d", result);
    $fclose(result_file);

    // End simulation
    $finish;
  end

endmodule