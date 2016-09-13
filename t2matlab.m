f = @(x) (1+sin(exp(3*x)));
format long;
I = integral(f,-1,1,'AbsTol',1e-12)
