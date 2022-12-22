#ifndef CAR_H_
#define CAR_H

/*Inkluderingsdirektiv*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <stdbool.h>

/*Enumerationer*/
enum car_transmission {NONE, MANUAL, AUTOMATIC};

/*strukt för bil*/
typedef struct
{
	char* brand;
	char* model;
	char* color;
	uint16_t year_of_launch;
	enum car_transmission transmission;
	struct car_vtable* vptr;

}car;

/*strukt för vtalbe*/
struct car_vtable
{
	void (*print)(car* self, FILE* ostream);
	void (*change_color)(car* self, char* color);
	void (*change_transmission)(car* self);
};

/* Funktions deklarationer */
static void car_change_transmission(car* self);

static void car_change_color(car* self,
	                         char* color);

extern void car_print(car* self,
	                  FILE* ostream);

extern void car_init(car* self,
					 char* brand,
					 char* model,
					 char* color,
					 unsigned int year,
					 enum car_transmission transmission);

extern void car_clear(car* self);

car* car_new(char* brand,
			 char* model,
			 char* color,
			 unsigned int year,
			 enum car_transmission transmission);

extern void car_delete(car** self);

int file_read(const char* filepath);

#endif /* CAR_H_ */#pragma once
