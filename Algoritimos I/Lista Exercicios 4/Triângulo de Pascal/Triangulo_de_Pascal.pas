program Triangulo_de_Pascal;
	
	type tipo_vetor = array [-1..400] of longint;
	var valor_repete, i, parar : integer;
		vetor_reserva: tipo_vetor;
		

procedure constroi_piramide(comprimento : integer);

var vetor_aux: tipo_vetor;
	cont : integer;

begin
	
	for cont := 0 to comprimento do
	begin
		vetor_aux [cont] := vetor_reserva[cont-1] + vetor_reserva[cont];
		write(vetor_aux [cont] ,' ');
	end;
	
	for cont := 0 to comprimento do
	begin
		vetor_reserva [cont] := vetor_aux[cont];
	end;
	vetor_aux[cont + 1] := 0;
	writeln();
end;

begin
	
	vetor_reserva[-1] := 0;
	vetor_reserva[0] := 1;
	vetor_reserva[1] := 0;
	
	read (valor_repete);
	
	for i := 0 to (valor_repete - 1)do
	begin
		constroi_piramide(i);
	end;
	read(parar);
end.