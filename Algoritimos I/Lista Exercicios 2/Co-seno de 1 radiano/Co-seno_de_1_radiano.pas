program Co_seno_de_1_radiano;

var a, b,  i, aux : longint;

var soma, final : real;

var teste : boolean; 

begin
	
	final := 1;
	soma := 0;
	i := 0;
	b:= 1;
	teste:= true;
	
	while ((final >= 0.000001) or  (final = 0)) do
	begin
		
		a := 1;
		aux := 1;	
		
		while(aux <= i) do
		begin
			a := a * aux;
			aux := aux + 1;
			writeln('aux a = ',a);
		end;
		
		
		if(teste) then
		begin;
			soma:= soma + 1/a;
			teste:= false;
		end
		
		else
		begin
			soma:= soma -  1/a;
			teste:= true;
		end;
		
		i := i + 2;
		
		final:= ((1/b) - (1/a));
		
		b := a;		
		
		
		writeln('soma = ',abs(soma));
		writeln('i = ',i);
		writeln('a = ',1/a);
		writeln('b = ',1/b);
	end;
	
	writeln(soma);
end.