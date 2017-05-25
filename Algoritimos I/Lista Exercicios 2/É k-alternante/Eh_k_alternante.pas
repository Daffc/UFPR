program Eh_k_alternante;

var k, a,c, variante, aux: longint;

begin
	
	read (k);
	read (a);
	
	variante:= k;
	
	while(a <> 0) and (variante = k) do
	begin
		
		aux:= a mod 2;
		variante:= 0;
		
		while((a mod 2 = aux) and (a <> 0)) do
		begin	
			variante := variante + 1;
			read(a);
		end;
	end;
	
	
	if((a = 0) and (variante = k)) then
	begin
		writeln('Sim eh k-alternante');
	end
	else
	begin
		writeln('Nao eh k-alternante');
	end;	
	read(a);
end.