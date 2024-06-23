#pragma once
#include <datatypes/fraction.h>
#include <fields/number_theory.h>

fraction_t*
fraction_init(int numerator, unsigned int denominator)
{
	fraction_t* fraction = (fraction_t*)malloc(sizeof(fraction_t));
	if (fraction == NULL)
	{
		fprintf(stderr, "[*] fraction_init : failed to allocate memory");
		return NULL;
	}

	fraction->numerator = numerator;
	fraction->denominator = denominator;

	return fraction;
}

bool
fraction_free(fraction_t* self)
{
	free(self);
	self = NULL;

	return (self == NULL) ? true : false;
}

fraction_t*
fraction_reciprocal(fraction_t* self)
{
	// determine if positive or negative fraction
	int numerator = self->numerator < 0 ? (-1 * self->denominator) : self->denominator;
	unsigned int denominator = abs(self->numerator);

	return fraction_init(numerator, self->numerator);
}

void
fraction_simplify(fraction_t* self)
{
	unsigned int gcd = greatest_common_divisor(abs(self->numerator), self->denominator);

	if (self->numerator < 0)
	{
		// find gcd without negative sign and then reassign numerator
		unsigned int numberator_abs = abs(self->numerator) / gcd;
		self->numerator = -1 * numberator_abs;
	}
	else
	{
		self->numerator = self->numerator / gcd;
	}

	// simplify the denominator by dividing the gcd
	self->denominator = self->denominator / gcd;
}

double
fraction_to_decimal(fraction_t* self)
{
	return (double)self->numerator / (double)self->denominator;
}

str_t*
fraction_to_string(fraction_t* self)
{
	char buffer[50];
	snprintf(buffer, sizeof(buffer), "%d/%u", self->numerator, self->denominator);
	str_t* frac = str_init(buffer);
	return frac;
}
