#pragma once
#include <datatypes/data/list.h>

// public list functions

void*
list_init(list_type list_type)
{
	list_info list_info = { .type = list_type, .size = 0 };

	switch (list_type)
	{
		case LIST_I32_T: {
			list_i32_t* list = (list_i32_t*)malloc(sizeof(list_i32_t));
			list->list_info = list_info;
			list->first = NULL;
			list->last = NULL;
			return list;
		}
		case LIST_I64_T: {
			list_i64_t* list = (list_i64_t*)malloc(sizeof(list_i64_t));
			list->list_info = list_info;
			list->first = NULL;
			list->last = NULL;
			return list;
		}
		case LIST_U32_T: {
			list_u32_t* list = (list_u32_t*)malloc(sizeof(list_u32_t));
			list->list_info = list_info;
			list->first = NULL;
			list->last = NULL;
			return list;
		}
		case LIST_U64_T: {
			list_u64_t* list = (list_u64_t*)malloc(sizeof(list_u64_t));
			list->list_info = list_info;
			list->first = NULL;
			list->last = NULL;
			return list;
		}
		case LIST_F32_T: {
			list_f32_t* list = (list_f32_t*)malloc(sizeof(list_f32_t));
			list->list_info = list_info;
			list->first = NULL;
			list->last = NULL;
			return list;
		}
		case LIST_F64_T: {
			list_f64_t* list = (list_f64_t*)malloc(sizeof(list_f64_t));
			list->list_info = list_info;
			list->first = NULL;
			list->last = NULL;
			return list;
		}
		default: {
			fprintf(stderr, "[*] list_init: unsupported vector type\n");
			return NULL;
		}
	}
}

bool
list_free(void* self)
{
	if (self == NULL) return false;

	list_info_t* list_info = (list_info_t*)self;

	switch (list_info->type) {
		case LIST_I32_T:
		{
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			while (current) {
				list_i32_node_t* next = current->next;
				free(current);
				current = next;
			}
			free(list);
			return true;
		}
		case LIST_I64_T:
		{
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			while (current) {
				list_i64_node_t* next = current->next;
				free(current);
				current = next;
			}
			free(list);
			return true;
		}
		case LIST_U32_T:
		{
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			while (current) {
				list_u32_node_t* next = current->next;
				free(current);
				current = next;
			}
			free(list);
			return true;
		}
		case LIST_U64_T:
		{
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			while (current) {
				list_u64_node_t* next = current->next;
				free(current);
				current = next;
			}
			free(list);
			return true;
		}
		case LIST_F32_T:
		{
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			while (current) {
				list_f32_node_t* next = current->next;
				free(current);
				current = next;
			}
			free(list);
			return true;
		}
		case LIST_F64_T:
		{
			list_f64_t* list = (list_f64_t*)self;
			list_f64_node_t* current = list->first;
			while (current) {
				list_f64_node_t* next = current->next;
				free(current);
				current = next;
			}
			free(list);
			return true;
		}
		default:
			fprintf(stderr, "[*] list_free: unsupported vector type\n");
			return false;
	}
}

bool
list_contains(void* self, const void* element)
{
	if (self == NULL || element == NULL)
	{
		fprintf(stderr, "[*] list_contains: Invalid list or element\n");
		return false;
	}

	switch (((list_info_t*)self)->type) {
		case LIST_I32_T: {
			i32 search_element = *((i32*)element);
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					return true;
				}
				current = current->next;
			}
			return false;
		}
		case LIST_I64_T: {
			i64 search_element = *((i64*)element);
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					return true;
				}
				current = current->next;
			}
			return false;
		}
		case LIST_U32_T: {
			u32 search_element = *((u32*)element);
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					return true;
				}
				current = current->next;
			}
			return false;
		}
		case LIST_U64_T: {
			u64 search_element = *((u64*)element);
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					return true;
				}
				current = current->next;
			}
			return false;
		}
		case LIST_F32_T: {
			f32 search_element = *((f32*)element);
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					return true;
				}
				current = current->next;
			}
			return false;
		}
		case LIST_F64_T: {
			f64 search_element = *((f64*)element);
			list_f64_t* list = (list_f64_t*)self;
			list_f64_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					return true;
				}
				current = current->next;
			}
			return false;
		}
		default:
			fprintf(stderr, "[*] list_contains: Unknown list type\n");
			return false;
	}
}

bool
list_clear(void* self)
{
	if (self == NULL)
	{
		fprintf(stderr, "[*] list_clear: Invalid list\n");
		return false;
	}

	switch (((list_info_t*)self)->type)
	{
		case LIST_I32_T:
		{
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			while (current != NULL)
			{
				list_i32_node_t* next = current->next;
				free(current);
				current = next;
			}
			list->first = NULL;
			list->last = NULL;
			list->list_info.size = 0;
			return true;
		}
		case LIST_I64_T:
		{
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			while (current != NULL)
			{
				list_i64_node_t* next = current->next;
				free(current);
				current = next;
			}
			list->first = NULL;
			list->last = NULL;
			list->list_info.size = 0;
			return true;
		}
		case LIST_U32_T:
		{
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			while (current != NULL)
			{
				list_u32_node_t* next = current->next;
				free(current);
				current = next;
			}
			list->first = NULL;
			list->last = NULL;
			list->list_info.size = 0;
			return true;
		}
		case LIST_U64_T:
		{
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			while (current != NULL)
			{
				list_u64_node_t* next = current->next;
				free(current);
				current = next;
			}
			list->first = NULL;
			list->last = NULL;
			list->list_info.size = 0;
			return true;
		}
		case LIST_F32_T:
		{
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			while (current != NULL)
			{
				list_f32_node_t* next = current->next;
				free(current);
				current = next;
			}
			list->first = NULL;
			list->last = NULL;
			list->list_info.size = 0;
			return true;
		}
		case LIST_F64_T:
		{
			list_f64_t* list = (list_f64_t*)self;
			list_f64_node_t* current = list->first;
			while (current != NULL)
			{
				list_f64_node_t* next = current->next;
				free(current);
				current = next;
			}
			list->first = NULL;
			list->last = NULL;
			list->list_info.size = 0;
			return true;
		}
		default:
			fprintf(stderr, "[*] list_clear: Unknown list type\n");
			return false;
	}
}

u32
list_find_all(void* self, const void* element) {
	if (self == NULL || element == NULL)
	{
		fprintf(stderr, "[*] list_find_all: Invalid list or element\n");
		return NULL_VAL;
	}

	u32 count = 0;

	switch (((list_info_t*)self)->type) {
		case LIST_I32_T: {
			i32 search_element = *((i32*)element);
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					count++;
				}
				current = current->next;
			}
			return count;
		}
		case LIST_I64_T: {
			i64 search_element = *((i64*)element);
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					count++;
				}
				current = current->next;
			}
			return count;
		}
		case LIST_U32_T: {
			u32 search_element = *((u32*)element);
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					count++;
				}
				current = current->next;
			}
			return count;
		}
		case LIST_U64_T: {
			u64 search_element = *((u64*)element);
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					count++;
				}
				current = current->next;
			}
			return count;
		}
		case LIST_F32_T: {
			f32 search_element = *((f32*)element);
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					count++;
				}
				current = current->next;
			}
			return count;
		}
		case LIST_F64_T: {
			f64 search_element = *((f64*)element);
			list_f64_t* list = (list_f64_t*)self;
			list_f64_node_t* current = list->first;
			while (current != NULL) {
				if (current->data == search_element) {
					count++;
				}
				current = current->next;
			}
			return count;
		}
		default:
			fprintf(stderr, "[*] list_find_all: Unknown list type\n");
			return 0;
	}
}

bool
list_insert(void* self, u32 index, const void* element)
{
	if (self == NULL) {
		fprintf(stderr, "[*] list_insert: Invalid list\n");
		return false;
	}

	switch (((list_info_t*)self)->type) {
		case LIST_I32_T: {
			list_i32_t* list = (list_i32_t*)self;
			if (index > list->list_info.size)
			{
				fprintf(stderr, "[*] list_insert: Index out of bounds\n");
				return false;
			}

			list_i32_node_t* new_node = (list_i32_node_t*)malloc(sizeof(list_i32_node_t));
			if (new_node == NULL)
			{
				fprintf(stderr, "[*] list_insert: Memory allocation failed\n");
				return false;
			}

			new_node->data = *((i32*)element);

			if (index == 0)
			{
				new_node->prev = NULL;
				new_node->next = list->first;
				if (list->first != NULL) {
					list->first->prev = new_node;
				}
				list->first = new_node;
				if (list->last == NULL) {
					list->last = new_node;
				}
			}
			else
			{
				list_i32_node_t* current = list->first;
				for (u32 i = 0; i < index - 1; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				new_node->prev = current;
				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}
				else
				{
					list->last = new_node;
				}
				current->next = new_node;
			}

			list->list_info.size++;
			return true;
		}
		case LIST_I64_T: {
			list_i64_t* list = (list_i64_t*)self;
			if (index > list->list_info.size)
			{
				fprintf(stderr, "[*] list_insert: Index out of bounds\n");
				return false;
			}

			list_i64_node_t* new_node = (list_i64_node_t*)malloc(sizeof(list_i64_node_t));
			if (new_node == NULL)
			{
				fprintf(stderr, "[*] list_insert: Memory allocation failed\n");
				return false;
			}
			new_node->data = *((i64*)element);

			if (index == 0)
			{
				new_node->prev = NULL;
				new_node->next = list->first;
				if (list->first != NULL) {
					list->first->prev = new_node;
				}
				list->first = new_node;
				if (list->last == NULL) {
					list->last = new_node;
				}
			}
			else
			{
				list_i64_node_t* current = list->first;
				for (u32 i = 0; i < index - 1; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				new_node->prev = current;
				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}
				else
				{
					list->last = new_node;
				}
				current->next = new_node;
			}

			list->list_info.size++;
			return true;
		}
		case LIST_U32_T: {
			list_u32_t* list = (list_u32_t*)self;
			if (index > list->list_info.size)
			{
				fprintf(stderr, "[*] list_insert: Index out of bounds\n");
				return false;
			}

			list_u32_node_t* new_node = (list_u32_node_t*)malloc(sizeof(list_u32_node_t));
			if (new_node == NULL)
			{
				fprintf(stderr, "[*] list_insert: Memory allocation failed\n");
				return false;
			}
			new_node->data = *((u32*)element);

			if (index == 0)
			{
				new_node->prev = NULL;
				new_node->next = list->first;
				if (list->first != NULL) {
					list->first->prev = new_node;
				}
				list->first = new_node;
				if (list->last == NULL) {
					list->last = new_node;
				}
			}
			else
			{
				list_u32_node_t* current = list->first;
				for (u32 i = 0; i < index - 1; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				new_node->prev = current;
				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}
				else
				{
					list->last = new_node;
				}
				current->next = new_node;
			}

			list->list_info.size++;
			return true;
		}
		case LIST_U64_T: {
			list_u64_t* list = (list_u64_t*)self;
			if (index > list->list_info.size) {
				fprintf(stderr, "[*] list_insert: Index out of bounds\n");
				return false;
			}

			list_u64_node_t* new_node = (list_u64_node_t*)malloc(sizeof(list_i64_node_t));
			if (new_node == NULL) {
				fprintf(stderr, "[*] list_insert: Memory allocation failed\n");
				return false;
			}

			new_node->data = *((i64*)element);

			if (index == 0)
			{
				new_node->prev = NULL;
				new_node->next = list->first;
				if (list->first != NULL) {
					list->first->prev = new_node;
				}
				list->first = new_node;
				if (list->last == NULL) {
					list->last = new_node;
				}
			}
			else
			{
				list_u64_node_t* current = list->first;
				for (u32 i = 0; i < index - 1; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				new_node->prev = current;
				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}
				else
				{
					list->last = new_node;
				}
				current->next = new_node;
			}

			list->list_info.size++;
			return true;
		}
		case LIST_F32_T: {
			list_f32_t* list = (list_f32_t*)self;
			if (index > list->list_info.size)
			{
				fprintf(stderr, "[*] list_insert: Index out of bounds\n");
				return false;
			}

			list_f32_node_t* new_node = (list_f32_node_t*)malloc(sizeof(list_f32_node_t));
			if (new_node == NULL)
			{
				fprintf(stderr, "[*] list_insert: Memory allocation failed\n");
				return false;
			}
			new_node->data = *((f32*)element);

			if (index == 0)
			{
				new_node->prev = NULL;
				new_node->next = list->first;
				if (list->first != NULL) {
					list->first->prev = new_node;
				}
				list->first = new_node;
				if (list->last == NULL) {
					list->last = new_node;
				}
			}
			else
			{
				list_f32_node_t* current = list->first;
				for (u32 i = 0; i < index - 1; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				new_node->prev = current;
				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}
				else
				{
					list->last = new_node;
				}
				current->next = new_node;
			}

			list->list_info.size++;
			return true;
		}
		case LIST_F64_T: {
			list_f64_t* list = (list_f64_t*)self;
			if (index > list->list_info.size) {
				fprintf(stderr, "[*] list_insert: Index out of bounds\n");
				return false;
			}

			list_f64_node_t* new_node = (list_f64_node_t*)malloc(sizeof(list_f64_node_t));
			if (new_node == NULL) {
				fprintf(stderr, "[*] list_insert: Memory allocation failed\n");
				return false;
			}

			new_node->data = *((f64*)element);

			if (index == 0)
			{
				new_node->prev = NULL;
				new_node->next = list->first;
				if (list->first != NULL) {
					list->first->prev = new_node;
				}
				list->first = new_node;
				if (list->last == NULL) {
					list->last = new_node;
				}
			}
			else
			{
				list_f64_node_t* current = list->first;
				for (u32 i = 0; i < index - 1; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				new_node->prev = current;
				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}
				else
				{
					list->last = new_node;
				}
				current->next = new_node;
			}

			list->list_info.size++;
			return true;
		}
		default:
			fprintf(stderr, "[*] list_insert: Unsupported list type\n");
			return false;
	}
}

bool
list_is_empty(void* self)
{
	list_info_t* list_info = (list_info_t*)self;
	return list_info->size == 0;
}

bool
list_is_equal(void* self, void* list)
{
	if (self == NULL || list == NULL)
	{
		fprintf(stderr, "[*] list_is_equal: one or both lists are NULL\n");
		return false;
	}

	list_info_t* info1 = (list_info_t*)self;
	list_info_t* info2 = (list_info_t*)list;

	if (info1->type != info2->type || info1->size != info2->size) return false;

	switch (info1->type)
	{
		case LIST_I32_T:
		{
			list_i32_t* list1 = (list_i32_t*)self;
			list_i32_t* list2 = (list_i32_t*)list;
			list_i32_node_t* node1 = list1->first;
			list_i32_node_t* node2 = list2->first;
			while (node1 != NULL && node2 != NULL)
			{
				if (node1->data != node2->data) return false;
				node1 = node1->next;
				node2 = node2->next;
			}
			return true;
		}
		case LIST_I64_T:
		{
			list_i64_t* list1 = (list_i64_t*)self;
			list_i64_t* list2 = (list_i64_t*)list;
			list_i64_node_t* node1 = list1->first;
			list_i64_node_t* node2 = list2->first;
			while (node1 != NULL && node2 != NULL)
			{
				if (node1->data != node2->data) return false;
				node1 = node1->next;
				node2 = node2->next;
			}
			return true;
		}
		case LIST_U32_T: {
			list_u32_t* list1 = (list_u32_t*)self;
			list_u32_t* list2 = (list_u32_t*)list;
			list_u32_node_t* node1 = list1->first;
			list_u32_node_t* node2 = list2->first;
			while (node1 != NULL && node2 != NULL)
			{
				if (node1->data != node2->data) return false;
				node1 = node1->next;
				node2 = node2->next;
			}
			return true;
		}
		case LIST_U64_T: {
			list_u64_t* list1 = (list_u64_t*)self;
			list_u64_t* list2 = (list_u64_t*)list;
			list_u64_node_t* node1 = list1->first;
			list_u64_node_t* node2 = list2->first;
			while (node1 != NULL && node2 != NULL)
			{
				if (node1->data != node2->data) return false;
				node1 = node1->next;
				node2 = node2->next;
			}
			return true;
		}
		case LIST_F32_T: {
			list_f32_t* list1 = (list_f32_t*)self;
			list_f32_t* list2 = (list_f32_t*)list;
			list_f32_node_t* node1 = list1->first;
			list_f32_node_t* node2 = list2->first;
			while (node1 != NULL && node2 != NULL)
			{
				if (node1->data != node2->data) return false;
				node1 = node1->next;
				node2 = node2->next;
			}
			return true;
		}
		case LIST_F64_T: {
			list_f64_t* list1 = (list_f64_t*)self;
			list_f64_t* list2 = (list_f64_t*)list;
			list_f64_node_t* node1 = list1->first;
			list_f64_node_t* node2 = list2->first;
			while (node1 != NULL && node2 != NULL)
			{
				if (node1->data != node2->data) return false;
				node1 = node1->next;
				node2 = node2->next;
			}
			return true;
		}
		default:
			fprintf(stderr, "[*] list_is_equal: Unknown list type\n");
			return false;
	}
}

bool
list_remove(void* self, u32 index)
{
	if (self == NULL) return false;

	list_info_t* list_info = (list_info_t*)self;

	if (index < 0 || (u32)index >= list_info->size)  return false; // Index out of bounds

	switch (list_info->type) {
		case LIST_I32_T: {
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			for (i32 i = 0; i < index; ++i) { current = current->next; }

			if (current == NULL)  return false;
			if (current->prev != NULL) { current->prev->next = current->next; }
			else { list->first = current->next; }

			if (current->next != NULL) { current->next->prev = current->prev; }
			else { list->last = current->prev; }

			free(current);
			break;
		}
		case LIST_I64_T: {
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			for (i64 i = 0; i < index; ++i) { current = current->next; }

			if (current == NULL)  return false;
			if (current->prev != NULL) { current->prev->next = current->next; }
			else { list->first = current->next; }

			if (current->next != NULL) { current->next->prev = current->prev; }
			else { list->last = current->prev; }

			free(current);
			break;
		}
		case LIST_U32_T: {
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			for (u32 i = 0; i < index; ++i) { current = current->next; }

			if (current == NULL)  return false;
			if (current->prev != NULL) { current->prev->next = current->next; }
			else { list->first = current->next; }

			if (current->next != NULL) { current->next->prev = current->prev; }
			else { list->last = current->prev; }

			free(current);
			break;
		}
		case LIST_U64_T: {
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			for (u64 i = 0; i < index; ++i) { current = current->next; }

			if (current == NULL)  return false;
			if (current->prev != NULL) { current->prev->next = current->next; }
			else { list->first = current->next; }

			if (current->next != NULL) { current->next->prev = current->prev; }
			else { list->last = current->prev; }

			free(current);
			break;
		}
		case LIST_F32_T: {
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			for (f32 i = 0; i < index; ++i) { current = current->next; }

			if (current == NULL)  return false;
			if (current->prev != NULL) { current->prev->next = current->next; }
			else { list->first = current->next; }

			if (current->next != NULL) { current->next->prev = current->prev; }
			else { list->last = current->prev; }

			free(current);
			break;
		}
		case LIST_F64_T: {
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			for (f32 i = 0; i < index; ++i) { current = current->next; }

			if (current == NULL)  return false;
			if (current->prev != NULL) { current->prev->next = current->next; }
			else { list->first = current->next; }

			if (current->next != NULL) { current->next->prev = current->prev; }
			else { list->last = current->prev; }

			free(current);
			break;
		}
		default:
			fprintf(stderr, "[*] list_remove: unsupported list type\n");
			return false;
	}

	list_info->size--;

	return true;
}

bool
list_reverse(void* self)
{
	if (self == NULL)
	{
		fprintf(stderr, "[*] list_reverse: list is NULL\n");
		return false;
	}

	list_info_t* info = (list_info_t*)self;

	switch (info->type)
	{
		case LIST_I32_T:
		{
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			list_i32_node_t* temp = NULL;
			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL) {
				list->first = temp->prev;
			}
			return true;
		}
		case LIST_I64_T:
		{
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			list_i64_node_t* temp = NULL;
			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL)
			{
				list->first = temp->prev;
			}
			return true;
		}
		case LIST_U32_T:
		{
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			list_u32_node_t* temp = NULL;
			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL)
			{
				list->first = temp->prev;
			}
			return true;
		}
		case LIST_U64_T:
		{
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			list_u64_node_t* temp = NULL;
			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL)
			{
				list->first = temp->prev;
			}
			return true;
		}
		case LIST_F32_T:
		{
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			list_f32_node_t* temp = NULL;
			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL)
			{
				list->first = temp->prev;
			}
			return true;
		}
		case LIST_F64_T: {
			list_f64_t* list = (list_f64_t*)self;
			list_f64_node_t* current = list->first;
			list_f64_node_t* temp = NULL;
			while (current != NULL)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}
			if (temp != NULL)
			{
				list->first = temp->prev;
			}
			return true;
		}
		default:
			fprintf(stderr, "[*] list_reverse: Unknown list type\n");
			return false;
	}
}

bool
list_set(void* self, u32 index, const void* element)
{
	if (self == NULL || element == NULL)
	{
		fprintf(stderr, "[*] list_set: list or element is NULL\n");
		return false;
	}

	list_info_t* info = (list_info_t*)self;

	if (index >= info->size)
	{
		fprintf(stderr, "[*] list_set: index out of bounds\n");
		return false;
	}

	switch (info->type)
	{
		case LIST_I32_T:
		{
			list_i32_t* list = (list_i32_t*)self;
			list_i32_node_t* current = list->first;
			for (u32 i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->data = *(i32*)element;
			return true;
		}
		case LIST_I64_T:
		{
			list_i64_t* list = (list_i64_t*)self;
			list_i64_node_t* current = list->first;
			for (u32 i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->data = *(i64*)element;
			return true;
		}
		case LIST_U32_T:
		{
			list_u32_t* list = (list_u32_t*)self;
			list_u32_node_t* current = list->first;
			for (u32 i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->data = *(u32*)element;
			return true;
		}
		case LIST_U64_T:
		{
			list_u64_t* list = (list_u64_t*)self;
			list_u64_node_t* current = list->first;
			for (u32 i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->data = *(u64*)element;
			return true;
		}
		case LIST_F32_T:
		{
			list_f32_t* list = (list_f32_t*)self;
			list_f32_node_t* current = list->first;
			for (u32 i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->data = *(f32*)element;
			return true;
		}
		case LIST_F64_T:
		{
			list_f64_t* list = (list_f64_t*)self;
			list_f64_node_t* current = list->first;
			for (u32 i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->data = *(f64*)element;
			return true;
		}
		default:
			fprintf(stderr, "[*] list_set: Unknown list type\n");
			return false;
	}
}

u32
list_size(void* self)
{
	list_info_t* list_info = (list_info_t*)self;
	return list_info->size;
}

bool
list_sort(void* self)
{
	if (self == NULL)
	{
		fprintf(stderr, "[*] list_sort: list is NULL\n");
		return false;
	}

	list_info_t* info = (list_info_t*)self;

	switch (info->type)
	{
		case LIST_I32_T:
		{
			list_i32_t* list = (list_i32_t*)self;
			if (list->first == NULL || list->last == NULL) return false;

			bool swapped;
			list_i32_node_t* current;
			list_i32_node_t* last = NULL;

			do
			{
				swapped = false;
				current = list->first;

				while (current->next != last)
				{
					if (current->data > current->next->data)
					{
						i32 temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				last = current;
			} while (swapped);

			return true;
		}

		case LIST_I64_T: {
			list_i64_t* list = (list_i64_t*)self;
			if (list->first == NULL || list->last == NULL) return false;

			bool swapped;
			list_i64_node_t* current;
			list_i64_node_t* last = NULL;

			do
			{
				swapped = false;
				current = list->first;

				while (current->next != last)
				{
					if (current->data > current->next->data)
					{
						i64 temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				last = current;
			} while (swapped);

			return true;
		}

		case LIST_U32_T: {
			list_u32_t* list = (list_u32_t*)self;
			if (list->first == NULL || list->last == NULL) return false;

			bool swapped;
			list_u32_node_t* current;
			list_u32_node_t* last = NULL;

			do
			{
				swapped = false;
				current = list->first;

				while (current->next != last)
				{
					if (current->data > current->next->data)
					{
						u32 temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				last = current;
			} while (swapped);

			return true;
		}

		case LIST_U64_T:
		{
			list_u64_t* list = (list_u64_t*)self;
			if (list->first == NULL || list->last == NULL) return false;

			bool swapped;
			list_u64_node_t* current;
			list_u64_node_t* last = NULL;

			do
			{
				swapped = false;
				current = list->first;

				while (current->next != last)
				{
					if (current->data > current->next->data)
					{
						u64 temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				last = current;
			} while (swapped);

			return true;
		}

		case LIST_F32_T:
		{
			list_f32_t* list = (list_f32_t*)self;
			if (list->first == NULL || list->last == NULL) return false;

			bool swapped;
			list_f32_node_t* current;
			list_f32_node_t* last = NULL;

			do
			{
				swapped = false;
				current = list->first;

				while (current->next != last)
				{
					if (current->data > current->next->data)
					{
						f32 temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				last = current;
			} while (swapped);

			return true;
		}

		case LIST_F64_T:
		{
			list_f64_t* list = (list_f64_t*)self;
			if (list->first == NULL || list->last == NULL) return false;

			bool swapped;
			list_f64_node_t* current;
			list_f64_node_t* last = NULL;

			do
			{
				swapped = false;
				current = list->first;

				while (current->next != last)
				{
					if (current->data > current->next->data)
					{
						f64 temp = current->data;
						current->data = current->next->data;
						current->next->data = temp;
						swapped = true;
					}
					current = current->next;
				}
				last = current;
			} while (swapped);

			return true;
		}
		default:
			fprintf(stderr, "[*] list_sort: unknown list type\n");
			return false;
	}
}

// internal list functions

list_i32_node_t*
_list_append_i32(list_i32_t* self, i32 element) {
	if (self == NULL) return NULL;

	list_i32_node_t* new_node = (list_i32_node_t*)malloc(sizeof(list_i32_node_t));
	if (new_node == NULL) return NULL;

	// Fill the new node with data
	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (self->last == NULL) {
		// The list is empty, set first and last to the new node
		self->first = new_node;
		self->last = new_node;
	}
	else {
		// Append the new node to the end of the list
		new_node->prev = self->last;
		self->last->next = new_node;
		self->last = new_node;
	}

	// Increment the size of the list
	self->list_info.size++;

	return new_node;
}

list_i64_node_t*
_list_append_i64(list_i64_t* self, i64 element) {
	if (self == NULL) return NULL;

	list_i64_node_t* new_node = (list_i64_node_t*)malloc(sizeof(list_i64_node_t));
	if (new_node == NULL) return NULL;

	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (self->last == NULL) {
		self->first = new_node;
		self->last = new_node;
	}
	else {
		new_node->prev = self->last;
		self->last->next = new_node;
		self->last = new_node;
	}

	self->list_info.size++;

	return new_node;
}

list_u32_node_t*
_list_append_u32(list_u32_t* self, u32 element) {
	if (self == NULL) return NULL;

	list_u32_node_t* new_node = (list_u32_node_t*)malloc(sizeof(list_u32_node_t));
	if (new_node == NULL) return NULL;

	// Fill the new node with data
	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (self->last == NULL)
	{
		self->first = new_node;
		self->last = new_node;
	}
	else
	{
		new_node->prev = self->last;
		self->last->next = new_node;
		self->last = new_node;
	}

	// Increment the size of the list
	self->list_info.size++;

	return new_node;
}

list_u64_node_t*
_list_append_u64(list_u64_t* self, u64 element) {
	if (self == NULL) return NULL;

	list_u64_node_t* new_node = (list_u64_node_t*)malloc(sizeof(list_u64_node_t));
	if (new_node == NULL) return NULL;

	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (self->last == NULL)
	{
		self->first = new_node;
		self->last = new_node;
	}
	else
	{
		new_node->prev = self->last;
		self->last->next = new_node;
		self->last = new_node;
	}

	self->list_info.size++;

	return new_node;
}

list_f32_node_t*
_list_append_f32(list_f32_t* self, f32 element) {
	if (self == NULL) return NULL;

	list_f32_node_t* new_node = (list_f32_node_t*)malloc(sizeof(list_f32_node_t));
	if (new_node == NULL) return NULL;

	// Fill the new node with data
	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (self->last == NULL)
	{
		self->first = new_node;
		self->last = new_node;
	}
	else
	{
		new_node->prev = self->last;
		self->last->next = new_node;
		self->last = new_node;
	}

	self->list_info.size++;

	return new_node;
}

list_f64_node_t*
_list_append_f64(list_f64_t* self, f64 element) {
	if (self == NULL) return NULL;

	// Allocate memory for a new node
	list_f64_node_t* new_node = (list_f64_node_t*)malloc(sizeof(list_f64_node_t));
	if (new_node == NULL) return NULL;

	// Fill the new node with data
	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (self->last == NULL)
	{
		self->first = new_node;
		self->last = new_node;
	}
	else
	{
		new_node->prev = self->last;
		self->last->next = new_node;
		self->last = new_node;
	}

	self->list_info.size++;

	return new_node;
}

i32
_list_first_i32(list_i32_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->first->data;
}

i64
_list_first_i64(list_i64_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->first->data;
}

u32
_list_first_u32(list_u32_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->first->data;
}

u64
_list_first_u64(list_u64_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->first->data;
}

f32
_list_first_f32(list_f32_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->first->data;
}

f64
_list_first_f64(list_f64_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_first_f64: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->first->data;
}

i32
_list_get_i32(list_i32_t* self, i32 index)
{
	if (self == NULL || index >= self->list_info.size)
	{
		fprintf(stderr, "[*] list_get: Invalid list or index out of bounds\n");
		return NULL_VAL;
	}

	list_i32_node_t* current = self->first;
	for (uint i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->data;
}

i64
_list_get_i64(list_i64_t* self, i32 index)
{
	if (self == NULL || index >= self->list_info.size)
	{
		fprintf(stderr, "[*] list_get: Invalid list or index out of bounds\n");
		return NULL_VAL;
	}

	list_i64_node_t* current = self->first;
	for (uint i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->data;
}

u32
_list_get_u32(list_u32_t* self, i32 index)
{
	if (self == NULL || index >= self->list_info.size)
	{
		fprintf(stderr, "[*] _list_get_u32: Invalid list or index out of bounds\n");
		return NULL_VAL;
	}

	list_u32_node_t* current = self->first;
	for (uint i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->data;
}

u64
_list_get_u64(list_u64_t* self, i32 index)
{
	if (self == NULL || index >= self->list_info.size)
	{
		fprintf(stderr, "[*] _list_get_u64: Invalid list or index out of bounds\n");
		return NULL_VAL;
	}

	list_u64_node_t* current = self->first;
	for (uint i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->data;
}

f32
_list_get_f32(list_f32_t* self, i32 index)
{
	if (self == NULL || index >= self->list_info.size)
	{
		fprintf(stderr, "[*] _list_get_f32: Invalid list or index out of bounds\n");
		return NULL_VAL;
	}

	list_f32_node_t* current = self->first;
	for (uint i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->data;
}

f64
_list_get_f64(list_f64_t* self, i32 index)
{
	if (self == NULL || index >= self->list_info.size)
	{
		fprintf(stderr, "[*] _list_get_f64: Invalid list or index out of bounds\n");
		return NULL_VAL;
	}

	list_f64_node_t* current = self->first;
	for (uint i = 0; i < index; ++i)
	{
		current = current->next;
	}

	return current->data;
}

i32
_list_last_i32(list_i32_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->last->data;
}

i64
_list_last_i64(list_i64_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_i64: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->last->data;
}

u32
_list_last_u32(list_u32_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_u32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->last->data;
}

u64
_list_last_u64(list_u64_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_u64: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->last->data;
}

f32
_list_last_f32(list_f32_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_f32: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->last->data;
}

f64
_list_last_f64(list_f64_t* self)
{
	if (self == NULL || self->last == NULL)
	{
		fprintf(stderr, "[*] _list_last_f64: Invalid list or list is empty\n");
		return NULL_VAL;
	}

	return self->last->data;
}

void*
_list_node_init(list_type type, void* data)
{
	switch (type) {
	case LIST_I32_T: {
		list_i32_node_t* node = (list_i32_node_t*)malloc(sizeof(list_i32_node_t));
		if (!node) return NULL;
		node->data = *(i32*)data;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
	case LIST_I64_T: {
		list_i64_node_t* node = (list_i64_node_t*)malloc(sizeof(list_i64_node_t));
		if (!node) return NULL;
		node->data = *(i64*)data;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
	case LIST_U32_T: {
		list_u32_node_t* node = (list_u32_node_t*)malloc(sizeof(list_u32_node_t));
		if (!node) return NULL;
		node->data = *(u32*)data;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
	case LIST_U64_T: {
		list_u64_node_t* node = (list_u64_node_t*)malloc(sizeof(list_u64_node_t));
		if (!node) return NULL;
		node->data = *(u64*)data;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
	case LIST_F32_T: {
		list_f32_node_t* node = (list_f32_node_t*)malloc(sizeof(list_f32_node_t));
		if (!node) return NULL;
		node->data = *(f32*)data;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
	case LIST_F64_T: {
		list_f64_node_t* node = (list_f64_node_t*)malloc(sizeof(list_f64_node_t));
		if (!node) return NULL;
		node->data = *(f64*)data;
		node->prev = NULL;
		node->next = NULL;
		return node;
	}
	default:
		fprintf(stderr, "[*] list_node_init: unsupported vector type\n");
		return NULL;
	}
}