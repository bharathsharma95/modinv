ap_uint<1024> modinv(ap_uint<1024>a, ap_uint<1024>b)
{

	ap_uint<16> count = 0;
	ap_uint<1024> temp = 0;
	cout<< "\n******************************************\n\n";

	a_arr[count] = a;
	b_arr[count] = b;
	ap_uint<1024> b_0 = b;
	//cout << "a_arr[" << count << "] : " << a_arr[count] << "\n";
	//cout << "b_arr[" << count << "] : " << b_arr[count] << "\n\n";
	//count++;


	while(a!=0)
	{
		temp = a;
		temp_arr[count] = temp;

		a = b%a;
		a_arr[count+1] = a;

		b = temp;
		b_arr[count+1] = b;

		cout << "a_arr[" << count << "] : " << a_arr[count] << "\n";
		cout << "b_arr[" << count << "] : " << b_arr[count] << "\n\n";
		count++;
	}

	b_arr[0] = b_0;
	cout << "here b_arr[0] : " << b_arr[0] << "\n\n";

	//count is 13 until now

	// when a == 0; setting values of pointers '*x = 0' and '*y = 1'

	ap_uint<1024> gcd = b;
	x_arr[count] = 0; y_arr[count] = 1;

	cout << "a_arr[" << count << "] : " << a_arr[count] << "\n";
	cout << "b_arr[" << count << "] : " << b_arr[count] << "\n";
	cout << "\nreturning b_arr[" << count << "] as gcd : " << gcd << "\n\n";

	count--;
	cout << "after count-- , count is : " << count << "\n\n";


	// updating the values of pointers x & y from recursive calls (from while loop)

		while(count!=0)
		{

			ap_uint<1024> b_arr_temp = b_arr[count];
			ap_uint<1024> a_arr_temp = a_arr[count];

			ap_uint<1024> X_arr_count_plus1;
			ap_uint<1024> Y_arr_count_plus1;
			X_arr_count_plus1 = x_arr[count+1];
			Y_arr_count_plus1 = y_arr[count+1];

				//calculating *x= y1 - ((b/a) * x1);
				ap_uint<1024> X_arr_count_temp;
				X_arr_count_temp = Y_arr_count_plus1 - ((b_arr_temp/a_arr_temp) * X_arr_count_plus1);

					x_arr[count] = X_arr_count_temp;
					cout << "x_arr[" << count << "] : " << x_arr[count] << "\n";

					//calculating *y=x1
				ap_uint<1024> Y_arr_count_temp;
				Y_arr_count_temp = x_arr[count+1];

					y_arr[count] = Y_arr_count_temp;
					cout << "y_arr[" << count << "] : " << y_arr[count] << "\n";
					cout << "a_arr[" << count << "] : " << a_arr[count] << "\n";
					cout << "b_arr[" << count << "] : " << b_arr[count] << "\n\n";

			count--;
		}



	// When count == 0

			ap_uint<1024> b_arr_temp = b_arr[count];
			ap_uint<1024> a_arr_temp = a_arr[count];

			ap_uint<1024> X_arr_count_plus1;
			ap_uint<1024> Y_arr_count_plus1;

			X_arr_count_plus1 = x_arr[count+1];
			Y_arr_count_plus1 = y_arr[count+1];


				ap_uint<1024> X_arr_count_temp;
				X_arr_count_temp = Y_arr_count_plus1 - ((b_arr_temp/a_arr_temp) * X_arr_count_plus1);

					x_arr[count] = X_arr_count_temp;
					cout << "x_arr[" << count << "] : " << x_arr[count] << "\n";

				ap_uint<1024> Y_arr_count_temp;
				Y_arr_count_temp = x_arr[count+1];

					y_arr[count] = Y_arr_count_temp;
					cout << "y_arr[" << count << "] : " << y_arr[count] << "\n";
					cout << "a_arr[" << count << "] : " << a_arr[count] << "\n";
					cout << "b_arr[" << count << "] : " << b_arr[count] << "\n\n";


	// when count == 0 --> end




		ap_uint<1024> res;
		if (gcd != 1)
		        cout << "Inverse doesn't exist\n\n\n";
	    else
	    {
	        // phi_n is added to handle negative x
	    	ap_uint<1024> phi_n = "134369998990354300089952937559587535776969448542275036274354877139580565294709571734984987344659981049823868256870131654179172131661304459362060269619979448861355471525288293114690580693447255431404780065203686577811517411724345053044304720270314669616919153209303508163154216935023021982650271214520";
	    	ap_uint<1024> x_arr_temp = x_arr[count];
	    	cout << "x_arr_temp : " << x_arr_temp << "\n";
	    	cout << "phi_n : " << phi_n << "\n";
	    	//ap_uint<1024> helper1 = x_arr_temp % phi_n;
	    	//ap_uint<1024> helper2 = ((x_arr_temp % phi_n) + phi_n);

	        res = ((x_arr_temp % phi_n) + phi_n) % phi_n;
	        cout << "Modular multiplicative inverse is " << res <<"\n\n\n";
	    }


		return 0;
}
