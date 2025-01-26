
module ALU (
  input [3:0] opcode,  // Operation code (e.g., 0000 = add, 0001 = subtract)
  input [7:0] A, B,    // Input operands
  output reg [7:0] result // Output result
);

always @(*) begin
  case (opcode)
    4'b0000: result = A + B;    // Add
    4'b0001: result = A - B;    // Subtract
    4'b0010: result = A & B;    // AND
    4'b0011: result = A | B;    // OR
    default: result = 8'b0;     // Default
  endcase
end

endmodule