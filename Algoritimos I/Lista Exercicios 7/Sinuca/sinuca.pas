program sinuca;
uses crt;

const
  maxbolas = 9;
  PI = 3.14159265;

 type
 	vetor = array [1 .. maxbolas] of longint;

 var
 	L, C, B: integer;
  	Vel, Ang: real;
  	mesa: vetor;

procedure le_posicao_das_bolas(var m: vetor; larg, comp, bolas : integer);
var 
	i, valor : integer;
begin


	write('Entre com a posicao da Largura da Bola Branca: ');
	read(valor);
	m[1] := valor * 100;

	write('Entre com a posicao do Comprimento da Bola Branca: ');
	read(valor);
	m[1] := m[1] + valor;

	for i := 2 to bolas do 
	begin
		write('Entre com a posicao da Largura da Bola: ');
		read(valor);
		m[i] := valor * 100;

		write('Entre com a posicao do Comprimento da Bola: ');
		read(valor);
		m[i] := m[i] + valor;

	end
end;
function posiciona_esfera(var esf: vetor; lin, col, quantidade : integer):boolean;
var 
	i : integer;
begin
	posiciona_esfera:= false;
	for i := 1 to quantidade do
	begin
		if ((esf[i] div 100) = lin) and ((esf[i] mod 100) = col) then
			posiciona_esfera := true; 
	end;
end;
procedure imprime_mesa(var m: vetor; larg, comp, bolas : integer);
var
	i, j : integer; 
begin
	clrscr;
	for i := 1 to larg do
	begin
		for j:= 1 to comp do
		begin
		if(posiciona_esfera(m, i, j, bolas)) then
			write('*')
		else
		begin
			if((j = 1) or (j = comp)) then
					write('|')
			else
				if((i = 1) or (i = larg)) then
						write('-')
				else
						write(' ');
			end;
		end;
	writeln();
	end;
end;
function verifica_movimento(posicao: longint; ang: real):real;
begin

end;
procedure simula ( var campo: vetor; largura, comprimento, bolar: integer; velocidade, angulo : real);
var 
	somador_lin, somador_col: real;
	aux_lin, aux_col, senti_lin, senti_col, movimento: integer;
	borda : boolean;
begin
	somador_lin := 0;
	somador_col := 0;
	senti_lin := 1;
	senti_col := 1;
	aux_lin := campo[1] div 100;
	aux_col := campo[1] mod 100;
	angulo := (PI * angulo) / 180;
	borda := false;

	movimento := 1000 - trunc((velocidade/3) * 1000);
	while movimento <= 1000 do
	begin
		delay(movimento);

		if(campo[1] mod 100 = 1) and (campo[1] div 100 = 1) then
		begin
			if(not(borda)) then
			begin
				aux_lin := campo[1] div 100;
				aux_col := campo[1] mod 100;
				somador_lin := 0;
				somador_col := 0;
				senti_col := abs(senti_col);
				senti_lin := abs(senti_lin);
				borda := true;
				angulo := (7 * PI) / 4;
			end;
		end;
		if(campo[1] mod 100 = 1) and (campo[1] div 100 = largura) then
		begin
			if(not(borda)) then
			begin
				aux_lin := campo[1] div 100;
				aux_col := campo[1] mod 100;
				somador_lin := 0;
				somador_col := 0;
				senti_col := abs(senti_col);
				senti_lin := abs(senti_lin);
				borda := true;
				angulo := PI / 4;
			end;
		end;
		if(campo[1] mod 100 = comprimento) and (campo[1] div 100 = 1) then
		begin
			if(not(borda)) then
			begin
				aux_lin := campo[1] div 100;
				aux_col := campo[1] mod 100;
				somador_lin := 0;
				somador_col := 0;
				senti_col := abs(senti_col);
				senti_lin := abs(senti_lin);
				borda := true;
				angulo := (5*PI) / 4;
			end;
		end;
		if(campo[1] mod 100 = comprimento) and (campo[1] div 100 = largura) then
		begin
			if(not(borda)) then
			begin
				aux_lin := campo[1] div 100;
				aux_col := campo[1] mod 100;
				somador_lin := 0;
				somador_col := 0;
				senti_col := abs(senti_col);
				senti_lin := abs(senti_lin);
				borda := true;
				angulo := (3*PI) / 4;
			end;
		end
		else
		begin
			if(campo[1] mod 100 = comprimento) or (campo[1] mod 100 = 1) then
			begin
				if(not(borda)) then
				begin
					aux_lin := campo[1] div 100;
					aux_col := campo[1] mod 100;
					somador_lin := 0;
					somador_col := 0;
					senti_col := -senti_col;
					borda := true;
				end;
			end;
			if(campo[1] div 100 = largura) or (campo[1] div 100 = 1) then
			begin
				if(not(borda)) then
				begin
					aux_lin := campo[1] div 100;
					aux_col := campo[1] mod 100;
					somador_lin := 0;
					somador_col := 0;
					senti_lin := -senti_lin;
					borda := true;
				end;
			end
			else
				borda := false;
		end;

		somador_lin := somador_lin - (sin(angulo) * senti_lin);
		somador_col := somador_col + (cos(angulo) * senti_col);
		campo[1] := round(aux_lin + somador_lin) * 100;
		campo[1] := round(aux_col + somador_col) + campo[1];
		imprime_mesa(mesa, L, C, B);
		
		velocidade := velocidade - 0.05;
		movimento := 1000 - trunc((velocidade/3) * 1000);
	end;
end;


begin

	write('Entre com a Largura da mesa em pixels (no maximo 40): ');
	read(L);
	write('Entre com o Comprimento da mesa em pixels (no maximo 40): ');
	read(C);
	write('Entre com a quantidade de Bolas da mesa (no maximo 9): ');
	read(B);
	le_posicao_das_bolas(mesa, L, C, B);
	write('Entre com a Velocidade Inicial da Bola Branca em pixels/s (de 0.01 a 3.0): ');
	read(Vel);
	write('Entre com o Angulo Inicial da Bola Branca em graus (de 0 a 359): ');
	read(Ang);
	imprime_mesa(mesa, L, C, B);
	simula(mesa, L, C, B, Vel, Ang);

end.