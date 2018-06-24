#include <iostream>
#define AP_INT_MAX_W 4096
#include <ap_int.h>
using namespace std;

ap_uint<1024> temp_arr[13] = {0};
ap_uint<1024> a_arr[13] = {0};
ap_uint<1024> b_arr[13] = {0};
ap_uint<1024> x_arr[13] = {0};
ap_uint<1024> y_arr[13] = {0};


ap_uint<1024> modinv(ap_uint<1024>a, ap_uint<1024>b)
{

	ap_uint<16> count = 0;
	ap_uint<1024> temp = 0;


	while(a!=0)
	{
		temp = a;
		temp_arr[count] = temp;
		a = b%a;
		a_arr[count] = a;
		b = temp;
		b_arr[count] = b;
		count++;
	}

	// when a == 0; setting values of pointers '*x = 0' and '*y = 1'

	ap_uint<1024> gcd = b;
	cout << "gcd is : " << gcd << "\n";
	count--;
	cout << "count is : " << count << "\n";
	x_arr[count] = 0; y_arr[count] = 1;
	count--;

	// updating the values of pointers x & y from recursive calls (from while loop)


		while(count!=0)
		{

			ap_uint<1024> div_helper;
			ap_uint<1024> b_arr_temp = b_arr[count];
			ap_uint<1024> a_arr_temp = a_arr[count];
			ap_uint<1024> X_arr_count_plus1;
			ap_uint<1024> Y_arr_count_plus1;

			div_helper = b_arr_temp/a_arr_temp;
			X_arr_count_plus1 = x_arr[count+1];
			Y_arr_count_plus1 = y_arr[count+1];

			ap_uint<1024> mult_helper;
			mult_helper = (div_helper * X_arr_count_plus1);

				ap_uint<1024> X_arr_count_temp;
				X_arr_count_temp = Y_arr_count_plus1 - mult_helper;

					x_arr[count] = X_arr_count_temp;
					cout << "x_arr[" << count << "] : " << x_arr[count] << "\n";

				ap_uint<1024> Y_arr_count_temp;
				Y_arr_count_temp = x_arr[count+1];

					y_arr[count] = Y_arr_count_temp;
					cout << "y_arr[" << count << "] : " << y_arr[count] << "\n";
					cout << "a_arr[" << count << "] : " << a_arr[count] << "\n";
					cout << "b_arr[" << count << "] : " << b_arr[count] << "\n\n";

			count--;
		}



	// when count == 0


		ap_uint<1024> div_helper;
			ap_uint<1024> b_arr_temp = b_arr[count];
			ap_uint<1024> a_arr_temp = a_arr[count];
			ap_uint<1024> X_arr_count_plus1;
			ap_uint<1024> Y_arr_count_plus1;

			div_helper = b_arr_temp/a_arr_temp;
			X_arr_count_plus1 = x_arr[count+1];
			Y_arr_count_plus1 = y_arr[count+1];

			ap_uint<1024> mult_helper;
			mult_helper = (div_helper * X_arr_count_plus1);

				ap_uint<1024> X_arr_count_temp;
				X_arr_count_temp = Y_arr_count_plus1 - mult_helper;

					x_arr[count] = X_arr_count_temp;
					cout << "x_arr[" << count << "] : " << x_arr[count] << "\n";

				ap_uint<1024> Y_arr_count_temp;
				Y_arr_count_temp = x_arr[count+1];

					y_arr[count] = Y_arr_count_temp;
					cout << "y_arr[" << count << "] : " << y_arr[count] << "\n\n";

/*
		ap_uint<1024> div_helper;
			ap_uint<1024> b_arr_temp = b_arr[count];
			ap_uint<1024> a_arr_temp = a_arr[count];
			ap_uint<1024> X_arr_count_plus1;
			ap_uint<1024> Y_arr_count_plus1;

			div_helper = b_arr_temp/a_arr_temp;
			X_arr_count_plus1 = x_arr[count+1];
			Y_arr_count_plus1 = y_arr[count+1];

			ap_uint<1024> mult_helper;
			mult_helper = (div_helper * X_arr_count_plus1);

				ap_uint<1024> X_arr_count_temp;
				X_arr_count_temp = Y_arr_count_plus1 - mult_helper;

					x_arr[count] = X_arr_count_temp;
					cout << "x_arr[" << count << "] : " << x_arr[count] << "\n";

				ap_uint<1024> Y_arr_count_temp;
				Y_arr_count_temp = x_arr[count+1];

					y_arr[count] = Y_arr_count_temp;
					cout << "y_arr[" << count << "] : " << y_arr[count] << "\n\n";

*/
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
