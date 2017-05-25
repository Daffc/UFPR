program Numeros_repetidos;
	
	type tipo_vetor = array [0..400] of integer;
	var cont_recebido, cont_repetidos, parar, i, transportador: integer;
		vetor_recebido, vetor_repetidos: tipo_vetor;
		

function verifica_iguais( vet: tipo_vetor; numero, contador : integer): integer;

var aux : integer;

begin
	
	verifica_iguais := 0;
	
	for aux := contador downto 0 do
		begin
						
			if(numero = vet[aux]) then
			begin
				verifica_iguais := numero;
			end;
	end;
end;

begin


	cont_repetidos := 0;
	cont_recebido := 0;
	
	read(vetor_recebido[cont_recebido]);
	
	while (vetor_recebido[cont_recebido] <> 0) do
	begin
		
		if ( verifica_iguais( vetor_repetidos, vetor_recebido[cont_recebido], cont_repetidos) = 0) then
		begin
			
			transportador := verifica_iguais(vetor_recebido, vetor_recebido[cont_recebido], cont_recebido - 1);	
			
			if( transportador <> 0) then
			begin
				vetor_repetidos[cont_repetidos] := transportador;
				cont_repetidos := cont_repetidos + 1;
			end;
		end;
		
		cont_recebido := cont_recebido + 1;
		read(vetor_recebido[cont_recebido]);
		
	end;
	
	write('Os repetidos sao:');
	for i:= 0 to (cont_repetidos - 1) do
	write(' ',vetor_repetidos[i]);

	read(parar);

end.