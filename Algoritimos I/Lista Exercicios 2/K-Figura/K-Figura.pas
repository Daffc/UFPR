program K_Figura;

var a, con, i: integer;

begin

	read (a);
	con := 0;
	
	while(con < a) do
	begin
		i := 1;
		
		while(i <= con) do
		begin
			write(i);
			i:= i + 1;
		end;
		
		while(i >= 1 ) do
		begin
			write(i);
			i:= i - 1;
		end;
		
		writeln ('');
		
		con:= con + 1;
	end;
end.