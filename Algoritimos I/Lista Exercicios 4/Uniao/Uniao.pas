program Uniao;
	
	type tipo_vetor = array [0..400] of integer;
	var cont_uniao, i: integer;
		vetor_uniao: tipo_vetor;
		

function ler_vetor( vet: tipo_vetor; numero, contador : integer): boolean;

var aux : integer;

begin
	
	ler_vetor := true;
	
	for aux := contador downto 0 do
		begin
						
			if(numero = vet[aux]) then
			begin
				ler_vetor := false;
			end;
	end;
end;

procedure grupo();

var vetor_grupo: tipo_vetor;

begin
	i := 0;
	read(vetor_grupo[i]);
	
	while (vetor_grupo[i] <> 0) do
	begin
		
		if (ler_vetor(vetor_uniao, vetor_grupo[i], cont_uniao)) then
		begin
			vetor_uniao[cont_uniao] := vetor_grupo[i];
			cont_uniao := cont_uniao + 1;
		end;
		
		i := i + 1;
		read(vetor_grupo[i]);
		
	end;
end;
begin


	cont_uniao := 0;
	
	grupo();
	grupo();
	
	write('Conjunto Uniao =');
	for i:= 0 to (cont_uniao - 1) do
	write(' ',vetor_uniao[i]);

end.