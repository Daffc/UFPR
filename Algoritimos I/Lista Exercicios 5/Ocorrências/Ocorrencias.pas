program Ocorrencias;

type 	tipo_vetor = array[0..200] of longint;
var 	vetor : tipo_vetor;		
		tamanho: integer;


procedure preencher(var vet: tipo_vetor; var tam : integer);
var a : longint;
begin
	read(a);
	while (a <> 0)do
	begin
		tam := tam + 1;
		vet[tam]:= a;
		read(a);
	end;
end;

function repetidos(var v: tipo_vetor;var v_tam: integer; valor : longint): boolean;
var cont : integer;
begin
	repetidos := false;
	cont := 0;

	while (cont <= v_tam) and not(repetidos) do
	begin
		if(v[cont] = valor) then
		begin
			repetidos := true;
		end;
		cont := cont + 1;
	end;

	if not(repetidos) then
	begin
		v_tam := v_tam + 1;
		v[v_tam] := valor;
	end;
end;

procedure Ocorrencias(var vet: tipo_vetor;tam : integer);
var i, j, tam_repetidos,soma : integer;
	v_repetidos : tipo_vetor;

	
begin
	tam_repetidos := -1;

	writeln('A sequencia contem:');

	for i := 0 to tam do
	begin
		soma := 1;
		if(not(repetidos(v_repetidos, tam_repetidos,vet[i]))) then
		begin
			for j := tam  downto i + 1 do
				if(vet[j] = vet[i]) then
					soma := soma + 1;
			if(soma = 1 ) then
				writeln(vet[i],': ',soma,' ocorrencia')
			else	
				writeln(vet[i],': ',soma,' ocorrencias');
		end;
	end;
end;

begin
	tamanho := -1;
	preencher(vetor,tamanho);
	Ocorrencias(vetor,tamanho);
end.
