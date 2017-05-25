program Ocorrencias;
	
	type tipo_vetor = array [0..200] of integer;
	var  parar, a: integer;
		vetor_a: tipo_vetor;
		

procedure preenche(var vet : tipo_vetor;var tam : integer);

var aux : integer;
begin
	
	read (aux);
	while aux <> 0 do
	begin
		tam := tam + 1;
		vet[tam] := aux;
		read(aux);
	end;
end;
function verifica( var vet : tipo_vetor; var coluna: integer; valor : integer): boolean;
var contador : integer;
begin
	contador := 0;
	verifica := true;
	vet[(coluna + 1)] := valor;
	
	while vet[coluna] <> valor do
		contador := contador + 1;

	if(contador = coluna + 1) then
	begin
		coluna := contador;
	end
	else
		verifica := false;
end; 

procedure ocorrencia(var vetor: tipo_vetor; tam: integer);
var cont_cres,cont_decre, colu_aux, soma : integer;
	vet_aux : tipo_vetor;
begin	
		colu_aux := -1;
		
		writeln('A sequencia contem:');
		
		for cont_cres := 0 to tam do
		begin
			soma := 0;
			if (verifica(vet_aux,colu_aux, vetor[cont_cres])) then
			begin
				write(vetor[cont_cres]);
				
				for cont_decre := tam downto cont_cres do
				begin
					if vetor[cont_cres] = cont_decre then
					begin
						soma := soma + 1;
					end;
				end;
				
				write(': ',soma,' ocorrencias');
				writeln();
			end;
			writeln (vetor[cont_cres]);
		end;

end;

begin
	a := -1;
	preenche(vetor_a, a);
	
	ocorrencia(vetor_a,a);
	
read(parar);
end.