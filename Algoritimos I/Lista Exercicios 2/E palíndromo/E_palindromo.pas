program E_palindromo;

var a, b, con_1, con_2, i, aux: longint;

begin
	read (a);
	con_1:= 1;
	con_2:= 1;
	i:= 0;
	b:=0;
	
	{contando o numero de casas decimais do valor de entrada}
	
	while((a mod con_1) <> a) do
	begin
		con_1:= con_1 * 10;
		i:= i + 1;
	end;
	
	con_1 := con_1 div 10;
	aux := a;
	
	while(i>0) do
	begin
		b := b +  ((aux div con_1)* con_2);
		aux := aux - ((aux div con_1)* con_1);
		con_1:= con_1 div 10;		
		con_2:= con_2 * 10;
		i:= i - 1;
	end;
	
	if (b = a) then
		writeln('Sim eh palindromo')
	else
		writeln('Nao eh palindromo');
	read (a);
end.