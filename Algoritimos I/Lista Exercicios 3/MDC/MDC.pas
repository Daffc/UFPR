program MDC;

 var valor, auxiliar, max_dc, cont : longint;

begin

read(valor);
max_dc:= valor;

while(valor <> 0) do
begin
	
	cont := 2;
	auxiliar := 1;
	
	while (valor <> 1) do
	begin 
		if( valor mod cont = 0) then
		begin
			valor := valor div cont;
			
			if( max_dc mod cont = 0) then
			begin
				max_dc:= max_dc div cont;
				auxiliar := auxiliar * cont;
			end;
		end
		
		else
			cont := cont  + 1;
	end;
	max_dc:= auxiliar;
	
	read(valor); 
end;
writeln (max_dc);
end.