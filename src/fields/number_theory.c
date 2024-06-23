#include <fields/number_theory.h>

u32
greatest_common_divisor(u32 num1, u32 num2)
{
	// use the Euclidean algorithm to find the GCD
	while (num2 != 0)
	{
		u32 temp = num2;
		num2 = num1 % num2;
		num1 = temp;;
	}

	// return the GCD
	return num1;
}

u64
least_common_multiple(u32 num1, u32 num2)
{
	u32 gcd = greatest_common_divisor(num1, num2);

	// LCM(num1, num2) = (num1 / GCD) * num2
	return ((u64)num1 / gcd) * num2;
}

u32
num_of_divisors(u32 num)
{
	if (num == 0) return 0;

	u32 count = 0;

	// iterate from 1 to num & count divisors
	for (u32 i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			count += 1;
		}
	}

	return count;
}

u64
modular_exponentiation(i64 base, u32 exponent, u32 modulus)
{
	if (modulus == 1)
	{
		return 0; // modulus is invalid
	}

	u64 result = 1;
	base = base % modulus;

	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		{
			result = (result * base) % modulus; // multiple result by base % modulus
		}
		exponent = exponent / 2; // divide exponent by 2
		base = (base * base) % modulus; // square base % modulus
	}

	return result;
}

u64
sum_of_divisors(u32 num)
{
	if (num == 0 || num == 1) return 0; // 0 & 1 has no divisors

	u64 sum = 0;
	u32 sqrt_num = (u32)sqrt(num); // only need to iterate up to num's square root

	for (u32 i = 1; i <= sqrt_num; i++)
	{
		if (num % i == 0)
		{
			// add divisor
			sum += i;

			// if i is a divisor of num, num / i is also a divisor of num
			if (i != num / i)
			{
				sum += (u64)(num / i);
			}
		}
	}

	return sum;
}

u64
sum_of_proper_divisors(u32 num)
{
	if (num == 0 || num == 1) return 0; // 0 & 1 has no divisors

	u64 sum = 0;
	u32 sqrt_num = (u32)sqrt(num); // only need to iterate up to num's square root

	for (u32 i = 1; i <= sqrt_num; i++)
	{
		if (num % i == 0)
		{
			// exclude num and 1 from proper divisors
			if (i != num)
			{
				sum += i;
			}

			// add num/i to sum if it's a proper divisor and not equal to num and not equal to i
			if (num / i != num && num / i != i)
			{
				sum += num / i;
			}
		}
	}

	return sum;
}

u64
sum_of_squares(u32 num)
{
	u64 sum = 0;

	while (num > 0)
	{
		u32 digit = num % 10; // get the last digit of num
		sum += ((u64)digit * digit); // square the digit & add the sum
		num /= 10; // remove the last digit from num
	}

	return sum;
}
