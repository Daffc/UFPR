program Aniversario;
	
	const tamanho = 26;
	
	type tipo_vetor = array [0..50] of integer;
	var  i, cont_true: longint;
		vetor_final: tipo_vetor;
		

function tem_coincidencia (vetor : tipo_vetor): boolean;

var cont_1, cont_2, aux, busca : integer;

begin
	tem_coincidencia := false;	
	
	for cont_1 := 0 to tamanho do
	begin
		aux := vetor[cont_1];
		busca := 0;
		for cont_2 := 0 to tamanho do
		begin
			if aux = vetor[cont_2] then
				busca := busca + 1;
		end;
		
		if busca >= 2 then
		begin
			tem_coincidencia := true;
		end;
	end;
end;

procedure preenche(var vet : tipo_vetor);

var cont : integer;
begin
	
	
	for cont := 0 to tamanho do
	begin
		vet[cont] := random(364) + 1;
	end;
end;

begin
	randomize();	
	cont_true := 0;

	for i := 0 to 100000 do
	begin
	preenche(vetor_final);
	if tem_coincidencia(vetor_final) then
		cont_true := cont_true + 1;
	end;
	
	write ((trunc((cont_true / 100000)* 100)/100):3:2);	
end.