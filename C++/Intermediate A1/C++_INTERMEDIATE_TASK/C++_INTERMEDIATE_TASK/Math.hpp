#ifndef __MATH_HPP__
#define __MATH_HPP__


#include <type_traits>


template <typename T, typename U, typename ... Ts>
auto sum(const T& a, const U& b, const  Ts& ... values)
{
	static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && std::is_arithmetic_v<Ts>, "T , U & Ts must be arith.");
	if constexpr (sizeof ... (Ts) > 0)
	{
		auto r = a + b;
		return sum(r, values ...);



	}
	else
	{
		return a +  b;
	}

}
template <typename T, typename U, typename ... Ts>
auto sub(const T& a, const U& b, const  Ts& ... values)
{

	static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && std::is_arithmetic_v<Ts>, "T , U & Ts must be arith.");


	if constexpr (sizeof ... (Ts) > 0)
	{
		auto r = abs(a - b);
		return sub(r, values ...);



	}
	else
	{
		return abs(a - b);
	}

}
template <typename T, typename U, typename ... Ts>
auto max(const T& a, const U& b, const  Ts& ... values)
{
	static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U> && std::is_arithmetic_v<Ts>, "T , U & Ts must be arith.");
	 auto maxium = (double) a;
	

	 if constexpr (sizeof ... (Ts) > 0)
	 {
		 if (b > maxium)
		 {
			 maxium = b;
		 }

		 return max(maxium, values ...);

	 }
	 else
	 {
		 if (b > maxium)
		 {
			 maxium = b;
		 }
		 return maxium;
	 }
	
}
template <typename T, typename U, typename ... Ts>
auto min(const T& a, const U& b, const  Ts& ... values)
{
	static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U> , "T and U must be arith.");
	auto minium = (double) a;

	if constexpr (sizeof ... (Ts) > 0)
	{
		if (b < minium)
		{
			minium = b;
		}

		return min(minium, values ...);

	}
	else
	{
		if (b < minium)
		{
			minium = b;
		}
		return minium;
	}

}





#endif
