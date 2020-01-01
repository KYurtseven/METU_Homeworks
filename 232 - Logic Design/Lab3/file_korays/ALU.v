`timescale 1ns / 1ps
module ALU(
input [3:0] A, 
input [3:0] B, 
input [3:0] ALUop, 
output reg [3:0] C, 
output reg [3:0] Cond // Z,N,C,V
    );
//
//Write your code below
//
initial Cond = 4'b0000;
initial C = 4'b0000;
always @(*)
begin
	case(ALUop)
			
			4'b0000:
			begin
				Cond = 4'b1000;
				C = 4'b0000;
			end
			
			4'b0001 : //A+B
			begin
				C = A + B;
				if(C == 4'b0000) //Zero
						Cond[3] = 1;
				else
						Cond[3] = 0;
				if(C[3] == 1) //Negative
						Cond[2] = 1;
				else
						Cond[2] = 0;
				if(C<A || C<B) //carrybit var C =1
						Cond[1] = 1;
				else
						Cond[1] = 0;
				if((A[3] == B[3]) && (A[3] != C[3])) //Overflow var
						Cond[0] = 1;
				else
						Cond[0] = 0;
			end
		
			4'b0010 : //A-B
			begin
				C = A - B;
				if(C == 4'b0000) //Zero
						Cond[3] = 1;
				else
						Cond[3] = 0;
				if(C[3] == 1) //Negative
						Cond[2] = 1;
				else
						Cond[2] = 0;
				if(A > B) //carrybit
						Cond[1] = 0;
				else
						Cond[1] = 1;
				if((A[3] != B[3]) && (C[3] != A[3])) // Overflowbit
						Cond[0] = 1;
				else
						Cond[0] = 0;
			end
			
			4'b0011 : //-B
			begin
				C = -B;
				
				
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b0100 : //A and B
			begin
				C[3] = A[3]&B[3];
				C[2] = A[2]&B[2];
				C[1] = A[1]&B[1];
				C[0] = A[0]&B[0];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;	
			end
			
			4'b0101 : //A or B
			begin
				C[3] = A[3]|B[3];
				C[2] = A[2]|B[2];
				C[1] = A[1]|B[1];
				C[0] = A[0]|B[0];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;	
			end
			
			4'b0110 : //A xor B
			begin
				C[3] = A[3]^B[3];
				C[2] = A[2]^B[2];
				C[1] = A[1]^B[1];
				C[0] = A[0]^B[0];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;	
			end
			
			4'b0111 : //not(B)
			begin
				C[3] = ~B[3];
				C[2] = ~B[2];
				C[1] = ~B[1];
				C[0] = ~B[0];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b1001 : //B
			begin
				C[3] = B[3];
				C[2] = B[2];
				C[1] = B[1];
				C[0] = B[0];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b1010 : //shiftl(A)
			begin
				C[3] = A[2];
				C[2] = A[1];
				C[1] = A[0];
				C[0] = 0;
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b1011 : //shiftr(A)
			begin
				C[3] = 0;
				C[2] = A[3];
				C[1] = A[2];
				C[0] = A[1];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b1100 : //rotl(A)
			begin
				C[3] = A[2];
				C[2] = A[1];
				C[1] = A[0];
				C[0] = A[3];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b1101 : //rotr(A)
			begin
				C[3] = A[0];
				C[2] = A[3];
				C[1] = A[2];
				C[0] = A[1];
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			4'b1110 : //A+4 ????????????????????
			begin
				C= A+4;
				if(C == 4'b0000) //Zero
					Cond[3] = 1;
				else
					Cond[3] = 0;
				if(C[3] == 1) //Negative
					Cond[2] = 1;
				else
					Cond[2] = 0;
				Cond[1] = 0;
				Cond[0] = 0;
			end
			
			default:
				begin
					Cond = 4'bxxxx;
					C = 4'bxxxx;
				end		
	endcase
end
endmodule