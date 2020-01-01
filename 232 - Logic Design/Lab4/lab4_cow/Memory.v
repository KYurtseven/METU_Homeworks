`timescale 1ns / 1ps
module Memory(
input [23:0] Addr,
input Length, //byte:0 vs. word:1
input Rd, 
input Wr, 
input Enable,
output reg Rdy,
input [31:0] DataIn, 
output reg [31:0] DataOut
);

localparam Tmem= 8; //8 ns
localparam Td = 0.2; //200 ps

//integer x = 2**24;
reg [31:0] memory_ram_d[0:16777215];

initial begin
	Rdy = 1;
end

always@(Rd or Wr or Enable)
	begin
		if (Enable)
			begin
				if (Rdy)
					begin
						if (Rd)
							begin
								Rdy <=#Td 0;
								if (Length) //Word demek
									begin
										DataOut <=#Tmem memory_ram_d[Addr[23:2]];
									end
								else //Byte demek
									begin
										case(Addr[1:0])
											2'b00:
											begin
												DataOut[7:0] <=#Tmem memory_ram_d[Addr[23:2]][7:0];
											end					
											2'b01:
											begin
												DataOut[7:0] <=#Tmem memory_ram_d[Addr[23:2]][15:8];
											end
											2'b10:
											begin
												DataOut[7:0] <=#Tmem memory_ram_d[Addr[23:2]][23:16];
											end
											2'b11:
											begin
												DataOut[7:0] <=#Tmem memory_ram_d[Addr[23:2]][31:24];
											end
											
										endcase
									end
								Rdy <=#Tmem 1;
							end
						if (Wr)
							begin
								Rdy <=#Td 0;
								if (Length) //word demek
									begin
										memory_ram_d[Addr[23:2]] <= DataIn;
									end
								else
									begin
										case(Addr[1:0])
											2'b00:
											begin
												memory_ram_d[Addr[23:2]][7:0] <= DataIn[7:0];
											end					
											2'b01:
											begin
												memory_ram_d[Addr[23:2]][15:8] <= DataIn[15:8];
											end
											2'b10:
											begin
												memory_ram_d[Addr[23:2]][23:16] <= DataIn[23:16];
											end
											2'b11:
											begin
												memory_ram_d[Addr[23:2]][31:24] <= DataIn[31:24];
											end
										endcase
									end
								Rdy <=#Tmem 1;
							end		
					end
			end	
	end
//
//Write your code below
//


endmodule
	
	
