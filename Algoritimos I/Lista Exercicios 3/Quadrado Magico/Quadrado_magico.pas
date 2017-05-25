program Quadrado_magico;

var para, valor,v_11,v_12,v_13,v_21,v_22,v_23,v_31,v_32,v_33, divisor, aux: longint;
	definitivo: boolean;


procedure agregar(var val, casa,  divisao: longint);
begin
	casa := val div divisao;
	val := val - (casa * divisao);
	divisao := divisao div 10;
end;


function checa(var vl_1, vl_2: longint): boolean;
begin 
	if ((vl_1 <> vl_2) and (vl_1 <> 0) and ( vl_2 <> 0)) then
		checa := true
	else
		checa := false;
end;
 
begin
valor := 123456789;
definitivo := true;

while((v_11 + v_12 + v_13 <> 15) or (v_21 + v_22 + v_23 <> 15) or (v_31+v_32+v_33 <> 15) or (v_11 + v_22+v_33 <> 15) or (v_13 + v_22 + v_31 <> 15) or (v_11 + v_21 + v_31 <> 15) or (v_12 + v_22 + v_32 <> 15) or (v_13 + v_23 + v_33 <> 15) or definitivo ) do
begin
	definitivo := true;
	
	aux := valor;
	divisor := 100000000;
	
	agregar(aux, v_11, divisor);
	agregar(aux, v_12, divisor);
	agregar(aux, v_13, divisor);
	agregar(aux, v_21, divisor);
	agregar(aux, v_22, divisor);
	agregar(aux, v_23, divisor);
	agregar(aux, v_31, divisor);
	agregar(aux, v_32, divisor);
	agregar(aux, v_33, divisor);
	
	if(v_22 = 5) then
	if(v_11 mod 2 = 0) and (v_13 mod 2 = 0) and (v_31 mod 2 = 0) and (v_33 mod 2 = 0) then
	if(v_12 mod 2 = 1) and (v_21 mod 2 = 1) and (v_23 mod 2 = 1) and (v_32 mod 2 = 1) then
	definitivo:= false;
	{	
	if checa(v_11,v_12) then
		if checa(v_11,v_13) then
			if checa(v_11,v_21) then
				if checa(v_11,v_22) then
					if checa(v_11,v_23) then
						if checa(v_11,v_31) then
							if checa(v_11,v_32) then
								if checa(v_11,v_33) then
									if checa(v_12,v_13) then
										if checa(v_12,v_21) then
											if checa(v_12,v_22) then
												if checa(v_12,v_23) then
													if checa(v_12,v_31) then
														if checa(v_12,v_32) then
															if checa(v_12,v_33) then
																if checa(v_13,v_21) then
																	if checa(v_13,v_22) then
																		if checa(v_13,v_23) then
																			if checa(v_13,v_31) then
																				if checa(v_13,v_32) then
																					if checa(v_13,v_33) then
																						if checa(v_21,v_22) then
																							if checa(v_21,v_23) then
																								if checa(v_21,v_31) then
																									if checa(v_21,v_32) then
																										if checa(v_21,v_33) then
																											if checa(v_22,v_23) then
																												if checa(v_22,v_31) then
																													if checa(v_22,v_32) then
																														if checa(v_22,v_33) then
																															if checa(v_23,v_31) then
																																if checa(v_23,v_32) then
																																	if checa(v_23,v_33) then
																																		if checa(v_31,v_32) then
																																			if checa(v_31,v_33) then
																																				if checa(v_32,v_33) then
																																					definitivo:= false;
																																					}
	valor := valor + 1;
end;
writeln (v_11,' ',v_12,' ',v_13);
writeln (v_21,' ',v_22,' ',v_23);
writeln (v_31,' ',v_32,' ',v_33);


read(para);
end.