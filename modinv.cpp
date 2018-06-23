#include <iostream>
#define AP_INT_MAX_W 4096
#include <ap_int.h>
using namespace std;

ap_uint<1024> temp_arr[12] = {0};
ap_uint<1024> a_arr[12] = {0};
ap_uint<1024> b_arr[12] = {0};
ap_uint<1024> x_arr[12] = {0};
ap_uint<1024> y_arr[12] = {0};

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
	cout << "gcd is:" << gcd << "\n";
	x_arr[count] = 0; y_arr[count] = 1;
	count--;

	// updating the values of pointers x & y from recursive calls (from while loop)

/*
		while(count!=0)
		{

			ap_uint<1024> div_helper;
			ap_uint<1024> b_arr_temp = b_arr[count];
			ap_uint<1024> a_arr_temp = a_arr[count];

			div_helper = b_arr[count]/a_arr[count];

			ap_uint<1024> mult_helper;
			mult_helper = (div_helper * x_arr[count+1]);

				ap_uint<1024> X_arr_count_temp;
				X_arr_count_temp = y_arr[count+1] - mult_helper;

					x_arr[count] = X_arr_count_temp;

				ap_uint<1024> Y_arr_count_temp;
				Y_arr_count_temp = x_arr[count+1];

					y_arr[count] = Y_arr_count_temp;

			count--;
		}



	// when count == 0

	x_arr[count] = y_arr[count+1] - ((b_arr[count]/a_arr[count]) * x_arr[count+1]);
	y_arr[count] = x_arr[count+1];

		ap_uint<1024> res;
		if (gcd != 1)
		        cout << "Inverse doesn't exist\n\n\n";
	    else
	    {
	        // phi_n is added to handle negative x
	        res = ((x_arr[count] % b) + b) % b;
	        cout << "Modular multiplicative inverse is " << res <<"\n\n\n";
	    }
*/
		return 0;
}
