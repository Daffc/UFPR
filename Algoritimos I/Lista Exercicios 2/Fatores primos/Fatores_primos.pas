program Fatores_primos;

var a, con: integer;

begin
	read (a);
	
	while( a <> 1) do
	begin
		con:= 2;
		while(a mod con <> 0) do
		begin
			con:= con + 1;
		end;
		write( con, ' ');
		a:= a div con;
	end;
	read(a);
end.