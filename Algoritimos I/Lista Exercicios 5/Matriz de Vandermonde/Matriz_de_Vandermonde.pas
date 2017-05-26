program Matriz_de_Vandermonde;
type
	tipo_matriz = array [0..100, 0..100] of integer;
var 
	matriz : tipo_matriz;
	linha, coluna : integer;

function verifica (var mat: tipo_matriz; lin, col : integer): boolean;
var 
	i, j, valor: integer;

begin
	verifica := true;
	
	i := 0;
	while (i <= lin) and (verifica) do
	begin

		j := 1;
		valor := 1;
		
		while (j <= col) and (verifica) do
		begin
			
			valor := valor * matriz[i, 1];
			if(matriz[i, j] <> valor) then
				verifica := false;
			
			j := j + 1;	
		end;
		i := i + 1;
	end;
end;

procedure preencher (var mat: tipo_matriz; lin, col : integer);
var 
	i, j : integer;
begin
	for i := 0 to lin do
		for j := 0 to col do
		begin
			read(mat[i,j]);
		end;
end;

begin
	read(linha);
	read(coluna);

	linha := linha -1;
	coluna := coluna - 1;

	preencher(matriz,linha,coluna);

	writeln();
	if(verifica(matriz,linha,coluna)) then
		writeln('Sim')
	else
		writeln('Nao');
end.