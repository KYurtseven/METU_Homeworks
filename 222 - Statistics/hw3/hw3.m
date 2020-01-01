N=38416; %montecarlo number
results = []; %array of fish kg's
counter = 0;
for i=1:N;
	poissu = poissrnd(12); 
	totalkg = 0;
	for k=1:poissu;
		u = rand;
		if (u<=0.2)
			p = [0.1 -0.2 0 0.3 -u]; %integral of first function = u
			r = roots(p);
			r = r(imag(r)==0);
			r = r(r<=1);
			r = r(r>=0);		
		elseif (0.2<u && u<=0.6)
			p = [-0.3 1.8 -3.6 3.1 (-0.8-u)]; %integral of second function + 0.2 =u
			r = roots(p);
			r = r(imag(r)==0);
			r = r(r<=2);
			r = r(r>=1);
		else
			p = [0.3 -3 10.8 -16.1 (8.8-u)]; %integral of third function + 0.6 = u
			r = roots(p);
			r = r(imag(r)==0);
			r = r(r<=3);
			r = r(r>=2);
		end
		totalkg = totalkg+r;
	end;
	results(i) = totalkg;
	if results(i) > 25
		counter = counter + 1;
	end
end;
probab= counter / N;
probab
meann= mean(results);
meann
stnddv = std(results);
stnddv
