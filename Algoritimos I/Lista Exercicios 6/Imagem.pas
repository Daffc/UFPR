program Imagem;
Type
	Picture = array [1..1000,1..1000] of integer;
var
	linhas, colunas, max : longint;
	cabecalho : String[2];
	Original : Picture;


procedure Carregar_Imagem(var Orig : Picture; var lin, col, max : longint;var cabe : string );

var i, j : longint;
begin
	readln(cabe);
	if cabe = 'P2' then
	begin
		read(col,lin);
		read(max);
		for i := 1 to lin do
			for j := 1 to col do
				read(Orig[i,j]);
	end;
end;


procedure Mostrar_Imagem(var Orig : Picture; lin, col, max : longint;cabe : string );

var i, j : longint;
begin
	if cabe = 'P2' then
	begin
		writeln(cabe);
		writeln(col,' ',lin);
		writeln(max);
		for i := 1 to lin do
		begin
			for j := 1 to col do
				write(Orig[i,j],' ');
			writeln();
		end;
	end;
end;

procedure Modifica(var Orig : Picture; lin, col, max : longint;cabe : string );
var i, j, horizontal, vertical: longint;
begin

	read(horizontal, vertical);
	if cabe = 'P2' then
	begin
		if (horizontal >= 0) then
		begin
			if(vertical >=0) then
			begin
				writeln(cabe);
				writeln(col,' ',lin); 
				writeln(max);
				for i := 1 to lin do
				begin
					for j := 1 to col do
						if(j - horizontal > 0) then
						begin
							if(i + vertical <= lin) then
								write(Orig[i + vertical,(j - horizontal)],' ')
							else
								write(Orig[(i + vertical) - lin ,(j - horizontal)],' ');
						end
						else
							if(i + vertical <= lin) then
								write(Orig[i + vertical,col + (j - horizontal)],' ')
							else
								write(Orig[(i + vertical) - lin ,col + (j - horizontal)],' ');
					writeln();
				end;
			end
			else
			begin
				writeln(cabe);
				writeln(col,' ',lin); 
				writeln(max);
				for i := 1 to lin do
				begin
					for j := 1 to col do
					begin
						if(j - horizontal > 0)  then
						begin
							if(i + vertical > 0) then
								write(Orig[i + vertical,(j - horizontal)],' ')
							else
								write(Orig[(i + vertical) + lin ,(j - horizontal)],' ');
						end
						else
						begin
							if(i + vertical > 0) then
								write(Orig[i + vertical,col + (j - horizontal)],' ')
							else
								write(Orig[(i + vertical) + lin ,col + (j - horizontal)],' ');
						end;
					end;
					writeln();
				end;
			end;
		end
		else
		begin
			if(vertical >=0) then
			begin
				writeln(cabe);
				writeln(col,' ',lin); 
				writeln(max);
				for i := 1 to lin do
				begin
					for j := 1 to col do
					begin
						if(j - horizontal <= col) then
						begin
							if(i + vertical <= lin) then
								write(Orig[i + vertical,(j - horizontal)],' ')
							else
								write(Orig[(i + vertical) - lin ,(j - horizontal)],' ');
						end
						else
							if(i + vertical <= lin) then
								write(Orig[i + vertical,(j - horizontal) - col],' ')
							else
								write(Orig[(i + vertical) - lin ,(j - horizontal) - col],' ');
					end;
					writeln();
				end;
			end
			else
			begin
				writeln(cabe);
				writeln(col,' ',lin); 
				writeln(max);
				for i := 1 to lin do
				begin
					for j := 1 to col do
					begin
						if(j - horizontal <= col) then
						begin
							if(i + vertical > 0) then
								write(Orig[i + vertical,(j - horizontal)],' ')
							else
								write(Orig[(i + vertical) + lin ,(j - horizontal)],' ');
						end
						else
							if(i + vertical > 0) then
								write(Orig[i + vertical,(j - horizontal) - col],' ')
							else
								write(Orig[(i + vertical) + lin ,(j - horizontal) - col],' ');
					end;
					writeln();
				end;
			end;
		end;
	end;	
end;

begin
	Carregar_Imagem(Original,linhas,colunas, max,cabecalho);
	//Mostrar_Imagem(Original,linhas,colunas, max,cabecalho);
	Modifica(Original,linhas,colunas, max,cabecalho);
end.