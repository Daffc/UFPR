program primos;

function encontra_primo( limite: integer): integer;

var atual, contagem, aux: integer;

begin  
  
  contagem:= 0;
  atual := 2;
  
  while (contagem < limite)do
  
  begin
  
  	aux:= trunc(sqrt(atual));
    
    while ( (atual mod aux <> 0) and (aux > 1)) do
    begin
    	aux := aux - 1;
    end;
    
    if(aux = 1) then
    	contagem := contagem + 1;
        
    atual := atual + 1;   
    
  end;
  
  encontra_primo:= atual - 1;
  
end;


begin

writeln(encontra_primo(23));
end.