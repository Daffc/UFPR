program Gera_imagem;

const
	m = 210;
	n =140;
	max = 29399;

type
	comprimento = 0 .. max;
	tipo_matriz = array [0..m,0..n] of longint;

var
	matriz : tipo_matriz;
	i, j: integer;


begin

	writeln('P2');
	writeln(m,' ',n);
	writeln(max);

	//GERAR MATRIZ DE FORMA CRESCENTE

	{
	for i := 3 to  m do
	begin
		for j := 0 to n do
		begin
			matriz[i,j] := (i*n) + j;
			write(matriz[i,j],' ');
		end;
		writeln();
	end;
	}

	//GERAR ELEMENTOS DE MATRIZ DE FORMA RANDÔMICA
	{
	for i := 3 to  m do
	begin
		for j := 0 to n do
		begin
			matriz[i,j] :=random(max);
			write(matriz[i,j],' ');
		end;
		writeln();
	end;
	}

	//GERAR MATRIZ DE FORMA CICLICA
	
	for i := 3 to  m do
	begin
		for j := 0 to n do
		begin
			matriz[i,j] := trunc(sin(i mod 360) * 1000);
			write(matriz[i,j],' ');
		end;
		writeln();
	end;

end.