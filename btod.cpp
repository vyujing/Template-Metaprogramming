/*
 * 	@Author		Kim Gwangmin
 * 	@binary to decimal in metaprogramming
 *
 *
 * 	How to use?
 *	*************************************
 *
 * 	             CODE
 *	- int n = binary<1011>::value;
 *	- cout << n << endl;
 *
 *	n is 11
 *
 *	*************************************
 *	If you write in <> not binary num like
 *	
 *	- int n = binary<9999>::value;
 *
 *	It will be make compile error.
 *	9999 is not binary.
 */
template<int N> class int2type
{
	enum { value = N };
};

template<typename N> struct isZeroOne
{
	static const N value = nullptr;
};

template<> struct isZeroOne<int2type<1>>
{
	static const int value = 1;
};
template<> struct isZeroOne<int2type<0>>
{
	static const int value = 0;
};
template<int N> struct binary
{
	static const int value = isZeroOne<int2type<N % 10>>::value + binary<N/10>::value * 2;
};
template<> struct binary<0>
{
	static const int value = 0;
};
