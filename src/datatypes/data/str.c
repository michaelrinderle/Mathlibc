#pragma once
#include <datatypes/data/str.h>

str_t*
str_init(char* str)
{
	// get string details
	const size_t size = sizeof(str);
	const size_t length = strlen(str);

	// allocate buffer
	str_t* buffer = (str_t*)malloc(sizeof(str_t) + size + 1);
	if (buffer == NULL)
	{
		fprintf(stderr, "[*] string_init : error allocating memory");
		return NULL;
	}

	// set size and copy string to buffer
	buffer->size = size;
	buffer->length = length;
	strcpy(buffer->buffer, str);

	if (buffer == NULL)
		buffer->buffer[0] = '\0';
	else
		buffer->buffer[length] = '\0';

	return buffer;
}

bool
str_free(str_t* self)
{
	// free string struct & check operation
	free(self);
	self = NULL;
	if (self != NULL)
	{
		fprintf(stderr, "[*] str_free : error freeing memory\n");
		return false;
	}

	return true;
}

bool
str_concatenate(str_t** self, char* cat_str)
{
	// get new string size details
	char* temp = strcat((*self)->buffer, cat_str);
	size_t new_size = strlen(temp) + 1;
	size_t length = (*self)->length + strlen(cat_str);

	// update string len & size details
	if ((*self)->size != new_size)
	{
		(*self)->size = new_size;
		(*self)->length = length;
	}

	// concat string
	strcpy(&(*self)->buffer[new_size], temp);
	(*self)->buffer[new_size] = '\0';

	return true;
}

bool
str_compare(str_t* self, str_t* str)
{
	// string compare buffers
	const int result = strcmp(self->buffer, str->buffer);
	if (result != 0)
		return false;

	return true;
}

str_t*
str_copy(str_t* self)
{
	// allocate buffer
	str_t* buffer = (str_t*)malloc(sizeof(str_t*));
	if (buffer == NULL) return NULL;
	// copy values and string buffer
	*buffer = *self;
	strcpy(buffer->buffer, self->buffer);
	return buffer;
}

bool
str_insert(str_t** self, uint pos, char* insert_str)
{
	if (self == NULL || insert_str == NULL)
	{
		fprintf(stderr, "[zl] str_ins : null value\n");
		return false;
	}
	// create temp buffer
	char* temp = "\0";

	// copy start text
	strncpy(temp, (*self)->buffer, pos);
	int length = strlen(temp);

	// copy insert text
	strcpy(temp + length, insert_str);
	length += strlen(insert_str);

	// copy end text
	strcpy(temp + length, (*self)->buffer + pos);

	// update string len + size
	(*self)->size = sizeof(temp);
	(*self)->length = strlen(temp);

	// copy temp buffer over
	strcpy(&(*self)->buffer, temp);
	return true;
}

bool
str_is_null(str_t* self)
{
	// check length of string
	if (self->length != 0)
		return false;

	return true;
}

bool
str_is_number(str_t* self)
{
	if (self->buffer == NULL) return false;

	// iterate over string & examine each char for alpha
	for (char* temp =self->buffer; *temp != '\0'; temp++)
	{
		if (isalpha(temp))
			return false;
	}

	return false;
}

bool
str_is_sub_char(str_t* self, char c)
{
	return strchr(self->buffer, c) != NULL ? true : false;
}

char*
str_replace(str_t** self, const char* target, const char* replace)
{
	char* p;
	int final_size = 0;
	const int search_size = strlen(target);

	// count how many occurrences
	for (p = strstr((*self)->buffer, (*self)->buffer);
		p != NULL;
		p = strstr(p + search_size, (*self)->buffer))
		final_size++;

	// final size
	final_size = (strlen(replace) - search_size) * final_size + strlen((*self)->buffer);

	// new subject with new size
	char* new_subject = (char*)malloc(final_size);

	// set it to blank
	strcpy(new_subject, "");

	// the start position
	char* old = (*self)->buffer;

	for (p = strstr((*self)->buffer, target);
		p != NULL; p = strstr(p + search_size, target))
	{
		// move ahead and copy some text from original subject , from a certain position
		strncpy(new_subject + strlen(new_subject), old, p - old);

		// move ahead and copy the replacement text
		strcpy(new_subject + strlen(new_subject), replace);

		// the new start position after this search match
		old = p + search_size;
	}

	// copy the part after the last search match
	strcpy(new_subject + strlen(new_subject), old);
	// copy new
	strcpy((*self)->buffer, new_subject);

	return new_subject;
}

char**
str_tokenize(str_t* self, char delim)
{
	char** tokens = NULL;
	char* token = strtok(self, &delim);
	size_t token_count = 0;

	while (token != NULL) {
		// reallocate memory for tokens arrays to ccommodate new token
		tokens = realloc(tokens, (token_count + 1) * sizeof(char*));

		// allocate memory for the current token & copy it
		tokens[token_count] = malloc(strlen(token) + 1);
		strcpy(tokens[token_count], token);

		// increment token count & get next token
		token_count++;
		token = strtok(NULL, &delim);
	}

	// add a NULL terminator at the end of the tokens array
	tokens = realloc(tokens, (token_count + 1) * sizeof(char*));
	tokens[token_count] = NULL;

	return tokens;
}

char*
str_trim(str_t** self)
{
	char* part = (*self)->buffer;
	int len = strlen(part);

	// trim lead & tail whitespace
	// saving ptr by moving to beginning
	while (isspace(part[len - 1])) part[--len] = 0;
	while (*part && isspace(*part)) ++part; --len;

	// update string len & size
	(*self)->size = sizeof(part);
	(*self)->length = strlen(part);
	memmove(&(*self)->buffer, part, (len + 1));

	return part;
}