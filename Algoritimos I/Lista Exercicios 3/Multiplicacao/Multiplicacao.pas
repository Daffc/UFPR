program MDC;

var valor_1,  valor_2, total, casa: longint;
    aux_1: real;
 
function multiplica( valor, multiplo, decimal: longint):longint;
    
    var auxiliar: real;
        soma, multiplicador: longint;
     
begin
    multiplicador := 1;
    
    soma := 0;
    while(valor > 0) do
    begin
        auxiliar := valor / 10;
        valor:= trunc(auxiliar);
        auxiliar := auxiliar - valor;
        auxiliar := round(auxiliar * 10);
        
        
        soma := soma + ((trunc(auxiliar) * multiplo)*multiplicador);
        multiplicador := multiplicador * 10;
        
    end ;
    
    multiplica := soma * decimal;
    
end;



begin
    read(valor_1);
    read(valor_2);
    
    total := 0;
    casa := 1;
    
    while(valor_2 > 0) do
    begin
        aux_1 := valor_2 / 10;
        valor_2:= trunc(aux_1);
        aux_1 := aux_1 - valor_2;
        aux_1 := round(aux_1 * 10);
        total := total + multiplica(valor_1, trunc(aux_1), casa);
        casa := casa * 10;
    end ;
    writeln(total);
end.