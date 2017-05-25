program Intercala;
	
	type tipo_vetor = array [0..200] of real;
	var  parar, i, a, b, c: integer;
		vetor_a, vetor_b, vetor_c: tipo_vetor;
		

procedure preenche(var vet : tipo_vetor;var tam : integer);

var aux : real;
begin
	
	read (aux);
	while aux <> 0 do
	begin
		tam := tam + 1;
		vet[tam] := aux;
		read(aux);
	end;
end;

function maior(a, b : integer): integer;
begin
	if (a > b) then
		maior := a
	else
		maior := b;
end;

procedure intercalar(var Va, Vb, Vc: tipo_vetor; tam_a, tam_b: integer; var tam_c : integer);
var cont : integer;
begin
		cont := maior(tam_a, tam_b);
		
		for cont := 0 to cont do
		begin
			if (cont <= tam_a) then
			begin
				tam_c := tam_c + 1;
				Vc[tam_c] := Va[cont];
			end;
			
			if (cont <= tam_b) then
			begin
				tam_c := tam_c + 1;
				Vc[tam_c] := Vb[cont];
			end;
		end;
end;


begin
	a := -1;
	b := -1;
	c := -1;
	preenche(vetor_a, a);
	preenche(vetor_b, b);
	intercalar(vetor_a, vetor_b, vetor_c, a, b, c);
	
	for i := 0 to c do
		write((vetor_c[i]):2:1, ' ');
		
	read(parar);
end.